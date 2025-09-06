#if !defined PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "statusCodes.h"
#include "inventory.h"
#include "room.h"


class Player
{
	std::string name;
	std::string description;
	Inventory inventory;
	Room* position;
public:
	Player(std::string name, std::string description, Room* position);

	std::string getName() const; //Получить имя игрока

	std::string getDescription() const; //Получить описание игрока

	Inventory& getInventory(); //Получить инвентарь игрока

	Room* getPosition() const; //Получить текущую позицию игрока

	void setPosition(Room* newPosition); //Установить новую позицию игрока
};
#endif
