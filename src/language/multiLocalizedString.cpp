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

int MultiLocalizedString::readFile(std::ifstream& file)
{
	int count;
	file.read((char*)(&count), sizeof(count));
	if (!file)
	{
		return FILE_ERROR;
	}

	for (int i = 0; i < count; i++)
	{
		int langLength;
		file.read((char*)(&langLength), sizeof(langLength));
		if (!file || langLength <= 0)
		{
			return INVALID_LENGTH_ERROR;
		}

		std::string lang(langLength, '\0');
		file.read(&lang[0], langLength);
		if (!file)
		{
			return READ_ERROR;
		}

		int valueLength;
		file.read((char*)(&valueLength), sizeof(valueLength));
		if (!file || valueLength < 0)
		{
			return INVALID_LENGTH_ERROR;
		}

		std::string value(valueLength, '\0');
		file.read(&value[0], valueLength);
		if (!file)
		{
			return READ_ERROR;
		}

		values.emplace_back(value, Language(lang));
	}

	return SUCCESS;
}

int MultiLocalizedString::writeFile(std::ofstream& file) const
{
	int count = values.size();
	file.write((const char*)(&count), sizeof(count));
	if (!file)
	{
		return FILE_ERROR;
	}

	for (int i = 0; i < count; ++i)
	{
		std::string lang = values[i].getLanguage().getLanguage();
		int langLength = lang.size();
		file.write((const char*)(&langLength), sizeof(langLength));
		if (!file)
		{
			return WRITE_ERROR;
		}

		file.write(lang.c_str(), langLength);
		if (!file)
		{
			return WRITE_ERROR;
		}

		std::string value = values[i].getValue();
		int valueLength = value.size();
		file.write((const char*)(&valueLength), sizeof(valueLength));
		if (!file)
		{
			return WRITE_ERROR;
		}

		file.write(value.c_str(), valueLength);
		if (!file)
		{
			return WRITE_ERROR;
		}
	}

	return SUCCESS;
}

int MultiLocalizedString::readFile(FILE* file)
{
	int count;
	if (fread(&count, sizeof(count), 1, file) != 1)
	{
		return FILE_ERROR;
	}

	for (int i = 0; i < count; ++i)
	{
		int langLength;
		if (fread(&langLength, sizeof(langLength), 1, file) != 1 || langLength <= 0)
		{
			return INVALID_LENGTH_ERROR;
		}

		std::string lang(langLength, '\0');
		if (fread(&lang[0], sizeof(char), langLength, file) != static_cast<size_t>(langLength))
		{
			return READ_ERROR;
		}

		int valueLength;
		if (fread(&valueLength, sizeof(valueLength), 1, file) != 1 || valueLength < 0)
		{
			return INVALID_LENGTH_ERROR;
		}

		std::string value(valueLength, '\0');
		if (fread(&value[0], sizeof(char), valueLength, file) != static_cast<size_t>(valueLength))
		{
			return READ_ERROR;
		}

		values.emplace_back(value, Language(lang));
	}

	return SUCCESS;
}

int MultiLocalizedString::writeFile(FILE* file) const
{
	int count = values.size();
	if (fwrite(&count, sizeof(count), 1, file) != 1)
	{
		return FILE_ERROR;
	}

	for (int i = 0; i < count; i++)
	{
		std::string lang = values[i].getLanguage().getLanguage();
		int langLength = lang.size();
		if (fwrite(&langLength, sizeof(langLength), 1, file) != 1)
		{
			return WRITE_ERROR;
		}
		if (fwrite(lang.c_str(), sizeof(char), langLength, file) != static_cast<size_t>(langLength))
		{
			return WRITE_ERROR;
		}

		std::string value = values[i].getValue();
		int valueLength = value.size();
		if (fwrite(&valueLength, sizeof(valueLength), 1, file) != 1)
		{
			return WRITE_ERROR;
		}

		if (fwrite(value.c_str(), sizeof(char), valueLength, file) != static_cast<size_t>(valueLength))
		{
			return WRITE_ERROR;
		}
	}

	return SUCCESS;
}