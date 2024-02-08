#include "LocationEvents.h"

bool LocationEvents::isLookedAround(int x, int y) {
    return aIsLookedAround[y][x];
}

void LocationEvents::changeValueLookedAround(int x, int y) {
    aIsLookedAround[y][x] = true;
}