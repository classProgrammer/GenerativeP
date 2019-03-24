#pragma once


template<typename Config_>
class Counter {
public:
	typedef typename Config_::Config Config;

private:
	typedef typename Config::ValueType ValueType;

public:
	Counter() {
		value_ = new ValueType(Config::Init::value);
	}

	~Counter() {
		delete value_;
	}

	const ValueType &value() {
		return *value_;
	}

	void increment() {
		(*value_)++;
	}

	void reset() {
		delete value_;
		value_ = new ValueType(Config::Init::value);
	}

protected:
	ValueType *value_;

};