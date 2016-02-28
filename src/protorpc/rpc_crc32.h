// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#pragma once

#ifndef PROTORPC_CRC32_H__
#define PROTORPC_CRC32_H__

#include <stddef.h>
#include <stdint.h>

namespace protorpc {

// Return the crc32c of data[0,n-1]
uint32_t HashCRC32(const char* data, size_t n);

}  // namespace protorpc

#endif // PROTORPC_CRC32_H__

