// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef PROTORPC_COMPILER_CPP_GENERATOR_H
#define PROTORPC_COMPILER_CPP_GENERATOR_H

#include "protorpc/compiler/config.h"

#include <google/protobuf/descriptor.h>

#include <string>

namespace protorpc_cpp_generator {

// Contains all the parameters that are parsed from the command line.
struct Parameters {
  // Puts the service into a namespace
  std::string services_namespace;
};

// Return the prologue of the generated header file.
std::string GetHeaderPrologue(const google::protobuf::FileDescriptor *file,
                               const Parameters &params);

// Return the includes needed for generated header file.
std::string GetHeaderIncludes(const google::protobuf::FileDescriptor *file,
                               const Parameters &params);

// Return the includes needed for generated source file.
std::string GetSourceIncludes(const google::protobuf::FileDescriptor *file,
                               const Parameters &params);

// Return the epilogue of the generated header file.
std::string GetHeaderEpilogue(const google::protobuf::FileDescriptor *file,
                               const Parameters &params);

// Return the prologue of the generated source file.
std::string GetSourcePrologue(const google::protobuf::FileDescriptor *file,
                               const Parameters &params);

// Return the services for generated header file.
std::string GetHeaderServices(const google::protobuf::FileDescriptor *file,
                               const Parameters &params);

// Return the services for generated source file.
std::string GetSourceServices(const google::protobuf::FileDescriptor *file,
                               const Parameters &params);

// Return the epilogue of the generated source file.
std::string GetSourceEpilogue(const google::protobuf::FileDescriptor *file,
                               const Parameters &params);

}  // namespace protorpc_cpp_generator

#endif  // PROTORPC_COMPILER_CPP_GENERATOR_H
