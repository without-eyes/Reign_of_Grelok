cmake_minimum_required(VERSION 3.27)
project(Reign_of_Grelok)

set(CMAKE_CXX_STANDARD 20)

add_executable(Reign_of_Grelok menu/main.cpp
        player/Inventory.h
        player/Inventory.cpp
        menu/Menu.h
        action/interface/Command.h
        menu/Menu.cpp
        action/movement/GoNorth.h
        action/movement/GoNorth.cpp
        action/movement/GoSouth.h
        action/movement/GoEast.h
        action/movement/GoWest.h
        action/movement/GoSouth.cpp
        action/movement/GoEast.cpp
        action/movement/GoWest.cpp
        player/Player.h
        player/Player.cpp
)
