#include "itemType.h"

ItemType::ItemType(string name, string description, vector<ConstantProperty*> properties, bool uniqueItem)
{
	this->name = name;
	this->description = description;
	this->properties = properties;
	this->uniqueItem = uniqueItem;
}

string ItemType::getDescription() const
{
	return description;
}

string ItemType::getName() const
{
	return name;
}

vector<ConstantProperty*> ItemType::getConstantProperties() const
{
	return properties;
}

ConstantProperty* ItemType::getConstantProperty(int index) const
{
	return properties[index];
}
