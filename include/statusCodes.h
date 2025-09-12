#ifndef STATUS_CODES_H
#define STATUS_CODES_H

enum class StatusCode
{
	// Предупреждения
	MUST_BE_REMOVED = 1, // Объект должен быть удален
	// Успех
	SUCCESS = 0,
	OK = 0,
	// Ошибки
	FILE_ERROR = -1,
	READ_ERROR = -2,
	WRITE_ERROR = -3,
	INVALID_LENGTH_ERROR = -4,

	GAME_LOGIC_ERROR = -5,
	NOT_EXISTS = -6,
	ALREADY_EXISTS = -7,
	INVALID_STATE = -8, // Некорректное состояние объекта
	PERMISSION_DENIED = -9,
	TIMEOUT = -10,
	OUT_OF_MEMORY = -11,
	UNKNOWN_ERROR = -12,
	PARSE_ERROR = -13,
	VALIDATION_ERROR = -14,
	CONFLICT = -15,
	UNAVAILABLE = -16,
	INCORRECT_INPUT = -17,
	UNMATCHED_ITEM_TYPE = -18 // Несовпадающий тип предмета
};

bool isSuccess(StatusCode code);

bool isError(StatusCode code);

bool isWarning(StatusCode code);

bool isNotError(StatusCode code);


// Успех
/*#define SUCCESS 0
#define OK 0

// Ошибки файловых операций
#define FILE_ERROR -1
#define READ_ERROR -2
#define WRITE_ERROR -3
#define INVALID_LENGTH_ERROR -4

// Общие ошибки
#define GAME_LOGIC_ERROR -5
#define NOT_EXISTS -6
#define ALREADY_EXISTS -7
#define INVALID_STATE -8 // Некорректное состояние объекта
#define PERMISSION_DENIED -9
#define TIMEOUT -10
#define OUT_OF_MEMORY -11
#define UNKNOWN_ERROR -12
#define PARSE_ERROR -13
#define VALIDATION_ERROR -14
#define CONFLICT -15
#define UNAVAILABLE -16
#define INCORRECT_INPUT -17*/

#endif 


