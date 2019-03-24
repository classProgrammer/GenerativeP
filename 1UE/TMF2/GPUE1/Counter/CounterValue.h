#pragma once

template<int n>
struct IntValue {
	static const int value = n;
};

struct DoubleValue_0_5 {
	static const double value;
};

struct DoubleValue_3_4 {
	static const double value;
};

struct DoubleValue_0_85 {
	static const double value;
};

const double DoubleValue_0_5::value(0.5);
const double DoubleValue_3_4::value(3.4);
const double DoubleValue_0_85::value(0.85);