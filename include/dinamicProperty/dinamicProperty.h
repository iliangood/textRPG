#if !defined DINAMIC_PROPERTY_H
#define DINAMIC_PROPERTY_H

#include <string>
#include <vector>
#include <variant>

#include "dinamicProperty/dinamicPropertyType.h"

typedef std::variant<int, std::string, std::vector<char>> dinamicPropertyValue;

class dinamicProperty
{
private:
	DinamicPropertyType* type;
	dinamicPropertyValue value;
public:
	dinamicProperty(DinamicPropertyType* type, dinamicPropertyValue value);
	DinamicPropertyType* getType() const;
	std::string getName() const;
	std::string getDescription() const;
	dinamicPropertyTypeEnum getValueType() const;
	bool isHidden() const;
	dinamicPropertyValue getValue() const;
	void setValue(dinamicPropertyValue newValue);
};


#endif