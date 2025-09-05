#include <future>
#if !defined INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>

#include "statusCodes.h"

#include "itemStack.h"

using namespace std;

class Inventory
{
	vector<ItemStack> itemStacks;
public:
	Inventory(){}

	vector<ItemStack> getItemStacks() const;

	bool isExistence(ItemType item);

	string getName(int index) const; //Получить имя предмета(ов) в определенной ячеке инвентаря

	vector<string> getNames() const; //Получить имена всех предметов в инвентаре

	vector<ItemStack> getItemStack() const; //Получить все ячейки инвентаря

	string getDescription(int index) const; //Получить описание предмета(ов) в определенной ячейке инвентаря

	ItemStack getItemStack(int index) const; //Получить определенную ячейку инвентаря

	ItemType* getItemType(int index) const; //Получить тип предмета в определенной ячейке

	int getCount() const; //Подсчитать количество ячеек инвентаря

	int getTotalCount() const; //Подсчитать общее количество предметов в инвентаре

	int getCount(int index) const; //Подсчитать количество предметов в определенной ячейке инвентаря

	bool isEmpty() const; //Проверит пустой ли инвентарь

	int findIndex(ItemType* item) const; //Поиск индекса предмета по предмету

	int findIndex(string name) const; //Поиск индекса предмета по имени предмета

	int push(ItemType* item, int count); //Положить предмет(ы) в инвентарь

	int uniquePush(ItemType* item); //Положить предмет если его не существует

	int pull(ItemType* item, int count); //Достать предметы из инвентаря
};
#endif
