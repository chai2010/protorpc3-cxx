// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#pragma once

#ifndef PROTORPC_WIRE_H__
#define PROTORPC_WIRE_H__

#include <stddef.h>
#include <stdint.h>

#include "protorpc/rpc_service.h"
#include "protorpc/rpc_conn.h"

namespace protorpc {
namespace wire {

static const int kMaxHeaderLen = 1024;

Error SendRequest(Conn* conn,
	uint64_t id, const std::string& serviceMethod,
	const ::google::protobuf::Message* request
);
Error RecvRequestHeader(Conn* conn,
	RequestHeader* header
);
Error RecvRequestBody(Conn* conn,
	const RequestHeader* header,
	::google::protobuf::Message* request
);

Error SendResponse(Conn* conn,
	uint64_t id, const std::string& error,
	const ::google::protobuf::Message* response
);
Error RecvResponseHeader(Conn* conn,
	ResponseHeader* header
);
Error RecvResponseBody(Conn* conn,
	const ResponseHeader* header,
	::google::protobuf::Message* request
);

} // namespace wire
} // namespace protorpc

#endif // PROTORPC_WIRE_H__

