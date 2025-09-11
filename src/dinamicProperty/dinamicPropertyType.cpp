#include "dinamicProperty/dinamicPropertyType.h"

DinamicPropertyType::DinamicPropertyType(MultiLocalizedString* name, MultiLocalizedString* description, DinamicPropertyTypeEnum type, bool hidden)
	: name(std::move(name)), description(std::move(description)), type(type), hidden(hidden)
{}

MultiLocalizedString* DinamicPropertyType::getName() const
{
	return name;
}

MultiLocalizedString* DinamicPropertyType::getDescription() const
{
	return description;
}

DinamicPropertyTypeEnum DinamicPropertyType::getType() const
{
	return type;
}

bool DinamicPropertyType::isHidden() const
{
	return hidden;
}
