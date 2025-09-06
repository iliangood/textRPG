#include "inventory.h"

bool isExistence(ItemType item);

std::vector<ItemStack> Inventory::getItemStacks() const
{
	return itemStacks;
}

ItemStack Inventory::getItemStack(int index) const
{
	return itemStacks[index];
}

ItemType* Inventory::getItemType(int index) const
{
	return getItemStack(index).getItem();
}

std::string Inventory::getName(int index) const
{
	return getItemStack(index).getName();
}

std::string Inventory::getDescription(int index) const
{
	return getItemStack(index).getDescription();
}

std::vector<std::string> Inventory::getNames() const
{
	std::vector<std::string> res;
	int size = getCount();
	res.resize(size);
	for(int i = 0; i < size; i++)
	{
		res[i] = itemStacks[i].getName();
	}
	return res;
}


int Inventory::getCount() const
{
	return itemStacks.size();
}

int Inventory::getTotalCount() const
{
	int res = 0;
	for(size_t i = 0; i < itemStacks.size(); i++)
	{
		res += itemStacks[i].getCount();
	}
	return res;
}

int Inventory::getCount(int index) const
{
	return itemStacks[index].getCount();
}

bool Inventory::isEmpty() const
{
	return itemStacks.size();
}

int Inventory::findIndex(ItemType* item) const
{
	for(int i = 0; i < getCount(); i++)
	{
		if(getItemType(i) == item)
		{
			return i;
		}
	}
	return NOT_EXISTS;
}

int Inventory::findIndex(std::string name) const
{
	for(int i = 0; i < getCount(); i++)
	{
		if(getName(i) == name)
		{
			return i;
		}
	}
	return NOT_EXISTS;
}

int Inventory::push(ItemType* item, int count)
{
	if(count < 0)
	{
		return INCORRECT_INPUT;
	}
	int index = findIndex(item);
	if(index != NOT_EXISTS)
	{
		getItemStack(index).push(item, count);
		return OK;
	}
	itemStacks.push_back(ItemStack(item, count));
	return OK;
}

int Inventory::uniquePush(ItemType* item)
{
	if(findIndex(item) == NOT_EXISTS)
	{
		push(item, 1);
		return OK;
	}
	return GAME_LOGIC_ERROR;
}

int Inventory::pull(ItemType* item, int count)
{
	if(count < 0)
	{
		return INCORRECT_INPUT;
	}
	int index = findIndex(item);
	if(index < 0)
	{
		return GAME_LOGIC_ERROR;
	}
	if(getCount(index) < count)
	{
		return GAME_LOGIC_ERROR;
	}
	return getItemStack(index).pull(count);
}
