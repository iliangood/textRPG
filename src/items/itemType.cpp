#include "items/itemType.h"

ItemType::ItemType(MultiLocalizedString* name, MultiLocalizedString* description, std::vector<ConstantProperty*> properties, 
	std::optional<std::vector<DinamicPropertyType*>> dinamicProperties)
{
	this->name = name;
	this->description = description;
	this->properties = properties;
	this->dinamicProperties = dinamicProperties;
}

MultiLocalizedString* ItemType::getDescription() const
{
	return description;
}

MultiLocalizedString* ItemType::getName() const
{
	return name;
}

std::vector<ConstantProperty*> ItemType::getConstantProperties()
{
	return properties;
}

std::optional<ConstantProperty*> ItemType::getConstantProperty(size_t index)
{
	if(index >= properties.size())
	{
		return std::nullopt;
	}
	return properties[index];
}

std::optional<ConstantProperty*> ItemType::getConstantProperty(std::optional<size_t> index)
{
	if(!index.has_value())
		return std::nullopt;
	return getConstantProperty(index.value());
}

bool ItemType::hasDinamicProperties() const
{
	return dinamicProperties.has_value();
}

StatusCode ItemType::addConstantProperty(ConstantProperty* property)
{
	
	properties.push_back(property);
	return StatusCode::OK;
}

StatusCode ItemType::addConstantProperty(std::optional<ConstantProperty*> property)
{
	if(!property.has_value())
		return StatusCode::INCORRECT_INPUT;
	return addConstantProperty(property.value());
}

StatusCode ItemType::removeConstantProperty(size_t index)
{
	if(index >= (properties.size()))
	{
		return StatusCode::INCORRECT_INPUT;
	}
	properties.erase(properties.begin() + index);
	return StatusCode::OK;
}

StatusCode ItemType::removeConstantProperty(std::optional<size_t> index)
{
	if(!index.has_value())
		return StatusCode::INCORRECT_INPUT;
	return removeConstantProperty(index.value());
}

std::optional<std::vector<DinamicPropertyType*>> ItemType::getDinamicProperties()
{
	return dinamicProperties;
}

StatusCode ItemType::addDinamicProperty(DinamicPropertyType* property)
{
	if(!dinamicProperties.has_value())
	{
		dinamicProperties = std::vector<DinamicPropertyType*>();
	}
	dinamicProperties.value().push_back(property);
	return StatusCode::OK;
}

StatusCode ItemType::addDinamicProperty(std::optional<DinamicPropertyType*> property)
{
	if(!property.has_value())
		return StatusCode::INCORRECT_INPUT;
	return addDinamicProperty(property.value());
}

StatusCode ItemType::removeDinamicProperty(size_t index)
{
	if(!dinamicProperties.has_value())
	return StatusCode::NOT_EXISTS;
	if(index >= dinamicProperties.value().size())
	{
		return StatusCode::INCORRECT_INPUT;
	}
	dinamicProperties.value().erase(dinamicProperties.value().begin() + index);
	return StatusCode::OK;
}

StatusCode ItemType::removeDinamicProperty(std::optional<size_t> index)
{
	if(!index.has_value())
		return StatusCode::INCORRECT_INPUT;
	return removeDinamicProperty(index.value());
}

bool ItemType::checkConstantProperty(ConstantProperty* property) const
{
	for(size_t i = 0; i < properties.size(); i++)
	{
		if(properties[i] == property)
			return true;
	}
	return false;
}

bool ItemType::checkConstantProperty(std::optional<ConstantProperty*> property) const
{
	if(!property.has_value())
		return false;
	return checkConstantProperty(property.value());
}

bool ItemType::checkDinamicProperty(DinamicPropertyType* property) const
{
	if(!dinamicProperties.has_value())
		return false;
	for(size_t i = 0; i < dinamicProperties.value().size(); i++)
	{
		if(dinamicProperties.value()[i] == property)
			return true;
	}
	return false;
}

bool ItemType::checkDinamicProperty(std::optional<DinamicPropertyType*> property) const
{
	if(!property.has_value())
		return false;
	return checkDinamicProperty(property.value());
}

std::optional<DinamicPropertyType*> ItemType::getDinamicProperty(size_t index)
{
	if(!dinamicProperties.has_value())
		return std::nullopt;
	if(index >= dinamicProperties.value().size())
	{
		return std::nullopt;
	}
	return dinamicProperties.value()[index];
}

std::optional<DinamicPropertyType*> ItemType::getDinamicProperty(std::optional<size_t> index)
{
	if(!index.has_value())
		return std::nullopt;
	return getDinamicProperty(index.value());
}