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

	std::vector<LocalizedString> getValues() const; // Получить на все локализации

	std::vector<std::string> getLanguages() const; // Получить список всех языков, на которые переведена строка

	std::optional<LocalizedString> getValue(size_t index) const; // Получить строку по индексу

	std::optional<LocalizedString> getValue(Language language) const; // Получить строку с локализацией по языку

	std::optional<std::string> getStringValue(Language language) const; // Получить строковое значение по языку

	std::optional<std::string> getStringValue(size_t index) const; // Получить строковое значение по индексу

	size_t getCount() const; // Получить количество локализаций

	bool hasLanguage(Language language) const; // Проверить есть ли локализация на такой язык

	int readFile(std::ifstream& file); // Получить из файла

	int writeFile(std::ofstream& file) const; // Записать в файл

	int readFile(FILE* file); // Получить из файла

	int writeFile(FILE* file) const; // Записать в файл
};

#endif