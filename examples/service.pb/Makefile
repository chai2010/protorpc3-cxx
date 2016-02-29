# Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

default:
	../../bin/protoc3  --cpp_out=. arith.proto echo.proto
	../../bin/protoc3  --protorpc_out=. --plugin=protoc-gen-protorpc=../../bin/protoc-gen-protorpc arith.proto echo.proto
