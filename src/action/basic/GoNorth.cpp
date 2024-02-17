#include <rog/action/basic/GoNorth.h>

#include <rog/player/Player.h>
#include <rog/ui/menu/Menu.h>

void GoNorth::execute() {
    if (Player::getY() != 0) {
        Menu::setLowerText("You walk to the north...");
    }
    Player::changeY(1);
}

std::string GoNorth::getDescription() const {
    return "Go North";
}


