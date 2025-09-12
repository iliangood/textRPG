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

StatusCode ItemStack::push(size_t Count)
{
	if(item->hasDinamicProperties())
	{
		if(Count + count > 1)
			return StatusCode::GAME_LOGIC_ERROR;
	}
	count += Count;
	return StatusCode::OK;
}


StatusCode ItemStack::push(const ItemType* item, size_t Count)
{
	if(this->item != item)
	{
		return StatusCode::GAME_LOGIC_ERROR;
	}
	return push(Count);
}

StatusCode ItemStack::pull(size_t count)
{
	if(this->count < count)
		return StatusCode::GAME_LOGIC_ERROR;
	this->count -= count;
	return StatusCode::OK;
}

StatusCode ItemStack::pull(const ItemType* item, size_t count)
{
	if(this->item != item)
	{
		return StatusCode::GAME_LOGIC_ERROR;
	}
	return pull(count);
}
