#include "items/itemStack.h"

ItemStack::ItemStack(const ItemType *item, int count)
{
	this->item = item;
	this->count = count;
}

MultiLocalizedString* ItemStack::getName() const
{
	return item->getName();
}

MultiLocalizedString* ItemStack::getDescription() const
{
	return item->getDescription();
}

const ItemType* ItemStack::getItem() const
{
	return item;
}

size_t ItemStack::getCount() const
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


int ItemStack::push(const ItemType* item, size_t Count)
{
	if(this->item != item)
	{
		return GAME_LOGIC_ERROR;
	}
	return push(Count);
}

int ItemStack::pull(size_t count)
{
	if(this->count < count)
		return GAME_LOGIC_ERROR;
	this->count -= count;
	return OK;
}

int ItemStack::pull(const ItemType* item, size_t count)
{
	if(this->item != item)
	{
		return GAME_LOGIC_ERROR;
	}
	return pull(count);
}
