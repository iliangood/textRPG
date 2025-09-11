#if !defined PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "statusCodes.h"

#include "dinamicProperty/dinamicProperty.h"
#include "constantProperty.h"
#include "items/inventory.h"
#include "room.h"
#include "language/multiLocalizedString.h"


class Player
{
	MultiLocalizedString* name;
	MultiLocalizedString* description;
	Room* position;
	std::vector<DinamicProperty> dinamicProperties;
	std::vector<ConstantProperty*> constantProperties;
	Inventory inventory;
public:
	Player(MultiLocalizedString* name, MultiLocalizedString* description, Room* position,
		std::vector<DinamicProperty> dinamicProperties = {},
		std::vector<ConstantProperty*> constantProperties = {});

	MultiLocalizedString* getName() const; //Получить имя игрока

	MultiLocalizedString* getDescription() const; //Получить описание игрока

	Inventory& getInventory(); //Получить инвентарь игрока

	Room* getPosition() const; //Получить текущую позицию игрока

	void setPosition(Room* newPosition); //Установить новую позицию игрока

	std::vector<DinamicProperty>* getDinamicProperties(); //Получить все динамические свойства игрока

	std::vector<ConstantProperty*>* getConstantProperties(); //Получить все постоянные свойства игрока
};
#endif
