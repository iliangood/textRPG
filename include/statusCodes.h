#ifndef STATUS_CODES_H
#define STATUS_CODES_H

// Успех
#define SUCCESS 0
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
#define INCORRECT_INPUT -17

#endif 


