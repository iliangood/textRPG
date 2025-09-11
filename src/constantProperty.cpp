#include "constantProperty.h"

MultiLocalizedString* ConstantProperty::getName()
{
    return name;
}

MultiLocalizedString* ConstantProperty::getDescription()
{
    return description;
}

bool ConstantProperty::getHidden()
{
    return hidden;
}
