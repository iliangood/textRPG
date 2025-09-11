#if !defined DINAMIC_PROPERTY_H
#define DINAMIC_PROPERTY_H

#include <string>
#include <vector>
#include <variant>

#include "dinamicProperty/dinamicPropertyType.h"
#include "language/multiLocalizedString.h"

typedef std::variant<int, std::string, std::vector<char>> DinamicPropertyValue;

class DinamicProperty
{
private:
	DinamicPropertyType* type;
	DinamicPropertyValue value;
public:
	DinamicProperty(DinamicPropertyType* type, DinamicPropertyValue value);
	DinamicPropertyType* getType() const;
	MultiLocalizedString* getName() const;
	MultiLocalizedString* getDescription() const;
	DinamicPropertyTypeEnum getValueType() const;
	bool isHidden() const;
	DinamicPropertyValue getValue() const;
	void setValue(DinamicPropertyValue newValue);
};


#endif