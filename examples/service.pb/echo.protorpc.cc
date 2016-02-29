// Generated by the protorpc compiler.  DO NOT EDIT!!!
// source: echo.proto

#include "echo.protorpc.h"

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>

namespace service {

namespace {

const ::google::protobuf::ServiceDescriptor* EchoService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* EchoService2_descriptor_ = NULL;

GOOGLE_PROTOBUF_DECLARE_ONCE(protorpc_AssignDescriptors_once_);

void protorpc_AssignDesc_echo_2eproto() {
	protobuf_AddDesc_echo_2eproto();
	auto file = ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName("echo.proto");
	GOOGLE_CHECK(file != NULL);
	EchoService_descriptor_ = file->service(0);
	EchoService2_descriptor_ = file->service(1);
}
inline void protorpc_AssignDescriptorsOnce() {
	::google::protobuf::GoogleOnceInit(
		&protorpc_AssignDescriptors_once_,
		&protorpc_AssignDesc_echo_2eproto
	);
}

} // namespace

EchoService::~EchoService() {}

const ::google::protobuf::ServiceDescriptor* EchoService::descriptor() {
	protorpc_AssignDescriptorsOnce();
	return EchoService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* EchoService::GetDescriptor() {
	protorpc_AssignDescriptorsOnce();
	return EchoService_descriptor_;
}

const ::protorpc::Error EchoService::Echo(
	const ::service::EchoRequest* request,
	::service::EchoResponse* reponse
) {
	return ::protorpc::Error("Method EchoService::Echo() not implemented.");
}

const ::protorpc::Error EchoService::EchoTwice(
	const ::service::EchoRequest* request,
	::service::EchoResponse* reponse
) {
	return ::protorpc::Error("Method EchoService::EchoTwice() not implemented.");
}

const ::protorpc::Error EchoService::CallMethod(
	const ::google::protobuf::MethodDescriptor* method,
	const ::google::protobuf::Message* request,
	::google::protobuf::Message* response
) {
	GOOGLE_DCHECK_EQ(method->service(), EchoService_descriptor_);
	switch(method->index()) {
	case 0:
		return Echo(
			::google::protobuf::down_cast<const ::service::EchoRequest*>(request),
			::google::protobuf::down_cast<::service::EchoResponse*>(response)
		);
	case 1:
		return EchoTwice(
			::google::protobuf::down_cast<const ::service::EchoRequest*>(request),
			::google::protobuf::down_cast<::service::EchoResponse*>(response)
		);
	default:
		return ::protorpc::Error("Bad method index; this should never happen.");
	}
}

const ::google::protobuf::Message& EchoService::GetRequestPrototype(
	const ::google::protobuf::MethodDescriptor* method
) const {
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

const ::google::protobuf::Message& EchoService::GetResponsePrototype(
	const ::google::protobuf::MethodDescriptor* method
) const {
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

EchoService_Stub::EchoService_Stub(::protorpc::Caller* client)
	: client_(client), owns_client_(false) {}
EchoService_Stub::EchoService_Stub(::protorpc::Caller* client, bool client_ownership)
	: client_(client), owns_client_(client_ownership) {}
EchoService_Stub::~EchoService_Stub() {
	if (owns_client_) delete client_;
}

const ::protorpc::Error EchoService_Stub::Echo(
	const ::service::EchoRequest* request,
	::service::EchoResponse* response
) {
	return client_->CallMethod(descriptor()->method(0), request, response);
}

const ::protorpc::Error EchoService_Stub::EchoTwice(
	const ::service::EchoRequest* request,
	::service::EchoResponse* response
) {
	return client_->CallMethod(descriptor()->method(0), request, response);
}

EchoService2::~EchoService2() {}

const ::google::protobuf::ServiceDescriptor* EchoService2::descriptor() {
	protorpc_AssignDescriptorsOnce();
	return EchoService2_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* EchoService2::GetDescriptor() {
	protorpc_AssignDescriptorsOnce();
	return EchoService2_descriptor_;
}

const ::protorpc::Error EchoService2::Echo(
	const ::service::EchoRequest* request,
	::service::EchoResponse* reponse
) {
	return ::protorpc::Error("Method EchoService2::Echo() not implemented.");
}

const ::protorpc::Error EchoService2::EchoTwice(
	const ::service::EchoRequest* request,
	::service::EchoResponse* reponse
) {
	return ::protorpc::Error("Method EchoService2::EchoTwice() not implemented.");
}

const ::protorpc::Error EchoService2::Foo(
	const ::service::Message* request,
	::service::Message* reponse
) {
	return ::protorpc::Error("Method EchoService2::Foo() not implemented.");
}

const ::protorpc::Error EchoService2::CallMethod(
	const ::google::protobuf::MethodDescriptor* method,
	const ::google::protobuf::Message* request,
	::google::protobuf::Message* response
) {
	GOOGLE_DCHECK_EQ(method->service(), EchoService2_descriptor_);
	switch(method->index()) {
	case 0:
		return Echo(
			::google::protobuf::down_cast<const ::service::EchoRequest*>(request),
			::google::protobuf::down_cast<::service::EchoResponse*>(response)
		);
	case 1:
		return EchoTwice(
			::google::protobuf::down_cast<const ::service::EchoRequest*>(request),
			::google::protobuf::down_cast<::service::EchoResponse*>(response)
		);
	case 2:
		return Foo(
			::google::protobuf::down_cast<const ::service::Message*>(request),
			::google::protobuf::down_cast<::service::Message*>(response)
		);
	default:
		return ::protorpc::Error("Bad method index; this should never happen.");
	}
}

const ::google::protobuf::Message& EchoService2::GetRequestPrototype(
	const ::google::protobuf::MethodDescriptor* method
) const {
	GOOGLE_DCHECK_EQ(method->service(), descriptor());
	switch(method->index()) {
	case 0:
		return ::service::EchoResponse::default_instance();
	case 1:
		return ::service::EchoResponse::default_instance();
	case 2:
		return ::service::Message::default_instance();
	default:
		GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
		return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
	}
}

const ::google::protobuf::Message& EchoService2::GetResponsePrototype(
	const ::google::protobuf::MethodDescriptor* method
) const {
	GOOGLE_DCHECK_EQ(method->service(), descriptor());
	switch(method->index()) {
	case 0:
		return ::service::EchoRequest::default_instance();
	case 1:
		return ::service::EchoRequest::default_instance();
	case 2:
		return ::service::Message::default_instance();
	default:
		GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
		return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
	}
}

EchoService2_Stub::EchoService2_Stub(::protorpc::Caller* client)
	: client_(client), owns_client_(false) {}
EchoService2_Stub::EchoService2_Stub(::protorpc::Caller* client, bool client_ownership)
	: client_(client), owns_client_(client_ownership) {}
EchoService2_Stub::~EchoService2_Stub() {
	if (owns_client_) delete client_;
}

const ::protorpc::Error EchoService2_Stub::Echo(
	const ::service::EchoRequest* request,
	::service::EchoResponse* response
) {
	return client_->CallMethod(descriptor()->method(0), request, response);
}

const ::protorpc::Error EchoService2_Stub::EchoTwice(
	const ::service::EchoRequest* request,
	::service::EchoResponse* response
) {
	return client_->CallMethod(descriptor()->method(0), request, response);
}

const ::protorpc::Error EchoService2_Stub::Foo(
	const ::service::Message* request,
	::service::Message* response
) {
	return client_->CallMethod(descriptor()->method(0), request, response);
}

}  // namespace service

