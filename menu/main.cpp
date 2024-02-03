#include "Menu.h"
#include "../action/movement/GoNorth.h"
#include "../action/movement/GoSouth.h"
#include "../action/movement/GoEast.h"
#include "../action/movement/GoWest.h"
#include "../action/special/LookAround.h"

int main() {
    std::vector<Command*> vCommandList;
    vCommandList.push_back(new LookAround(Player::getX(), Player::getY()));
    vCommandList.push_back(new GoNorth);
    vCommandList.push_back(new GoSouth);
    vCommandList.push_back(new GoEast);
    vCommandList.push_back(new GoWest);

    while (true) {
        Menu menu(vCommandList);
        menu.start();
        vCommandList[0] = new LookAround(Player::getX(), Player::getY());
    }
}
