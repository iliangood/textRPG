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

	std::vector<ConstantProperty*> getConstantProperties() const; // Получить свойства предмета

	std::optional<std::vector<DinamicPropertyType*>> getDinamicProperties() const; // Получить динамические свойства предмета

	int addConstantProperty(ConstantProperty* property); // Добавить свойство предмету

	int removeConstantProperty(size_t index); // Убрать свойство предмета по индексу

	int addDinamicProperty(DinamicPropertyType* property); // Добавить динамическое свойство предмету

	int removeDinamicProperty(size_t index); // Убрать динамическое свойство предмета по индексу

	bool itemIsUnique() const; // Узнать должен ли предмет быть уникальным

	std::optional<ConstantProperty*> getConstantProperty(size_t index) const; // Получить свойство предмета по индексу

	bool checkProperty(ConstantProperty* property) const; // Проверить есть ли у предмета свойство с таким именем
};
#endif
