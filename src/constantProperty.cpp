#include "constantProperty.h"

std::string ConstantProperty::getName()
{
    return name;
}

std::string ConstantProperty::getDescription()
{
    return description;
}

bool ConstantProperty::getHidden()
{
    return hidden;
}
