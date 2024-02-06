#include "Menu.h"
#include "../../action/special/LookAround.h"
#include "../../action/movement/GoNorth.h"
#include "../../action/movement/GoSouth.h"
#include "../../action/movement/GoEast.h"
#include "../../action/movement/GoWest.h"

int main() {
    while (true) {
        SetConsoleTitle("Reign of Grelok (beta v.632)");

        std::vector<Command*> vCommandList;

        if (Player::getX() == 0 && Player::getY() == 0) {
            vCommandList.push_back(new LookAround(Player::getX(), Player::getY()));
            vCommandList.push_back(new GoNorth);
            vCommandList.push_back(new GoSouth);
            vCommandList.push_back(new GoEast);
            vCommandList.push_back(new GoWest);
            vCommandList.push_back(new Inventory);
        } else if (Player::getX() == 0 && Player::getY() == 1) {
            SetConsoleTitle("Reign of Grelok (beta v.632) - Grelok is here, spewing heresies.");

            vCommandList.push_back(new LookAround(Player::getX(), Player::getY()));
            vCommandList.push_back(new GoSouth);
            vCommandList.push_back(new Inventory);
            // Back ???
        }

        Menu::start(vCommandList);
    }
}
