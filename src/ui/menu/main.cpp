#include <windows.h>
#include <rog/ui/menu/Menu.h>
#include <rog/player/Player.h>
#include <rog/action/basic/LookAround.h>
#include <rog/action/basic/GoNorth.h>
#include <rog/action/basic/GoSouth.h>
#include <rog/action/basic/GoEast.h>
#include <rog/action/basic/GoWest.h>
#include <rog/player/Inventory.h>
#include <rog/action/basic/Back.h>
#include <rog/action/special/LocationEvents.h>
#include <rog/action/special/InvestigateGlintingObject.h>
#include <rog/action/special/UseSwordGrelok.h>
#include <rog/action/special/UseSwordZombie.h>
#include <rog/action/special/ExamineGrave.h>
#include <rog/action/special/TalkToTheWizard.h>
#include <rog/action/special/SpeakWithBlacksmith.h>
#include <rog/action/special/SpeakWithPriest.h>
#include <rog/action/special/ExamineChapel.h>
#include <rog/action/special/UseMagicalSwordGrelok.h>
#include "rog/ui/textoutput/TextOutput.h"

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
                if (Inventory::hasItem(Inventory::ItemType::RustySword)) {
                    commandList.push_back(new UseSwordGrelok);
                } else if (Inventory::hasItem(Inventory::ItemType::MagicSword) &&
                           LocationEvents::hasFilledFlask()) {
                    commandList.push_back(new UseMagicalSwordGrelok);
                }

                if (!LocationEvents::hasFoundRawGemstone()) {
                    commandList.push_back(new InvestigateGlintingObject);
                }
            }
            commandList.push_back(new GoSouth);
            commandList.push_back(new Inventory);
            commandList.push_back(new Back);

        } else if (Player::getX() == 1 && Player::getY() == 0) { // EAST

            commandList.push_back(new LookAround);
            if (LocationEvents::hasLookedAround(Player::getX(), Player::getY())) {
                if (!LocationEvents::hasZombieKilled()) {
                    commandList.push_back(new UseSwordZombie);
                }

                if (LocationEvents::hasUnlockedChapel()) {
                    commandList.push_back(new ExamineChapel);
                }

                if (!Inventory::hasItem(Inventory::ItemType::BrassKey) || !LocationEvents::hasUnlockedChapel()) {
                    commandList.push_back(new ExamineGrave);
                }

            }
            commandList.push_back(new GoWest);
            commandList.push_back(new Inventory);
            commandList.push_back(new Back);

        } else if (Player::getX() == -1 && Player::getY() == 0) { // WEST

            commandList.push_back(new LookAround);
            if (LocationEvents::hasLookedAround(Player::getX(), Player::getY())) {
                commandList.push_back(new TalkToTheWizard);
            }
            commandList.push_back(new GoEast);
            commandList.push_back(new Inventory);
            commandList.push_back(new Back);

        } else if (Player::getX() == 0 && Player::getY() == -1) { // SOUTH

            commandList.push_back(new LookAround);
            if (LocationEvents::hasLookedAround(Player::getX(), Player::getY())) {
                commandList.push_back(new SpeakWithBlacksmith);
                commandList.push_back(new SpeakWithPriest);
            }
            commandList.push_back(new GoNorth);
            commandList.push_back(new Inventory);
            commandList.push_back(new Back);

        }

        Menu::start(commandList);
    }
}
