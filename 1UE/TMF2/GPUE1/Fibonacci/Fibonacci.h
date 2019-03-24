#ifndef Fibonacci_h
#define Fibonacci_h

// recursive function
int fibonacci(int n) { 
	return n == 0 ? 0 :
		n == 1 ? 1 :
		fibonacci(n - 1) + fibonacci(n - 2);
}

// partly specialized template
template<int n>
struct Fibonacci {
	enum { RET = Fibonacci<n - 1>::RET + Fibonacci<n - 2>::RET };
};

template<>
struct Fibonacci<1> {
	enum { RET = 1 };
};

template<>
struct Fibonacci<0> {
	enum { RET = 0 };
};

// fibonacci template for for-loop
template<int n>
struct FibonacciStatement {
	enum { current = n };
	static void exec() {
		std::cout << "Fibonacci<" << n << ">::RET = " << Fibonacci<n>::RET << std::endl;
	}

	typedef FibonacciStatement<n + 1> Next;
};

// fibonacci template end condition for for-loop
template<int max>
struct FibonacciEndCondition {

	template<typename Statement> // template in a template
	struct Code {
		enum { RET = Statement::current <= max };
	};
};

#endif