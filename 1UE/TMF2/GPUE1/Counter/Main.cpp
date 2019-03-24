#include <iostream>
#include <string>

#include "Counter.h"
#include "BoundedCounter.h"
#include "CounterConfig.h"
#include "CounterValue.h"
using namespace std;



int main() {
	//typedef BoundedIntCounterConfig<IntValue<0>, IntValue<5>>::Counter Counter;
	//typedef VarIncrementIntCounterConfig<IntValue<0>, IntValue<2>>::Counter Counter;
	//typedef BoundedDoubleCounterConfig<DoubleValue_0_5, DoubleValue_3_4>::Counter Counter;
	typedef BoundedVarIncrementDoubleCounterConfig<DoubleValue_0_5, DoubleValue_3_4, DoubleValue_0_85>::Counter Counter;
	Counter counter;

	cout << counter.value() << endl;
	//counter.increment();
	//cout << counter.value() << endl;

	for (int i = 0; i < 10; ++i) {
		counter.increment();
	}

	cout << counter.value() << endl;

	return 0;
}