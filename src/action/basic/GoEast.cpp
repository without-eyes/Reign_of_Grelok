#include <rog/action/basic/GoEast.h>

#include <rog/player/Player.h>
#include <rog/ui/menu/Menu.h>

void GoEast::execute() {
    if (Player::getX() != 0) {
        Menu::setLowerText("You walk to the east...");
    }
    Player::changeX(1);
}

std::string GoEast::getDescription() const {
    return "Go East";
}


