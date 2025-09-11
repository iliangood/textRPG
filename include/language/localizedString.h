#if !defined LOCALIZED_STRING_H
#define LOCALIZED_STRING_H

#include <string>

#include "language/language.h"

class LocalizedString
{
	std::string value;
	Language* language;
public:
	LocalizedString(std::string value, Language* language);
	std::string getString() const;
	Language* getLanguage() const;
	bool hasSubstring(std::string substring) const; // Проверяет, есть ли в строке подстрока
};

#endif