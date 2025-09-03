#include "inventoryCell.h"

InventoryCell::InventoryCell(Item item, int count)
{
	this->item = item;
	this->count = count;
}

string InventoryCell::getName() const
{
	return item.getName();
}

string InventoryCell::getDescription() const
{
	return item.getDescription();
}

Item InventoryCell::getItem() const
{
	return item;
}

int InventoryCell::getCount() const
{
	return count;
}

bool InventoryCell::isEmpty() const
{
	return !count;
}

int InventoryCell::push(int Count)
{
		count += Count;
		return OK;
}

int InventoryCell::pull(int Count)
{
		if(count < Count)
			return GAME_LOGIC_ERROR;
		count -= count;
		return OK;
}
