#include <future>
#if !defined INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>

#include "inventoryCell.h"

using namespace std;

class Inventory
{
	vector<InventoryCell> inventoryCells;
public:
	string getName(int index) const; //Получить имя предмета(ов) в определенной ячеке инвентаря

	vector<string> getNames() const; //Получить имена всех предметов в инвентаре

	vector<InventoryCell> getInventoryCells() const; //Получить все ячейки инвентаря

	string getDescription(int index) const; //Получить описание предмета(ов) в определенной ячейке инвентаря

	InventoryCell getInventoryCell(int index) const; //Получить ячейку определенную инвентаря

	int getCount() const; //Подсчитать количество ячеек инвентаря

	int getTotalCount() const; //Подсчитать общее количество предметов в инвентаре

	int getCount(int index) const; //Подсчитать количество предметов в определенной ячейке инвентаря

	bool isEmpty() const; //Проверит пустой ли инвентарь

	int findIndex(string name) const; //Поиск индекса предмета по имени предмета, если предмета еще нет в инвенторе то возвращает -1

	int push(string name, int count); //Положить предмет(ы) в инвентарь, всегда возвращает 0

	int pull(string name, int count); //Достать предметы из инвентаря, возвращает 0 при успехе, 1 если недостаточно предметов
};
#endif
