#pragma once

template<typename BaseCounter>
class BoundedCounter : public BaseCounter {
public:
	typedef typename BaseCounter::Config Config;
private:
	typedef typename Config::ValueType ValueType;

protected:
	ValueType *bound_;

public:

	BoundedCounter() {
		bound_ = new ValueType(Config::Bound::value);
	}

	~BoundedCounter() {
		delete bound_;
	}

	void increment() {
		if (BaseCounter::value() < *bound_) BaseCounter::increment();
	}
};