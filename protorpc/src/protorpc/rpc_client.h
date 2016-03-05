// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#pragma once

#ifndef PROTORPC_CLIENT_H__
#define PROTORPC_CLIENT_H__

#include "protorpc/rpc_conn.h"
#include "protorpc/rpc_service.h"

#include <stdint.h>

namespace protorpc {

class Env;

class Client: public Caller {
public:
	Client(const char* host, int port, Env* env=NULL);
	~Client();

	const ::protorpc::Error CallMethod(
		const std::string& method,
		const ::google::protobuf::Message* request,
		::google::protobuf::Message* response
	);
	const ::protorpc::Error CallMethod(
		const ::google::protobuf::MethodDescriptor* method,
		const ::google::protobuf::Message* request,
		::google::protobuf::Message* response
	);

	// Close the connection
	void Close();

private:
	const ::protorpc::Error callMethod(
		const std::string& method,
		const ::google::protobuf::Message* request,
		::google::protobuf::Message* response
	);

	bool checkMothdValid(
		const std::string& method,
		const ::google::protobuf::Message* request,
		::google::protobuf::Message* response
	) const;
	bool checkMothdValid(
		const ::google::protobuf::MethodDescriptor* method,
		const ::google::protobuf::Message* request,
		::google::protobuf::Message* response
	) const;

	std::string host_;
	int port_;
	Conn conn_;
	uint64_t seq_;

private:
	GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(Client);
};

} // namespace protorpc

#endif // PROTORPC_CLIENT_H__
