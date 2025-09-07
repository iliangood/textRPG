#if !defined LOCALIZED_STRING_H
#define LOCALIZED_STRING_H

#include <string>

#include "language/language.h"

class LocalizedString
{
	std::string value;
	Language language;
public:
	LocalizedString(std::string value, Language language);
	std::string getValue() const;
	Language getLanguage() const;
};

#endif