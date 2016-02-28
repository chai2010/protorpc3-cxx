// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef PROTORPC_COMPILER_CONFIG_H
#define PROTORPC_COMPILER_CONFIG_H

#ifndef PROTORPC_CUSTOM_DESCRIPTOR
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#define PROTORPC_CUSTOM_DESCRIPTOR ::google::protobuf::Descriptor
#define PROTORPC_CUSTOM_FILEDESCRIPTOR ::google::protobuf::FileDescriptor
#define PROTORPC_CUSTOM_METHODDESCRIPTOR ::google::protobuf::MethodDescriptor
#define PROTORPC_CUSTOM_SERVICEDESCRIPTOR ::google::protobuf::ServiceDescriptor
#endif

#ifndef PROTORPC_CUSTOM_CODEGENERATOR
#include <google/protobuf/compiler/code_generator.h>
#define PROTORPC_CUSTOM_CODEGENERATOR ::google::protobuf::compiler::CodeGenerator
#define PROTORPC_CUSTOM_GENERATORCONTEXT \
  ::google::protobuf::compiler::GeneratorContext
#endif

#ifndef PROTORPC_CUSTOM_PRINTER
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#define PROTORPC_CUSTOM_PRINTER ::google::protobuf::io::Printer
#define PROTORPC_CUSTOM_CODEDOUTPUTSTREAM ::google::protobuf::io::CodedOutputStream
#define PROTORPC_CUSTOM_STRINGOUTPUTSTREAM \
  ::google::protobuf::io::StringOutputStream
#endif

#ifndef PROTORPC_CUSTOM_PLUGINMAIN
#include <google/protobuf/compiler/plugin.h>
#define PROTORPC_CUSTOM_PLUGINMAIN ::google::protobuf::compiler::PluginMain
#endif

namespace protorpc {
typedef PROTORPC_CUSTOM_DESCRIPTOR Descriptor;
typedef PROTORPC_CUSTOM_FILEDESCRIPTOR FileDescriptor;
typedef PROTORPC_CUSTOM_METHODDESCRIPTOR MethodDescriptor;
typedef PROTORPC_CUSTOM_SERVICEDESCRIPTOR ServiceDescriptor;
namespace compiler {
typedef PROTORPC_CUSTOM_CODEGENERATOR CodeGenerator;
typedef PROTORPC_CUSTOM_GENERATORCONTEXT GeneratorContext;
static inline int PluginMain(int argc, char* argv[], const CodeGenerator* generator) {
  return PROTORPC_CUSTOM_PLUGINMAIN(argc, argv, generator);
}  // namespace compiler
namespace io {
typedef PROTORPC_CUSTOM_PRINTER Printer;
typedef PROTORPC_CUSTOM_CODEDOUTPUTSTREAM CodedOutputStream;
typedef PROTORPC_CUSTOM_STRINGOUTPUTSTREAM StringOutputStream;
}  // namespace io
}  // namespace protorpc

#endif  // PROTORPC_COMPILER_CONFIG_H
