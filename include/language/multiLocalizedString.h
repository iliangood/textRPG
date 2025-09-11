#if !defined MULTI_LOCALIZED_STRING_H
#define MULTI_LOCALIZED_STRING_H

#include <vector>
#include <string>
#include <optional>

#include "language/localizedString.h"
#include "language/language.h"

class MultiLocalizedString
{
	std::vector<LocalizedString*> values;
public:
	MultiLocalizedString(std::vector<LocalizedString*> values);

	std::vector<LocalizedString*> getValues() const; // Получить на все локализации

	std::vector<Language*> getLanguages() const; // Получить список всех языков, на которые переведена строка

	std::optional<LocalizedString*> getValue(size_t index) const; // Получить строку по индексу

	std::optional<LocalizedString*> getValue(Language* language) const; // Получить строку с локализацией по языку

	std::optional<std::string> getStringValue(Language* language) const; // Получить строковое значение по языку

	std::optional<std::string> getStringValue(size_t index) const; // Получить строковое значение по индексу

	size_t getCount() const; // Получить количество локализаций

	bool hasSubstring(std::string substring) const; // Проверяет, есть ли в какой-либо из строк подстрока

	bool hasLanguage(Language* language) const; // Проверить есть ли локализация на такой язык

	std::optional<size_t> findLocalization(Language* language) const; // Найти индекс локализации по языку

	int addLocalization(LocalizedString* localization); // Добавить локализацию

	int removeLocalization(size_t index); // Удалить локализацию по индексу

	int removeLocalization(Language* language); // Удалить локализацию по языку

	int readFile(std::ifstream& file); // Получить из файла TODO:

	int writeFile(std::ofstream& file) const; // Записать в файл TODO:

	int readFile(FILE* file); // Получить из файла TODO:

	int writeFile(FILE* file) const; // Записать в файл TODO:
};

#endif