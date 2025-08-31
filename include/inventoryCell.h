#if !defined INVENTORYCELL_H
#define INVENTORYCELL_H

#include <string>

#include "item.h"

using namespace std;

class InventoryCell
{
	Item item;
	int count;
public:
	string getName() const;
	string getDescription() const;
	Item getItem() const;
	int getCount() const;
	bool isEmpty() const;
	int push(int count);
	int pull(int count);
};
#endif
