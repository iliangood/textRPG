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

std::optional<ItemStack*> Inventory::getItemStack(size_t index)
{
	if(index >= itemStacks.size())
		return std::nullopt;
	return &(itemStacks[index]);
}

std::optional<const ItemType*> Inventory::getItemType(size_t index) const
{
	std::optional<const ItemStack*> itemstack = getItemStack(index);
	if(itemstack == std::nullopt)
		return std::nullopt;
	return itemstack.value()->getItem();
}

std::optional<MultiLocalizedString*> Inventory::getName(size_t index) const
{
	std::optional<const ItemStack*> itemstack = getItemStack(index);
	if(itemstack == std::nullopt)
		return std::nullopt;
	return itemstack.value()->getName();
}

std::optional<MultiLocalizedString*> Inventory::getDescription(size_t index) const
{
	std::optional<const ItemStack*> itemstack = getItemStack(index);
	if(itemstack == std::nullopt)
	{
		return std::nullopt;
	}
	return getItemStack(index).value()->getDescription();
}

std::vector<MultiLocalizedString*> Inventory::getNames() const
{
	std::vector<MultiLocalizedString*> res;
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

std::optional<size_t> Inventory::findFirstIndex(const ItemType* item) const
{
	for(size_t i = 0; i < getCount(); i++)
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
	for(size_t i = 0; i < getCount(); i++)
	{
		if(getName(i).value()->hasSubstring(name))
		{
			return i;
		}
	}
	return std::nullopt;
}

StatusCode Inventory::push(const ItemType* item, size_t count)
{
	std::optional<size_t> index = findFirstIndex(item);
	if(index != std::nullopt)
	{
		getItemStack(index.value()).value()->push(item, count);
		return StatusCode::OK;
	}
	itemStacks.push_back(ItemStack(item, count));
	return StatusCode::OK;
}

/*int Inventory::uniquePush(ItemType* item)
{
	if(findIndex(item).has_value())
	{
		return ALREADY_EXISTS;
	}
	{
		push(item, 1);
		return OK;
	}
	return GAME_LOGIC_ERROR;
}*/

StatusCode Inventory::pull(const ItemType* item, size_t count)
{
	std::optional<size_t> index = findFirstIndex(item);
	if(!index.has_value())
	{
		return StatusCode::INCORRECT_INPUT;
	}
	std::optional<size_t> Count = getCount(index.value());
	if(Count == std::nullopt)
	{
		return StatusCode::GAME_LOGIC_ERROR;
	}
	if(Count.value() < count)
	{
		return StatusCode::GAME_LOGIC_ERROR;
	}
	std::optional<ItemStack*> itemStack = getItemStack(index.value());
	if(itemStack == std::nullopt)
	{
		return StatusCode::GAME_LOGIC_ERROR;
	}
	return itemStack.value()->pull(count);
}
