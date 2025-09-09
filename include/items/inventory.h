#include <future>
#if !defined INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <optional>

#include "statusCodes.h"

#include "items/itemStack.h"


class Inventory
{
	std::vector<ItemStack> itemStacks;
public:
	Inventory(){}

	std::vector<ItemStack>* getItemStacks(); //Получить все ячейки инвентаря

	bool isExistence(ItemType item);

	std::optional<std::string> getName(size_t index) const; //Получить имя предмета(ов) в определенной ячеке инвентаря

	std::vector<std::string> getNames() const; //Получить имена всех предметов в инвентаре

	std::optional<std::string> getDescription(size_t index) const; //Получить описание предмета(ов) в определенной ячейке инвентаря

	std::optional<const ItemStack*> getItemStack(size_t index) const; //Получить определенную ячейку инвентаря

	std::optional<const ItemType*> getItemType(size_t index) const; //Получить тип предмета в определенной ячейке

	size_t getCount() const; //Подсчитать количество ячеек инвентаря

	size_t getTotalCount() const; //Подсчитать общее количество предметов в инвентаре

	size_t getCount(size_t index) const; //Подсчитать количество предметов в определенной ячейке инвентаря

	bool isEmpty() const; //Проверит пустой ли инвентарь

	std::optional<size_t> findFirstIndex(ItemType* item) const; //Поиск индекса предмета по предмету

	std::optional<size_t> findFirstIndex(std::string name) const; //Поиск первого индекса предмета по имени предмета
	
	std::vector<size_t> findIndexes(std::string name) const; //Поиск всех индексов предмета по имени предмета

	int push(ItemType* item, size_t count); //Положить предмет(ы) в инвентарь

	int uniquePush(ItemType* item); //Положить предмет если его не существует

	int pull(ItemType* item, size_t count); //Достать предметы из инвентаря
};
#endif
