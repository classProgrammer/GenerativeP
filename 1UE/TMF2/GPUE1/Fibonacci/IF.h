#pragma once
template<bool condition, typename Then, typename Else>
struct IF {
	typedef Then RET;
};

template<typename Then, typename Else>
struct IF<false, Then, Else> {
	typedef Else RET;
};
