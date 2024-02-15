#include <rog/action/basic/Back.h>

#include <rog/player/Player.h>

void Back::execute() {
    if (Player::getX() != 0) {
        Player::changeX(-Player::getX());
    }

    if (Player::getY() != 0) {
        Player::changeY(-Player::getY());
    }
}

std::string Back::getDescription() const {
    return "Back";
}
