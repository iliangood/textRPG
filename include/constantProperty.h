#if !defined CONSTANT_PROPERTY_H
#define CONSTANT_PROPERTY_H

#include <string>

using namespace std;

class ConstantProperty
{
	string name;
	string description;
	bool hidden;
public:
	string getName();
	string getDescription();
	bool getHidden();
};
#endif
