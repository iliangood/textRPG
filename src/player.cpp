#include "player.h"

Player::Player(std::string name, std::string description, Room* position)
	: name(std::move(name)), description(std::move(description)), position(position)
{}

std::string Player::getName() const
{
	return name;
}

std::string Player::getDescription() const
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