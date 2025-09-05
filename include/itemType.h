#if !defined ITEM_H
#define ITEM_H

#include <string>
#include <vector>

#include "statusCodes.h"
#include "property.h"

using namespace std;

class ItemType
{
	string name;
	string description;
	vector<Property> properties;
public:
	ItemType(string name, string description, vector<Property> properties);

	string getDescription() const; //Получить описание предмета

	string getName() const; //Получить имя предмета

	vector<Property> getProperties();

	Property getProperty(int index);
};
#endif
