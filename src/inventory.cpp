#include "inventory.h"

string Inventory::getName(int index) const
{
	return inventoryCells[index].getName();
}

string Inventory::getDescription(int index) const
{
	return inventoryCells[index].getDescription();
}

vector<string> Inventory::getNames() const
{
	vector<string> res;
	int size = getCount();
	res.resize(size);
	for(int i = 0; i < size; i++)
	{
		res[i] = inventoryCells[i].getName();
	}
	return res;
}

vector<InventoryCell> Inventory::getInventoryCells() const
{
	return inventoryCells;
}

InventoryCell Inventory::getInventoryCell(int index) const
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
	for(size_t i = 0; i < inventoryCells.size(); i++)
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

int Inventory::findIndex(string name) const
{
	for(int i = 0; i < getCount(); i++)
	{
		if(inventoryCells[i].getName() == name)
		{
			return i;
		}
	}
	return NOT_EXISTS;
}

int Inventory::push(string name, int count)
{
	if(count < 0)
	{
		return INCORRECT_INPUT;
	}
	int index = findIndex(name);
	if(index != NOT_EXISTS)
	{
		inventoryCells[index].push(name, count);
		return OK;
	}
	inventoryCells.push_back(InventoryCell());
	return OK;
}

int Inventory::uniquePush(string name)
{
	if(findIndex(name) == NOT_EXISTS)
	{
		push(name, 1);
		return OK;
	}
	return GAME_LOGIC_ERROR;
}

int Inventory::pull(string name, int count)
{
	if(count < 0)
	{
		return INCORRECT_INPUT;
	}
	int index = findIndex(name);
	if(index < 0)
	{
		return GAME_LOGIC_ERROR;
	}
	if(getCount(index) < count)
	{
		return GAME_LOGIC_ERROR;
	}
	return inventoryCells[index].pull(count);
}
