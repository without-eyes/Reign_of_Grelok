#include <rog/action/special/UseSwordGrelok.h>

#include <rog/ui/menu/Menu.h>

void UseSwordGrelok::execute() {
    if (Inventory::hasItem(Inventory::ItemType::RustySword)) {
        Menu::setLowerText("Your puny weapons are useless on Grelok.");
    } else {

    }
}

std::string UseSwordGrelok::getDescription() const {
    return "Use Sword Grelok";
}
