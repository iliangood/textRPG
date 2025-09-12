#include "statusCodes.h"

bool isSuccess(StatusCode code)
{
	return code == StatusCode::SUCCESS;
}

bool isError(StatusCode code)
{
	return code < StatusCode::SUCCESS;
}

bool isWarning(StatusCode code)
{
	return code > StatusCode::SUCCESS;
}

bool isNotError(StatusCode code)
{
	return !isError(code);
}