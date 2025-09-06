#if !defined ROOM_H
#define ROOM_H

class Passage;

#include <vector>
#include <string>

#include "passage.h"
#include "statusCodes.h"
#include "roomObject.h"
#include "dinamicProperty/dinamicProperty.h"
#include "constantProperty.h"

class Room
{
	std::string name;
	std::string description;
	std::vector<Passage> passages;
	std::vector<roomObject> objects;
	std::vector<dinamicProperty> dinamicProperties;
	std::vector<ConstantProperty> constantProperties;

public:
	Room(std::string name, std::string description,
		std::vector<Passage> passages = {},
		std::vector<roomObject> objects = {},
		std::vector<dinamicProperty> dinamicProperties = {},
		std::vector<ConstantProperty> constantProperties = {});

	std::string getName() const; //Получить имя комнаты

	std::string getDescription() const; //Получить описание комнаты

	std::vector<Passage> getPassages() const; //Получить все выходы из комнаты

	std::vector<roomObject> getObjects() const; //Получить все объекты в комнате

	std::vector<dinamicProperty> getDinamicProperties() const; //Получить все динамические свойства комнаты

	std::vector<ConstantProperty> getConstantProperties() const; //Получить все постоянные свойства комнаты
};

#endif
