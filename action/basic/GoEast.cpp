#include "GoEast.h"

void GoEast::execute() {
    Player::changeX(1);
}

std::string GoEast::getDescription() const {
    return "Go East";
}


