#if !defined ROOM_OBJECT_H
#define ROOM_OBJECT_H

#include <string>
#include <vector>

#include "condition.h"
#include "dinamicProperty/dinamicProperty.h"
#include "constantProperty.h"

class roomObject
{
private:
	std::string name;
	std::string description;
	std::vector<dinamicProperty> dinamicProperties;
	std::vector<ConstantProperty> constantProperties;
	Condition* visibilityCondition;
	void (*interactionFunc)(void* data);
public:
	roomObject(std::string name, std::string description,
		std::vector<dinamicProperty> dinamicProperties = {},
		std::vector<ConstantProperty> constantProperties = {},
		Condition* visibilityCondition = nullptr,
		void (*interactionFunc)(void* data) = nullptr);
	std::string getName() const;
	std::string getDescription() const;
	std::vector<dinamicProperty> getDinamicProperties() const;
	std::vector<ConstantProperty> getConstantProperties() const;
	bool checkVisibility() const;
	bool checkVisibility(void* arg) const;
	void interact(void* data) const;
	void interact() const;

};

#endif