#if !defined LANGUAGE_H
#define LANGUAGE_H

#include <string>

class Language
{
	std::string language;
public:
	Language(std::string language);
	std::string getLanguage() const;
};

#endif 