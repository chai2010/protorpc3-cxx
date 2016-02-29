// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#pragma once

#ifndef PROTORPC_COMPILER_CPP_GENERATOR_HELPERS_H
#define PROTORPC_COMPILER_CPP_GENERATOR_HELPERS_H

#include "protorpc/compiler/generator_helpers.h"

#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>

namespace protorpc_cpp_generator {

inline std::string DotsToColons(const std::string &name) {
	return protorpc_generator::StringReplace(name, ".", "::");
}

inline std::string DotsToUnderscores(const std::string &name) {
	return protorpc_generator::StringReplace(name, ".", "_");
}

inline std::string ClassName(const google::protobuf::Descriptor *descriptor, bool qualified) {
	// Find "outer", the descriptor of the top-level message in which
	// "descriptor" is embedded.
	const google::protobuf::Descriptor *outer = descriptor;
	while (outer->containing_type() != NULL) outer = outer->containing_type();

	const std::string &outer_name = outer->full_name();
	std::string inner_name = descriptor->full_name().substr(outer_name.size());

	if (qualified) {
		return "::" + DotsToColons(outer_name) + DotsToUnderscores(inner_name);
	} else {
		return outer->name() + DotsToUnderscores(inner_name);
	}
}

}  // namespace protorpc_cpp_generator

#endif  // PROTORPC_COMPILER_CPP_GENERATOR_HELPERS_H
