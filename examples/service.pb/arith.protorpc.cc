// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: arith.proto

#include "arith.pb.h"
#include "arith.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace service {

static const char* ArithService_method_names[] = {
  "/service.ArithService/add",
  "/service.ArithService/mul",
  "/service.ArithService/div",
  "/service.ArithService/error",
};

std::unique_ptr< ArithService::Stub> ArithService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< ArithService::Stub> stub(new ArithService::Stub(channel));
  return stub;
}

ArithService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_add_(ArithService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_mul_(ArithService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_div_(ArithService_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_error_(ArithService_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ArithService::Stub::add(::grpc::ClientContext* context, const ::service::ArithRequest& request, ::service::ArithResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_add_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::service::ArithResponse>* ArithService::Stub::AsyncaddRaw(::grpc::ClientContext* context, const ::service::ArithRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::service::ArithResponse>(channel_.get(), cq, rpcmethod_add_, context, request);
}

::grpc::Status ArithService::Stub::mul(::grpc::ClientContext* context, const ::service::ArithRequest& request, ::service::ArithResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_mul_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::service::ArithResponse>* ArithService::Stub::AsyncmulRaw(::grpc::ClientContext* context, const ::service::ArithRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::service::ArithResponse>(channel_.get(), cq, rpcmethod_mul_, context, request);
}

::grpc::Status ArithService::Stub::div(::grpc::ClientContext* context, const ::service::ArithRequest& request, ::service::ArithResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_div_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::service::ArithResponse>* ArithService::Stub::AsyncdivRaw(::grpc::ClientContext* context, const ::service::ArithRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::service::ArithResponse>(channel_.get(), cq, rpcmethod_div_, context, request);
}

::grpc::Status ArithService::Stub::error(::grpc::ClientContext* context, const ::service::ArithRequest& request, ::service::ArithResponse* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_error_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::service::ArithResponse>* ArithService::Stub::AsyncerrorRaw(::grpc::ClientContext* context, const ::service::ArithRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::service::ArithResponse>(channel_.get(), cq, rpcmethod_error_, context, request);
}

ArithService::Service::Service() {
  (void)ArithService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      ArithService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< ArithService::Service, ::service::ArithRequest, ::service::ArithResponse>(
          std::mem_fn(&ArithService::Service::add), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      ArithService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< ArithService::Service, ::service::ArithRequest, ::service::ArithResponse>(
          std::mem_fn(&ArithService::Service::mul), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      ArithService_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< ArithService::Service, ::service::ArithRequest, ::service::ArithResponse>(
          std::mem_fn(&ArithService::Service::div), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      ArithService_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< ArithService::Service, ::service::ArithRequest, ::service::ArithResponse>(
          std::mem_fn(&ArithService::Service::error), this)));
}

ArithService::Service::~Service() {
}

::grpc::Status ArithService::Service::add(::grpc::ServerContext* context, const ::service::ArithRequest* request, ::service::ArithResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ArithService::Service::mul(::grpc::ServerContext* context, const ::service::ArithRequest* request, ::service::ArithResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ArithService::Service::div(::grpc::ServerContext* context, const ::service::ArithRequest* request, ::service::ArithResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ArithService::Service::error(::grpc::ServerContext* context, const ::service::ArithRequest* request, ::service::ArithResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace service
