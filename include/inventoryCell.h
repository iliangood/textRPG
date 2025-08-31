#if !defined INVENTORYCELL_H
#define INVENTORYCELL_H

#include <string>

#include "item.h"

using namespace std;

class InventoryCell
{
	Item item;
	int count;
public:
	InventoryCell(){}
	InventoryCell(Item item, int count);

	string getName() const; //Получить имя предмета в ячейке

	string getDescription() const; //Получить описание предмета в ячейке

	Item getItem() const; //Получить объкт предмета

	int getCount() const; //Получить количество предметов в ячейке

	bool isEmpty() const; //Проверить ячейку на то, что она пуста

	int push(int count); //Положить count предметов в ячейку

	int pull(int count); //Взять count предметов из ячейки
};
#endif
