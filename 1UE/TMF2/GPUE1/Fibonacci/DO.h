#pragma once
#include "IF.h"

struct Stop {
	static void exec() { }
};

template<typename Statement, typename Condition>
struct DO {
	static void exec() {
		Statement::exec();

		IF<Condition::Code<Statement::Next>::RET,
			DO<Statement::Next, Condition>,
			Stop
		>::RET::exec();
	}
};