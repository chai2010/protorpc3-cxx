// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: echo.proto

#ifndef PROTOBUF_echo_2eproto__INCLUDED
#define PROTOBUF_echo_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace message {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_echo_2eproto();
void protobuf_AssignDesc_echo_2eproto();
void protobuf_ShutdownFile_echo_2eproto();

class EchoRequest;
class EchoResponse;

// ===================================================================

class EchoRequest : public ::google::protobuf::Message {
 public:
  EchoRequest();
  virtual ~EchoRequest();

  EchoRequest(const EchoRequest& from);

  inline EchoRequest& operator=(const EchoRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EchoRequest& default_instance();

  void Swap(EchoRequest* other);

  // implements Message ----------------------------------------------

  EchoRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const EchoRequest& from);
  void MergeFrom(const EchoRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string msg = 1;
  inline bool has_msg() const;
  inline void clear_msg();
  static const int kMsgFieldNumber = 1;
  inline const ::std::string& msg() const;
  inline void set_msg(const ::std::string& value);
  inline void set_msg(const char* value);
  inline void set_msg(const char* value, size_t size);
  inline ::std::string* mutable_msg();
  inline ::std::string* release_msg();
  inline void set_allocated_msg(::std::string* msg);

  // @@protoc_insertion_point(class_scope:message.EchoRequest)
 private:
  inline void set_has_msg();
  inline void clear_has_msg();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* msg_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_echo_2eproto();
  friend void protobuf_AssignDesc_echo_2eproto();
  friend void protobuf_ShutdownFile_echo_2eproto();

  void InitAsDefaultInstance();
  static EchoRequest* default_instance_;
};
// -------------------------------------------------------------------

class EchoResponse : public ::google::protobuf::Message {
 public:
  EchoResponse();
  virtual ~EchoResponse();

  EchoResponse(const EchoResponse& from);

  inline EchoResponse& operator=(const EchoResponse& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EchoResponse& default_instance();

  void Swap(EchoResponse* other);

  // implements Message ----------------------------------------------

  EchoResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const EchoResponse& from);
  void MergeFrom(const EchoResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string msg = 1;
  inline bool has_msg() const;
  inline void clear_msg();
  static const int kMsgFieldNumber = 1;
  inline const ::std::string& msg() const;
  inline void set_msg(const ::std::string& value);
  inline void set_msg(const char* value);
  inline void set_msg(const char* value, size_t size);
  inline ::std::string* mutable_msg();
  inline ::std::string* release_msg();
  inline void set_allocated_msg(::std::string* msg);

  // @@protoc_insertion_point(class_scope:message.EchoResponse)
 private:
  inline void set_has_msg();
  inline void clear_has_msg();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* msg_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_echo_2eproto();
  friend void protobuf_AssignDesc_echo_2eproto();
  friend void protobuf_ShutdownFile_echo_2eproto();

  void InitAsDefaultInstance();
  static EchoResponse* default_instance_;
};
// ===================================================================


// ===================================================================

// EchoRequest

// optional string msg = 1;
inline bool EchoRequest::has_msg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void EchoRequest::set_has_msg() {
  _has_bits_[0] |= 0x00000001u;
}
inline void EchoRequest::clear_has_msg() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void EchoRequest::clear_msg() {
  if (msg_ != &::google::protobuf::internal::kEmptyString) {
    msg_->clear();
  }
  clear_has_msg();
}
inline const ::std::string& EchoRequest::msg() const {
  return *msg_;
}
inline void EchoRequest::set_msg(const ::std::string& value) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(value);
}
inline void EchoRequest::set_msg(const char* value) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(value);
}
inline void EchoRequest::set_msg(const char* value, size_t size) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* EchoRequest::mutable_msg() {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  return msg_;
}
inline ::std::string* EchoRequest::release_msg() {
  clear_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = msg_;
    msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void EchoRequest::set_allocated_msg(::std::string* msg) {
  if (msg_ != &::google::protobuf::internal::kEmptyString) {
    delete msg_;
  }
  if (msg) {
    set_has_msg();
    msg_ = msg;
  } else {
    clear_has_msg();
    msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// EchoResponse

// optional string msg = 1;
inline bool EchoResponse::has_msg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void EchoResponse::set_has_msg() {
  _has_bits_[0] |= 0x00000001u;
}
inline void EchoResponse::clear_has_msg() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void EchoResponse::clear_msg() {
  if (msg_ != &::google::protobuf::internal::kEmptyString) {
    msg_->clear();
  }
  clear_has_msg();
}
inline const ::std::string& EchoResponse::msg() const {
  return *msg_;
}
inline void EchoResponse::set_msg(const ::std::string& value) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(value);
}
inline void EchoResponse::set_msg(const char* value) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(value);
}
inline void EchoResponse::set_msg(const char* value, size_t size) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* EchoResponse::mutable_msg() {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  return msg_;
}
inline ::std::string* EchoResponse::release_msg() {
  clear_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = msg_;
    msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void EchoResponse::set_allocated_msg(::std::string* msg) {
  if (msg_ != &::google::protobuf::internal::kEmptyString) {
    delete msg_;
  }
  if (msg) {
    set_has_msg();
    msg_ = msg;
  } else {
    clear_has_msg();
    msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace message

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_echo_2eproto__INCLUDED