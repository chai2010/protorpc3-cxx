
namespace service {

namespace {

const ::google::protobuf::Descriptor* EchoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EchoRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* EchoResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EchoResponse_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* EchoService_descriptor_ = NULL;

}  // namespace


EchoService::~EchoService() {}

const ::google::protobuf::ServiceDescriptor* EchoService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* EchoService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoService_descriptor_;
}

const ::google::protobuf::rpc::Error EchoService::Echo(
  const ::service::EchoRequest*,
  ::service::EchoResponse*) {
  return ::google::protobuf::rpc::Error("Method EchoService::Echo() not implemented.");
}

const ::google::protobuf::rpc::Error EchoService::EchoTwice(
  const ::service::EchoRequest*,
  ::service::EchoResponse*) {
  return ::google::protobuf::rpc::Error("Method EchoService::EchoTwice() not implemented.");
}

const ::google::protobuf::rpc::Error EchoService::CallMethod(
  const ::google::protobuf::MethodDescriptor* method,
  const ::google::protobuf::Message* request,
  ::google::protobuf::Message* response) {
  GOOGLE_DCHECK_EQ(method->service(), EchoService_descriptor_);
  switch(method->index()) {
    case 0:
      return Echo(
        ::google::protobuf::down_cast<const ::service::EchoRequest*>(request),
        ::google::protobuf::down_cast< ::service::EchoResponse*>(response));
    case 1:
      return EchoTwice(
        ::google::protobuf::down_cast<const ::service::EchoRequest*>(request),
        ::google::protobuf::down_cast< ::service::EchoResponse*>(response));
    default:
      return ::google::protobuf::rpc::Error("Bad method index; this should never happen.");
  }
}

const ::google::protobuf::Message& EchoService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::service::EchoRequest::default_instance();
    case 1:
      return ::service::EchoRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& EchoService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::service::EchoResponse::default_instance();
    case 1:
      return ::service::EchoResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

EchoService_Stub::EchoService_Stub(::google::protobuf::rpc::Caller* client)
  : client_(client), owns_client_(false) {}
EchoService_Stub::EchoService_Stub(
    ::google::protobuf::rpc::Caller* client, bool client_ownership)
  : client_(client),
    owns_client_(client_ownership) {}
EchoService_Stub::~EchoService_Stub() {
  if (owns_client_) delete client_;
}

const ::google::protobuf::rpc::Error EchoService_Stub::Echo(
  const ::service::EchoRequest* request,
  ::service::EchoResponse* response) {
  return client_->CallMethod(descriptor()->method(0), request, response);
}
const ::google::protobuf::rpc::Error EchoService_Stub::EchoTwice(
  const ::service::EchoRequest* request,
  ::service::EchoResponse* response) {
  return client_->CallMethod(descriptor()->method(1), request, response);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace service
