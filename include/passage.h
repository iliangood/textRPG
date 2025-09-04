#if !defined PASSAGE_H
#define PASSAGE_H

#include <string>

#include "statusCodes.h"

#include "room.h"
#include "condition.h"

using namespace std;

class Passage
{
	Room* target;
	string description;
	Condition cond;
public:
	Passage();
	string getDescription();
};
#endif
