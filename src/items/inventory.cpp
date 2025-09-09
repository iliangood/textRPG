#include "items/inventory.h"

bool isExistence(ItemType item);

std::vector<ItemStack>* Inventory::getItemStacks()
{
	return &itemStacks;
}

std::optional<const ItemStack*> Inventory::getItemStack(size_t index) const
{
	if(index >= itemStacks.size())
		return std::nullopt;
	return &(itemStacks[index]);
}

std::optional<const ItemType*> Inventory::getItemType(size_t index) const
{
	std::optional<ItemStack*> itemstack = getItemStack(index);
	if(itemstack == std::nullopt)
		return std::nullopt;
	return itemstack.value()->getItem();
}

std::optional<std::string> Inventory::getName(size_t index) const
{
	std::optional<const ItemStack*> itemstack = getItemStack(index);
	if(itemstack == std::nullopt)
		return std::nullopt;
	return itemstack.value()->getName();
}

std::optional<std::string> Inventory::getDescription(size_t index) const
{
	std::optional<const ItemStack*> itemstack = getItemStack(index);
	if(itemstack == std::nullopt)
	{
		return std::nullopt;
	}
	return getItemStack(index).value()->getDescription();
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


size_t Inventory::getCount() const
{
	return itemStacks.size();
}

size_t Inventory::getTotalCount() const
{
	int res = 0;
	for(size_t i = 0; i < itemStacks.size(); i++)
	{
		res += itemStacks[i].getCount();
	}
	return res;
}

size_t Inventory::getCount(size_t index) const
{
	return itemStacks[index].getCount();
}

bool Inventory::isEmpty() const
{
	return itemStacks.size();
}

std::optional<size_t> Inventory::findFirstIndex(ItemType* item) const
{
	for(int i = 0; i < getCount(); i++)
	{
		if(getItemType(i) == item)
		{
			return i;
		}
	}
	return std::nullopt;
}

std::optional<size_t> Inventory::findFirstIndex(std::string name) const
{
	for(int i = 0; i < getCount(); i++)
	{
		if(getName(i) == name)
		{
			return i;
		}
	}
	return std::nullopt;
}

int Inventory::push(ItemType* item, size_t count)
{
	if(count < 0)
	{
		return INCORRECT_INPUT;
	}
	std::optional<size_t> index = findFirstIndex(item);
	if(index != std::nullopt)
	{
		getItemStack(index.value()).value().push(item, count);
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
