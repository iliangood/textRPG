#include "itemType.h"

ItemType::ItemType(string name, string description, vector<Property> properties)
{
	this->name = name;
	this->description = description;
	this->properties = properties;
}

string ItemType::getDescription() const
{
	return description;
}

string ItemType::getName() const
{
	return name;
}

vector<Property> ItemType::getProperties()
{
	return properties;
}

Property ItemType::getProperty(int index)
{
	return properties[index];
}
