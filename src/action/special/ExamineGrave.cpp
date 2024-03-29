#include <rog/action/special/ExamineGrave.h>

#include <rog/ui/textoutput/TextOutput.h>
#include <rog/player/Inventory.h>
#include <rog/action/special/LocationEvents.h>

void ExamineGrave::execute() {
    std::vector<std::string> text;

    if (!LocationEvents::hasZombieKilled()) {

        text.emplace_back("There is a deep, empty grave in the cemetery. Several bloated rats");
        text.emplace_back("floating in a foot of filthy water at the bottom. Don't fall in!");

    } else if (!LocationEvents::hasExaminedGrave() && !Inventory::hasItem(Inventory::ItemType::ZombieHead)) {

        text.emplace_back("There is a deep, empty grave in the cemetery. Several bloated rats and");
        text.emplace_back("a zombie corpse float in a foot of filthy water at the bottom. Don't fall");
        text.emplace_back("in!\n");

        text.emplace_back("A grotesque zombie head is stuck on a root near the top of the grave.");
        text.emplace_back("You bag the horrific trophy as proof of your deed.");

        Inventory::addItem(Inventory::ItemType::ZombieHead);
        LocationEvents::changeValueExaminedGrave();

    } else {

        text.emplace_back("There is a deep, empty grave in the cemetery. Several bloated rats and");
        text.emplace_back("a zombie corpse float in a foot of filthy water at the bottom. Don't fall");
        text.emplace_back("in!");

    }

    text.emplace_back("You peer into the open grave...");

    TextOutput::writeText(text);
}

std::string ExamineGrave::getDescription() const {
    return "Examine grave";
}
