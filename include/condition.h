#if !defined CONDITTION_H
#define CONDITTION_H


#include <string>

#include "statusCodes.h"

#include "inventory.h"

using namespace std;

class Condition
{
	bool (*checkFunc)(void* data);
public:
	Condition((*CheckFunc)(void* data));
	bool check(void* data);
	bool check();
};
#endif
