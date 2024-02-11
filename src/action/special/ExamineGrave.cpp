#include "rog/action/special/ExamineGrave.h"

void ExamineGrave::execute() {
    std::vector<std::string> vText;

    if (!LocationEvents::isZombieKilled()) {

        vText.emplace_back("There is a deep, empty grave in the cemetery. Several bloated rats");
        vText.emplace_back("floating in a foot of filthy water at the bottom. Don't fall in!");

    } else {

        vText.emplace_back("There is a deep, empty grave in the cemetery. Several bloated rats");
        vText.emplace_back("floating in a foot of filthy water at the bottom. Don't fall in!\n");

        vText.emplace_back("A grotesque zombie head is stuck on a root near the top of the grave.");
        vText.emplace_back("You bag the horrific trophy as proof of your deed.");

        Inventory::addItem("Zombie Head");

    }

    vText.emplace_back("You peer into the open grave...");

    TextOutput::writeText(vText);
}

std::string ExamineGrave::getDescription() const {
    return "Examine grave";
}
