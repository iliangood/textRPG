#if !defined MULTI_LOCALIZED_STRING_H
#define MULTI_LOCALIZED_STRING_H

#include <vector>
#include <string>
#include <optional>

#include "language/localizedString.h"

class MultiLocalizedString
{
	std::vector<LocalizedString> values;
public:
	MultiLocalizedString(std::vector<LocalizedString> values);
	std::vector<LocalizedString> getValues() const;
	std::vector<std::string> getLanguages() const;
	std::optional<LocalizedString> getValue(size_t index) const;
	std::optional<LocalizedString> getValue(Language language) const;
	std::optional<std::string> getStringValue(Language language) const;
	std::optional<std::string> getStringValue(size_t index) const;
	size_t getCount() const;
	bool hasLanguage(Language language) const;
	int readFile(std::ifstream& file);
	int writeFile(std::ofstream& file) const;
	int readFile(FILE* file);
	int writeFile(FILE* file) const;
};

#endif