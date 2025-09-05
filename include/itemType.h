#if !defined ITEM_TYPE_H
#define ITEM_TYPE_H

#include <string>
#include <vector>

#include "statusCodes.h"
#include "constantProperty.h"

using namespace std;

class ItemType
{
	string name;
	string description;
	vector<ConstantProperty*> properties;
	bool uniqueItem; //Должен ли быть предмет уникальным
public:
	ItemType(string name, string description, vector<ConstantProperty*> properties, bool uniqueItem = false);

	string getDescription() const; //Получить описание предмета

	string getName() const; //Получить имя предмета

	vector<ConstantProperty*> getConstantProperties() const; // Получить свойства предмета

	bool itemIsUnique() const; // Узнать должен ли предмет быть уникальным

	ConstantProperty* getConstantProperty(int index) const;
};
#endif
