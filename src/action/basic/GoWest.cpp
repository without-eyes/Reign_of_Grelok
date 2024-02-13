#include <rog/action/basic/GoWest.h>

void GoWest::execute() {
    Player::changeX(-1);
}

std::string GoWest::getDescription() const {
    return "Go West";
}


