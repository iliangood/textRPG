#include "item.h"

Item::Item(string name, string description)
{
	this->name = name;
	this->description = description;
}

string Item::getDescription() const
{
	return description;
}

string Item::getName() const
{
	return name;
}
