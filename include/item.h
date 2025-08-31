#if !defined ITEM_H
#define ITEM_H
using namespace std;
#include <string>
class Item
{
	string name;
	string description;
public:
	string getDescription() const;
	string getName() const;
};
#endif
