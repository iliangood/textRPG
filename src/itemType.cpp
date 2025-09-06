#include "itemType.h"

ItemType::ItemType(std::string name, std::string description, std::vector<ConstantProperty*> properties, bool uniqueItem)
{
	this->name = name;
	this->description = description;
	this->properties = properties;
	this->uniqueItem = uniqueItem;
}

std::string ItemType::getDescription() const
{
	return description;
}

std::string ItemType::getName() const
{
	return name;
}

std::vector<ConstantProperty*> ItemType::getConstantProperties() const
{
	return properties;
}

ConstantProperty* ItemType::getConstantProperty(int index) const
{
	return properties[index];
}
