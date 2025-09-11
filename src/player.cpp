#include "player.h"

Player::Player(MultiLocalizedString* name, MultiLocalizedString* description, Room* position,
	std::vector<DinamicProperty> dinamicProperties,
	std::vector<ConstantProperty*> constantProperties)
	: name(name), description(description), position(position),
	dinamicProperties(dinamicProperties),
	constantProperties(constantProperties)
{}

MultiLocalizedString* Player::getName() const
{
	return name;
}

MultiLocalizedString* Player::getDescription() const
{
	return description;
}

Inventory& Player::getInventory()
{
	return inventory;
}

Room* Player::getPosition() const
{
	return position;
}

void Player::setPosition(Room* newPosition)
{
	position = newPosition;
}

std::vector<DinamicProperty>* Player::getDinamicProperties()
{
	return &dinamicProperties;
}

std::vector<ConstantProperty*>* Player::getConstantProperties()
{
	return &constantProperties;
}