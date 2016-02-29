# Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(PROTORPC)

if(NOT WIN32)
	add_definitions(-DHAVE_PTHREAD)
endif()

set(protobuf_source_dir
	${CMAKE_CURRENT_SOURCE_DIR}/protobuf/protobuf-3.0.0-beta-2
)
include_directories(AFTER
	${protobuf_source_dir}/src
	./src
)

include(libprotobuf-lite.cmake)
include(libprotobuf.cmake)
include(libprotoc.cmake)

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

add_library(libprotobuf_lite
	${libprotobuf_lite_files}
)
add_library(libprotobuf
	${libprotobuf_lite_files}
	${libprotobuf_files}
)
add_library(libprotoc
	${libprotobuf_lite_files}
	${libprotobuf_files}
	${libprotoc_files}
)
add_library(libprotorpc
	${PROTORPC_SRC}
	${PROTORPC_HDR}

	${libprotobuf_lite_files}
	${libprotobuf_files}
)
install(TARGETS libprotobuf_lite libprotobuf libprotoc libprotorpc
	RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(protoc3
	${protobuf_source_dir}/src/google/protobuf/compiler/main.cc
)
target_link_libraries(protoc3
	libprotoc
)
install(TARGETS protoc3
	RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(protoc-gen-protorpc
	./src/protorpc/compiler/config.h
	./src/protorpc/compiler/generator_helpers.h
	./src/protorpc/compiler/cpp_generator_helpers.h
	./src/protorpc/compiler/cpp_generator.cc
	./src/protorpc/compiler/cpp_generator.h
	./src/protorpc/compiler/cpp_plugin.h
	./src/protorpc/compiler/cpp_plugin.cc
	./src/protorpc/compiler/main.cc
)
target_link_libraries(protoc-gen-protorpc
	libprotoc
)
install(TARGETS protoc-gen-protorpc
	RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(protorpc-test
	./examples/rpctest.cc
	./examples/service.pb/arith.pb.h
	./examples/service.pb/arith.pb.cc
	./examples/service.pb/arith.protorpc.golden.h
	./examples/service.pb/arith.protorpc.golden.cc
	./examples/service.pb/echo.pb.h
	./examples/service.pb/echo.pb.cc
	./examples/service.pb/echo.protorpc.golden.h
	./examples/service.pb/echo.protorpc.golden.cc
)
target_link_libraries(protorpc-test
	libprotorpc
)
install(TARGETS protorpc-test
	RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(protorpc-server
	./examples/rpcserver.cc
	./examples/service.pb/arith.pb.h
	./examples/service.pb/arith.pb.cc
	./examples/service.pb/arith.protorpc.golden.h
	./examples/service.pb/arith.protorpc.golden.cc
	./examples/service.pb/echo.pb.h
	./examples/service.pb/echo.pb.cc
	./examples/service.pb/echo.protorpc.golden.h
	./examples/service.pb/echo.protorpc.golden.cc
)
target_link_libraries(protorpc-server
	libprotorpc
)
install(TARGETS protorpc-server
	RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(protorpc-client
	./examples/rpcclient.cc
	./examples/service.pb/arith.pb.h
	./examples/service.pb/arith.pb.cc
	./examples/service.pb/arith.protorpc.golden.h
	./examples/service.pb/arith.protorpc.golden.cc
	./examples/service.pb/echo.pb.h
	./examples/service.pb/echo.pb.cc
	./examples/service.pb/echo.protorpc.golden.h
	./examples/service.pb/echo.protorpc.golden.cc
)
target_link_libraries(protorpc-client
	libprotorpc
)
install(TARGETS protorpc-client
	RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib
)
