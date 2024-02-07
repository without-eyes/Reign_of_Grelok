#include "Menu.h"
#include "../../action/basic/LookAround.h"
#include "../../action/basic/GoNorth.h"
#include "../../action/basic/GoSouth.h"
#include "../../action/basic/GoEast.h"
#include "../../action/basic/GoWest.h"
#include "../../action/special/LocationEvents.h"
#include "../../action/special/InvestigateGlintingObject.h"
#include "../../action/special/UseSwordGrelok.h"

int main() {
    while (true) {
        SetConsoleTitle("Reign of Grelok (beta v.632)");

        std::vector<Command*> vCommandList;

        if (Player::getX() == 0 && Player::getY() == 0) {
            vCommandList.push_back(new LookAround());
            vCommandList.push_back(new GoNorth);
            vCommandList.push_back(new GoSouth);
            vCommandList.push_back(new GoEast);
            vCommandList.push_back(new GoWest);
            vCommandList.push_back(new Inventory);
        } else if (Player::getX() == 0 && Player::getY() == 1) {
            SetConsoleTitle("Reign of Grelok (beta v.632) - Grelok is here, spewing heresies.");

            vCommandList.push_back(new LookAround());
            if (LocationEvents::isLookedAround(Player::getX(), Player::getY())) {
                if (!LocationEvents::isGemstonePicked())
                    vCommandList.push_back(new InvestigateGlintingObject);
                vCommandList.push_back(new UseSwordGrelok);
            }
            vCommandList.push_back(new GoSouth);
            vCommandList.push_back(new Inventory);
            // Back ???
        }

        Menu::start(vCommandList);
    }
}
