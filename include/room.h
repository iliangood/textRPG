#if !defined ROOM_H
#define ROOM_H

class Passage;

#include "passage.h"
#include "statusCodes.h"

class Room
{
	Passage* passage;
public:
	Room(){}
};
#endif
