#include "language/localizedString.h"

LocalizedString::LocalizedString(std::string value, Language language) : value(value), language(language)
{}

std::string LocalizedString::getValue() const
{
	return value;
}

Language LocalizedString::getLanguage() const
{
	return language;
}