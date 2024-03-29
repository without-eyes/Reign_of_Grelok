cmake_minimum_required(VERSION 3.27)
project(Reign_of_Grelok)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(GAME_NAME Reign_of_Grelok)

add_executable(${GAME_NAME}
        src/ui/menu/main.cpp
        src/player/Inventory.cpp
        src/ui/menu/Menu.cpp
        src/action/basic/GoNorth.cpp
        src/action/basic/GoSouth.cpp
        src/action/basic/GoEast.cpp
        src/action/basic/GoWest.cpp
        src/player/Player.cpp
        src/action/basic/LookAround.cpp
        src/ui/textoutput/TextOutput.cpp
        src/action/special/UseSwordGrelok.cpp
        src/action/special/InvestigateGlintingObject.cpp
        src/action/special/LocationEvents.cpp
        src/action/special/UseSwordZombie.cpp
        src/action/special/ExamineGrave.cpp
        src/action/special/TalkToTheWizard.cpp
        src/action/special/SpeakWithBlacksmith.cpp
        include/rog/action/special/SpeakWithBlacksmith.h
        src/action/special/SpeakWithPriest.cpp
        include/rog/action/special/SpeakWithPriest.h
        src/action/special/ExamineChapel.cpp
        include/rog/action/special/ExamineChapel.h
        src/action/special/UseMagicalSwordGrelok.cpp
        include/rog/action/special/UseMagicalSwordGrelok.h
        src/action/basic/Back.cpp
        include/rog/action/basic/Back.h
        src/action/special/GameOver.cpp
        include/rog/action/special/GameOver.h
)

target_include_directories(
        ${GAME_NAME}
        PRIVATE
        include
)

target_link_libraries(Reign_of_Grelok PRIVATE winmm)
