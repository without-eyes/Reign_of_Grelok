#include "Menu.h"
#include "../../action/special/LookAround.h"
#include "../../action/movement/GoNorth.h"
#include "../../action/movement/GoSouth.h"
#include "../../action/movement/GoEast.h"
#include "../../action/movement/GoWest.h"

int main() {
    SetConsoleTitle("Reign of Grelok (beta v.632)");

    std::vector<Command*> vCommandList;
    vCommandList.push_back(new LookAround(Player::getX(), Player::getY()));
    vCommandList.push_back(new GoNorth);
    vCommandList.push_back(new GoSouth);
    vCommandList.push_back(new GoEast);
    vCommandList.push_back(new GoWest);
    vCommandList.push_back(new Inventory);

    while (true) {
        Menu::start(vCommandList);
        vCommandList[0] = new LookAround(Player::getX(), Player::getY());
    }
}
