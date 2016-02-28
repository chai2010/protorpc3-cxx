// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef PROTORPC_COMPILER_CPP_GENERATOR_HELPERS_H
#define PROTORPC_COMPILER_CPP_GENERATOR_HELPERS_H

#include "protorpc/compiler/config.h"
#include "protorpc/compiler/generator_helpers.h"

#include <map>

namespace protorpc_cpp_generator {

inline grpc::string DotsToColons(const grpc::string &name) {
  return grpc_generator::StringReplace(name, ".", "::");
}

inline grpc::string DotsToUnderscores(const grpc::string &name) {
  return grpc_generator::StringReplace(name, ".", "_");
}

inline grpc::string ClassName(const grpc::protobuf::Descriptor *descriptor,
                              bool qualified) {
  // Find "outer", the descriptor of the top-level message in which
  // "descriptor" is embedded.
  const grpc::protobuf::Descriptor *outer = descriptor;
  while (outer->containing_type() != NULL) outer = outer->containing_type();

  const grpc::string &outer_name = outer->full_name();
  grpc::string inner_name = descriptor->full_name().substr(outer_name.size());

  if (qualified) {
    return "::" + DotsToColons(outer_name) + DotsToUnderscores(inner_name);
  } else {
    return outer->name() + DotsToUnderscores(inner_name);
  }
}

}  // namespace protorpc_cpp_generator

#endif  // PROTORPC_COMPILER_CPP_GENERATOR_HELPERS_H
