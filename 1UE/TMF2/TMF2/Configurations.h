#pragma once
#include "Counter.h"
#include "BoundedCounter.h"

template<typename Init_> 
struct IntCounterConfig {
	typedef int ValueType;
	typedef Init_ Init;
	typedef IntCounterConfig Config;
	typedef Counter<IntCounterConfig> Counter;
};

template<typename Init_, typename Bound_>
struct BoundedIntCounterConfig {
	typedef int ValueType;
	typedef Init_ Init;
	typedef Bound_ Bound;
	typedef BoundedIntCounterConfig Config;
	typedef BoundedCounter<Counter<BoundedIntCounterConfig>> Counter;
};