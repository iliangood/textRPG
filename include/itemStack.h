#if !defined ITEM_STACK_H
#define ITEM_STACK_H

#include <string>

#include "statusCodes.h"

#include "itemType.h"


class ItemStack
{
	ItemType *item;
	int count;
public:
	ItemStack(){}
	ItemStack(ItemType *item, int count);

	std::string getName() const; //Получить имя предмета в ячейке

	std::string getDescription() const; //Получить описание предмета в ячейке

	ItemType* getItem() const; //Получить объкт предмета

	int getCount() const; //Получить количество предметов в ячейке

	bool isEmpty() const; //Проверить ячейку на то, что она пуста

	int push(int count); //Положить count предметов в ячейку

	int push(ItemType *item, int count); //Положить count предметов в ячейку с подтверждением предмета

	int pull(int count); //Взять count предметов из ячейки

	int pull(ItemType *item, int count); //Взять count предметов из ячейки с подтверждением предмета

};
#endif
