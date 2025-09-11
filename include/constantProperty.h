#if !defined CONSTANT_PROPERTY_H
#define CONSTANT_PROPERTY_H

#include <string>
#include "language/multiLocalizedString.h"


class ConstantProperty
{
	MultiLocalizedString* name;
	MultiLocalizedString* description;
	bool hidden;
public:
	MultiLocalizedString* getName();
	MultiLocalizedString* getDescription();
	bool getHidden();
};
#endif
