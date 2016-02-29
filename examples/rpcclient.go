// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package main

import (
	"fmt"
	"log"
	"net/rpc"

	"github.com/chai2010/protorpc"

	service "./service.pb/gopkg.pb"
)

func main() {
	var client *rpc.Client
	var err error

	client, err = protorpc.Dial("tcp", "127.0.0.1:1234")
	if err != nil {
		log.Fatal(err)
	}
	defer client.Close()

	arithStub := &service.ArithServiceClient{client}
	echoStub := &service.EchoServiceClient{client}

	var arithArgs service.ArithRequest
	var echoArgs service.EchoRequest

	// Add
	arithArgs.A = 1
	arithArgs.B = 2
	arithReply, err := arithStub.Add(&arithArgs)
	if err != nil {
		log.Fatalf(`arith.Add: %v`, err)
	}
	if arithReply.C != 3 {
		log.Fatalf(`arith.Add: expected = %d, got = %d`, 3, arithReply.C)
	}

	// Mul
	arithArgs.A = 2
	arithArgs.B = 3
	arithReply, err = arithStub.Mul(&arithArgs)
	if err != nil {
		log.Fatalf(`arith.Mul: %v`, err)
	}
	if arithReply.C != 6 {
		log.Fatalf(`arith.Mul: expected = %d, got = %d`, 6, arithReply.C)
	}

	// Div
	arithArgs.A = 13
	arithArgs.B = 5
	arithReply, err = arithStub.Div(&arithArgs)
	if err != nil {
		log.Fatalf(`arith.Div: %v`, err)
	}
	if arithReply.C != 2 {
		log.Fatalf(`arith.Div: expected = %d, got = %d`, 2, arithReply.C)
	}

	// Div zero
	arithArgs.A = 1
	arithArgs.B = 0
	arithReply, err = arithStub.Div(&arithArgs)
	if err.Error() != "divide by zero" {
		log.Fatalf(`arith.Div: expected = "%s", got = "%s"`, "divide by zero", err.Error())
	}

	// Error
	arithArgs.A = 1
	arithArgs.B = 2
	arithReply, err = arithStub.Error(&arithArgs)
	if err.Error() != "ArithError" {
		log.Fatalf(`arith.Error: expected = "%s", got = "%s"`, "ArithError", err.Error())
	}

	// EchoService.Echo
	echoArgs.Msg = "Hello, Protobuf-RPC"
	echoReply, err := echoStub.Echo(&echoArgs)
	if err != nil {
		log.Fatalf(`echoStub.Echo: %v`, err)
	}
	if echoArgs.Msg != echoReply.Msg {
		log.Fatalf(`echoStub.Echo: expected = "%s", got = "%s"`, echoArgs.Msg, echoReply.Msg)
	}

	fmt.Printf("Done\n")
}
