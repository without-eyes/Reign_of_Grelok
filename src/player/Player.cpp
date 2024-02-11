#include "rog/player/Player.h"

void Player::changeX(const short newX) {
    positionX += newX;
}

void Player::changeY(const short newY) {
    positionY += newY;
}

short Player::getX() {
    return positionX;
}

short Player::getY() {
    return positionY;
}

