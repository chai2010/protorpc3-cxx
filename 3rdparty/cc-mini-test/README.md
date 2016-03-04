# C++ Mini UnitTest and Benchmark Library

This package implements a C++ mini unittest and benchmark library.

Talk: [C++迷你单元测试和基准测试库](http://go-talks.appspot.com/github.com/chai2010/talks/chai2010-cc-mini-test-intro.slide) .

## Unittest

Use `TEST` define a unit test:

	#include "test.h"

	// 1, 1, 2, 3, 5, ...
	int Fibonacci(int i) {
		return (i < 2)? 1: Fibonacci(i-1) + Fibonacci(i-2);
	}

	TEST(Fibonacci, Simple) {
		ASSERT_TRUE(Fibonacci(0) == 1);
		ASSERT_TRUE(Fibonacci(1) == 1);
		ASSERT_TRUE(Fibonacci(2) == 2);
		ASSERT_TRUE(Fibonacci(3) == 3);
		ASSERT_TRUE(Fibonacci(4) == 5);
		ASSERT_TRUE(Fibonacci(5) == 8);
	}

	TEST(Fibonacci, All) {
		static const int fib[] = { 1, 1, 2, 3, 5, ... };
		for(int i = 0; i < sizeof(fib)/sizeof(fib[0]); ++i) {
			ASSERT_TRUE_MSG(Fibonacci(i) == fib[i],
				"failed on fib[%d], expected = %d, got = %d",
				i, fib[i], Fibonacci(i)
			);
		}
	}

Run test: `./a.out` (or `./a.out -test=regexp`):

	[test] Fibonacci.Simple ok
	[test] Fibonacci.All ok
	PASS


## Benchmark

Use `BENCH` define a bench test:

	BENCH(Fibonacci, 5) {
		for(int i = 0; i < BenchN(); ++i) {
			Fibonacci(5);
		}
	}
	BENCH(Fibonacci, 10) {
		for(int i = 0; i < BenchN(); ++i) {
			Fibonacci(10);
		}
	}
	BENCH(Fibonacci, 15) {
		for(int i = 0; i < BenchN(); ++i) {
			Fibonacci(15);
		}
	}

Run benchmark: `./a.out -test.bench`:

	[bench] Fibonacci.5 20000000 65.5 ns/op
	[bench] Fibonacci.10 2000000 763 ns/op
	[bench] Fibonacci.15 200000 8740 ns/op

The output means that the loop ran 20000000 times at a speed of 65.5 ns per loop.

If a benchmark needs some expensive setup before running, the timer may be reset:

	BENCH(Name, case1) {
		auto big = NewBig();
		BenchResetTimer();

		for(int i = 0; i < BenchN(); ++i) {
			big.Len();
		}
	}

	BENCH(Name, case2) {
		BenchStopTimer();
		auto big = NewBig();
		BenchStartTimer();

		for(int i = 0; i < BenchN(); ++i) {
			big.Len();
		}
		BenchStopTimer();
		delete big;
	}


## Init and Exit

We can use `INIT` define a init func, and use `EXIT` define a exit func:

	INIT(Fibonacci, init) {
		// do some init work
	}
	EXIT(Fibonacci, exit) {
		// do some clean work
	}

The init funcs run before the tests, the exit funcs run after the tests.

## Usage

	./a.out -help
	usage: a.out
	  [-list=.*]
	  [-test=.*]
	  [-test.bench=]
	  [-test.benchtime=1second]
	  [-help]
	  [-h]

## BUGS

Please report bugs to <chaishushan@gmail.com>.

Thanks!
