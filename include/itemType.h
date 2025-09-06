#if !defined ITEM_TYPE_H
#define ITEM_TYPE_H

#include <string>
#include <vector>

#include "statusCodes.h"
#include "constantProperty.h"


class ItemType
{
	std::string name;
	std::string description;
	std::vector<ConstantProperty*> properties;
	bool uniqueItem; //Должен ли быть предмет уникальным
public:
	ItemType(std::string name, std::string description, std::vector<ConstantProperty*> properties, bool uniqueItem = false);

	std::string getDescription() const; //Получить описание предмета

	std::string getName() const; //Получить имя предмета

	std::vector<ConstantProperty*> getConstantProperties() const; // Получить свойства предмета

	bool itemIsUnique() const; // Узнать должен ли предмет быть уникальным

	ConstantProperty* getConstantProperty(int index) const;
};
#endif
