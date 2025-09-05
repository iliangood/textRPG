#include "condition.h"

Condition::Condition(bool (*checkFunc)(void* data))
{
	this->checkFunc = checkFunc;
}

bool Condition::check(void* arg) const
{
	return checkFunc(data);
}

bool Condition::check() const
{
	return checkFunc(nullptr);
}
