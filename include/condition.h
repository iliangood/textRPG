#if !defined CONDITTION_H
#define CONDITTION_H


#include <string>

#include "statusCodes.h"

#include "inventory.h"

class Condition
{
	bool (*checkFunc)(void* data);
public:
	Condition(){}
	Condition(bool (*CheckFunc)(void* data));
	bool check(void* arg) const;
	bool check() const;
};
#endif
