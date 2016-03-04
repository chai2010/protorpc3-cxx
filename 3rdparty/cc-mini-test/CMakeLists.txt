# Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

project(TEST)

add_library(cc-mini-test
	./test.cc
	./test_main.cc
)

add_executable(cc-mini-test-example
	./example_test.cc
	./example.cc
)

target_link_libraries(cc-mini-test-example
	cc-mini-test
)

