#if !defined ROOM_OBJECT_H
#define ROOM_OBJECT_H

#include <string>
#include <vector>

#include "condition.h"
#include "dinamicProperty/dinamicProperty.h"
#include "constantProperty.h"
#include "statusCodes.h"
#include "language/multiLocalizedString.h"

class roomObject
{
private:
	MultiLocalizedString* name;
	MultiLocalizedString* description;
	std::vector<DinamicProperty> dinamicProperties;
	std::vector<ConstantProperty*> constantProperties;
	Condition* visibilityCondition;
	void (*interactionFunc)(void* data);
public:
	roomObject(MultiLocalizedString* name, MultiLocalizedString* description,
		std::vector<DinamicProperty> dinamicProperties = {},
		std::vector<ConstantProperty*> constantProperties = {},
		Condition* visibilityCondition = nullptr,
		void (*interactionFunc)(void* data) = nullptr);
	MultiLocalizedString* getName() const;
	MultiLocalizedString* getDescription() const;
	std::vector<DinamicProperty>* getDinamicProperties();
	std::vector<ConstantProperty*>* getConstantProperties();
	std::optional<bool> checkVisibility() const;
	std::optional<bool> checkVisibility(void* arg) const;
	void interact(void* data) const;
	void interact() const;

};

#endif