#include <rog/action/special/UseSwordGrelok.h>

#include <rog/ui/menu/Menu.h>

void UseSwordGrelok::execute() {
    Menu::setLowerText("Your puny weapons are useless on Grelok.");
}

std::string UseSwordGrelok::getDescription() const {
    return "Use Sword Grelok";
}
