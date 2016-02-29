// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "./service.pb/arith.pb.h"
#include "./service.pb/echo.pb.h"

#include "./service.pb/arith.protorpc.golden.h"
#include "./service.pb/echo.protorpc.golden.h"

#include <protorpc/rpc_server.h>
#include <protorpc/rpc_client.h>

class ArithService: public service::ArithService {
 public:
  inline ArithService() {}
  virtual ~ArithService() {}

  virtual const ::protorpc::Error add(
    const ::service::ArithRequest* args,
    ::service::ArithResponse* reply
  ) {
    reply->set_c(args->a() + args->b());
    printf("ArithService.Add: args = a:%d b:%d, reply = c:%d, err = \"%s\"\n",
      args->a(), args->b(), reply->c(), ""
    );
    return ::protorpc::Error::Nil();
  }
  virtual const ::protorpc::Error mul(
    const ::service::ArithRequest* args,
    ::service::ArithResponse* reply
  ) {
    reply->set_c(args->a() * args->b());
    printf("ArithService.Mul: args = a:%d b:%d, reply = c:%d, err = \"%s\"\n",
      args->a(), args->b(), reply->c(), ""
    );
    return ::protorpc::Error::Nil();
  }
  virtual const ::protorpc::Error div(
    const ::service::ArithRequest* args,
    ::service::ArithResponse* reply
  ) {
    if(args->b() == 0) {
      printf("ArithService.Div: args = a:%d b:%d, reply = c:%d, err = \"%s\"\n",
        args->a(), args->b(), reply->c(), "divide by zero"
      );
      return ::protorpc::Error::New("divide by zero");
    }
    reply->set_c(args->a() / args->b());
    printf("ArithService.Div: args = a:%d b:%d, reply = c:%d, err = \"%s\"\n",
      args->a(), args->b(), reply->c(), ""
    );
    return ::protorpc::Error::Nil();
  }
  virtual const ::protorpc::Error error(
    const ::service::ArithRequest* args,
    ::service::ArithResponse* reply
  ) {
    printf("ArithService.Error: args = a:%d b:%d, reply = c:%d, err = \"%s\"\n",
      args->a(), args->b(), reply->c(), "ArithError"
    );
    return ::protorpc::Error::New("ArithError");
  }
};

class EchoService: public service::EchoService {
 public:
  inline EchoService() {}
  virtual ~EchoService() {}

  virtual const ::protorpc::Error Echo(
    const ::service::EchoRequest* args,
    ::service::EchoResponse* reply
  ) {
    reply->set_msg(args->msg());
    printf("EchoService.Echo: args = msg:\"%s\", reply = msg:\"%s\", err = \"%s\"\n",
      args->msg().c_str(), reply->msg().c_str(), ""
    );
    return ::protorpc::Error::Nil();
  }
  virtual const ::protorpc::Error EchoTwice(
    const ::service::EchoRequest* args,
    ::service::EchoResponse* reply
  ) {
    reply->set_msg(args->msg() + args->msg());
    printf("EchoService.EchoTwice: args = msg:\"%s\", reply = msg:\"%s\", err = \"%s\"\n",
      args->msg().c_str(), reply->msg().c_str(), ""
    );
    return ::protorpc::Error::Nil();
  }
};

int main() {
  ::protorpc::Server server;

  server.AddService(new ArithService, true);
  server.AddService(new EchoService, true);

  server.BindAndServe(1234);
  return 0;
}
