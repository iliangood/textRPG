#include "language/multiLocalizedString.h"

MultiLocalizedString::MultiLocalizedString(std::vector<LocalizedString> values) : values(std::move(values))
{}

std::vector<LocalizedString> MultiLocalizedString::getValues() const
{
	return values;
}

std::vector<std::string> MultiLocalizedString::getLanguages() const
{
	std::vector<std::string> languages;
	for (const auto& val : values)
	{
		languages.push_back(val.getLanguage().getLanguage());
	}
	return languages;
}

LocalizedString MultiLocalizedString::getValue(int index) const
{
	return values[index];
}

int MultiLocalizedString::getCount() const
{
	return values.size();
}