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

add_library(player ./src/player.cpp ./include/player.h)

add_library(map ./src/room.cpp ./include/room.h)

add_library(passage ./src/passage.cpp ./include/passage.h)

target_link_libraries(passage PUBLIC room)
target_link_libraries(room PUBLIC passage)

add_library(itemType ./src/itemType.cpp ./include/itemType.h)

add_library(itemStack ./src/itemStack.cpp ./include/itemStack.h)
target_link_libraries(itemStack PUBLIC itemType)

add_library(inventory ./src/inventory.cpp ./include/inventory.h)
target_link_libraries(inventory PUBLIC itemStack)

add_library(condition ./src/condition.cpp ./include/condition.h)

add_library(constantProperty ./src/constantProperty.cpp ./include/constantProperty.h)

add_executable(game main.cpp)
