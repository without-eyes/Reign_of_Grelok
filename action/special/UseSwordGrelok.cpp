#include "UseSwordGrelok.h"

void UseSwordGrelok::execute() {
    if (Inventory::vItems[0] == "Rusty Sword") {
        Menu::sLowerText = "Your puny weapons are useless on Grelok.";
    } else {

    }
}

std::string UseSwordGrelok::getDescription() const {
    return "Use Sword Grelok";
}
