// Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include "example.h"

#include <math.h>
#include <stdint.h>

int Sum(int a, int b) {
	return a+b;
}

// 1, 1, 2, 3, 5, ...
int FibonacciSlow(int i) {
	return (i < 2)? 1: FibonacciSlow(i-1) + FibonacciSlow(i-2);
}

// 1, 1, 2, 3, 5, ...
int FibonacciFast(int i) {
	static int fib[47];
	return (fib[i] != 0)? fib[i]: (
		fib[i] = (i < 2)? 1: FibonacciFast(i-1) + FibonacciFast(i-2)
	);
}

float FindMinValueSlow(float array[8]) {
	float minValue = array[0];
	for(int i = 1; i < 8; ++i) {
		if(fabsf(array[i]) < fabsf(minValue)) {
			minValue = array[i];
		}
	}
	return minValue;
}

float FindMinValueFast(float array[8]) {
	union MyFloat {
		struct ieee754 {
			uint32_t asLong:31;
			uint32_t sign:1;
		} raw;
		float f;
	};

	float minValue = array[0];
	uint32_t minValueAbs = ((MyFloat*)(&minValue))->raw.asLong;

	for(int i = 1; i < 8; ++i) {
		float v = array[i];
		uint32_t vAbs = ((MyFloat*)(&v))->raw.asLong;
		if(vAbs < minValueAbs) {
			minValue = v;
			minValueAbs = vAbs;
		}
	}
	return minValue;
}
