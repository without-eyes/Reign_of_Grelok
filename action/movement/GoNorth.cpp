#include "GoNorth.h"

void GoNorth::execute() {
    Player::changeY(1);
}

std::string GoNorth::getDescription() const {
    return "Go North";
}


