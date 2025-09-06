#if !defined DINAMIC_PROPERTY_TYPE_H
#define DINAMIC_PROPERTY_TYPE_H

#include <string>

enum class dinamicPropertyTypeEnum
{
	INT,
	STRING,
	CHAR_VECTOR
};

class DinamicPropertyType
{
private:
	std::string name;
	std::string description;
	dinamicPropertyTypeEnum type;
	bool hidden;
public:
	DinamicPropertyType(std::string name, std::string description, dinamicPropertyTypeEnum type, bool hidden = false);
	std::string getName() const;
	std::string getDescription() const;
	dinamicPropertyTypeEnum getType() const;
	bool isHidden() const;
};


#endif
