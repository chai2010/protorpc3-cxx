// Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "test.h"
#include "./service.pb/arith.protorpc.h"

#include <thread>
#include <mutex>

struct tArithService: public service::ArithService {
	inline tArithService() {}
	virtual ~tArithService() {}

	virtual const ::protorpc::Error add(
		const ::service::ArithRequest* args,
		::service::ArithResponse* reply
	) {
		reply->set_c(args->a() + args->b());
		return ::protorpc::Error::Nil();
	}
	virtual const ::protorpc::Error mul(
		const ::service::ArithRequest* args,
		::service::ArithResponse* reply
	) {
		reply->set_c(args->a() * args->b());
		return ::protorpc::Error::Nil();
	}
	virtual const ::protorpc::Error div(
		const ::service::ArithRequest* args,
		::service::ArithResponse* reply
	) {
		if(args->b() == 0) {
			return ::protorpc::Error::New("divide by zero");
		}
		reply->set_c(args->a() / args->b());
		return ::protorpc::Error::Nil();
	}
	virtual const ::protorpc::Error error(
		const ::service::ArithRequest* args,
		::service::ArithResponse* reply
	) {
		return ::protorpc::Error::New("ArithError");
	}
};

static std::thread* tArithServer     = NULL;
static int          tArithServerPort = 2016;

static void tStartArithServerCallback() {
	protorpc::Server server;
	server.AddService(new tArithService, true);
	server.BindAndServe(tArithServerPort);
}

void tStartArithServer() {
	if(tArithServer != NULL) {
		return;
	}
	tArithServer = new std::thread(tStartArithServerCallback);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return;
}

INIT(protorpc, StartArithServer) {
	tStartArithServer();
}
EXIT(protorpc, StopArithServer) {
	// do some clean work
}

TEST(protorpc, ArithService) {
	protorpc::Client client("127.0.0.1", tArithServerPort);
	service::ArithService::Stub stub(&client);

	service::ArithRequest args;
	service::ArithResponse reply;
	protorpc::Error err;

	// ArithService.add
	args.set_a(1);
	args.set_b(2);
	err = stub.add(&args, &reply);
	ASSERT_TRUE_MSG(err.IsNil(), "err = %s", err.String().c_str());
	ASSERT_EQ(3, reply.c());

	// ArithService.mul
	args.set_a(3);
	args.set_b(4);
	err = stub.mul(&args, &reply);
	ASSERT_TRUE_MSG(err.IsNil(), "err = %s", err.String().c_str());
	ASSERT_EQ(12, reply.c());

	// ArithService.div
	args.set_a(13);
	args.set_b(5);
	err = stub.div(&args, &reply);
	ASSERT_TRUE_MSG(err.IsNil(), "err = %s", err.String().c_str());
	ASSERT_EQ(2, reply.c());

	// ArithService.div: divide by zero
	args.set_a(1);
	args.set_b(0);
	err = stub.div(&args, &reply);
	ASSERT_STREQ("divide by zero", err.String().c_str());
}

