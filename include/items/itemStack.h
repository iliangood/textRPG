#if !defined ITEM_STACK_H
#define ITEM_STACK_H

#include <string>

#include "statusCodes.h"

#include "items/itemType.h"
#include "language/multiLocalizedString.h"


class ItemStack
{
	const ItemType* item;
	size_t count;
public:
	ItemStack(){}
	ItemStack(const ItemType *item, int count);

	MultiLocalizedString* getName() const; //Получить имя предмета в ячейке

	MultiLocalizedString* getDescription() const; //Получить описание предмета в ячейке

	const ItemType* getItem() const; //Получить объкт предмета

	size_t getCount() const; //Получить количество предметов в ячейке

	bool isEmpty() const; //Проверить ячейку на то, что она пуста

	int push(size_t count); //Положить count предметов в ячейку

	int push(const ItemType* item, size_t count); //Положить count предметов в ячейку с подтверждением предмета

	int pull(size_t count); //Взять count предметов из ячейки

	int pull(const ItemType* item, size_t count); //Взять count предметов из ячейки с подтверждением предмета

};
#endif
