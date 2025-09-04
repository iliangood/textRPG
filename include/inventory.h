#include <future>
#if !defined INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>

#include "statusCodes.h"

#include "inventoryCell.h"

using namespace std;

class Inventory
{
	vector<InventoryCell> inventoryCells;
public:
	Inventory(){}

	string getName(int index) const; //Получить имя предмета(ов) в определенной ячеке инвентаря

	vector<string> getNames() const; //Получить имена всех предметов в инвентаре

	vector<InventoryCell> getInventoryCells() const; //Получить все ячейки инвентаря

	string getDescription(int index) const; //Получить описание предмета(ов) в определенной ячейке инвентаря

	InventoryCell getInventoryCell(int index) const; //Получить ячейку определенную инвентаря

	int getCount() const; //Подсчитать количество ячеек инвентаря

	int getTotalCount() const; //Подсчитать общее количество предметов в инвентаре

	int getCount(int index) const; //Подсчитать количество предметов в определенной ячейке инвентаря

	bool isEmpty() const; //Проверит пустой ли инвентарь

	int findIndex(string name) const; //Поиск индекса предмета по имени предмета

	int push(string name, int count); //Положить предмет(ы) в инвентарь

	int uniquePush(string name); //Положить предмет если его не существует

	int pull(string name, int count); //Достать предметы из инвентаря
};
#endif
