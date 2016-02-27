# Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(PROTORPC)

set(protobuf_source_dir ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/protobuf-3.0.0-beta-2)

include_directories(AFTER ${protobuf_source_dir}/src)

include(libprotobuf-lite.cmake)
include(libprotobuf.cmake)
include(libprotoc.cmake)

add_executable(hiuis3hello
	./examples/hello.cc
    
	${libprotobuf_lite_files}
	${libprotobuf_files}
)
