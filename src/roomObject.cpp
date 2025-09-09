#include "roomObject.h"



roomObject::roomObject(std::string name, std::string description,
	std::vector<dinamicProperty> dinamicProperties,
	std::vector<ConstantProperty> constantProperties,
	Condition* visibilityCondition,
	void (*interactionFunc)(void* data))
	: name(std::move(name)), description(std::move(description)),
	dinamicProperties(std::move(dinamicProperties)),
	constantProperties(std::move(constantProperties)),
	visibilityCondition(visibilityCondition),
	interactionFunc(interactionFunc)
{}

std::string roomObject::getName() const
{
	return name;
}

std::string roomObject::getDescription() const
{
	return description;
}

std::vector<dinamicProperty> roomObject::getDinamicProperties() const
{
	return dinamicProperties;
}

std::vector<ConstantProperty> roomObject::getConstantProperties() const
{
	return constantProperties;
}

bool roomObject::checkVisibility() const
{
	if (visibilityCondition == nullptr)
		return true;
	return visibilityCondition->check();
}

bool roomObject::checkVisibility(void* arg) const
{
	if (visibilityCondition == nullptr)
		return true;
	return visibilityCondition->check(arg);
}

void roomObject::interact(void* data) const
{
	if (interactionFunc != nullptr)
		interactionFunc(data);
}

void roomObject::interact() const
{
	if (interactionFunc != nullptr)
		interactionFunc(nullptr);
}

