#pragma once
#include "Counter.h"
#include "BoundedCounter.h"
#include "VarIncrementCounter.h"
#include "BoundedVarIncrementCounter.h"

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
	typedef BoundedIntCounterConfig Config;
	typedef BoundedCounter<Counter<BoundedIntCounterConfig>> Counter;
	typedef Bound_ Bound;
};

template<typename Init_, typename Step_>
struct VarIncrementIntCounterConfig {
	typedef int ValueType;
	typedef Init_ Init;
	typedef VarIncrementIntCounterConfig Config;
	typedef VarIncrementCounter<Counter<VarIncrementIntCounterConfig>> Counter;
	typedef Step_ Step;
};

template<typename Init_, typename Bound_>
struct BoundedDoubleCounterConfig{
	typedef double ValueType;
	typedef Init_ Init;
	typedef BoundedDoubleCounterConfig Config;
	typedef BoundedCounter<Counter<BoundedDoubleCounterConfig>> Counter;
	typedef Bound_ Bound;
};

template<typename Init_, typename Bound_, typename Step_>
struct BoundedVarIncrementDoubleCounterConfig {
	typedef double ValueType;
	typedef Init_ Init;
	typedef BoundedVarIncrementDoubleCounterConfig Config;
	typedef BoundedVarIncrementCounter<Counter<BoundedVarIncrementDoubleCounterConfig>> Counter;
	typedef Bound_ Bound;
	typedef Step_ Step;
};