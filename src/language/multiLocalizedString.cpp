#include "language/multiLocalizedString.h"

#include <fstream>
#include <cstdio>
#include <utility>

#include "statusCodes.h"

MultiLocalizedString::MultiLocalizedString(std::vector<LocalizedString*> values) : values(std::move(values))
{}

std::vector<LocalizedString*> MultiLocalizedString::getValues() const
{
	return values;
}

std::vector<Language*> MultiLocalizedString::getLanguages() const
{
	std::vector<Language*> languages;
	for (size_t i = 0; i < values.size(); ++i)
	{
		languages.push_back(values[i]->getLanguage());
	}
	return languages;
}

std::optional<LocalizedString*> MultiLocalizedString::getValue(size_t index) const
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

bool MultiLocalizedString::hasLanguage(Language* language) const
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		if (values[i]->getLanguage() == language)
		{
			return true;
		}
	}
	return false;
}

std::optional<LocalizedString*> MultiLocalizedString::getValue(Language* language) const
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		if (values[i]->getLanguage() == language)
		{
			return values[i];
		}
	}
	return std::nullopt;
}

std::optional<std::string> MultiLocalizedString::getStringValue(Language* language) const
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		if (values[i]->getLanguage() == language)
		{
			return values[i]->getString();
		}
	}
	return std::nullopt;
}

std::optional<std::string> MultiLocalizedString::getStringValue(size_t index) const
{
	if (index < values.size())
	{
		return values[index]->getString();
	}
	return std::nullopt;
}

bool MultiLocalizedString::hasSubstring(std::string substring) const
{
	for (size_t i = 0; i < values.size(); i++)
	{
		if (values[i]->hasSubstring(substring))
		{
			return true;
		}
	}
	return false;
}

std::optional<size_t> MultiLocalizedString::findLocalization(Language* language) const
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		if (values[i]->getLanguage() == language)
		{
			return i;
		}
	}
	return std::nullopt;
}

int MultiLocalizedString::addLocalization(LocalizedString* localization)
{
	if(localization == nullptr)
	{
		return INCORRECT_INPUT; // Некорректный указатель
	}
	if (hasLanguage(localization->getLanguage()))
	{
		return  ALREADY_EXISTS;// Локализация на такой язык уже есть
	}
	values.push_back(localization);
	return OK;
}

int MultiLocalizedString::removeLocalization(size_t index)
{
	if (index >= values.size())
	{
		return NOT_EXISTS; // Индекс вне диапазона
	}
	values.erase(values.begin() + index);
	return OK;
}

int MultiLocalizedString::removeLocalization(Language* language)
{
	std::optional<size_t> index = findLocalization(language);
	if (!index.has_value())
	{
		return NOT_EXISTS; // Локализация на такой язык не найдена
	}
	values.erase(values.begin() + index.value());
	return OK;
}