// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "protorpc/compiler/cpp_generator.h"
#include "protorpc/compiler/cpp_generator_helpers.h"

namespace protorpc_cpp_generator {


std::string GetHeaderPrologue(const google::protobuf::FileDescriptor *file, const Parameters &params) {
	std::string output;
	{
		// Scope the output stream so it closes and finalizes output to the string.
		google::protobuf::io::StringOutputStream output_stream(&output);
		google::protobuf::io::Printer printer(&output_stream, '$');
		std::map<std::string, std::string> vars;

		vars["filename"] = file->name();
		vars["filename_identifier"] = protorpc_generator::FilenameIdentifier(file->name());
		vars["filename_base"] = protorpc_generator::StripProto(file->name());

		printer.Print(vars, "// Generated by the protorpc protobuf plugin.\n");
		printer.Print(vars, "// If you make any local change, they will be lost.\n");
		printer.Print(vars, "// source: $filename$\n");
		printer.Print(vars, "\n");
		printer.Print(vars, "#ifndef PROTORPC_$filename_identifier$__INCLUDED\n");
		printer.Print(vars, "#define PROTORPC_$filename_identifier$__INCLUDED\n");
		printer.Print(vars, "\n");
		printer.Print(vars, "#include \"$filename_base$.pb.h\"\n");
		printer.Print(vars, "\n");
	}
	return output;
}


std::string GetHeaderIncludes(const google::protobuf::FileDescriptor *file, const Parameters &params) {
	std::string temp = (
		"#include <protorpc/rpc_service.h>\n"
		"\n"
	);

	if (!file->package().empty()) {
		auto parts = protorpc_generator::tokenize(file->package(), ".");
		for (auto part = parts.begin(); part != parts.end(); part++) {
			temp.append("namespace ");
			temp.append(*part);
			temp.append(" {\n");
		}
		temp.append("\n");
	}

	return temp;
}


void PrintHeaderClientMethodInterfaces(
	google::protobuf::io::Printer *printer,
	const google::protobuf::MethodDescriptor *method,
	std::map<std::string, std::string> *vars, bool is_public
) {
	(*vars)["Method"]   = method->name();
	(*vars)["Request"]  = protorpc_cpp_generator::ClassName(method->input_type(), true);
	(*vars)["Response"] = protorpc_cpp_generator::ClassName(method->output_type(), true);

	if (is_public) {
		if (protorpc_generator::NoStreaming(method)) {
			printer->Print(*vars,
				"virtual ::grpc::Status $Method$(::grpc::ClientContext* context, "
				"const $Request$& request, $Response$* response) = 0;\n");
			printer->Print(*vars,
				"std::unique_ptr< "
				"::grpc::ClientAsyncResponseReaderInterface< $Response$>> "
				"Async$Method$(::grpc::ClientContext* context, "
				"const $Request$& request, "
				"::grpc::CompletionQueue* cq) {\n");
			printer->Indent();
			printer->Print(*vars,
				"return std::unique_ptr< "
				"::grpc::ClientAsyncResponseReaderInterface< $Response$>>("
				"Async$Method$Raw(context, request, cq));\n");
			printer->Outdent();
			printer->Print("}\n");
		} else if (protorpc_generator::ClientOnlyStreaming(method)) {
			printer->Print(*vars,
				"std::unique_ptr< ::grpc::ClientWriterInterface< $Request$>>"
				" $Method$("
				"::grpc::ClientContext* context, $Response$* response) {\n");
			printer->Indent();
			printer->Print(*vars,
				"return std::unique_ptr< ::grpc::ClientWriterInterface< $Request$>>"
				"($Method$Raw(context, response));\n");
			printer->Outdent();
			printer->Print("}\n");
			printer->Print(*vars,
				"std::unique_ptr< ::grpc::ClientAsyncWriterInterface< $Request$>>"
				" Async$Method$(::grpc::ClientContext* context, $Response$* "
				"response, "
				"::grpc::CompletionQueue* cq, void* tag) {\n");
			printer->Indent();
			printer->Print(*vars,
				"return std::unique_ptr< "
				"::grpc::ClientAsyncWriterInterface< $Request$>>("
				"Async$Method$Raw(context, response, cq, tag));\n");
			printer->Outdent();
			printer->Print("}\n");
		} else if (protorpc_generator::ServerOnlyStreaming(method)) {
			printer->Print(*vars,
						"std::unique_ptr< ::grpc::ClientReaderInterface< $Response$>>"
						" $Method$(::grpc::ClientContext* context, const $Request$& request)"
						" {\n");
			printer->Indent();
			printer->Print(*vars,
						   "return std::unique_ptr< ::grpc::ClientReaderInterface< $Response$>>"
						   "($Method$Raw(context, request));\n");
			printer->Outdent();
			printer->Print("}\n");
			printer->Print(*vars,
						   "std::unique_ptr< ::grpc::ClientAsyncReaderInterface< $Response$>> "
						   "Async$Method$("
						   "::grpc::ClientContext* context, const $Request$& request, "
						   "::grpc::CompletionQueue* cq, void* tag) {\n");
			printer->Indent();
			printer->Print(*vars,
						   "return std::unique_ptr< "
						   "::grpc::ClientAsyncReaderInterface< $Response$>>("
						   "Async$Method$Raw(context, request, cq, tag));\n");
			printer->Outdent();
			printer->Print("}\n");
		} else if (protorpc_generator::BidiStreaming(method)) {
			printer->Print(*vars,
						   "std::unique_ptr< ::grpc::ClientReaderWriterInterface< "
						   "$Request$, $Response$>> "
						   "$Method$(::grpc::ClientContext* context) {\n");
			printer->Indent();
			printer->Print(*vars,
						   "return std::unique_ptr< "
						   "::grpc::ClientReaderWriterInterface< $Request$, $Response$>>("
						   "$Method$Raw(context));\n");
			printer->Outdent();
			printer->Print("}\n");
			printer->Print(*vars,
						   "std::unique_ptr< "
						   "::grpc::ClientAsyncReaderWriterInterface< $Request$, $Response$>> "
						   "Async$Method$(::grpc::ClientContext* context, "
						   "::grpc::CompletionQueue* cq, void* tag) {\n");
			printer->Indent();
			printer->Print(*vars,
						   "return std::unique_ptr< "
						   "::grpc::ClientAsyncReaderWriterInterface< $Request$, $Response$>>("
						   "Async$Method$Raw(context, cq, tag));\n");
			printer->Outdent();
			printer->Print("}\n");
		}
	} else {
		if (protorpc_generator::NoStreaming(method)) {
			printer->Print(*vars,
						   "virtual ::grpc::ClientAsyncResponseReaderInterface< $Response$>* "
						   "Async$Method$Raw(::grpc::ClientContext* context, "
						   "const $Request$& request, "
						   "::grpc::CompletionQueue* cq) = 0;\n");
		} else if (protorpc_generator::ClientOnlyStreaming(method)) {
			printer->Print(*vars,
						   "virtual ::grpc::ClientWriterInterface< $Request$>*"
						   " $Method$Raw("
						   "::grpc::ClientContext* context, $Response$* response) = 0;\n");
			printer->Print(*vars,
						   "virtual ::grpc::ClientAsyncWriterInterface< $Request$>*"
						   " Async$Method$Raw(::grpc::ClientContext* context, "
						   "$Response$* response, "
						   "::grpc::CompletionQueue* cq, void* tag) = 0;\n");
		} else if (protorpc_generator::ServerOnlyStreaming(method)) {
			printer->Print(*vars,
						   "virtual ::grpc::ClientReaderInterface< $Response$>* $Method$Raw("
						   "::grpc::ClientContext* context, const $Request$& request) = 0;\n");
			printer->Print(*vars,
						   "virtual ::grpc::ClientAsyncReaderInterface< $Response$>* "
						   "Async$Method$Raw("
						   "::grpc::ClientContext* context, const $Request$& request, "
						   "::grpc::CompletionQueue* cq, void* tag) = 0;\n");
		} else if (protorpc_generator::BidiStreaming(method)) {
			printer->Print(*vars,
						   "virtual ::grpc::ClientReaderWriterInterface< $Request$, "
						   "$Response$>* "
						   "$Method$Raw(::grpc::ClientContext* context) = 0;\n");
			printer->Print(*vars,
						   "virtual ::grpc::ClientAsyncReaderWriterInterface< "
						   "$Request$, $Response$>* "
						   "Async$Method$Raw(::grpc::ClientContext* context, "
						   "::grpc::CompletionQueue* cq, void* tag) = 0;\n");
		}
	}
}



void PrintHeaderClientMethod(
		google::protobuf::io::Printer *printer,
		const google::protobuf::MethodDescriptor *method,
		std::map<std::string, std::string> *vars,
		bool is_public
) {
	(*vars)["Method"]   = method->name();
	(*vars)["Request"]  = protorpc_cpp_generator::ClassName(method->input_type(), true);
	(*vars)["Response"] = protorpc_cpp_generator::ClassName(method->output_type(), true);

	if (is_public) {
		if (protorpc_generator::NoStreaming(method)) {
			printer->Print(*vars,
						   "::grpc::Status $Method$(::grpc::ClientContext* context, "
						   "const $Request$& request, $Response$* response) GRPC_OVERRIDE;\n");
			printer->Print(*vars,
						   "std::unique_ptr< ::grpc::ClientAsyncResponseReader< $Response$>> "
						   "Async$Method$(::grpc::ClientContext* context, "
						   "const $Request$& request, "
						   "::grpc::CompletionQueue* cq) {\n");
			printer->Indent();
			printer->Print(*vars,
						   "return std::unique_ptr< "
						   "::grpc::ClientAsyncResponseReader< $Response$>>("
						   "Async$Method$Raw(context, request, cq));\n");
			printer->Outdent();
			printer->Print("}\n");
		} else if (protorpc_generator::ClientOnlyStreaming(method)) {
			printer->Print(*vars,
						   "std::unique_ptr< ::grpc::ClientWriter< $Request$>>"
						   " $Method$("
						   "::grpc::ClientContext* context, $Response$* response) {\n");
			printer->Indent();
			printer->Print(*vars,
						   "return std::unique_ptr< ::grpc::ClientWriter< $Request$>>"
						   "($Method$Raw(context, response));\n");
			printer->Outdent();
			printer->Print("}\n");
			printer->Print(*vars,
						   "std::unique_ptr< ::grpc::ClientAsyncWriter< $Request$>>"
						   " Async$Method$(::grpc::ClientContext* context, "
						   "$Response$* response, "
						   "::grpc::CompletionQueue* cq, void* tag) {\n");
			printer->Indent();
			printer->Print(*vars,
						   "return std::unique_ptr< ::grpc::ClientAsyncWriter< $Request$>>("
						   "Async$Method$Raw(context, response, cq, tag));\n");
			printer->Outdent();
			printer->Print("}\n");
		} else if (protorpc_generator::ServerOnlyStreaming(method)) {
			printer->Print(*vars,
						   "std::unique_ptr< ::grpc::ClientReader< $Response$>>"
						   " $Method$(::grpc::ClientContext* context, const $Request$& request)"
						   " {\n");
	  printer->Indent();
	  printer->Print(
		  *vars,
		  "return std::unique_ptr< ::grpc::ClientReader< $Response$>>"
		  "($Method$Raw(context, request));\n");
	  printer->Outdent();
	  printer->Print("}\n");
	  printer->Print(
		  *vars,
		  "std::unique_ptr< ::grpc::ClientAsyncReader< $Response$>> "
		  "Async$Method$("
		  "::grpc::ClientContext* context, const $Request$& request, "
		  "::grpc::CompletionQueue* cq, void* tag) {\n");
	  printer->Indent();
	  printer->Print(
		  *vars,
		  "return std::unique_ptr< ::grpc::ClientAsyncReader< $Response$>>("
		  "Async$Method$Raw(context, request, cq, tag));\n");
	  printer->Outdent();
	  printer->Print("}\n");
	} else if (protorpc_generator::BidiStreaming(method)) {
	  printer->Print(
		  *vars,
		  "std::unique_ptr< ::grpc::ClientReaderWriter< $Request$, $Response$>>"
		  " $Method$(::grpc::ClientContext* context) {\n");
	  printer->Indent();
	  printer->Print(*vars,
					 "return std::unique_ptr< "
					 "::grpc::ClientReaderWriter< $Request$, $Response$>>("
					 "$Method$Raw(context));\n");
	  printer->Outdent();
	  printer->Print("}\n");
	  printer->Print(*vars,
					 "std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< "
					 "$Request$, $Response$>> "
					 "Async$Method$(::grpc::ClientContext* context, "
					 "::grpc::CompletionQueue* cq, void* tag) {\n");
	  printer->Indent();
	  printer->Print(*vars,
					 "return std::unique_ptr< "
					 "::grpc::ClientAsyncReaderWriter< $Request$, $Response$>>("
					 "Async$Method$Raw(context, cq, tag));\n");
	  printer->Outdent();
	  printer->Print("}\n");
	}
  } else {
	if (protorpc_generator::NoStreaming(method)) {
	  printer->Print(*vars,
					 "::grpc::ClientAsyncResponseReader< $Response$>* "
					 "Async$Method$Raw(::grpc::ClientContext* context, "
					 "const $Request$& request, "
					 "::grpc::CompletionQueue* cq) GRPC_OVERRIDE;\n");
	} else if (protorpc_generator::ClientOnlyStreaming(method)) {
	  printer->Print(*vars,
					 "::grpc::ClientWriter< $Request$>* $Method$Raw("
					 "::grpc::ClientContext* context, $Response$* response) "
					 "GRPC_OVERRIDE;\n");
	  printer->Print(
		  *vars,
		  "::grpc::ClientAsyncWriter< $Request$>* Async$Method$Raw("
		  "::grpc::ClientContext* context, $Response$* response, "
		  "::grpc::CompletionQueue* cq, void* tag) GRPC_OVERRIDE;\n");
	} else if (protorpc_generator::ServerOnlyStreaming(method)) {
	  printer->Print(*vars,
					 "::grpc::ClientReader< $Response$>* $Method$Raw("
					 "::grpc::ClientContext* context, const $Request$& request)"
					 " GRPC_OVERRIDE;\n");
	  printer->Print(
		  *vars,
		  "::grpc::ClientAsyncReader< $Response$>* Async$Method$Raw("
		  "::grpc::ClientContext* context, const $Request$& request, "
		  "::grpc::CompletionQueue* cq, void* tag) GRPC_OVERRIDE;\n");
	} else if (protorpc_generator::BidiStreaming(method)) {
	  printer->Print(
		  *vars,
		  "::grpc::ClientReaderWriter< $Request$, $Response$>* "
		  "$Method$Raw(::grpc::ClientContext* context) GRPC_OVERRIDE;\n");
	  printer->Print(
		  *vars,
		  "::grpc::ClientAsyncReaderWriter< $Request$, $Response$>* "
		  "Async$Method$Raw(::grpc::ClientContext* context, "
		  "::grpc::CompletionQueue* cq, void* tag) GRPC_OVERRIDE;\n");
	}
  }
}



void PrintHeaderClientMethodData(google::protobuf::io::Printer *printer,
								 const google::protobuf::MethodDescriptor *method,
								 std::map<std::string, std::string> *vars) {
  (*vars)["Method"] = method->name();
  printer->Print(*vars, "const ::grpc::RpcMethod rpcmethod_$Method$_;\n");
}

void PrintHeaderServerMethodSync(google::protobuf::io::Printer *printer,
								 const google::protobuf::MethodDescriptor *method,
								 std::map<std::string, std::string> *vars) {
  (*vars)["Method"] = method->name();
  (*vars)["Request"] =
	  protorpc_cpp_generator::ClassName(method->input_type(), true);
  (*vars)["Response"] =
	  protorpc_cpp_generator::ClassName(method->output_type(), true);
  if (protorpc_generator::NoStreaming(method)) {
	printer->Print(*vars,
				   "virtual ::grpc::Status $Method$("
				   "::grpc::ServerContext* context, const $Request$* request, "
				   "$Response$* response);\n");
  } else if (protorpc_generator::ClientOnlyStreaming(method)) {
	printer->Print(*vars,
				   "virtual ::grpc::Status $Method$("
				   "::grpc::ServerContext* context, "
				   "::grpc::ServerReader< $Request$>* reader, "
				   "$Response$* response);\n");
  } else if (protorpc_generator::ServerOnlyStreaming(method)) {
	printer->Print(*vars,
				   "virtual ::grpc::Status $Method$("
				   "::grpc::ServerContext* context, const $Request$* request, "
				   "::grpc::ServerWriter< $Response$>* writer);\n");
  } else if (protorpc_generator::BidiStreaming(method)) {
	printer->Print(
		*vars,
		"virtual ::grpc::Status $Method$("
		"::grpc::ServerContext* context, "
		"::grpc::ServerReaderWriter< $Response$, $Request$>* stream);"
		"\n");
  }
}


void PrintHeaderServerMethodAsync(
	google::protobuf::io::Printer *printer,
	const google::protobuf::MethodDescriptor *method,
	std::map<std::string, std::string> *vars) {
  (*vars)["Method"] = method->name();
  (*vars)["Request"] =
	  protorpc_cpp_generator::ClassName(method->input_type(), true);
  (*vars)["Response"] =
	  protorpc_cpp_generator::ClassName(method->output_type(), true);
  printer->Print(*vars, "template <class BaseClass>\n");
  printer->Print(*vars,
				 "class WithAsyncMethod_$Method$ : public BaseClass {\n");
  printer->Print(
	  " private:\n"
	  "  void BaseClassMustBeDerivedFromService(Service *service) {}\n");
  printer->Print(" public:\n");
  printer->Indent();
  printer->Print(*vars,
				 "WithAsyncMethod_$Method$() {\n"
				 "  ::grpc::Service::MarkMethodAsync($Idx$);\n"
				 "}\n");
  printer->Print(*vars,
				 "~WithAsyncMethod_$Method$() GRPC_OVERRIDE {\n"
				 "  BaseClassMustBeDerivedFromService(this);\n"
				 "}\n");
  if (protorpc_generator::NoStreaming(method)) {
	printer->Print(
		*vars,
		"// disable synchronous version of this method\n"
		"::grpc::Status $Method$("
		"::grpc::ServerContext* context, const $Request$* request, "
		"$Response$* response) GRPC_FINAL GRPC_OVERRIDE {\n"
		"  abort();\n"
		"  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, \"\");\n"
		"}\n");
	printer->Print(
		*vars,
		"void Request$Method$("
		"::grpc::ServerContext* context, $Request$* request, "
		"::grpc::ServerAsyncResponseWriter< $Response$>* response, "
		"::grpc::CompletionQueue* new_call_cq, "
		"::grpc::ServerCompletionQueue* notification_cq, void *tag) {\n");
	printer->Print(*vars,
				   "  ::grpc::Service::RequestAsyncUnary($Idx$, context, "
				   "request, response, new_call_cq, notification_cq, tag);\n");
	printer->Print("}\n");
  } else if (protorpc_generator::ClientOnlyStreaming(method)) {
	printer->Print(
		*vars,
		"// disable synchronous version of this method\n"
		"::grpc::Status $Method$("
		"::grpc::ServerContext* context, "
		"::grpc::ServerReader< $Request$>* reader, "
		"$Response$* response) GRPC_FINAL GRPC_OVERRIDE {\n"
		"  abort();\n"
		"  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, \"\");\n"
		"}\n");
	printer->Print(
		*vars,
		"void Request$Method$("
		"::grpc::ServerContext* context, "
		"::grpc::ServerAsyncReader< $Response$, $Request$>* reader, "
		"::grpc::CompletionQueue* new_call_cq, "
		"::grpc::ServerCompletionQueue* notification_cq, void *tag) {\n");
	printer->Print(*vars,
				   "  ::grpc::Service::RequestAsyncClientStreaming($Idx$, "
				   "context, reader, new_call_cq, notification_cq, tag);\n");
	printer->Print("}\n");
  } else if (protorpc_generator::ServerOnlyStreaming(method)) {
	printer->Print(
		*vars,
		"// disable synchronous version of this method\n"
		"::grpc::Status $Method$("
		"::grpc::ServerContext* context, const $Request$* request, "
		"::grpc::ServerWriter< $Response$>* writer) GRPC_FINAL GRPC_OVERRIDE "
		"{\n"
		"  abort();\n"
		"  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, \"\");\n"
		"}\n");
	printer->Print(
		*vars,
		"void Request$Method$("
		"::grpc::ServerContext* context, $Request$* request, "
		"::grpc::ServerAsyncWriter< $Response$>* writer, "
		"::grpc::CompletionQueue* new_call_cq, "
		"::grpc::ServerCompletionQueue* notification_cq, void *tag) {\n");
	printer->Print(
		*vars,
		"  ::grpc::Service::RequestAsyncServerStreaming($Idx$, "
		"context, request, writer, new_call_cq, notification_cq, tag);\n");
	printer->Print("}\n");
  } else if (protorpc_generator::BidiStreaming(method)) {
	printer->Print(
		*vars,
		"// disable synchronous version of this method\n"
		"::grpc::Status $Method$("
		"::grpc::ServerContext* context, "
		"::grpc::ServerReaderWriter< $Response$, $Request$>* stream) "
		"GRPC_FINAL GRPC_OVERRIDE {\n"
		"  abort();\n"
		"  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, \"\");\n"
		"}\n");
	printer->Print(
		*vars,
		"void Request$Method$("
		"::grpc::ServerContext* context, "
		"::grpc::ServerAsyncReaderWriter< $Response$, $Request$>* stream, "
		"::grpc::CompletionQueue* new_call_cq, "
		"::grpc::ServerCompletionQueue* notification_cq, void *tag) {\n");
	printer->Print(*vars,
				   "  ::grpc::Service::RequestAsyncBidiStreaming($Idx$, "
				   "context, stream, new_call_cq, notification_cq, tag);\n");
	printer->Print("}\n");
  }
  printer->Outdent();
  printer->Print(*vars, "};\n");
}



void PrintHeaderServerMethodGeneric(
	google::protobuf::io::Printer *printer,
	const google::protobuf::MethodDescriptor *method,
	std::map<std::string, std::string> *vars) {
  (*vars)["Method"] = method->name();
  (*vars)["Request"] =
	  protorpc_cpp_generator::ClassName(method->input_type(), true);
  (*vars)["Response"] =
	  protorpc_cpp_generator::ClassName(method->output_type(), true);
  printer->Print(*vars, "template <class BaseClass>\n");
  printer->Print(*vars,
				 "class WithGenericMethod_$Method$ : public BaseClass {\n");
  printer->Print(
	  " private:\n"
	  "  void BaseClassMustBeDerivedFromService(Service *service) {}\n");
  printer->Print(" public:\n");
  printer->Indent();
  printer->Print(*vars,
				 "WithGenericMethod_$Method$() {\n"
				 "  ::grpc::Service::MarkMethodGeneric($Idx$);\n"
				 "}\n");
  printer->Print(*vars,
				 "~WithGenericMethod_$Method$() GRPC_OVERRIDE {\n"
				 "  BaseClassMustBeDerivedFromService(this);\n"
				 "}\n");
  if (protorpc_generator::NoStreaming(method)) {
	printer->Print(
		*vars,
		"// disable synchronous version of this method\n"
		"::grpc::Status $Method$("
		"::grpc::ServerContext* context, const $Request$* request, "
		"$Response$* response) GRPC_FINAL GRPC_OVERRIDE {\n"
		"  abort();\n"
		"  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, \"\");\n"
		"}\n");
  } else if (protorpc_generator::ClientOnlyStreaming(method)) {
	printer->Print(
		*vars,
		"// disable synchronous version of this method\n"
		"::grpc::Status $Method$("
		"::grpc::ServerContext* context, "
		"::grpc::ServerReader< $Request$>* reader, "
		"$Response$* response) GRPC_FINAL GRPC_OVERRIDE {\n"
		"  abort();\n"
		"  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, \"\");\n"
		"}\n");
  } else if (protorpc_generator::ServerOnlyStreaming(method)) {
	printer->Print(
		*vars,
		"// disable synchronous version of this method\n"
		"::grpc::Status $Method$("
		"::grpc::ServerContext* context, const $Request$* request, "
		"::grpc::ServerWriter< $Response$>* writer) GRPC_FINAL GRPC_OVERRIDE "
		"{\n"
		"  abort();\n"
		"  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, \"\");\n"
		"}\n");
  } else if (protorpc_generator::BidiStreaming(method)) {
	printer->Print(
		*vars,
		"// disable synchronous version of this method\n"
		"::grpc::Status $Method$("
		"::grpc::ServerContext* context, "
		"::grpc::ServerReaderWriter< $Response$, $Request$>* stream) "
		"GRPC_FINAL GRPC_OVERRIDE {\n"
		"  abort();\n"
		"  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, \"\");\n"
		"}\n");
  }
  printer->Outdent();
  printer->Print(*vars, "};\n");
}



void PrintHeaderService(google::protobuf::io::Printer *printer,
						const google::protobuf::ServiceDescriptor *service,
						std::map<std::string, std::string> *vars) {
  (*vars)["Service"] = service->name();

  printer->Print(*vars,
				 "class $Service$ GRPC_FINAL {\n"
				 " public:\n");
  printer->Indent();

  // Client side
  printer->Print(
	  "class StubInterface {\n"
	  " public:\n");
  printer->Indent();
  printer->Print("virtual ~StubInterface() {}\n");
  for (int i = 0; i < service->method_count(); ++i) {
	PrintHeaderClientMethodInterfaces(printer, service->method(i), vars, true);
  }
  printer->Outdent();
  printer->Print("private:\n");
  printer->Indent();
  for (int i = 0; i < service->method_count(); ++i) {
	PrintHeaderClientMethodInterfaces(printer, service->method(i), vars, false);
  }
  printer->Outdent();
  printer->Print("};\n");
  printer->Print(
	  "class Stub GRPC_FINAL : public StubInterface"
	  " {\n public:\n");
  printer->Indent();
  printer->Print("Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);\n");
  for (int i = 0; i < service->method_count(); ++i) {
	PrintHeaderClientMethod(printer, service->method(i), vars, true);
  }
  printer->Outdent();
  printer->Print("\n private:\n");
  printer->Indent();
  printer->Print("std::shared_ptr< ::grpc::ChannelInterface> channel_;\n");
  for (int i = 0; i < service->method_count(); ++i) {
	PrintHeaderClientMethod(printer, service->method(i), vars, false);
  }
  for (int i = 0; i < service->method_count(); ++i) {
	PrintHeaderClientMethodData(printer, service->method(i), vars);
  }
  printer->Outdent();
  printer->Print("};\n");
  printer->Print(
	  "static std::unique_ptr<Stub> NewStub(const std::shared_ptr< "
	  "::grpc::ChannelInterface>& channel, "
	  "const ::grpc::StubOptions& options = ::grpc::StubOptions());\n");

  printer->Print("\n");

  // Server side - base
  printer->Print(
	  "class Service : public ::grpc::Service {\n"
	  " public:\n");
  printer->Indent();
  printer->Print("Service();\n");
  printer->Print("virtual ~Service();\n");
  for (int i = 0; i < service->method_count(); ++i) {
	PrintHeaderServerMethodSync(printer, service->method(i), vars);
  }
  printer->Outdent();
  printer->Print("};\n");

  // Server side - Asynchronous
  for (int i = 0; i < service->method_count(); ++i) {
	(*vars)["Idx"] = protorpc_generator::as_string(i);
	PrintHeaderServerMethodAsync(printer, service->method(i), vars);
  }

  printer->Print("typedef ");

  for (int i = 0; i < service->method_count(); ++i) {
	(*vars)["method_name"] = service->method(i)->name();
	printer->Print(*vars, "WithAsyncMethod_$method_name$<");
  }
  printer->Print("Service");
  for (int i = 0; i < service->method_count(); ++i) {
	printer->Print(" >");
  }
  printer->Print(" AsyncService;\n");

  // Server side - Generic
  for (int i = 0; i < service->method_count(); ++i) {
	(*vars)["Idx"] = protorpc_generator::as_string(i);
	PrintHeaderServerMethodGeneric(printer, service->method(i), vars);
  }

  printer->Outdent();
  printer->Print("};\n");
}


std::string GetHeaderServices(const google::protobuf::FileDescriptor *file,
							   const Parameters &params) {
  std::string output;
  {
	// Scope the output stream so it closes and finalizes output to the string.
	google::protobuf::io::StringOutputStream output_stream(&output);
	google::protobuf::io::Printer printer(&output_stream, '$');
	std::map<std::string, std::string> vars;
	// Package string is empty or ends with a dot. It is used to fully qualify
	// method names.
	vars["Package"] = file->package();
	if (!file->package().empty()) {
	  vars["Package"].append(".");
	}

	if (!params.services_namespace.empty()) {
	  vars["services_namespace"] = params.services_namespace;
	  printer.Print(vars, "\nnamespace $services_namespace$ {\n\n");
	}

	for (int i = 0; i < file->service_count(); ++i) {
	  PrintHeaderService(&printer, file->service(i), &vars);
	  printer.Print("\n");
	}

	if (!params.services_namespace.empty()) {
	  printer.Print(vars, "}  // namespace $services_namespace$\n\n");
	}
  }
  return output;
}


std::string GetHeaderEpilogue(const google::protobuf::FileDescriptor *file,
							   const Parameters &params) {
  std::string output;
  {
	// Scope the output stream so it closes and finalizes output to the string.
	google::protobuf::io::StringOutputStream output_stream(&output);
	google::protobuf::io::Printer printer(&output_stream, '$');
	std::map<std::string, std::string> vars;

	vars["filename"] = file->name();
	vars["filename_identifier"] = protorpc_generator::FilenameIdentifier(file->name());

	if (!file->package().empty()) {
	  std::vector<std::string> parts =
		  protorpc_generator::tokenize(file->package(), ".");

	  for (auto part = parts.rbegin(); part != parts.rend(); part++) {
		vars["part"] = *part;
		printer.Print(vars, "}  // namespace $part$\n");
	  }
	  printer.Print(vars, "\n");
	}

	printer.Print(vars, "\n");
	printer.Print(vars, "#endif  // GRPC_$filename_identifier$__INCLUDED\n");
  }
  return output;
}

}

