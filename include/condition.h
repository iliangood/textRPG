#if !defined CONDITTION_H
#define CONDITTION_H

#include <string>

#include "statusCodes.h"

#include "inventory.h"

using namespace std;

class Condition
{
    string itemName;
    unsigned int requiredQuantity;
    bool requiredMin;
    Inventory inventory;
public:
};
#endif
