#pragma once

template<typename BaseCounter>
class BoundedVarIncrementCounter : public BaseCounter {
public:
	typedef typename BaseCounter::Config Config;
private:
	typedef typename Config::ValueType ValueType;

protected:
	ValueType *bound_;
	ValueType *step_size_;
public:
	BoundedVarIncrementCounter() {
		bound_ = new ValueType(Config::Bound::value);
		step_size_ = new ValueType(Config::Step::value);
	}

	~BoundedVarIncrementCounter() {
		delete bound_;
		delete step_size_;
	}

	void increment() {
		if (BaseCounter::value() + *step_size_ <= *bound_)
			*BaseCounter::value_ += *step_size_;
		else *BaseCounter::value_ = *bound_;
	}
};