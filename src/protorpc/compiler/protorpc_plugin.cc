// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// Generates cpp protorpc service interface out of Protobuf IDL.
//

#include "protorpc/compiler/protorpc_plugin.h"
#include "protorpc/compiler/protorpc_plugin_helpers.h"
#include "protorpc/compiler/protorpc_generator.h"

struct ProtorpcGenerator: public google::protobuf::compiler::CodeGenerator {
	ProtorpcGenerator() {}
	virtual ~ProtorpcGenerator() {}

	virtual bool Generate(
		const google::protobuf::FileDescriptor *file,
		const std::string &parameter,
		google::protobuf::compiler::GeneratorContext *context,
		std::string *error
	) const {
		if (file->options().cc_generic_services()) {
			*error = (
				"cpp protorpc compiler plugin does not work with generic "
				"services. To generate cpp protorpc APIs, please set \""
				"cc_generic_service = false\"."
			);
			return false;
		}

		protorpc_generator::Parameters generator_parameters;

		if (!parameter.empty()) {
			auto parameters_list = protorpc_generator::tokenize(parameter, ",");
			for (
				auto parameter_string = parameters_list.begin();
				parameter_string != parameters_list.end();
				parameter_string++
			) {
				auto param = protorpc_generator::tokenize(*parameter_string, "=");
				if(param.size() >= 2 && param[0] == "services_namespace") {
					generator_parameters.services_namespace = param[1];
				} else {
					*error = std::string("Unknown parameter: ") + *parameter_string;
					return false;
				}
			}
		}

		std::string file_name = protorpc_generator::StripProto(file->name());

		std::unique_ptr<google::protobuf::io::ZeroCopyOutputStream> header_output(
			context->Open(file_name + ".protorpc.h")
		);
		std::unique_ptr<google::protobuf::io::ZeroCopyOutputStream> source_output(
			context->Open(file_name + ".protorpc.cc")
		);

		std::string header_code = (
			protorpc_generator::GetHeaderPrologue(file, generator_parameters) +
			protorpc_generator::GetHeaderIncludes(file, generator_parameters) +
			protorpc_generator::GetHeaderServices(file, generator_parameters) +
			protorpc_generator::GetHeaderEpilogue(file, generator_parameters)
		);
		std::string source_code = (
			protorpc_generator::GetSourcePrologue(file, generator_parameters) +
			protorpc_generator::GetSourceIncludes(file, generator_parameters) +
			protorpc_generator::GetSourceServices(file, generator_parameters) +
			protorpc_generator::GetSourceEpilogue(file, generator_parameters)
		);

		google::protobuf::io::CodedOutputStream header_coded_out(
			header_output.get()
		);
		google::protobuf::io::CodedOutputStream source_coded_out(
			source_output.get()
		);

		header_coded_out.WriteRaw(header_code.data(), header_code.size());
		source_coded_out.WriteRaw(source_code.data(), source_code.size());
		return true;
	}
};

int protorpc_plugin_Main(int argc, char* argv[]) {
	ProtorpcGenerator generator;
	return google::protobuf::compiler::PluginMain(argc, argv, &generator);
}
