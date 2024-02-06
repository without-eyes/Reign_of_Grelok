#include "LocationEvents.h"

bool LocationEvents::isGemstonePicked() {
    return bIsGemstonePicked;
}

void LocationEvents::changeValueGemstoneEvent() {
    bIsGemstonePicked = true;
}
