#include "language/multiLocalizedString.h"

#include <fstream>
#include <cstdio>
#include <utility>

#include "statusCodes.h"

MultiLocalizedString::MultiLocalizedString(std::vector<LocalizedString> values) : values(std::move(values))
{}

std::vector<LocalizedString> MultiLocalizedString::getValues() const
{
	return values;
}

std::vector<std::string> MultiLocalizedString::getLanguages() const
{
	std::vector<std::string> languages;
	for (size_t i = 0; i < values.size(); ++i)
	{
		languages.push_back(values[i].getLanguage().getLanguage());
	}
	return languages;
}

std::optional<LocalizedString> MultiLocalizedString::getValue(size_t index) const
{
	if(index >= values.size())
	{
		return std::nullopt;
	}
	return values[index];
}

size_t MultiLocalizedString::getCount() const
{
	return values.size();
}

bool MultiLocalizedString::hasLanguage(Language language) const
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		if (values[i].getLanguage().getLanguage() == language.getLanguage())
		{
			return true;
		}
	}
	return false;
}

std::optional<LocalizedString> MultiLocalizedString::getValue(Language language) const
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		if (values[i].getLanguage().getLanguage() == language.getLanguage())
		{
			return values[i];
		}
	}
	return std::nullopt;
}

std::optional<std::string> MultiLocalizedString::getStringValue(Language language) const
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		if (values[i].getLanguage().getLanguage() == language.getLanguage())
		{
			return values[i].getValue();
		}
	}
	return std::nullopt;
}

std::optional<std::string> MultiLocalizedString::getStringValue(size_t index) const
{
	if (index < values.size())
	{
		return values[index].getValue();
	}
	return std::nullopt;
}