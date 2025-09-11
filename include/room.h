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
	MultiLocalizedString* name;
	MultiLocalizedString* description;
	std::vector<Passage> passages;
	std::vector<roomObject> objects;
	std::vector<DinamicProperty> dinamicProperties;
	std::vector<ConstantProperty*> constantProperties;

public:
	Room(MultiLocalizedString* name, MultiLocalizedString* description,
		std::vector<Passage> passages = {},
		std::vector<roomObject> objects = {},
		std::vector<DinamicProperty> dinamicProperties = {},
		std::vector<ConstantProperty*> constantProperties = {});

	MultiLocalizedString* getName() const; //Получить имя комнаты

	MultiLocalizedString* getDescription() const; //Получить описание комнаты

	std::vector<Passage> getPassages() const; //Получить все выходы из комнаты

	std::vector<roomObject> getObjects() const; //Получить все объекты в комнате

	std::vector<DinamicProperty>* getDinamicProperties(); //Получить все динамические свойства комнаты

	std::vector<ConstantProperty*>* getConstantProperties(); //Получить все постоянные свойства комнаты
};

#endif
