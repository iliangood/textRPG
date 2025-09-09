#include "items/itemStack.h"

ItemStack::ItemStack(ItemType *item, int count)
{
	this->item = item;
	this->count = count;
}

std::string ItemStack::getName() const
{
	return item->getName();
}

std::string ItemStack::getDescription() const
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

int ItemStack::push(size_t Count)
{
	count += Count;
	return OK;
}


int ItemStack::push(ItemType* item, size_t Count)
{
	if(this->item != item)
	{
		return GAME_LOGIC_ERROR;
	}
	return push(Count);
}

int ItemStack::pull(size_t Count)
{
	if(count < Count)
		return GAME_LOGIC_ERROR;
	count -= count;
	return OK;
}

int ItemStack::pull(ItemType* item, size_t Count)
{
	if(this->item != item)
	{
		return GAME_LOGIC_ERROR;
	}
	return pull(Count);
}
