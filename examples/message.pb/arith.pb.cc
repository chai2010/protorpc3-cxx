// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: arith.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "arith.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace message {

namespace {

const ::google::protobuf::Descriptor* ArithRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArithRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* ArithResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArithResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_arith_2eproto() {
  protobuf_AddDesc_arith_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "arith.proto");
  GOOGLE_CHECK(file != NULL);
  ArithRequest_descriptor_ = file->message_type(0);
  static const int ArithRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArithRequest, a_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArithRequest, b_),
  };
  ArithRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ArithRequest_descriptor_,
      ArithRequest::default_instance_,
      ArithRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArithRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArithRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ArithRequest));
  ArithResponse_descriptor_ = file->message_type(1);
  static const int ArithResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArithResponse, c_),
  };
  ArithResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ArithResponse_descriptor_,
      ArithResponse::default_instance_,
      ArithResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArithResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArithResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ArithResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_arith_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ArithRequest_descriptor_, &ArithRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ArithResponse_descriptor_, &ArithResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_arith_2eproto() {
  delete ArithRequest::default_instance_;
  delete ArithRequest_reflection_;
  delete ArithResponse::default_instance_;
  delete ArithResponse_reflection_;
}

void protobuf_AddDesc_arith_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013arith.proto\022\007message\"$\n\014ArithRequest\022\t"
    "\n\001a\030\001 \001(\005\022\t\n\001b\030\002 \001(\005\"\032\n\rArithResponse\022\t\n"
    "\001c\030\001 \001(\005", 88);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "arith.proto", &protobuf_RegisterTypes);
  ArithRequest::default_instance_ = new ArithRequest();
  ArithResponse::default_instance_ = new ArithResponse();
  ArithRequest::default_instance_->InitAsDefaultInstance();
  ArithResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_arith_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_arith_2eproto {
  StaticDescriptorInitializer_arith_2eproto() {
    protobuf_AddDesc_arith_2eproto();
  }
} static_descriptor_initializer_arith_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ArithRequest::kAFieldNumber;
const int ArithRequest::kBFieldNumber;
#endif  // !_MSC_VER

ArithRequest::ArithRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ArithRequest::InitAsDefaultInstance() {
}

ArithRequest::ArithRequest(const ArithRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ArithRequest::SharedCtor() {
  _cached_size_ = 0;
  a_ = 0;
  b_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ArithRequest::~ArithRequest() {
  SharedDtor();
}

void ArithRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ArithRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArithRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArithRequest_descriptor_;
}

const ArithRequest& ArithRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_arith_2eproto();
  return *default_instance_;
}

ArithRequest* ArithRequest::default_instance_ = NULL;

ArithRequest* ArithRequest::New() const {
  return new ArithRequest;
}

void ArithRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    a_ = 0;
    b_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ArithRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 a = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &a_)));
          set_has_a();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_b;
        break;
      }

      // optional int32 b = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_b:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &b_)));
          set_has_b();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ArithRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 a = 1;
  if (has_a()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->a(), output);
  }

  // optional int32 b = 2;
  if (has_b()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->b(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ArithRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 a = 1;
  if (has_a()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->a(), target);
  }

  // optional int32 b = 2;
  if (has_b()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->b(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ArithRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 a = 1;
    if (has_a()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->a());
    }

    // optional int32 b = 2;
    if (has_b()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->b());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArithRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ArithRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ArithRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ArithRequest::MergeFrom(const ArithRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_a()) {
      set_a(from.a());
    }
    if (from.has_b()) {
      set_b(from.b());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ArithRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArithRequest::CopyFrom(const ArithRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArithRequest::IsInitialized() const {

  return true;
}

void ArithRequest::Swap(ArithRequest* other) {
  if (other != this) {
    std::swap(a_, other->a_);
    std::swap(b_, other->b_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ArithRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArithRequest_descriptor_;
  metadata.reflection = ArithRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ArithResponse::kCFieldNumber;
#endif  // !_MSC_VER

ArithResponse::ArithResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ArithResponse::InitAsDefaultInstance() {
}

ArithResponse::ArithResponse(const ArithResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ArithResponse::SharedCtor() {
  _cached_size_ = 0;
  c_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ArithResponse::~ArithResponse() {
  SharedDtor();
}

void ArithResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ArithResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArithResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArithResponse_descriptor_;
}

const ArithResponse& ArithResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_arith_2eproto();
  return *default_instance_;
}

ArithResponse* ArithResponse::default_instance_ = NULL;

ArithResponse* ArithResponse::New() const {
  return new ArithResponse;
}

void ArithResponse::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    c_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ArithResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 c = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &c_)));
          set_has_c();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ArithResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 c = 1;
  if (has_c()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->c(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ArithResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 c = 1;
  if (has_c()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->c(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ArithResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 c = 1;
    if (has_c()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->c());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArithResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ArithResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ArithResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ArithResponse::MergeFrom(const ArithResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_c()) {
      set_c(from.c());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ArithResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArithResponse::CopyFrom(const ArithResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArithResponse::IsInitialized() const {

  return true;
}

void ArithResponse::Swap(ArithResponse* other) {
  if (other != this) {
    std::swap(c_, other->c_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ArithResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArithResponse_descriptor_;
  metadata.reflection = ArithResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace message

// @@protoc_insertion_point(global_scope)
