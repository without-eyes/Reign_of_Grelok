#include <rog/action/special/LocationEvents.h>

bool LocationEvents::hasLookedAround(short positionX, short positionY) {
    return isLookedAround[positionY][positionX];
}

void LocationEvents::changeValueLookedAround(short positionX, short positionY) {
    isLookedAround[positionY][positionX] = true;
}

bool LocationEvents::hasZombieKilled() {
    return isZombieKilled;
}

void LocationEvents::changeValueZombieKilled() {
    isZombieKilled = true;
}
