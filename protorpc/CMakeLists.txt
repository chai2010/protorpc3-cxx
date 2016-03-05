# Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(PROTORPC)

# -----------------------------------------------------------------------------

if(NOT WIN32)
	add_definitions(-DHAVE_PTHREAD)
endif()

if(NOT MSVC)
	set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()

# -----------------------------------------------------------------------------
# 3rdparty

# Protobuf
set(PROTOBUF_ROOT ${CMAKE_SOURCE_DIR}/3rdparty/protobuf)
include_directories(AFTER ${PROTOBUF_ROOT}/protobuf-3.0.0-beta-2/src)

# cc-mini-test
set(CC_MINI_TEST_ROOT ${CMAKE_SOURCE_DIR}/3rdparty/cc-mini-test)
include_directories(AFTER ${CC_MINI_TEST_ROOT})

# -----------------------------------------------------------------------------
# protorpc

include_directories(AFTER
	./src
)

set(PROTORPC_HDR
	./src/protorpc/wire.pb/wire.pb.h
	./src/protorpc/rpc_service.h
	./src/protorpc/rpc_server.h
	./src/protorpc/rpc_server_conn.h
	./src/protorpc/rpc_client.h
	./src/protorpc/rpc_wire.h
	./src/protorpc/rpc_conn.h

	./src/protorpc/rpc_env.h
	./src/protorpc/rpc_crc32.h

	./src/protorpc/snappy/protorpc-snappy.h
)
set(PROTORPC_SRC
	./src/protorpc/wire.pb/wire.pb.cc
	./src/protorpc/rpc_service.cc
	./src/protorpc/rpc_server.cc
	./src/protorpc/rpc_server_conn.cc
	./src/protorpc/rpc_client.cc
	./src/protorpc/rpc_wire.cc
	./src/protorpc/rpc_conn.cc

	./src/protorpc/rpc_env.cc
	./src/protorpc/rpc_crc32.cc

	./src/protorpc/snappy/protorpc-snappy.cc
	./src/protorpc/snappy/protorpc-snappy-sinksource.cc
	./src/protorpc/snappy/protorpc-snappy-stubs-internal.cc
)

add_library(libprotorpc
	${PROTORPC_SRC}
	${PROTORPC_HDR}
)
target_link_libraries(libprotorpc
	libprotobuf
)
install(TARGETS libprotorpc
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
)

add_executable(protoc-gen-protorpc
	./src/protorpc/compiler/protorpc_plugin_helpers.h
	./src/protorpc/compiler/protorpc_plugin.h
	./src/protorpc/compiler/protorpc_plugin.cc
	./src/protorpc/compiler/protorpc_generator.h
	./src/protorpc/compiler/protorpc_generator_header.cc
	./src/protorpc/compiler/protorpc_generator_source.cc
	./src/protorpc/compiler/main.cc
)
target_link_libraries(protoc-gen-protorpc
	libprotoc
)
install(TARGETS protoc-gen-protorpc
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
)

# -----------------------------------------------------------------------------

add_executable(protorpc-test
	./examples/arith_test.cc
	./examples/echo_test.cc

	./examples/service.pb/arith.pb.h
	./examples/service.pb/arith.pb.cc
	./examples/service.pb/arith.protorpc.h
	./examples/service.pb/arith.protorpc.cc
	./examples/service.pb/echo.pb.h
	./examples/service.pb/echo.pb.cc
	./examples/service.pb/echo.protorpc.h
	./examples/service.pb/echo.protorpc.cc
)
target_link_libraries(protorpc-test
	libprotorpc
	cc-mini-test
)
install(TARGETS protorpc-test
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
)

add_executable(protorpc-server
	./examples/rpcserver.cc
	./examples/service.pb/arith.pb.h
	./examples/service.pb/arith.pb.cc
	./examples/service.pb/arith.protorpc.h
	./examples/service.pb/arith.protorpc.cc
	./examples/service.pb/echo.pb.h
	./examples/service.pb/echo.pb.cc
	./examples/service.pb/echo.protorpc.h
	./examples/service.pb/echo.protorpc.cc
)
target_link_libraries(protorpc-server
	libprotorpc
)
install(TARGETS protorpc-server
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
)

add_executable(protorpc-client
	./examples/rpcclient.cc
	./examples/service.pb/arith.pb.h
	./examples/service.pb/arith.pb.cc
	./examples/service.pb/arith.protorpc.h
	./examples/service.pb/arith.protorpc.cc
	./examples/service.pb/echo.pb.h
	./examples/service.pb/echo.pb.cc
	./examples/service.pb/echo.protorpc.h
	./examples/service.pb/echo.protorpc.cc
)
target_link_libraries(protorpc-client
	libprotorpc
)
install(TARGETS protorpc-client
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
)

# -----------------------------------------------------------------------------
