# Copyright 2016 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(PROTORPC_ALL)

# protorpc
set(PROTORPC_ROOT ${CMAKE_SOURCE_DIR}/protorpc/)
add_subdirectory(${PROTORPC_ROOT})

# Protobuf
set(PROTOBUF_ROOT ${CMAKE_SOURCE_DIR}/3rdparty/protobuf)
add_subdirectory(${PROTOBUF_ROOT})

# cc-mini-test
set(CC_MINI_TEST_ROOT ${CMAKE_SOURCE_DIR}/3rdparty/cc-mini-test)
add_subdirectory(${CC_MINI_TEST_ROOT})
