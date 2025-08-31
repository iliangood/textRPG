cmake_minimum_required(VERSION 3.28.3)
project(textRPG)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g -O0")
include_directories(include)

add_library(player ./src/player.cpp ./include/player.h)

add_library(room ./src/room.cpp ./include/room.h)

add_library(passage ./src/passage.cpp ./include/passage.h)

add_library(item ./src/item.cpp ./include/item.h)

add_library(inventoryCell ./src/inventoryCell.cpp ./include/inventoryCell.h)
target_link_libraries(inventoryCell PUBLIC item)

add_library(inventory ./src/inventory.cpp ./include/inventory.h)
target_link_libraries(inventory PUBLIC inventoryCell)

add_executable(game main.cpp)
