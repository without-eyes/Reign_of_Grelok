#include <rog/action/basic/GoWest.h>

#include <rog/player/Player.h>
#include <rog/ui/menu/Menu.h>

void GoWest::execute() {
    if (Player::getX() != 0) {
        Menu::setLowerText("You walk to the west...");
    }
    Player::changeX(-1);
}

std::string GoWest::getDescription() const {
    return "Go West";
}


