// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#pragma once

#ifndef PROTORPC_SERVER_CONN_H__
#define PROTORPC_SERVER_CONN_H__

#include "protorpc/rpc_env.h"
#include "protorpc/rpc_conn.h"
#include "protorpc/rpc_service.h"

namespace protorpc {

class Server;

class ServerConn {
 public:
  static void Serve(Server* server, Conn* conn, Env* env);

 private:
  ServerConn(Server* server, Conn* conn, Env* env);
  ~ServerConn();

  static void ServeProc(void* p);
  Error ProcessOneCall(Conn* receiver);

  const ::protorpc::Error callMethod(
    const std::string& method,
    const ::google::protobuf::Message* request,
    ::google::protobuf::Message* response);

  Server* server_;
  Conn* conn_;
  Env* env_;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ServerConn);
};

}  // namespace protorpc

#endif  // PROTORPC_SERVER_CONN_H__

