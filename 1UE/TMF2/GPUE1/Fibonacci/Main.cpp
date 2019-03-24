#include <iostream>
#include <string>
#include <chrono>

#include "Fibonacci.h"
#include "IF.h"
#include "DO.h"
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
	// a)
	cout << "++++++ a):" << endl;
	cout << "+++ Compiletime:" << endl;
	measure("Fibonacci<40>::RET", []() { return Fibonacci<40>::RET; });

	cout << "+++ Runtime:" << endl;
	measure("fibonacci(40)", []() { return fibonacci(40); });

	cout << "++++++ b):" << endl;
	auto start = chrono::high_resolution_clock::now();
	DO<FibonacciStatement<0>, FibonacciEndCondition<40>>::exec();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "DO<FibonacciStatement<0>, FibonacciEndCondition<40>>::exec():[duration: " << duration.count() << "ms] " << endl;
	
	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 40; ++i) {
		cout << "fibonacci(" << i << ") = " << fibonacci(i) << endl;
	}
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << "fibonacci(1)...fibonacci(40):[duration: " << duration.count() << "ms] " << endl;

	return 0;
}