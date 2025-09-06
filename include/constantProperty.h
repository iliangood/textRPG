#if !defined CONSTANT_PROPERTY_H
#define CONSTANT_PROPERTY_H

#include <string>


class ConstantProperty
{
	std::string name;
	std::string description;
	bool hidden;
public:
	std::string getName();
	std::string getDescription();
	bool getHidden();
};
#endif
