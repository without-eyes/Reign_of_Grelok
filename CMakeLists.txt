cmake_minimum_required(VERSION 3.27)
project(Reign_of_Grelok)

set(CMAKE_CXX_STANDARD 20)

add_executable(Reign_of_Grelok userinterface/menu/main.cpp
        player/Inventory.h
        player/Inventory.cpp
        userinterface/menu/Menu.h
        action/interface/Command.h
        userinterface/menu/Menu.cpp
        action/basic/GoNorth.h
        action/basic/GoNorth.cpp
        action/basic/GoSouth.h
        action/basic/GoEast.h
        action/basic/GoWest.h
        action/basic/GoSouth.cpp
        action/basic/GoEast.cpp
        action/basic/GoWest.cpp
        player/Player.h
        player/Player.cpp
        action/basic/LookAround.h
        action/basic/LookAround.cpp
        userinterface/textoutput/TextOutput.h
        userinterface/textoutput/TextOutput.cpp
        other/includes.h
        action/special/UseSwordGrelok.cpp
        action/special/UseSwordGrelok.h
        action/special/InvestigateGlintingObject.cpp
        action/special/InvestigateGlintingObject.h
        action/special/LocationEvents.cpp
        action/special/LocationEvents.h
)
