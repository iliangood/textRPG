#include "language/language.h"

Language::Language(std::string language) : language(language)
{}

std::string Language::getLanguage() const
{
	return language;
}