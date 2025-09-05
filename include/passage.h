#if !defined PASSAGE_H
#define PASSAGE_H

#include <string>

#include "statusCodes.h"

#include "room.h"
#include "condition.h"

using namespace std;

class Passage
{
	const Room* target;
	string description;
	const Condition* CheckVisibility;
public:
	Passage(){}
	Passage(const Room* target, string description, const Condition* CheckVisibility);
	string getDescription() const;
	bool checkVisibility() const;
	bool checkVisibility(void* arg) const;
};
#endif
