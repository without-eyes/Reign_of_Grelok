#include <rog/action/special/LocationEvents.h>

bool LocationEvents::hasLookedAround(short positionX, short positionY) {
    return isLookedAround[positionY][positionX];
}

void LocationEvents::changeValueLookedAround(short positionX, short positionY) {
    isLookedAround[positionY][positionX] = true;
}

bool LocationEvents::hasFoundRawGemstone() {
    return foundRawGemstone;
}

void LocationEvents::changeValueFoundRawGemstone() {
    foundRawGemstone = !foundRawGemstone;
}


bool LocationEvents::hasZombieKilled() {
    return isZombieKilled;
}

void LocationEvents::changeValueZombieKilled() {
    isZombieKilled = !isZombieKilled;
}

bool LocationEvents::hasExaminedGrave() {
    return examinedGrave;
}

void LocationEvents::changeValueExaminedGrave() {
    examinedGrave = !examinedGrave;
}

bool LocationEvents::hasSpokenToWizard() {
    return spokeToWizard;
}

void LocationEvents::changeValueSpokeToWizard() {
    spokeToWizard = !spokeToWizard;
}

bool LocationEvents::hasUnlockedChapel() {
    return unlockedChapel;
}

void LocationEvents::changeValueUnlockedChapel() {
    unlockedChapel = !unlockedChapel;
}

bool LocationEvents::hasFilledFlask() {
    return filledFlask;
}

void LocationEvents::changeValueFilledFlask() {
    filledFlask = !filledFlask;
}