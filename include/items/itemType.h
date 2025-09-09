#if !defined ITEM_TYPE_H
#define ITEM_TYPE_H

#include <string>
#include <vector>
#include <optional>

#include "statusCodes.h"
#include "constantProperty.h"
#include "dinamicProperty/dinamicProperty.h"
#include "dinamicProperty/dinamicPropertyType.h"


class ItemType
{
	std::string name;
	std::string description;
	std::vector<ConstantProperty*> properties;
	std::optional<std::vector<DinamicPropertyType*>> dinamicProperties;
	bool uniqueItem; //Должен ли быть предмет уникальным
public:
	ItemType(std::string name, std::string description, std::vector<ConstantProperty*> properties, 
		std::optional<std::vector<DinamicPropertyType*>> dinamicProperties = std::nullopt, bool uniqueItem = false);

	std::string getDescription() const; //Получить описание предмета

	std::string getName() const; //Получить имя предмета

	bool isUnique() const; // Узнать должен ли предмет быть уникальным

	std::vector<ConstantProperty*> getConstantProperties();// Получить свойства предмета

	std::optional<std::vector<DinamicPropertyType*>> getDinamicProperties();// Получить динамические свойства предмета

	std::optional<ConstantProperty*> getConstantProperty(size_t index); // Получить свойство предмета по индексу
	std::optional<ConstantProperty*> getConstantProperty(std::optional<size_t> index);

	std::optional<DinamicPropertyType*> getDinamicProperty(size_t index); // Получить динамическое свойство предмета по индексу
	std::optional<DinamicPropertyType*> getDinamicProperty(std::optional<size_t> index);

	int addConstantProperty(ConstantProperty* property); // Добавить свойство предмету
	int addConstantProperty(std::optional<ConstantProperty*> property);

	int removeConstantProperty(size_t index); // Убрать свойство предмета по индексу
	int removeConstantProperty(std::optional<size_t> index);

	int addDinamicProperty(DinamicPropertyType* property); // Добавить динамическое свойство предмету
	int addDinamicProperty(std::optional<DinamicPropertyType*> property);

	int removeDinamicProperty(size_t index); // Убрать динамическое свойство предмета по индексу
	int removeDinamicProperty(std::optional<size_t> index);

	bool checkConstantProperty(ConstantProperty* property) const; // Проверить есть ли у предмета такое свойство
	bool checkConstantProperty(std::optional<ConstantProperty*> property) const;

	bool checkDinamicProperty(DinamicPropertyType* property) const; // Проверить есть ли у предмета такое динамическое свойство
	bool checkDinamicProperty(std::optional<DinamicPropertyType*> property) const;
};
#endif
