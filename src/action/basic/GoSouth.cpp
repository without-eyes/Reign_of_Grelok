#include <rog/action/basic/GoSouth.h>

#include <rog/player/Player.h>
#include <rog/ui/menu/Menu.h>

void GoSouth::execute() {
    if (Player::getY() != 0) {
        Menu::setLowerText(" You retreat to the south...");
    }
    Player::changeY(-1);
}

std::string GoSouth::getDescription() const {
    return "Go South";
}


