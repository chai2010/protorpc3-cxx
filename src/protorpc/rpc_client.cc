// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "protorpc/rpc_client.h"
#include "protorpc/rpc_wire.h"

namespace protorpc {

Client::Client(const char* host, int port, Env* env):
	conn_(0,env), host_(host), port_(port), seq_(0) {
	//
}
Client::~Client() {
	Close();
}

const ::protorpc::Error Client::CallMethod(
	const std::string& method,
	const ::google::protobuf::Message* request,
	::google::protobuf::Message* response
) {
	if(!checkMothdValid(method, request, response)) {
		return ::protorpc::Error::New(
			std::string("protorpc.Client.CallMethod: Invalid method, method: ") + method
		);
	}
	return callMethod(method, request, response);
}

const ::protorpc::Error Client::CallMethod(
	const ::google::protobuf::MethodDescriptor* method,
	const ::google::protobuf::Message* request,
	::google::protobuf::Message* response
) {
	if(!checkMothdValid(method, request, response)) {
		return ::protorpc::Error::New(
			std::string("protorpc.Client.CallMethod: Invalid method, method: ") + Service::GetServiceMethodName(method)
		);
	}
	return callMethod(Service::GetServiceMethodName(method), request, response);
}

// Close the connection
void Client::Close() {
	conn_.Close();
}

// --------------------------------------------------------

const ::protorpc::Error Client::callMethod(
	const std::string& method,
	const ::google::protobuf::Message* request,
	::google::protobuf::Message* response
) {
	if(!conn_.IsValid()) {
		if(!conn_.DialTCP(host_.c_str(), port_)) {
			return ::protorpc::Error::New(
				std::string("protorpc.Client.callMethod: DialTCP fail, ") +
				std::string("host: ") + host_ + std::string(":") + std::to_string(static_cast<long long>(port_))
			);
		}
	}

	Error err;

	uint64_t id = seq_++;
	wire::ResponseHeader respHeader;

	// send request
	err = wire::SendRequest(&conn_, id, method, request);
	if(!err.IsNil()) {
		return err;
	}

	// recv response hdr
	err = wire::RecvResponseHeader(&conn_, &respHeader);
	if(!err.IsNil()) {
		return err;
	}
	// recv response body
	err = wire::RecvResponseBody(&conn_, &respHeader, response);
	if(!err.IsNil()) {
		return err;
	}
	if(respHeader.id() != id) {
		return Error::New("protorpc.Client.callMethod: unexpected call id.");
	}
	if(!respHeader.error().empty()) {
		return Error::New(respHeader.error());
	}

	return Error::Nil();
}

// --------------------------------------------------------

bool Client::checkMothdValid(
	const std::string& method,
	const ::google::protobuf::Message* request,
	::google::protobuf::Message* response
) const {
	if(method.empty()) return false;
	if(!request) return false;
	if(!response) return false;
	return true;
}
bool Client::checkMothdValid(
	const ::google::protobuf::MethodDescriptor* method,
	const ::google::protobuf::Message* request,
	::google::protobuf::Message* response
) const {
	if(!method) return false;
	if(!request) return false;
	if(!response) return false;
	if(method->input_type() != request->GetDescriptor()) return false;
	if(method->output_type() != response->GetDescriptor()) return false;
	return true;
}

} // namespace protorpc

