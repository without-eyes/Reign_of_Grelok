#include <windows.h>
#include <rog/ui/menu/Menu.h>
#include <rog/action/basic/LookAround.h>
#include <rog/action/basic/GoNorth.h>
#include <rog/action/basic/GoSouth.h>
#include <rog/action/basic/GoEast.h>
#include <rog/action/basic/GoWest.h>
#include <rog/player/Inventory.h>
#include <rog/action/special/LocationEvents.h>
#include <rog/action/special/InvestigateGlintingObject.h>
#include <rog/action/special/UseSwordGrelok.h>
#include <rog/action/special/UseSwordZombie.h>
#include <rog/action/special/ExamineGrave.h>
#include <rog/action/special/TalkToTheWizard.h>
#include <rog/action/special/SpeakWithBlacksmith.h>

int main() {
    while (true) {
        SetConsoleTitle("Reign of Grelok (beta v.632)");

        std::vector<Command *> commandList;

        if (Player::getX() == 0 && Player::getY() == 0) { // MIDDLE

            commandList.push_back(new LookAround);
            commandList.push_back(new GoNorth);
            commandList.push_back(new GoSouth);
            commandList.push_back(new GoEast);
            commandList.push_back(new GoWest);
            commandList.push_back(new Inventory);

        } else if (Player::getX() == 0 && Player::getY() == 1) { // NORTH
            SetConsoleTitle("Reign of Grelok (beta v.632) - Grelok is here, spewing heresies.");

            commandList.push_back(new LookAround);
            if (LocationEvents::hasLookedAround(Player::getX(), Player::getY())) {
                if (!Inventory::hasItem(Inventory::ItemType::RawGemstone) &&
                    !Inventory::hasItem(Inventory::ItemType::MagicalShard) &&
                    !Inventory::hasItem(Inventory::ItemType::MagicSword)) {
                    commandList.push_back(new InvestigateGlintingObject);
                }
                commandList.push_back(new UseSwordGrelok);
            }
            commandList.push_back(new GoSouth);
            commandList.push_back(new Inventory);
            // Back ???

        } else if (Player::getX() == 1 && Player::getY() == 0) { // EAST

            commandList.push_back(new LookAround);
            if (LocationEvents::hasLookedAround(Player::getX(), Player::getY())) {
                if (!LocationEvents::hasZombieKilled()) {
                    commandList.push_back(new UseSwordZombie);
                }
                commandList.push_back(new ExamineGrave);
            }
            commandList.push_back(new GoWest);
            commandList.push_back(new Inventory);
            // Back ????

        } else if (Player::getX() == -1 && Player::getY() == 0) { // WEST

            commandList.push_back(new LookAround);
            if (LocationEvents::hasLookedAround(Player::getX(), Player::getY())) {
                commandList.push_back(new TalkToTheWizard);
            }
            commandList.push_back(new GoEast);
            commandList.push_back(new Inventory);
            // Back ????

        } else if (Player::getX() == 0 && Player::getY() == -1) { // SOUTH

            commandList.push_back(new LookAround);
            if (LocationEvents::hasLookedAround(Player::getX(), Player::getY())) {
                commandList.push_back(new SpeakWithBlacksmith);
            }
            commandList.push_back(new GoNorth);
            commandList.push_back(new Inventory);
            // Back ????

        }

        Menu::start(commandList);
    }
}
