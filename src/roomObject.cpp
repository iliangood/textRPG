#include "roomObject.h"

roomObject::roomObject(MultiLocalizedString* name, MultiLocalizedString* description,
	std::vector<DinamicProperty> dinamicProperties,
	std::vector<ConstantProperty*> constantProperties,
	Condition* visibilityCondition,
	void (*interactionFunc)(void* data))
	: name(name), description(description), dinamicProperties(dinamicProperties),
	constantProperties(constantProperties),
	visibilityCondition(visibilityCondition), interactionFunc(interactionFunc)
{}

MultiLocalizedString* roomObject::getName() const
{
	return name;
}

MultiLocalizedString* roomObject::getDescription() const
{
	return description;
}

std::vector<DinamicProperty>* roomObject::getDinamicProperties()
{
	return &dinamicProperties;
}

std::vector<ConstantProperty*>* roomObject::getConstantProperties()
{
	return &constantProperties;
}

std::optional<bool> roomObject::checkVisibility() const
{
	if (visibilityCondition == nullptr)
		return std::nullopt;
	return visibilityCondition->check();
}

std::optional<bool> roomObject::checkVisibility(void* arg) const
{
	if (visibilityCondition == nullptr)
		return std::nullopt;
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

