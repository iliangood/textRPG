#include "dinamicProperty/dinamicProperty.h"

DinamicProperty::DinamicProperty(DinamicPropertyType* type, DinamicPropertyValue value)
	: type(type), value(value)
{}

DinamicPropertyType* DinamicProperty::getType() const
{
	return type;
}

MultiLocalizedString* DinamicProperty::getName() const
{
	return type->getName();
}

MultiLocalizedString* DinamicProperty::getDescription() const
{
	return type->getDescription();
}

DinamicPropertyTypeEnum DinamicProperty::getValueType() const
{
	return type->getType();
}

bool DinamicProperty::isHidden() const
{
	return type->isHidden();
}

DinamicPropertyValue DinamicProperty::getValue() const
{
	return value;
}

void DinamicProperty::setValue(DinamicPropertyValue newValue)
{
	value = newValue;
}