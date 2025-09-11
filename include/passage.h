#if !defined PASSAGE_H
#define PASSAGE_H

#include <string>

#include "statusCodes.h"

class Room;

#include "room.h"
#include "condition.h"
#include "language/multiLocalizedString.h"

class Passage
{
	const Room* target;
	MultiLocalizedString* name;
	MultiLocalizedString* description;
	const Condition* CheckVisibility;
	const Condition* CheckAccessibility;
public:
	Passage(){}
	Passage(const Room* target, MultiLocalizedString* description, const Condition* CheckVisibility);
	MultiLocalizedString* getDescription() const;
	MultiLocalizedString* getName() const;
	bool checkVisibility() const;
	bool checkVisibility(void* arg) const;
	const Room* getTarget() const;
	bool checkAccessibility() const;
	bool checkAccessibility(void* arg) const;
};
#endif
