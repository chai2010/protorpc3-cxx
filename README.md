# protorpc3-cxx

This package provides C++ Protobuf3-RPC support.

Go version: https://github.com/chai2010/protorpc

Talks: [Go/C++语言Protobuf-RPC简介](http://go-talks.appspot.com/github.com/chai2010/talks/chai2010-protorpc-intro.slide)

## Install

1. Install CMake and MSVC(Windows) or MinGW(Windows) or gcc(Unix)
2. cd `${protorpc_root}` and build with cmake

## Example

C++ use the same protocol as Go, so we can communication with C++ and Go with `Protobuf-RPC`.

Here is a simple proto file(`${protorpc_root}/examples/service.pb/echo.proto`):

```proto
syntax = "proto3";

package service;

option cc_generic_services = false;

message EchoRequest {
	string msg = 1;
}

message EchoResponse {
	string msg = 1;
}

service EchoService {
	rpc Echo (EchoRequest) returns (EchoResponse);
	rpc EchoTwice (EchoRequest) returns (EchoResponse);
}
```

For C++, must set `cc_generic_services` to `false`.

Then use `protoc` and `protoc-gen-protorpc` plugin to generate "arith.proto.{h|cc}" file(include rpc stub):

	protoc3 --protorpc_out=. --plugin=protoc-gen-protorpc=../../bin/protoc-gen-protorpc.exe echo.proto

The server calls (for TCP service):

```c++
#include "./service.pb/echo.protorpc.h"
	
class EchoService: public service::EchoService {
public:
	inline EchoService() {}
	virtual ~EchoService() {}

	virtual const google::protobuf::rpc::Error Echo(
		const service::EchoRequest* request,
		service::EchoResponse* response
	) {
		response->set_msg(request->msg());
		return google::protobuf::rpc::Error::Nil();
	}
};

int main() {
	::protorpc::Server server;

	server.AddService(new EchoService, true);

	server.Serve(9527);
}
```

At this point, clients can see a service `EchoService` with methods `EchoService.Echo`. To invoke one, a client first dials the server:

```c++
#include "./service.pb/echo.protorpc.h"

int main() {
	::protorpc::Client client("127.0.0.1", 1234);

	service::EchoService::Stub echoStub(&client);

	::service::EchoRequest echoArgs;
	::service::EchoResponse echoReply;
	::protorpc::Error err;
	
	// EchoService.Echo
	echoArgs.set_msg("Hello Protobuf-RPC!");
	err = echoStub.Echo(&echoArgs, &echoReply);
	if(!err.IsNil()) {
		fprintf(stderr, "echoStub.Echo: %s\n", err.String().c_str());
		return -1;
	}
	if(echoReply.msg() != echoArgs.msg()) {
		fprintf(stderr, "echoStub.Echo: expected = \"%s\", got = \"%s\"\n",
			echoArgs.msg().c_str(), echoReply.msg().c_str()
		);
		return -1;
	}

	// EchoService.Echo: Use Client
	echoArgs.set_msg("Hello Protobuf-RPC!");
	err = client.CallMethod("EchoService.Echo", &echoArgs, &echoReply);
	if(!err.IsNil()) {
		fprintf(stderr, "EchoService.Echo: %s\n", err.String().c_str());
		return -1;
	}
	if(echoReply.msg() != echoArgs.msg()) {
		fprintf(stderr, "EchoService.Echo: expected = \"%s\", got = \"%s\"\n",
			echoArgs.msg().c_str(), echoReply.msg().c_str()
		);
		return -1;
	}
	
	return 0;
}
```

## BUGS

Please report bugs to <chaishushan@gmail.com>.

Thanks!
