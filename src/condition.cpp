#include "condition.h"

Condition::Condition(bool (*checkFunc)(void* data))
{
	this->checkFunc = checkFunc;
}

bool Condition::check(void* arg) const
{
	return checkFunc(arg);
}

bool Condition::check() const
{
	return checkFunc(nullptr);
}
