#include <rog/action/special/UseSwordZombie.h>

#include <rog/ui/menu/Menu.h>
#include <rog/action/special/LocationEvents.h>

void UseSwordZombie::execute() {
    Menu::setLowerText(" Your blow knocks the zombie into a grave.");
    LocationEvents::changeValueZombieKilled();
}

std::string UseSwordZombie::getDescription() const {
    return "Use sword zombie";
}
