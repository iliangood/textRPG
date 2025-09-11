#if !defined DINAMIC_PROPERTY_TYPE_H
#define DINAMIC_PROPERTY_TYPE_H

#include <string>
#include "language/multiLocalizedString.h"

enum class DinamicPropertyTypeEnum
{
	INT,
	STRING,
	CHAR_VECTOR
};

class DinamicPropertyType
{
private:
	MultiLocalizedString* name;
	MultiLocalizedString* description;
	DinamicPropertyTypeEnum type;
	bool hidden;
public:
	DinamicPropertyType(MultiLocalizedString* name, MultiLocalizedString* description, DinamicPropertyTypeEnum type, bool hidden = false);
	MultiLocalizedString* getName() const;
	MultiLocalizedString* getDescription() const;
	DinamicPropertyTypeEnum getType() const;
	bool isHidden() const;
};


#endif
