#include "Player.h"

void Player::changeX(const short nValue) {
    sX += nValue;
}

void Player::changeY(const short nValue) {
    sY += nValue;
}

short Player::getX() {
    return sX;
}

short Player::getY() {
    return sY;
}

