// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#pragma once

#ifndef PROTORPC_PLUGIN_HELPERS_H
#define PROTORPC_PLUGIN_HELPERS_H

#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/stubs/strutil.h>

#include <map>
#include <sstream>

namespace protorpc_generator {

// --------------------------------------------------------

template <class T>
std::string as_string(T x) {
	std::ostringstream out;
	out << x;
	return out.str();
}

inline std::vector<std::string> tokenize(const std::string &input, const std::string &delimiters) {
	return google::protobuf::Split(input, delimiters.c_str());
}

inline bool StripSuffix(std::string *filename, const std::string &suffix) {
	if(google::protobuf::HasSuffixString(*filename, suffix)) {
		*filename = google::protobuf::StripSuffixString(*filename, suffix);
		return true;
	}

	return false;
}
inline std::string StripProto(std::string filename) {
	if (!StripSuffix(&filename, ".protodevel")) {
		StripSuffix(&filename, ".proto");
	}
	return filename;
}

inline std::string StringReplace(std::string str, const std::string &from, const std::string &to, bool replace_all) {
	return google::protobuf::StringReplace(str, from, to, replace_all);
}
inline std::string StringReplace(std::string str, const std::string &from, const std::string &to) {
	return StringReplace(str, from, to, true);
}

inline std::string CapitalizeFirstLetter(std::string s) {
	if (s.empty()) {
		return s;
	}
	s[0] = ::toupper(s[0]);
	return s;
}
inline std::string LowercaseFirstLetter(std::string s) {
	if (s.empty()) {
		return s;
	}
	s[0] = ::tolower(s[0]);
	return s;
}

inline std::string LowerUnderscoreToUpperCamel(std::string str) {
	std::vector<std::string> tokens = tokenize(str, "_");
	std::string result = "";
	for (unsigned int i = 0; i < tokens.size(); i++) {
		result += CapitalizeFirstLetter(tokens[i]);
	}
	return result;
}

// --------------------------------------------------------

inline std::string FilenameIdentifier(const std::string &filename) {
	std::string result;
	for (unsigned i = 0; i < filename.size(); i++) {
		char c = filename[i];
		if (isalnum(c)) {
			result.push_back(c);
		} else {
			static char hex[] = "0123456789abcdef";
			result.push_back('_');
			result.push_back(hex[(c >> 4) & 0xf]);
			result.push_back(hex[c & 0xf]);
		}
	}
	return result;
}

inline std::string FileNameInUpperCamel(const google::protobuf::FileDescriptor *file, bool include_package_path) {
	std::vector<std::string> tokens = tokenize(StripProto(file->name()), "/");
	std::string result = "";
	if (include_package_path) {
		for (unsigned int i = 0; i < tokens.size() - 1; i++) {
			result += tokens[i] + "/";
		}
	}
	result += LowerUnderscoreToUpperCamel(tokens.back());
	return result;
}
inline std::string FileNameInUpperCamel(const google::protobuf::FileDescriptor *file) {
	return FileNameInUpperCamel(file, true);
}

inline bool NoStreaming(const google::protobuf::MethodDescriptor *method) {
	return !method->client_streaming() && !method->server_streaming();
}
inline bool ClientOnlyStreaming(const google::protobuf::MethodDescriptor *method) {
	return method->client_streaming() && !method->server_streaming();
}
inline bool ServerOnlyStreaming(const google::protobuf::MethodDescriptor *method) {
	return !method->client_streaming() && method->server_streaming();
}
inline bool BidiStreaming(const google::protobuf::MethodDescriptor *method) {
	return method->client_streaming() && method->server_streaming();
}

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

// --------------------------------------------------------

}  // namespace protorpc_generator

#endif  // PROTORPC_PLUGIN_HELPERS_H
