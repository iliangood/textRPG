#include "inventory.h"

	string Inventory::getName(int index) const
	{
		return inventoryCells[index].getName();
	}

	string Inventory::getDescription(int index) const
	{
		return inventoryCells[index].getDescription;
	}

	vector<string> Inventory::getNames() const
	{
		vector res<string>;
		int size = getCount();
		res.resize(size);
		for(int i = 0; i < size; i++)
		{
			res[i] = inventoryCells[i].getName();
		}
	}

	vector<InventoryCell> Inventory::getInventoryCells() const
	{
		return inventoryCells;
	}

	InventoryCell Inventory::InventoryCell(int index) const
	{
		return inventoryCells[index];
	}

	int Inventory::getCount() const
	{
		return inventoryCells.size();
	}

	int Inventory::getTotalCount() const
	{
		int res = 0;
		for(int i = 0; i < inventoryCells.size(); i++)
		{
			res += inventoryCells[i].getCount();
		}
		return res;
	}

	int Inventory::getCount(int index) const
	{
		return inventoryCells[index].getCount();
	}

	bool Inventory::isEmpty() const
	{
		return inventoryCells.size();
	}

	int Inventory::findIndex() const
	{

	}

	int Inventory::push(string name, int count);
	{

	}
	int Inventory::pull(string name, int count);
