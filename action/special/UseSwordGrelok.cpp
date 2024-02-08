#include "UseSwordGrelok.h"

void UseSwordGrelok::execute() {
    if (Inventory::hasItem("Rusty Sword")) {
        Menu::setLowerText("Your puny weapons are useless on Grelok.");
    } else {

    }
}

std::string UseSwordGrelok::getDescription() const {
    return "Use Sword Grelok";
}
