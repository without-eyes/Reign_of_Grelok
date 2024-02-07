#include "GoSouth.h"

void GoSouth::execute() {
    Player::changeY(-1);
}

std::string GoSouth::getDescription() const {
    return "Go South";
}


