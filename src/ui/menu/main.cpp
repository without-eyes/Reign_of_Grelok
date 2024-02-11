#include <windows.h>
#include "rog/ui/menu/Menu.h"
#include "rog/action/basic/LookAround.h"
#include "rog/action/basic/GoNorth.h"
#include "rog/action/basic/GoSouth.h"
#include "rog/action/basic/GoEast.h"
#include "rog/action/basic/GoWest.h"
#include "rog/action/special/LocationEvents.h"
#include "rog/action/special/InvestigateGlintingObject.h"
#include "rog/action/special/UseSwordGrelok.h"
#include "rog/action/special/UseSwordZombie.h"
#include "rog/action/special/ExamineGrave.h"
#include "rog/action/special/TalkToTheWizard.h"

int main() {
    while (true) {
        SetConsoleTitle("Reign of Grelok (beta v.632)");

        std::vector<Command*> vCommandList;

        if (Player::getX() == 0 && Player::getY() == 0) {

            vCommandList.push_back(new LookAround);
            vCommandList.push_back(new GoNorth);
            vCommandList.push_back(new GoSouth);
            vCommandList.push_back(new GoEast);
            vCommandList.push_back(new GoWest);
            vCommandList.push_back(new Inventory);

        } else if (Player::getX() == 0 && Player::getY() == 1) {
            SetConsoleTitle("Reign of Grelok (beta v.632) - Grelok is here, spewing heresies.");

            vCommandList.push_back(new LookAround);
            if (LocationEvents::isLookedAround(Player::getX(), Player::getY())) {
                if (!Inventory::hasItem("Raw Gemstone")) {
                    vCommandList.push_back(new InvestigateGlintingObject);
                }
                vCommandList.push_back(new UseSwordGrelok);
            }
            vCommandList.push_back(new GoSouth);
            vCommandList.push_back(new Inventory);
            // Back ???

        } else if (Player::getX() == 1 && Player::getY() == 0) {

            vCommandList.push_back(new LookAround);
            if (LocationEvents::isLookedAround(Player::getX(), Player::getY())) {
                if (!LocationEvents::isZombieKilled()) {
                    vCommandList.push_back(new UseSwordZombie);
                }
                vCommandList.push_back(new ExamineGrave);
            }
            vCommandList.push_back(new GoWest);
            vCommandList.push_back(new Inventory);
            // Back ????

        } else if (Player::getX() == -1 && Player::getY() == 0) {

            vCommandList.push_back(new LookAround);
            if (LocationEvents::isLookedAround(Player::getX(), Player::getY())) {
                vCommandList.push_back(new TalkToTheWizard);
            }
            vCommandList.push_back(new GoEast);
            vCommandList.push_back(new Inventory);
            // Back ????

        }

        Menu::start(vCommandList);
    }
}
