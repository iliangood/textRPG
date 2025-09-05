#include "itemStack.h"

ItemStack::ItemStack(ItemType *item, int count)
{
	this->item = item;
	this->count = count;
}

string ItemStack::getName() const
{
	return item->getName();
}

string ItemStack::getDescription() const
{
	return item->getDescription();
}

ItemType* ItemStack::getItem() const
{
	return item;
}

int ItemStack::getCount() const
{
	return count;
}

bool ItemStack::isEmpty() const
{
	return !count;
}

int ItemStack::push(int Count)
{
	if(Count < 0)
		return INCORRECT_INPUT;
	count += Count;
	return OK;
}

int ItemStack::push(ItemType *item, int Count)
{
	if(this->item != item)
	{
		return GAME_LOGIC_ERROR;
	}
	return push(Count);
}

int ItemStack::pull(int Count)
{
	if(count < Count)
		return GAME_LOGIC_ERROR;
	count -= count;
	return OK;
}

int ItemStack::pull(ItemType *item, int Count)
{
	if(this->item != item)
	{
		return GAME_LOGIC_ERROR;
	}
	return pull(Count);
}
