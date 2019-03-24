#include <iostream>
#include "Fibonacci.h"
#include <string>
#include <chrono>
#include "IF.h"
#include "DO.h"
#include "Counter.h"
#include "BoundedCounter.h"
#include "Configurations.h"
#include "Values.h"
using namespace std;

template<typename Func>
void measure(string s, Func func) {
	auto start = chrono::high_resolution_clock::now();
	auto fib = func();
	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double, milli> duration = end - start;
	cout << "[duration: " << duration.count() << "ms] " << s << " = " << fib << endl;
}

int main(int argc, char *argv) {

	/*cout << "+++ Compiletime:" << endl;
	measure("Fibonacci<40>::RET", []() { return Fibonacci<40>::RET; });

	cout << "+++ Runtime:" << endl;
	measure("fibonacci(40)", []() { return fibonacci(40); });*/

	//for (int i = 0; i < 40; ++i) {
	//	measure("", [i]() { return fibonacci(i); });
	//}

	//DO<FibonacciStatement<20>, FibonacciEndCondition<40>>::exec();

	//for (int i = 20; i < 40; ++i) {
	//	cout << "fibonacci(" << i << ") = " << fibonacci(i) << endl;
	//}

	//typedef IntCounterConfig<IntValue<0>>::Counter Counter;
	typedef BoundedIntCounterConfig<IntValue<0>, IntValue<5>>::Counter Counter;
	Counter counter;

	cout << counter.value() << endl;
	counter.increment();
	cout << counter.value() << endl;

	for (int i = 0; i < 10; ++i) {
		counter.increment();
	}

	cout << counter.value() << endl;


	return 0;
}