cmake_minimum_required(VERSION 3.28.3)
project(textRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -g -O0)
endif()

include_directories(include)

add_library(statusCodes ./src/statusCodes.cpp ./include/statusCodes.h)

add_library(language ./src/language/language.cpp ./include/language/language.h)
add_library(localizedString ./src/language/localizedString.cpp ./include/language/localizedString.h)
target_link_libraries(localizedString PUBLIC language)
add_library(multiLocalizedString ./src/language/multiLocalizedString.cpp ./include/language/multiLocalizedString.h)
target_link_libraries(multiLocalizedString PUBLIC localizedString statusCodes)

add_library(itemType ./src/items/itemType.cpp ./include/items/itemType.h)

add_library(itemStack ./src/items/itemStack.cpp ./include/items/itemStack.h)
target_link_libraries(itemStack PUBLIC itemType statusCodes)

add_library(inventory ./src/items/inventory.cpp ./include/items/inventory.h)
target_link_libraries(inventory PUBLIC itemStack statusCodes)

add_library(roomObject ./src/roomObject.cpp ./include/roomObject.h)

add_library(room ./src/room.cpp ./include/room.h)

add_library(passage ./src/passage.cpp ./include/passage.h)

add_library(player ./src/player.cpp ./include/player.h)
target_link_libraries(player PUBLIC inventory room statusCodes)



target_link_libraries(passage PUBLIC room)
target_link_libraries(room PUBLIC passage)

add_library(dinamicPropertyType ./src/dinamicProperty/dinamicPropertyType.cpp ./include/dinamicProperty/dinamicPropertyType.h)
add_library(dinamicProperty ./src/dinamicProperty/dinamicProperty.cpp ./include/dinamicProperty/dinamicProperty.h)



add_library(condition ./src/condition.cpp ./include/condition.h)

add_library(constantProperty ./src/constantProperty.cpp ./include/constantProperty.h)

add_executable(game main.cpp)

target_link_libraries(game PUBLIC player room inventory itemType itemStack constantProperty dinamicProperty dinamicPropertyType condition statusCodes)
