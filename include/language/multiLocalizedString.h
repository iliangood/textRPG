#if !defined MULTI_LOCALIZED_STRING_H
#define MULTI_LOCALIZED_STRING_H

#include <vector>

#include "language/localizedString.h"

class MultiLocalizedString
{
	std::vector<LocalizedString> values;
public:
	MultiLocalizedString(std::vector<LocalizedString> values);
	std::vector<LocalizedString> getValues() const;
	std::vector<std::string> getLanguages() const;
	LocalizedString getValue(int index) const;
	int getCount() const;
};

#endif