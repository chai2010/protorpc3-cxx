# Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(PROTORPC)

if (NOT WIN32)
    add_definitions(-DHAVE_PTHREAD)
endif()

set(protobuf_source_dir ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/protobuf-3.0.0-beta-2)

include_directories(AFTER ${protobuf_source_dir}/src)

include(libprotobuf-lite.cmake)
include(libprotobuf.cmake)
include(libprotoc.cmake)

# snappy
set(SNAPPY_HDR
    ./src/protorpc/snappy/protorpc-snappy.h
)
set(SNAPPY_SRC
    ./src/protorpc/snappy/protorpc-snappy.cc
    ./src/protorpc/snappy/protorpc-snappy-sinksource.cc
    ./src/protorpc/snappy/protorpc-snappy-stubs-internal.cc
)

# rpc
set(PB_RPC_HDR
    ./src/protorpc/wire.pb/wire.pb.h
    ./src/protorpc/rpc_service.h
    ./src/protorpc/rpc_server.h
    ./src/protorpc/rpc_server_conn.h
    ./src/protorpc/rpc_client.h
    ./src/protorpc/rpc_wire.h
    ./src/protorpc/rpc_conn.h

    ./src/protorpc/rpc_env.h
    ./src/protorpc/rpc_crc32.h
)
set(PB_RPC_SRC
    ./src/protorpc/wire.pb/wire.pb.cc
    ./src/protorpc/rpc_service.cc
    ./src/protorpc/rpc_server.cc
    ./src/protorpc/rpc_server_conn.cc
    ./src/protorpc/rpc_client.cc
    ./src/protorpc/rpc_wire.cc
    ./src/protorpc/rpc_conn.cc

    ./src/protorpc/rpc_env.cc
    ./src/protorpc/rpc_crc32.cc
)

add_library(protorrpclib
	#${PB_RPC_SRC}
    #${PB_RPC_HDR}

    ${SNAPPY_SRC}
    ${SNAPPY_HDR}

	${libprotobuf_lite_files}
    ${libprotobuf_files}
)

add_executable(protoc3
    ${protobuf_source_dir}/src/google/protobuf/compiler/main.cc

    ${libprotobuf_lite_files}
    ${libprotobuf_files}
    ${libprotoc_files}
)

add_executable(protoc-gen-protorpc
	./examples/hello.cc

	${libprotobuf_lite_files}
    ${libprotobuf_files}
	${libprotoc_files}
)

add_executable(hiuis3hello
	./examples/hello.cc

	${libprotobuf_lite_files}
	${libprotobuf_files}
)
