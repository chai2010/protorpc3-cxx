// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// Generates cpp gRPC service interface out of Protobuf IDL.
//

#include <memory>

#include "protorpc/compiler/config.h"

#include "protorpc/compiler/cpp_generator.h"
#include "protorpc/compiler/cpp_generator_helpers.h"

#if 0

class CppProtorpcGenerator : public google::protobuf::compiler::CodeGenerator {
 public:
  CppProtorpcGenerator() {}
  virtual ~CppProtorpcGenerator() {}

  virtual bool Generate(const google::protobuf::FileDescriptor *file,
                        const google::string &parameter,
                        google::protobuf::compiler::GeneratorContext *context,
                        std::string *error) const {
    if (file->options().cc_generic_services()) {
      *error =
          "cpp protorpc compiler plugin does not work with generic "
          "services. To generate cpp protorpc APIs, please set \""
          "cc_generic_service = false\".";
      return false;
    }

    protorpc_cpp_generator::Parameters generator_parameters;

    if (!parameter.empty()) {
      std::vector<grpc::string> parameters_list =
        protorpc_generator::tokenize(parameter, ",");
      for (auto parameter_string = parameters_list.begin();
           parameter_string != parameters_list.end();
           parameter_string++) {
        std::vector<grpc::string> param =
          protorpc_generator::tokenize(*parameter_string, "=");
        if (param[0] == "services_namespace") {
          generator_parameters.services_namespace = param[1];
        } else {
          *error = grpc::string("Unknown parameter: ") + *parameter_string;
          return false;
        }
      }
    }

    std::string file_name = grpc_generator::StripProto(file->name());

    std::string header_code =
        grpc_cpp_generator::GetHeaderPrologue(file, generator_parameters) +
        grpc_cpp_generator::GetHeaderIncludes(file, generator_parameters) +
        grpc_cpp_generator::GetHeaderServices(file, generator_parameters) +
        grpc_cpp_generator::GetHeaderEpilogue(file, generator_parameters);
    std::unique_ptr<grpc::protobuf::io::ZeroCopyOutputStream> header_output(
        context->Open(file_name + ".grpc.pb.h"));
    google::protobuf::io::CodedOutputStream header_coded_out(
        header_output.get());
    header_coded_out.WriteRaw(header_code.data(), header_code.size());

    std::string source_code =
        grpc_cpp_generator::GetSourcePrologue(file, generator_parameters) +
        grpc_cpp_generator::GetSourceIncludes(file, generator_parameters) +
        grpc_cpp_generator::GetSourceServices(file, generator_parameters) +
        grpc_cpp_generator::GetSourceEpilogue(file, generator_parameters);
    std::unique_ptr<grpc::protobuf::io::ZeroCopyOutputStream> source_output(
        context->Open(file_name + ".grpc.pb.cc"));
    google::protobuf::io::CodedOutputStream source_coded_out(
        source_output.get());
    source_coded_out.WriteRaw(source_code.data(), source_code.size());

    return true;
  }

 private:
  // Insert the given code into the given file at the given insertion point.
  void Insert(google::protobuf::compiler::GeneratorContext *context,
              const grpc::string &filename, const grpc::string &insertion_point,
              const grpc::string &code) const {
    std::unique_ptr<grpc::protobuf::io::ZeroCopyOutputStream> output(
        context->OpenForInsert(filename, insertion_point));
    google::protobuf::io::CodedOutputStream coded_out(output.get());
    coded_out.WriteRaw(code.data(), code.size());
  }
};

int main(int argc, char *argv[]) {
  CppProtorpcGenerator generator;
  return google::protobuf::compiler::PluginMain(argc, argv, &generator);
}

#endif

int main(int argc, char *argv[]) {
    return 0;
}
