#include "language/localizedString.h"

LocalizedString::LocalizedString(std::string value, Language* language) : value(value), language(language)
{}

std::string LocalizedString::getString() const
{
	return value;
}

Language* LocalizedString::getLanguage() const
{
	return language;
}

bool LocalizedString::hasSubstring(std::string substring) const
{
	return value.find(substring) != std::string::npos;
}