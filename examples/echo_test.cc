// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "test.h"
#include "./service.pb/echo.protorpc.h"

#include <thread>
#include <mutex>

struct tEchoService: public service::EchoService {
	inline tEchoService() {}
	virtual ~tEchoService() {}

	virtual const ::protorpc::Error Echo(
		const ::service::EchoRequest* args,
		::service::EchoResponse* reply
	) {
		reply->set_msg(args->msg());
		return ::protorpc::Error::Nil();
	}
	virtual const ::protorpc::Error EchoTwice(
		const ::service::EchoRequest* args,
		::service::EchoResponse* reply
	) {
		reply->set_msg(args->msg() + args->msg());
		return ::protorpc::Error::Nil();
	}
};

static std::thread* tEchoServer = NULL;

void tStartEchoServer(int port) {
	if(tEchoServer != NULL) {
		return;
	}
	tEchoServer = new std::thread([&](int port){
		protorpc::Server server;
		server.AddService(new tEchoService, true);
		server.BindAndServe(port);
	}, port);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return;
}

INIT(StartEchoServer, port9527) {
	tStartEchoServer(9527);
}
EXIT(StopEchoServer, exit) {
	// do some clean work
}

TEST(protorpc3, EchoService) {
	protorpc::Client client("127.0.0.1", 9527);
	service::EchoService::Stub echoStub(&client);

	service::EchoRequest echoArgs;
	service::EchoResponse echoReply;
	protorpc::Error err;

	// EchoService.Echo
	echoArgs.set_msg("Hello Protobuf-RPC!");
	err = echoStub.Echo(&echoArgs, &echoReply);

	ASSERT_TRUE_MSG(err.IsNil(), "err = %s", err.String().c_str());
	ASSERT_STREQ("Hello Protobuf-RPC!", echoReply.msg().c_str());

	// EchoService.Echo: Use Client
	echoArgs.set_msg("Hi Protobuf-RPC!");
	err = client.CallMethod("EchoService.Echo", &echoArgs, &echoReply);

	ASSERT_TRUE_MSG(err.IsNil(), "err = %s", err.String().c_str());
	ASSERT_STREQ("Hi Protobuf-RPC!", echoReply.msg().c_str());
}