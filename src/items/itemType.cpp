#include "items/itemType.h"

ItemType::ItemType(std::string name, std::string description, std::vector<ConstantProperty*> properties, 
	std::optional<std::vector<DinamicPropertyType*>> dinamicProperties, bool uniqueItem)
{
	this->name = name;
	this->description = description;
	this->properties = properties;
	this->uniqueItem = uniqueItem;
	this->dinamicProperties = dinamicProperties;
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

std::optional<ConstantProperty*> ItemType::getConstantProperty(size_t index) const
{
	if(index >= properties.size())
	{
		return std::nullopt;
	}
	return properties[index];
}

bool ItemType::itemIsUnique() const
{
	return uniqueItem;
}

int ItemType::addConstantProperty(ConstantProperty* property)
{
	
	properties.push_back(property);
	return OK;
}

int ItemType::removeConstantProperty(size_t index)
{
	if(index < 0 || index >= static_cast<int>(properties.size()))
	{
		return INCORRECT_INPUT;
	}
	properties.erase(properties.begin() + index);
	return OK;
}