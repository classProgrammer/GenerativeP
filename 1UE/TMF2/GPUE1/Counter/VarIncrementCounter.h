#pragma once

template<typename BaseCounter>
class VarIncrementCounter : public BaseCounter {
public:
	typedef typename BaseCounter::Config Config;
private:
	typedef typename Config::ValueType ValueType;

protected:
	ValueType *step_size_;

public:
	VarIncrementCounter() {
		step_size_ = new ValueType(Config::Step::value);
	}

	~VarIncrementCounter() {
		delete step_size_;
	}

	void increment() {
		*BaseCounter::value_ += *step_size_;
	}
};