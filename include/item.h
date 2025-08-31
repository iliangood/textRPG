#if !defined ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
	string name;
	string description;
public:
	Item(){}
	Item(string name, string description);

	string getDescription() const; //Получить описание предмета

	string getName() const; //Получить имя предмета
};
#endif
