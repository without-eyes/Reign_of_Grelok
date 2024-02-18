#include <rog/action/basic/Back.h>

#include <rog/player/Player.h>
#include <rog/ui/menu/Menu.h>

void Back::execute() {
    if (Player::getX() != 0) {
        Player::changeX(-Player::getX());
    }

    if (Player::getY() != 0) {
        Player::changeY(-Player::getY());
    }
    Menu::setLowerText("");
}

std::string Back::getDescription() const {
    return "Back";
}
