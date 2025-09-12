#if !defined ITEM_TYPE_H
#define ITEM_TYPE_H

#include <string>
#include <vector>
#include <optional>

#include "statusCodes.h"
#include "constantProperty.h"
#include "dinamicProperty/dinamicProperty.h"
#include "dinamicProperty/dinamicPropertyType.h"
#include "language/multiLocalizedString.h"


class ItemType
{
	MultiLocalizedString* name;
	MultiLocalizedString* description;
	std::vector<ConstantProperty*> properties;
	std::optional<std::vector<DinamicPropertyType*>> dinamicProperties;
public:
	ItemType(MultiLocalizedString* name, MultiLocalizedString* description, std::vector<ConstantProperty*> properties = {}, 
		std::optional<std::vector<DinamicPropertyType*>> dinamicProperties = std::nullopt);

	MultiLocalizedString* getDescription() const; //Получить описание предмета

	MultiLocalizedString* getName() const; //Получить имя предмета

	bool hasDinamicProperties() const; // Проверить есть ли у предмета динамические свойства

	std::vector<ConstantProperty*> getConstantProperties();// Получить свойства предмета

	std::optional<std::vector<DinamicPropertyType*>> getDinamicProperties();// Получить динамические свойства предмета

	std::optional<ConstantProperty*> getConstantProperty(size_t index); // Получить свойство предмета по индексу
	std::optional<ConstantProperty*> getConstantProperty(std::optional<size_t> index);

	std::optional<DinamicPropertyType*> getDinamicProperty(size_t index); // Получить динамическое свойство предмета по индексу
	std::optional<DinamicPropertyType*> getDinamicProperty(std::optional<size_t> index);

	StatusCode addConstantProperty(ConstantProperty* property); // Добавить свойство предмету
	StatusCode addConstantProperty(std::optional<ConstantProperty*> property);

	StatusCode removeConstantProperty(size_t index); // Убрать свойство предмета по индексу
	StatusCode removeConstantProperty(std::optional<size_t> index);

	StatusCode addDinamicProperty(DinamicPropertyType* property); // Добавить динамическое свойство предмету
	StatusCode addDinamicProperty(std::optional<DinamicPropertyType*> property);

	StatusCode removeDinamicProperty(size_t index); // Убрать динамическое свойство предмета по индексу
	StatusCode removeDinamicProperty(std::optional<size_t> index);

	bool checkConstantProperty(ConstantProperty* property) const; // Проверить есть ли у предмета такое свойство
	bool checkConstantProperty(std::optional<ConstantProperty*> property) const;

	bool checkDinamicProperty(DinamicPropertyType* property) const; // Проверить есть ли у предмета такое динамическое свойство
	bool checkDinamicProperty(std::optional<DinamicPropertyType*> property) const;
};
#endif
