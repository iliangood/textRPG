#include "room.h"

Room::Room(MultiLocalizedString* name, MultiLocalizedString* description,
	std::vector<Passage> passages,
	std::vector<roomObject> objects,
	std::vector<DinamicProperty> dinamicProperties,
	std::vector<ConstantProperty*> constantProperties)
	: name(name), description(description), passages(passages), objects(objects),
	dinamicProperties(dinamicProperties), constantProperties(constantProperties)
{}

MultiLocalizedString* Room::getName() const
{
	return name;
}

MultiLocalizedString* Room::getDescription() const
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

std::vector<DinamicProperty>* Room::getDinamicProperties()
{
	return &dinamicProperties;
}

std::vector<ConstantProperty*>* Room::getConstantProperties()
{
	return &constantProperties;
}