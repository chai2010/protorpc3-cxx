// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: wire.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "wire.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace protorpc {
namespace wire {

namespace {

const ::google::protobuf::Descriptor* RequestHeader_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RequestHeader_reflection_ = NULL;
const ::google::protobuf::Descriptor* ResponseHeader_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ResponseHeader_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Const_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_wire_2eproto() {
  protobuf_AddDesc_wire_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "wire.proto");
  GOOGLE_CHECK(file != NULL);
  RequestHeader_descriptor_ = file->message_type(0);
  static const int RequestHeader_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestHeader, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestHeader, method_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestHeader, raw_request_len_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestHeader, snappy_compressed_request_len_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestHeader, checksum_),
  };
  RequestHeader_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      RequestHeader_descriptor_,
      RequestHeader::default_instance_,
      RequestHeader_offsets_,
      -1,
      -1,
      -1,
      sizeof(RequestHeader),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestHeader, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestHeader, _is_default_instance_));
  ResponseHeader_descriptor_ = file->message_type(1);
  static const int ResponseHeader_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, error_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, raw_response_len_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, snappy_compressed_response_len_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, checksum_),
  };
  ResponseHeader_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ResponseHeader_descriptor_,
      ResponseHeader::default_instance_,
      ResponseHeader_offsets_,
      -1,
      -1,
      -1,
      sizeof(ResponseHeader),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ResponseHeader, _is_default_instance_));
  Const_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_wire_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      RequestHeader_descriptor_, &RequestHeader::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ResponseHeader_descriptor_, &ResponseHeader::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_wire_2eproto() {
  delete RequestHeader::default_instance_;
  delete RequestHeader_reflection_;
  delete ResponseHeader::default_instance_;
  delete ResponseHeader_reflection_;
}

void protobuf_AddDesc_wire_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nwire.proto\022\rprotorpc.wire\"}\n\rRequestHe"
    "ader\022\n\n\002id\030\001 \001(\004\022\016\n\006method\030\002 \001(\t\022\027\n\017raw_"
    "request_len\030\003 \001(\r\022%\n\035snappy_compressed_r"
    "equest_len\030\004 \001(\r\022\020\n\010checksum\030\005 \001(\r\"\177\n\016Re"
    "sponseHeader\022\n\n\002id\030\001 \001(\004\022\r\n\005error\030\002 \001(\t\022"
    "\030\n\020raw_response_len\030\003 \001(\r\022&\n\036snappy_comp"
    "ressed_response_len\030\004 \001(\r\022\020\n\010checksum\030\005 "
    "\001(\r*.\n\005Const\022\010\n\004ZERO\020\000\022\033\n\026MAX_REQUEST_HE"
    "ADER_LEN\020\200\010b\006proto3", 339);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "wire.proto", &protobuf_RegisterTypes);
  RequestHeader::default_instance_ = new RequestHeader();
  ResponseHeader::default_instance_ = new ResponseHeader();
  RequestHeader::default_instance_->InitAsDefaultInstance();
  ResponseHeader::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_wire_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_wire_2eproto {
  StaticDescriptorInitializer_wire_2eproto() {
    protobuf_AddDesc_wire_2eproto();
  }
} static_descriptor_initializer_wire_2eproto_;
const ::google::protobuf::EnumDescriptor* Const_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Const_descriptor_;
}
bool Const_IsValid(int value) {
  switch(value) {
    case 0:
    case 1024:
      return true;
    default:
      return false;
  }
}


namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RequestHeader::kIdFieldNumber;
const int RequestHeader::kMethodFieldNumber;
const int RequestHeader::kRawRequestLenFieldNumber;
const int RequestHeader::kSnappyCompressedRequestLenFieldNumber;
const int RequestHeader::kChecksumFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RequestHeader::RequestHeader()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protorpc.wire.RequestHeader)
}

void RequestHeader::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

RequestHeader::RequestHeader(const RequestHeader& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protorpc.wire.RequestHeader)
}

void RequestHeader::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = GOOGLE_ULONGLONG(0);
  method_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  raw_request_len_ = 0u;
  snappy_compressed_request_len_ = 0u;
  checksum_ = 0u;
}

RequestHeader::~RequestHeader() {
  // @@protoc_insertion_point(destructor:protorpc.wire.RequestHeader)
  SharedDtor();
}

void RequestHeader::SharedDtor() {
  method_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void RequestHeader::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RequestHeader::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RequestHeader_descriptor_;
}

const RequestHeader& RequestHeader::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_wire_2eproto();
  return *default_instance_;
}

RequestHeader* RequestHeader::default_instance_ = NULL;

RequestHeader* RequestHeader::New(::google::protobuf::Arena* arena) const {
  RequestHeader* n = new RequestHeader;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void RequestHeader::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<RequestHeader*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(raw_request_len_, checksum_);
  id_ = GOOGLE_ULONGLONG(0);
  method_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());

#undef ZR_HELPER_
#undef ZR_

}

bool RequestHeader::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protorpc.wire.RequestHeader)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint64 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &id_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_method;
        break;
      }

      // optional string method = 2;
      case 2: {
        if (tag == 18) {
         parse_method:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_method()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->method().data(), this->method().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "protorpc.wire.RequestHeader.method"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_raw_request_len;
        break;
      }

      // optional uint32 raw_request_len = 3;
      case 3: {
        if (tag == 24) {
         parse_raw_request_len:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &raw_request_len_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_snappy_compressed_request_len;
        break;
      }

      // optional uint32 snappy_compressed_request_len = 4;
      case 4: {
        if (tag == 32) {
         parse_snappy_compressed_request_len:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &snappy_compressed_request_len_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_checksum;
        break;
      }

      // optional uint32 checksum = 5;
      case 5: {
        if (tag == 40) {
         parse_checksum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &checksum_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protorpc.wire.RequestHeader)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protorpc.wire.RequestHeader)
  return false;
#undef DO_
}

void RequestHeader::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protorpc.wire.RequestHeader)
  // optional uint64 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->id(), output);
  }

  // optional string method = 2;
  if (this->method().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->method().data(), this->method().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "protorpc.wire.RequestHeader.method");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->method(), output);
  }

  // optional uint32 raw_request_len = 3;
  if (this->raw_request_len() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->raw_request_len(), output);
  }

  // optional uint32 snappy_compressed_request_len = 4;
  if (this->snappy_compressed_request_len() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->snappy_compressed_request_len(), output);
  }

  // optional uint32 checksum = 5;
  if (this->checksum() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->checksum(), output);
  }

  // @@protoc_insertion_point(serialize_end:protorpc.wire.RequestHeader)
}

::google::protobuf::uint8* RequestHeader::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protorpc.wire.RequestHeader)
  // optional uint64 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->id(), target);
  }

  // optional string method = 2;
  if (this->method().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->method().data(), this->method().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "protorpc.wire.RequestHeader.method");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->method(), target);
  }

  // optional uint32 raw_request_len = 3;
  if (this->raw_request_len() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->raw_request_len(), target);
  }

  // optional uint32 snappy_compressed_request_len = 4;
  if (this->snappy_compressed_request_len() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->snappy_compressed_request_len(), target);
  }

  // optional uint32 checksum = 5;
  if (this->checksum() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->checksum(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:protorpc.wire.RequestHeader)
  return target;
}

int RequestHeader::ByteSize() const {
  int total_size = 0;

  // optional uint64 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->id());
  }

  // optional string method = 2;
  if (this->method().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->method());
  }

  // optional uint32 raw_request_len = 3;
  if (this->raw_request_len() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->raw_request_len());
  }

  // optional uint32 snappy_compressed_request_len = 4;
  if (this->snappy_compressed_request_len() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->snappy_compressed_request_len());
  }

  // optional uint32 checksum = 5;
  if (this->checksum() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->checksum());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RequestHeader::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const RequestHeader* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const RequestHeader>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RequestHeader::MergeFrom(const RequestHeader& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.method().size() > 0) {

    method_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.method_);
  }
  if (from.raw_request_len() != 0) {
    set_raw_request_len(from.raw_request_len());
  }
  if (from.snappy_compressed_request_len() != 0) {
    set_snappy_compressed_request_len(from.snappy_compressed_request_len());
  }
  if (from.checksum() != 0) {
    set_checksum(from.checksum());
  }
}

void RequestHeader::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RequestHeader::CopyFrom(const RequestHeader& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RequestHeader::IsInitialized() const {

  return true;
}

void RequestHeader::Swap(RequestHeader* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RequestHeader::InternalSwap(RequestHeader* other) {
  std::swap(id_, other->id_);
  method_.Swap(&other->method_);
  std::swap(raw_request_len_, other->raw_request_len_);
  std::swap(snappy_compressed_request_len_, other->snappy_compressed_request_len_);
  std::swap(checksum_, other->checksum_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata RequestHeader::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RequestHeader_descriptor_;
  metadata.reflection = RequestHeader_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// RequestHeader

// optional uint64 id = 1;
void RequestHeader::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
}
 ::google::protobuf::uint64 RequestHeader::id() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.RequestHeader.id)
  return id_;
}
 void RequestHeader::set_id(::google::protobuf::uint64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:protorpc.wire.RequestHeader.id)
}

// optional string method = 2;
void RequestHeader::clear_method() {
  method_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& RequestHeader::method() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.RequestHeader.method)
  return method_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void RequestHeader::set_method(const ::std::string& value) {
  
  method_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protorpc.wire.RequestHeader.method)
}
 void RequestHeader::set_method(const char* value) {
  
  method_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protorpc.wire.RequestHeader.method)
}
 void RequestHeader::set_method(const char* value, size_t size) {
  
  method_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protorpc.wire.RequestHeader.method)
}
 ::std::string* RequestHeader::mutable_method() {
  
  // @@protoc_insertion_point(field_mutable:protorpc.wire.RequestHeader.method)
  return method_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* RequestHeader::release_method() {
  
  return method_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void RequestHeader::set_allocated_method(::std::string* method) {
  if (method != NULL) {
    
  } else {
    
  }
  method_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), method);
  // @@protoc_insertion_point(field_set_allocated:protorpc.wire.RequestHeader.method)
}

// optional uint32 raw_request_len = 3;
void RequestHeader::clear_raw_request_len() {
  raw_request_len_ = 0u;
}
 ::google::protobuf::uint32 RequestHeader::raw_request_len() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.RequestHeader.raw_request_len)
  return raw_request_len_;
}
 void RequestHeader::set_raw_request_len(::google::protobuf::uint32 value) {
  
  raw_request_len_ = value;
  // @@protoc_insertion_point(field_set:protorpc.wire.RequestHeader.raw_request_len)
}

// optional uint32 snappy_compressed_request_len = 4;
void RequestHeader::clear_snappy_compressed_request_len() {
  snappy_compressed_request_len_ = 0u;
}
 ::google::protobuf::uint32 RequestHeader::snappy_compressed_request_len() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.RequestHeader.snappy_compressed_request_len)
  return snappy_compressed_request_len_;
}
 void RequestHeader::set_snappy_compressed_request_len(::google::protobuf::uint32 value) {
  
  snappy_compressed_request_len_ = value;
  // @@protoc_insertion_point(field_set:protorpc.wire.RequestHeader.snappy_compressed_request_len)
}

// optional uint32 checksum = 5;
void RequestHeader::clear_checksum() {
  checksum_ = 0u;
}
 ::google::protobuf::uint32 RequestHeader::checksum() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.RequestHeader.checksum)
  return checksum_;
}
 void RequestHeader::set_checksum(::google::protobuf::uint32 value) {
  
  checksum_ = value;
  // @@protoc_insertion_point(field_set:protorpc.wire.RequestHeader.checksum)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ResponseHeader::kIdFieldNumber;
const int ResponseHeader::kErrorFieldNumber;
const int ResponseHeader::kRawResponseLenFieldNumber;
const int ResponseHeader::kSnappyCompressedResponseLenFieldNumber;
const int ResponseHeader::kChecksumFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ResponseHeader::ResponseHeader()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protorpc.wire.ResponseHeader)
}

void ResponseHeader::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

ResponseHeader::ResponseHeader(const ResponseHeader& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protorpc.wire.ResponseHeader)
}

void ResponseHeader::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = GOOGLE_ULONGLONG(0);
  error_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  raw_response_len_ = 0u;
  snappy_compressed_response_len_ = 0u;
  checksum_ = 0u;
}

ResponseHeader::~ResponseHeader() {
  // @@protoc_insertion_point(destructor:protorpc.wire.ResponseHeader)
  SharedDtor();
}

void ResponseHeader::SharedDtor() {
  error_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void ResponseHeader::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ResponseHeader::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ResponseHeader_descriptor_;
}

const ResponseHeader& ResponseHeader::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_wire_2eproto();
  return *default_instance_;
}

ResponseHeader* ResponseHeader::default_instance_ = NULL;

ResponseHeader* ResponseHeader::New(::google::protobuf::Arena* arena) const {
  ResponseHeader* n = new ResponseHeader;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ResponseHeader::Clear() {
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<ResponseHeader*>(16)->f)

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(raw_response_len_, checksum_);
  id_ = GOOGLE_ULONGLONG(0);
  error_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());

#undef ZR_HELPER_
#undef ZR_

}

bool ResponseHeader::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protorpc.wire.ResponseHeader)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint64 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &id_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_error;
        break;
      }

      // optional string error = 2;
      case 2: {
        if (tag == 18) {
         parse_error:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_error()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->error().data(), this->error().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "protorpc.wire.ResponseHeader.error"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_raw_response_len;
        break;
      }

      // optional uint32 raw_response_len = 3;
      case 3: {
        if (tag == 24) {
         parse_raw_response_len:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &raw_response_len_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_snappy_compressed_response_len;
        break;
      }

      // optional uint32 snappy_compressed_response_len = 4;
      case 4: {
        if (tag == 32) {
         parse_snappy_compressed_response_len:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &snappy_compressed_response_len_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_checksum;
        break;
      }

      // optional uint32 checksum = 5;
      case 5: {
        if (tag == 40) {
         parse_checksum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &checksum_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protorpc.wire.ResponseHeader)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protorpc.wire.ResponseHeader)
  return false;
#undef DO_
}

void ResponseHeader::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protorpc.wire.ResponseHeader)
  // optional uint64 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->id(), output);
  }

  // optional string error = 2;
  if (this->error().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->error().data(), this->error().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "protorpc.wire.ResponseHeader.error");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->error(), output);
  }

  // optional uint32 raw_response_len = 3;
  if (this->raw_response_len() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->raw_response_len(), output);
  }

  // optional uint32 snappy_compressed_response_len = 4;
  if (this->snappy_compressed_response_len() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->snappy_compressed_response_len(), output);
  }

  // optional uint32 checksum = 5;
  if (this->checksum() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->checksum(), output);
  }

  // @@protoc_insertion_point(serialize_end:protorpc.wire.ResponseHeader)
}

::google::protobuf::uint8* ResponseHeader::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protorpc.wire.ResponseHeader)
  // optional uint64 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->id(), target);
  }

  // optional string error = 2;
  if (this->error().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->error().data(), this->error().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "protorpc.wire.ResponseHeader.error");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->error(), target);
  }

  // optional uint32 raw_response_len = 3;
  if (this->raw_response_len() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->raw_response_len(), target);
  }

  // optional uint32 snappy_compressed_response_len = 4;
  if (this->snappy_compressed_response_len() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->snappy_compressed_response_len(), target);
  }

  // optional uint32 checksum = 5;
  if (this->checksum() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->checksum(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:protorpc.wire.ResponseHeader)
  return target;
}

int ResponseHeader::ByteSize() const {
  int total_size = 0;

  // optional uint64 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->id());
  }

  // optional string error = 2;
  if (this->error().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->error());
  }

  // optional uint32 raw_response_len = 3;
  if (this->raw_response_len() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->raw_response_len());
  }

  // optional uint32 snappy_compressed_response_len = 4;
  if (this->snappy_compressed_response_len() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->snappy_compressed_response_len());
  }

  // optional uint32 checksum = 5;
  if (this->checksum() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->checksum());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ResponseHeader::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const ResponseHeader* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const ResponseHeader>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ResponseHeader::MergeFrom(const ResponseHeader& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.error().size() > 0) {

    error_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.error_);
  }
  if (from.raw_response_len() != 0) {
    set_raw_response_len(from.raw_response_len());
  }
  if (from.snappy_compressed_response_len() != 0) {
    set_snappy_compressed_response_len(from.snappy_compressed_response_len());
  }
  if (from.checksum() != 0) {
    set_checksum(from.checksum());
  }
}

void ResponseHeader::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ResponseHeader::CopyFrom(const ResponseHeader& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResponseHeader::IsInitialized() const {

  return true;
}

void ResponseHeader::Swap(ResponseHeader* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ResponseHeader::InternalSwap(ResponseHeader* other) {
  std::swap(id_, other->id_);
  error_.Swap(&other->error_);
  std::swap(raw_response_len_, other->raw_response_len_);
  std::swap(snappy_compressed_response_len_, other->snappy_compressed_response_len_);
  std::swap(checksum_, other->checksum_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ResponseHeader::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ResponseHeader_descriptor_;
  metadata.reflection = ResponseHeader_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ResponseHeader

// optional uint64 id = 1;
void ResponseHeader::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
}
 ::google::protobuf::uint64 ResponseHeader::id() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.ResponseHeader.id)
  return id_;
}
 void ResponseHeader::set_id(::google::protobuf::uint64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:protorpc.wire.ResponseHeader.id)
}

// optional string error = 2;
void ResponseHeader::clear_error() {
  error_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& ResponseHeader::error() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.ResponseHeader.error)
  return error_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void ResponseHeader::set_error(const ::std::string& value) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protorpc.wire.ResponseHeader.error)
}
 void ResponseHeader::set_error(const char* value) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protorpc.wire.ResponseHeader.error)
}
 void ResponseHeader::set_error(const char* value, size_t size) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protorpc.wire.ResponseHeader.error)
}
 ::std::string* ResponseHeader::mutable_error() {
  
  // @@protoc_insertion_point(field_mutable:protorpc.wire.ResponseHeader.error)
  return error_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* ResponseHeader::release_error() {
  
  return error_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void ResponseHeader::set_allocated_error(::std::string* error) {
  if (error != NULL) {
    
  } else {
    
  }
  error_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), error);
  // @@protoc_insertion_point(field_set_allocated:protorpc.wire.ResponseHeader.error)
}

// optional uint32 raw_response_len = 3;
void ResponseHeader::clear_raw_response_len() {
  raw_response_len_ = 0u;
}
 ::google::protobuf::uint32 ResponseHeader::raw_response_len() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.ResponseHeader.raw_response_len)
  return raw_response_len_;
}
 void ResponseHeader::set_raw_response_len(::google::protobuf::uint32 value) {
  
  raw_response_len_ = value;
  // @@protoc_insertion_point(field_set:protorpc.wire.ResponseHeader.raw_response_len)
}

// optional uint32 snappy_compressed_response_len = 4;
void ResponseHeader::clear_snappy_compressed_response_len() {
  snappy_compressed_response_len_ = 0u;
}
 ::google::protobuf::uint32 ResponseHeader::snappy_compressed_response_len() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.ResponseHeader.snappy_compressed_response_len)
  return snappy_compressed_response_len_;
}
 void ResponseHeader::set_snappy_compressed_response_len(::google::protobuf::uint32 value) {
  
  snappy_compressed_response_len_ = value;
  // @@protoc_insertion_point(field_set:protorpc.wire.ResponseHeader.snappy_compressed_response_len)
}

// optional uint32 checksum = 5;
void ResponseHeader::clear_checksum() {
  checksum_ = 0u;
}
 ::google::protobuf::uint32 ResponseHeader::checksum() const {
  // @@protoc_insertion_point(field_get:protorpc.wire.ResponseHeader.checksum)
  return checksum_;
}
 void ResponseHeader::set_checksum(::google::protobuf::uint32 value) {
  
  checksum_ = value;
  // @@protoc_insertion_point(field_set:protorpc.wire.ResponseHeader.checksum)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace wire
}  // namespace protorpc

// @@protoc_insertion_point(global_scope)
