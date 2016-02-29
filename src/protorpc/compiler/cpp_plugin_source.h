// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "protorpc/compiler/cpp_generator.h"
#include "protorpc/compiler/cpp_generator_helpers.h"

namespace protorpc_cpp_generator {


std::string GetSourcePrologue(const google::protobuf::FileDescriptor *file,
							   const Parameters &params) {
  std::string output;
  {
	// Scope the output stream so it closes and finalizes output to the string.
	google::protobuf::io::StringOutputStream output_stream(&output);
	google::protobuf::io::Printer printer(&output_stream, '$');
	std::map<std::string, std::string> vars;

	vars["filename"] = file->name();
	vars["filename_base"] = protorpc_generator::StripProto(file->name());

	printer.Print(vars, "// Generated by the gRPC protobuf plugin.\n");
	printer.Print(vars,
				  "// If you make any local change, they will be lost.\n");
	printer.Print(vars, "// source: $filename$\n\n");
	printer.Print(vars, "#include \"$filename_base$.pb.h\"\n");
	printer.Print(vars, "#include \"$filename_base$.grpc.pb.h\"\n");
	printer.Print(vars, "\n");
  }
  return output;
}


std::string GetSourceIncludes(const google::protobuf::FileDescriptor *file,
							   const Parameters &param) {
  std::string output;
  {
	// Scope the output stream so it closes and finalizes output to the string.
	google::protobuf::io::StringOutputStream output_stream(&output);
	google::protobuf::io::Printer printer(&output_stream, '$');
	std::map<std::string, std::string> vars;

	printer.Print(vars, "#include <grpc++/impl/codegen/async_stream.h>\n");
	printer.Print(vars, "#include <grpc++/impl/codegen/async_unary_call.h>\n");
	printer.Print(vars, "#include <grpc++/impl/codegen/channel_interface.h>\n");
	printer.Print(vars, "#include <grpc++/impl/codegen/client_unary_call.h>\n");
	printer.Print(vars,
				  "#include <grpc++/impl/codegen/method_handler_impl.h>\n");
	printer.Print(vars,
				  "#include <grpc++/impl/codegen/rpc_service_method.h>\n");
	printer.Print(vars, "#include <grpc++/impl/codegen/service_type.h>\n");
	printer.Print(vars, "#include <grpc++/impl/codegen/sync_stream.h>\n");

	if (!file->package().empty()) {
	  std::vector<std::string> parts =
		  protorpc_generator::tokenize(file->package(), ".");

	  for (auto part = parts.begin(); part != parts.end(); part++) {
		vars["part"] = *part;
		printer.Print(vars, "namespace $part$ {\n");
	  }
	}

	printer.Print(vars, "\n");
  }
  return output;
}


void PrintSourceClientMethod(google::protobuf::io::Printer *printer,
							 const google::protobuf::MethodDescriptor *method,
							 std::map<std::string, std::string> *vars) {
  (*vars)["Method"] = method->name();
  (*vars)["Request"] =
	  protorpc_cpp_generator::ClassName(method->input_type(), true);
  (*vars)["Response"] =
	  protorpc_cpp_generator::ClassName(method->output_type(), true);
  if (protorpc_generator::NoStreaming(method)) {
	printer->Print(*vars,
				   "::grpc::Status $ns$$Service$::Stub::$Method$("
				   "::grpc::ClientContext* context, "
				   "const $Request$& request, $Response$* response) {\n");
	printer->Print(*vars,
				   "  return ::grpc::BlockingUnaryCall(channel_.get(), "
				   "rpcmethod_$Method$_, "
				   "context, request, response);\n"
				   "}\n\n");
	printer->Print(
		*vars,
		"::grpc::ClientAsyncResponseReader< $Response$>* "
		"$ns$$Service$::Stub::Async$Method$Raw(::grpc::ClientContext* context, "
		"const $Request$& request, "
		"::grpc::CompletionQueue* cq) {\n");
	printer->Print(*vars,
				   "  return new "
				   "::grpc::ClientAsyncResponseReader< $Response$>("
				   "channel_.get(), cq, "
				   "rpcmethod_$Method$_, "
				   "context, request);\n"
				   "}\n\n");
  } else if (protorpc_generator::ClientOnlyStreaming(method)) {
	printer->Print(*vars,
				   "::grpc::ClientWriter< $Request$>* "
				   "$ns$$Service$::Stub::$Method$Raw("
				   "::grpc::ClientContext* context, $Response$* response) {\n");
	printer->Print(*vars,
				   "  return new ::grpc::ClientWriter< $Request$>("
				   "channel_.get(), "
				   "rpcmethod_$Method$_, "
				   "context, response);\n"
				   "}\n\n");
	printer->Print(*vars,
				   "::grpc::ClientAsyncWriter< $Request$>* "
				   "$ns$$Service$::Stub::Async$Method$Raw("
				   "::grpc::ClientContext* context, $Response$* response, "
				   "::grpc::CompletionQueue* cq, void* tag) {\n");
	printer->Print(*vars,
				   "  return new ::grpc::ClientAsyncWriter< $Request$>("
				   "channel_.get(), cq, "
				   "rpcmethod_$Method$_, "
				   "context, response, tag);\n"
				   "}\n\n");
  } else if (protorpc_generator::ServerOnlyStreaming(method)) {
	printer->Print(
		*vars,
		"::grpc::ClientReader< $Response$>* "
		"$ns$$Service$::Stub::$Method$Raw("
		"::grpc::ClientContext* context, const $Request$& request) {\n");
	printer->Print(*vars,
				   "  return new ::grpc::ClientReader< $Response$>("
				   "channel_.get(), "
				   "rpcmethod_$Method$_, "
				   "context, request);\n"
				   "}\n\n");
	printer->Print(*vars,
				   "::grpc::ClientAsyncReader< $Response$>* "
				   "$ns$$Service$::Stub::Async$Method$Raw("
				   "::grpc::ClientContext* context, const $Request$& request, "
				   "::grpc::CompletionQueue* cq, void* tag) {\n");
	printer->Print(*vars,
				   "  return new ::grpc::ClientAsyncReader< $Response$>("
				   "channel_.get(), cq, "
				   "rpcmethod_$Method$_, "
				   "context, request, tag);\n"
				   "}\n\n");
  } else if (protorpc_generator::BidiStreaming(method)) {
	printer->Print(
		*vars,
		"::grpc::ClientReaderWriter< $Request$, $Response$>* "
		"$ns$$Service$::Stub::$Method$Raw(::grpc::ClientContext* context) {\n");
	printer->Print(*vars,
				   "  return new ::grpc::ClientReaderWriter< "
				   "$Request$, $Response$>("
				   "channel_.get(), "
				   "rpcmethod_$Method$_, "
				   "context);\n"
				   "}\n\n");
	printer->Print(
		*vars,
		"::grpc::ClientAsyncReaderWriter< $Request$, $Response$>* "
		"$ns$$Service$::Stub::Async$Method$Raw(::grpc::ClientContext* context, "
		"::grpc::CompletionQueue* cq, void* tag) {\n");
	printer->Print(*vars,
				   "  return new "
				   "::grpc::ClientAsyncReaderWriter< $Request$, $Response$>("
				   "channel_.get(), cq, "
				   "rpcmethod_$Method$_, "
				   "context, tag);\n"
				   "}\n\n");
  }
}




void PrintSourceServerMethod(google::protobuf::io::Printer *printer,
							 const google::protobuf::MethodDescriptor *method,
							 std::map<std::string, std::string> *vars) {
  (*vars)["Method"] = method->name();
  (*vars)["Request"] =
	  protorpc_cpp_generator::ClassName(method->input_type(), true);
  (*vars)["Response"] =
	  protorpc_cpp_generator::ClassName(method->output_type(), true);
  if (protorpc_generator::NoStreaming(method)) {
	printer->Print(*vars,
				   "::grpc::Status $ns$$Service$::Service::$Method$("
				   "::grpc::ServerContext* context, "
				   "const $Request$* request, $Response$* response) {\n");
	printer->Print("  (void) context;\n");
	printer->Print("  (void) request;\n");
	printer->Print("  (void) response;\n");
	printer->Print(
		"  return ::grpc::Status("
		"::grpc::StatusCode::UNIMPLEMENTED, \"\");\n");
	printer->Print("}\n\n");
  } else if (protorpc_generator::ClientOnlyStreaming(method)) {
	printer->Print(*vars,
				   "::grpc::Status $ns$$Service$::Service::$Method$("
				   "::grpc::ServerContext* context, "
				   "::grpc::ServerReader< $Request$>* reader, "
				   "$Response$* response) {\n");
	printer->Print("  (void) context;\n");
	printer->Print("  (void) reader;\n");
	printer->Print("  (void) response;\n");
	printer->Print(
		"  return ::grpc::Status("
		"::grpc::StatusCode::UNIMPLEMENTED, \"\");\n");
	printer->Print("}\n\n");
  } else if (protorpc_generator::ServerOnlyStreaming(method)) {
	printer->Print(*vars,
				   "::grpc::Status $ns$$Service$::Service::$Method$("
				   "::grpc::ServerContext* context, "
				   "const $Request$* request, "
				   "::grpc::ServerWriter< $Response$>* writer) {\n");
	printer->Print("  (void) context;\n");
	printer->Print("  (void) request;\n");
	printer->Print("  (void) writer;\n");
	printer->Print(
		"  return ::grpc::Status("
		"::grpc::StatusCode::UNIMPLEMENTED, \"\");\n");
	printer->Print("}\n\n");
  } else if (protorpc_generator::BidiStreaming(method)) {
	printer->Print(*vars,
				   "::grpc::Status $ns$$Service$::Service::$Method$("
				   "::grpc::ServerContext* context, "
				   "::grpc::ServerReaderWriter< $Response$, $Request$>* "
				   "stream) {\n");
	printer->Print("  (void) context;\n");
	printer->Print("  (void) stream;\n");
	printer->Print(
		"  return ::grpc::Status("
		"::grpc::StatusCode::UNIMPLEMENTED, \"\");\n");
	printer->Print("}\n\n");
  }
}


void PrintSourceService(google::protobuf::io::Printer *printer,
						const google::protobuf::ServiceDescriptor *service,
						std::map<std::string, std::string> *vars) {
  (*vars)["Service"] = service->name();

  printer->Print(*vars,
				 "static const char* $prefix$$Service$_method_names[] = {\n");
  for (int i = 0; i < service->method_count(); ++i) {
	(*vars)["Method"] = service->method(i)->name();
	printer->Print(*vars, "  \"/$Package$$Service$/$Method$\",\n");
  }
  printer->Print(*vars, "};\n\n");

  printer->Print(*vars,
				 "std::unique_ptr< $ns$$Service$::Stub> $ns$$Service$::NewStub("
				 "const std::shared_ptr< ::grpc::ChannelInterface>& channel, "
				 "const ::grpc::StubOptions& options) {\n"
				 "  std::unique_ptr< $ns$$Service$::Stub> stub(new "
				 "$ns$$Service$::Stub(channel));\n"
				 "  return stub;\n"
				 "}\n\n");
  printer->Print(*vars,
				 "$ns$$Service$::Stub::Stub(const std::shared_ptr< "
				 "::grpc::ChannelInterface>& channel)\n");
  printer->Indent();
  printer->Print(": channel_(channel)");
  for (int i = 0; i < service->method_count(); ++i) {
	const google::protobuf::MethodDescriptor *method = service->method(i);
	(*vars)["Method"] = method->name();
	(*vars)["Idx"] = protorpc_generator::as_string(i);
	if (protorpc_generator::NoStreaming(method)) {
	  (*vars)["StreamingType"] = "NORMAL_RPC";
	} else if (protorpc_generator::ClientOnlyStreaming(method)) {
	  (*vars)["StreamingType"] = "CLIENT_STREAMING";
	} else if (protorpc_generator::ServerOnlyStreaming(method)) {
	  (*vars)["StreamingType"] = "SERVER_STREAMING";
	} else {
	  (*vars)["StreamingType"] = "BIDI_STREAMING";
	}
	printer->Print(*vars,
				   ", rpcmethod_$Method$_("
				   "$prefix$$Service$_method_names[$Idx$], "
				   "::grpc::RpcMethod::$StreamingType$, "
				   "channel"
				   ")\n");
  }
  printer->Print("{}\n\n");
  printer->Outdent();

  for (int i = 0; i < service->method_count(); ++i) {
	(*vars)["Idx"] = protorpc_generator::as_string(i);
	PrintSourceClientMethod(printer, service->method(i), vars);
  }

  printer->Print(*vars, "$ns$$Service$::Service::Service() {\n");
  printer->Indent();
  printer->Print(*vars, "(void)$prefix$$Service$_method_names;\n");
  for (int i = 0; i < service->method_count(); ++i) {
	const google::protobuf::MethodDescriptor *method = service->method(i);
	(*vars)["Idx"] = protorpc_generator::as_string(i);
	(*vars)["Method"] = method->name();
	(*vars)["Request"] =
		protorpc_cpp_generator::ClassName(method->input_type(), true);
	(*vars)["Response"] =
		protorpc_cpp_generator::ClassName(method->output_type(), true);
	if (protorpc_generator::NoStreaming(method)) {
	  printer->Print(
		  *vars,
		  "AddMethod(new ::grpc::RpcServiceMethod(\n"
		  "	$prefix$$Service$_method_names[$Idx$],\n"
		  "	::grpc::RpcMethod::NORMAL_RPC,\n"
		  "	new ::grpc::RpcMethodHandler< $ns$$Service$::Service, "
		  "$Request$, "
		  "$Response$>(\n"
		  "		std::mem_fn(&$ns$$Service$::Service::$Method$), this)));\n");
	} else if (protorpc_generator::ClientOnlyStreaming(method)) {
	  printer->Print(
		  *vars,
		  "AddMethod(new ::grpc::RpcServiceMethod(\n"
		  "	$prefix$$Service$_method_names[$Idx$],\n"
		  "	::grpc::RpcMethod::CLIENT_STREAMING,\n"
		  "	new ::grpc::ClientStreamingHandler< "
		  "$ns$$Service$::Service, $Request$, $Response$>(\n"
		  "		std::mem_fn(&$ns$$Service$::Service::$Method$), this)));\n");
	} else if (protorpc_generator::ServerOnlyStreaming(method)) {
	  printer->Print(
		  *vars,
		  "AddMethod(new ::grpc::RpcServiceMethod(\n"
		  "	$prefix$$Service$_method_names[$Idx$],\n"
		  "	::grpc::RpcMethod::SERVER_STREAMING,\n"
		  "	new ::grpc::ServerStreamingHandler< "
		  "$ns$$Service$::Service, $Request$, $Response$>(\n"
		  "		std::mem_fn(&$ns$$Service$::Service::$Method$), this)));\n");
	} else if (protorpc_generator::BidiStreaming(method)) {
	  printer->Print(
		  *vars,
		  "AddMethod(new ::grpc::RpcServiceMethod(\n"
		  "	$prefix$$Service$_method_names[$Idx$],\n"
		  "	::grpc::RpcMethod::BIDI_STREAMING,\n"
		  "	new ::grpc::BidiStreamingHandler< "
		  "$ns$$Service$::Service, $Request$, $Response$>(\n"
		  "		std::mem_fn(&$ns$$Service$::Service::$Method$), this)));\n");
	}
  }
  printer->Outdent();
  printer->Print(*vars, "}\n\n");
  printer->Print(*vars,
				 "$ns$$Service$::Service::~Service() {\n"
				 "}\n\n");
  for (int i = 0; i < service->method_count(); ++i) {
	(*vars)["Idx"] = protorpc_generator::as_string(i);
	PrintSourceServerMethod(printer, service->method(i), vars);
  }
}


std::string GetSourceServices(const google::protobuf::FileDescriptor *file,
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
	  vars["ns"] = params.services_namespace + "::";
	  vars["prefix"] = params.services_namespace;
	} else {
	  vars["ns"] = "";
	  vars["prefix"] = "";
	}

	for (int i = 0; i < file->service_count(); ++i) {
	  PrintSourceService(&printer, file->service(i), &vars);
	  printer.Print("\n");
	}
  }
  return output;
}


std::string GetSourceEpilogue(
	const google::protobuf::FileDescriptor *file,
	const Parameters &params
) {
	std::string temp;

	if (!file->package().empty()) {
		std::vector<std::string> parts =
			protorpc_generator::tokenize(file->package(), ".");

		for (auto part = parts.begin(); part != parts.end(); part++) {
			temp.append("}  // namespace ");
			temp.append(*part);
			temp.append("\n");
		}
		temp.append("\n");
	}

	return temp;
}

}
