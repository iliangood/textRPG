#include "inventoryCell.h"

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
		return 0;
	}

	int InventoryCell::pull(int Count)
	{
		if(count < Count)
			return 1;
		count -= count;
		return 0;
	}
