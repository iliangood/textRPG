#if !defined ITEM_H
#define ITEM_H

#include <string>
#include <vector>

#include "statusCodes.h"
#include "property.h"

using namespace std;

class Item
{
	string name;
	string description;
	vector<Property> properties;
public:
	Item(){}
	Item(string name, string description);

	string getDescription() const; //Получить описание предмета

	string getName() const; //Получить имя предмета
};
#endif
