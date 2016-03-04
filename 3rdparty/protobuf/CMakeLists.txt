# Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(PROTOBUF)

# -----------------------------------------------------------------------------

if(NOT WIN32)
	add_definitions(-DHAVE_PTHREAD)
endif()

set(protobuf_source_dir ${CMAKE_CURRENT_SOURCE_DIR}/protobuf-3.0.0-beta-2)
include_directories(AFTER ${protobuf_source_dir}/src)

include(libprotobuf-lite.cmake)
include(libprotobuf.cmake)
include(libprotoc.cmake)

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

install(TARGETS libprotobuf_lite libprotobuf libprotoc
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
)

add_executable(protoc
	${protobuf_source_dir}/src/google/protobuf/compiler/main.cc
)
target_link_libraries(protoc
	libprotoc
)
install(TARGETS protoc
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
)
