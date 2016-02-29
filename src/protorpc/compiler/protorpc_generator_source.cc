// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "protorpc/compiler/protorpc_generator.h"
#include "protorpc/compiler/protorpc_plugin_helpers.h"

namespace protorpc_generator {

static void PrintSourceALLServiceHelper(
	google::protobuf::io::Printer *printer,
	const google::protobuf::FileDescriptor *file,
	std::map<std::string, std::string> *vars
);
static void PrintSourceServiceImpl(
	google::protobuf::io::Printer *printer,
	const google::protobuf::ServiceDescriptor *service,
	std::map<std::string, std::string> *vars
);
static void PrintSourceServiceStubImpl(
	google::protobuf::io::Printer *printer,
	const google::protobuf::ServiceDescriptor *service,
	std::map<std::string, std::string> *vars
);

std::string GetSourcePrologue(const google::protobuf::FileDescriptor *file, const Parameters &params) {
	std::string output;
	{
		// Scope the output stream so it closes and finalizes output to the string.
		google::protobuf::io::StringOutputStream output_stream(&output);
		google::protobuf::io::Printer printer(&output_stream, '$');
		std::map<std::string, std::string> vars;

		vars["filename"] = file->name();
		vars["filename_base"] = protorpc_generator::StripProto(file->name());

		printer.Print(vars, "// Generated by the protorpc compiler.  DO NOT EDIT!!!\n");
		printer.Print(vars, "// source: $filename$\n");
		printer.Print(vars, "\n");
		printer.Print(vars, "#include \"$filename_base$.protorpc.h\"\n");
		printer.Print(vars, "\n");
	}
	return output;
}
std::string GetSourceIncludes(const google::protobuf::FileDescriptor *file, const Parameters &param) {
	std::string output;
	{
		// Scope the output stream so it closes and finalizes output to the string.
		google::protobuf::io::StringOutputStream output_stream(&output);
		google::protobuf::io::Printer printer(&output_stream, '$');
		std::map<std::string, std::string> vars;

		printer.Print(vars, "#include <google/protobuf/stubs/common.h>\n");
		printer.Print(vars, "#include <google/protobuf/stubs/once.h>\n");
		printer.Print(vars, "\n");

		if (!file->package().empty()) {
			auto parts = protorpc_generator::tokenize(file->package(), ".");
			for (auto part = parts.begin(); part != parts.end(); part++) {
				vars["part"] = *part;
				printer.Print(vars, "namespace $part$ {\n");
			}
		}
		printer.Print(vars, "\n");
	}
	return output;
}
std::string GetSourceEpilogue(const google::protobuf::FileDescriptor *file, const Parameters &params) {
	std::string temp;
	if (!file->package().empty()) {
		auto parts = protorpc_generator::tokenize(file->package(), ".");
		for (auto part = parts.begin(); part != parts.end(); part++) {
			temp.append("}  // namespace ");
			temp.append(*part);
			temp.append("\n");
		}
		temp.append("\n");
	}
	return temp;
}

std::string GetSourceServices(const google::protobuf::FileDescriptor *file, const Parameters &params) {
	std::string output;
	{
		// Scope the output stream so it closes and finalizes output to the string.
		google::protobuf::io::StringOutputStream output_stream(&output);
		google::protobuf::io::Printer printer(&output_stream, '$');
		std::map<std::string, std::string> vars;

		vars["filename"] = file->name();
		vars["filename_identifier"] = protorpc_generator::FilenameIdentifier(file->name());
		vars["filename_base"] = protorpc_generator::StripProto(file->name());

		PrintSourceALLServiceHelper(&printer, file, &vars);
		for(int i = 0; i < file->service_count(); ++i) {
			PrintSourceServiceImpl(&printer, file->service(i), &vars);
			PrintSourceServiceStubImpl(&printer, file->service(i), &vars);
		}
	}
	return output;
}

static void PrintSourceALLServiceHelper(
	google::protobuf::io::Printer *printer,
	const google::protobuf::FileDescriptor *file,
	std::map<std::string, std::string> *vars
) {
	(*vars)["__"] = "\t"; // use tab for indent

	printer->Print(*vars, "namespace {\n");
	printer->Print(*vars, "\n");

	for(int i = 0; i < file->service_count(); ++i) {
		(*vars)["service_name"] = file->service(i)->name();
		printer->Print(*vars, "const ::google::protobuf::ServiceDescriptor* $service_name$_descriptor_ = NULL;\n");
	}
	printer->Print(*vars, "\n");
	printer->Print(*vars, "GOOGLE_PROTOBUF_DECLARE_ONCE(protorpc_AssignDescriptors_once_);\n");
	printer->Print(*vars, "\n");
	printer->Print(*vars, "void protorpc_AssignDesc_$filename_identifier$() {\n");
	printer->Print(*vars, "$__$protobuf_AddDesc_$filename_identifier$();\n");
	printer->Print(*vars, "$__$auto file = ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(\"$filename$\");\n");
	printer->Print(*vars, "$__$GOOGLE_CHECK(file != NULL);\n");
	for(int i = 0; i < file->service_count(); ++i) {
		(*vars)["service_name"] = file->service(i)->name();
		(*vars)["service_index"] = protorpc_generator::as_string(file->service(i)->index());
		printer->Print(*vars, "$__$$service_name$_descriptor_ = file->service($service_index$);\n");
	}
	printer->Print(*vars, "}\n");
	printer->Print(*vars, "inline void protorpc_AssignDescriptorsOnce() {\n");
	printer->Print(*vars, "$__$::google::protobuf::GoogleOnceInit(\n");
	printer->Print(*vars, "$__$$__$&protorpc_AssignDescriptors_once_,\n");
	printer->Print(*vars, "$__$$__$&protorpc_AssignDesc_$filename_identifier$\n");
	printer->Print(*vars, "$__$);\n");
	printer->Print(*vars, "}\n");
	printer->Print(*vars, "\n");
	printer->Print(*vars, "} // namespace\n");
	printer->Print(*vars, "\n");
}

static void PrintSourceServiceImpl(
	google::protobuf::io::Printer *printer,
	const google::protobuf::ServiceDescriptor *service,
	std::map<std::string, std::string> *vars
) {
	(*vars)["service_name"] = service->name();
	(*vars)["service_full_name"] = service->full_name();
	(*vars)["__"] = "\t"; // use tab for indent

	printer->Print(*vars, "$service_name$::~$service_name$() {}\n");
	printer->Print(*vars, "\n");
	printer->Print(*vars, "const ::google::protobuf::ServiceDescriptor* $service_name$::descriptor() {\n");
	printer->Print(*vars, "$__$protorpc_AssignDescriptorsOnce();\n");
	printer->Print(*vars, "$__$return $service_name$_descriptor_;\n");
	printer->Print(*vars, "}\n");
	printer->Print(*vars, "\n");
	printer->Print(*vars, "const ::google::protobuf::ServiceDescriptor* $service_name$::GetDescriptor() {\n");
	printer->Print(*vars, "$__$protorpc_AssignDescriptorsOnce();\n");
	printer->Print(*vars, "$__$return $service_name$_descriptor_;\n");
	printer->Print(*vars, "}\n");
	printer->Print(*vars, "\n");

	for(int i = 0; i < service->method_count(); i++) {
		(*vars)["method_name"]        = service->method(i)->name();
		(*vars)["method_input_type"]  = protorpc_generator::ClassName(service->method(i)->input_type(), true);
		(*vars)["method_output_type"] = protorpc_generator::ClassName(service->method(i)->output_type(), true);

		printer->Print(*vars, "const ::protorpc::Error $service_name$::$method_name$(\n");
		printer->Print(*vars, "$__$const $method_input_type$* request,\n");
		printer->Print(*vars, "$__$$method_output_type$* reponse\n");
		printer->Print(*vars, ") {\n");
		printer->Print(*vars, "$__$return ::protorpc::Error(\"Method $service_name$::$method_name$() not implemented.\");\n");
		printer->Print(*vars, "}\n");
		printer->Print(*vars, "\n");
	}

	printer->Print(*vars, "const ::protorpc::Error $service_name$::CallMethod(\n");
	printer->Print(*vars, "$__$const ::google::protobuf::MethodDescriptor* method,\n");
	printer->Print(*vars, "$__$const ::google::protobuf::Message* request,\n");
	printer->Print(*vars, "$__$::google::protobuf::Message* response\n");
	printer->Print(*vars, ") {\n");
	printer->Print(*vars, "$__$GOOGLE_DCHECK_EQ(method->service(), $service_name$_descriptor_);\n");
	printer->Print(*vars, "$__$switch(method->index()) {\n");
	for(int i = 0; i < service->method_count(); i++) {
		(*vars)["method_name"]        = service->method(i)->name();
		(*vars)["method_input_type"]  = protorpc_generator::ClassName(service->method(i)->input_type(), true);
		(*vars)["method_output_type"] = protorpc_generator::ClassName(service->method(i)->output_type(), true);
		(*vars)["method_index"] = protorpc_generator::as_string(service->method(i)->index());

		printer->Print(*vars, "$__$case $method_index$:\n");
		printer->Print(*vars, "$__$$__$return $method_name$(\n");
		printer->Print(*vars, "$__$$__$$__$::google::protobuf::down_cast<const $method_input_type$*>(request),\n");
		printer->Print(*vars, "$__$$__$$__$::google::protobuf::down_cast<$method_output_type$*>(response)\n");
		printer->Print(*vars, "$__$$__$);\n");
	}
	printer->Print(*vars, "$__$default:\n");
	printer->Print(*vars, "$__$$__$return ::protorpc::Error(\"Bad method index; this should never happen.\");\n");
	printer->Print(*vars, "$__$}\n");
	printer->Print(*vars, "}\n");
	printer->Print(*vars, "\n");

	printer->Print(*vars, "const ::google::protobuf::Message& $service_name$::GetRequestPrototype(\n");
	printer->Print(*vars, "$__$const ::google::protobuf::MethodDescriptor* method\n");
	printer->Print(*vars, ") const {\n");
	printer->Print(*vars, "$__$GOOGLE_DCHECK_EQ(method->service(), descriptor());\n");
	printer->Print(*vars, "$__$switch(method->index()) {\n");
	for(int i = 0; i < service->method_count(); i++) {
		(*vars)["method_name"]        = service->method(i)->name();
		(*vars)["method_input_type"]  = protorpc_generator::ClassName(service->method(i)->input_type(), true);
		(*vars)["method_output_type"] = protorpc_generator::ClassName(service->method(i)->output_type(), true);
		(*vars)["method_index"]       = protorpc_generator::as_string(service->method(i)->index());

		printer->Print(*vars, "$__$case $method_index$:\n");
		printer->Print(*vars, "$__$$__$return $method_output_type$::default_instance();\n");
	}
	printer->Print(*vars, "$__$default:\n");
	printer->Print(*vars, "$__$$__$GOOGLE_LOG(FATAL) << \"Bad method index; this should never happen.\";\n");
	printer->Print(*vars, "$__$$__$return *reinterpret_cast< ::google::protobuf::Message*>(NULL);\n");
	printer->Print(*vars, "$__$}\n");
	printer->Print(*vars, "}\n");
	printer->Print(*vars, "\n");

	printer->Print(*vars, "const ::google::protobuf::Message& $service_name$::GetResponsePrototype(\n");
	printer->Print(*vars, "$__$const ::google::protobuf::MethodDescriptor* method\n");
	printer->Print(*vars, ") const {\n");
	printer->Print(*vars, "$__$GOOGLE_DCHECK_EQ(method->service(), descriptor());\n");
	printer->Print(*vars, "$__$switch(method->index()) {\n");
	for(int i = 0; i < service->method_count(); i++) {
		(*vars)["method_name"]        = service->method(i)->name();
		(*vars)["method_input_type"]  = protorpc_generator::ClassName(service->method(i)->input_type(), true);
		(*vars)["method_output_type"] = protorpc_generator::ClassName(service->method(i)->output_type(), true);
		(*vars)["method_index"]       = protorpc_generator::as_string(service->method(i)->index());

		printer->Print(*vars, "$__$case $method_index$:\n");
		printer->Print(*vars, "$__$$__$return $method_input_type$::default_instance();\n");
	}
	printer->Print(*vars, "$__$default:\n");
	printer->Print(*vars, "$__$$__$GOOGLE_LOG(FATAL) << \"Bad method index; this should never happen.\";\n");
	printer->Print(*vars, "$__$$__$return *reinterpret_cast< ::google::protobuf::Message*>(NULL);\n");
	printer->Print(*vars, "$__$}\n");
	printer->Print(*vars, "}\n");
	printer->Print(*vars, "\n");
}

static void PrintSourceServiceStubImpl(
	google::protobuf::io::Printer *printer,
	const google::protobuf::ServiceDescriptor *service,
	std::map<std::string, std::string> *vars
) {
	(*vars)["service_name"] = service->name();
	(*vars)["service_full_name"] = service->full_name();
	(*vars)["__"] = "\t"; // use tab for indent

	printer->Print(*vars, "$service_name$_Stub::$service_name$_Stub(::protorpc::Caller* client)\n");
	printer->Print(*vars, "$__$: client_(client), owns_client_(false) {}\n");
	printer->Print(*vars, "$service_name$_Stub::$service_name$_Stub(::protorpc::Caller* client, bool client_ownership)\n");
	printer->Print(*vars, "$__$: client_(client), owns_client_(client_ownership) {}\n");
	printer->Print(*vars, "$service_name$_Stub::~$service_name$_Stub() {\n");
	printer->Print(*vars, "$__$if (owns_client_) delete client_;\n");
	printer->Print(*vars, "}\n");
	printer->Print(*vars, "\n");

	for(int i = 0; i < service->method_count(); i++) {
		(*vars)["method_name"]        = service->method(i)->name();
		(*vars)["method_input_type"]  = protorpc_generator::ClassName(service->method(i)->input_type(), true);
		(*vars)["method_output_type"] = protorpc_generator::ClassName(service->method(i)->output_type(), true);

		printer->Print(*vars, "const ::protorpc::Error $service_name$_Stub::$method_name$(\n");
		printer->Print(*vars, "$__$const $method_input_type$* request,\n");
		printer->Print(*vars, "$__$$method_output_type$* response\n");
		printer->Print(*vars, ") {\n");
		printer->Print(*vars, "$__$return client_->CallMethod(descriptor()->method(0), request, response);\n");
		printer->Print(*vars, "}\n");
		printer->Print(*vars, "\n");
	}
}

} // namespace protorpc_generator
