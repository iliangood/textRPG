#include "condition.h"

bool Condition::check(void* data)
{
	return checkFunc(data);
}

bool Condition::check()
{
	return checkFunc(nullptr);
}
