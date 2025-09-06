#include "dinamicProperty/dinamicProperty.h"

dinamicProperty::dinamicProperty(DinamicPropertyType* type, dinamicPropertyValue value)
	: type(type), value(value)
{}

DinamicPropertyType* dinamicProperty::getType() const
{
	return type;
}

std::string dinamicProperty::getName() const
{
	return type->getName();
}

std::string dinamicProperty::getDescription() const
{
	return type->getDescription();
}

dinamicPropertyTypeEnum dinamicProperty::getValueType() const
{
	return type->getType();
}

bool dinamicProperty::isHidden() const
{
	return type->isHidden();
}

dinamicPropertyValue dinamicProperty::getValue() const
{
	return value;
}

void dinamicProperty::setValue(dinamicPropertyValue newValue)
{
	value = newValue;
}