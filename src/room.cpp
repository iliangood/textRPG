#include "room.h"

Room::Room(std::string name, std::string description,
	std::vector<Passage> passages,
	std::vector<roomObject> objects,
	std::vector<dinamicProperty> dinamicProperties,
	std::vector<ConstantProperty> constantProperties)
	: name(std::move(name)), description(std::move(description)),
	passages(std::move(passages)),
	objects(std::move(objects)),
	dinamicProperties(std::move(dinamicProperties)),
	constantProperties(std::move(constantProperties))
{}

std::string Room::getName() const
{
	return name;
}

std::string Room::getDescription() const
{
	return description;
}

std::vector<Passage> Room::getPassages() const
{
	return passages;
}

std::vector<roomObject> Room::getObjects() const
{
	return objects;
}

std::vector<dinamicProperty> Room::getDinamicProperties() const
{
	return dinamicProperties;
}

std::vector<ConstantProperty> Room::getConstantProperties() const
{
	return constantProperties;
}