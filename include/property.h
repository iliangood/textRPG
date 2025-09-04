#if !defined PROPERTY_H
#define PROPERTY_H

#include <string>

using namespace std;

class Property
{
	string name;
	string desctription;
	bool hidden;
public:
	string getName();
	string getDescription();
	bool getHidden();
};
#endif
