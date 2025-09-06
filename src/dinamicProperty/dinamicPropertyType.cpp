#include "dinamicProperty/dinamicPropertyType.h"

DinamicPropertyType::DinamicPropertyType(std::string name, std::string description, dinamicPropertyTypeEnum type, bool hidden)
	: name(std::move(name)), description(std::move(description)), type(type), hidden(hidden)
{}

std::string DinamicPropertyType::getName() const
{
	return name;
}

std::string DinamicPropertyType::getDescription() const
{
	return description;
}

dinamicPropertyTypeEnum DinamicPropertyType::getType() const
{
	return type;
}

bool DinamicPropertyType::isHidden() const
{
	return hidden;
}
