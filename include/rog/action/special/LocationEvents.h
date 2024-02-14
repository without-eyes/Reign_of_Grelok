#pragma once

class LocationEvents {
public:
    static bool hasLookedAround(short positionX, short positionY);

    static void changeValueLookedAround(short positionX, short positionY);

    static bool hasZombieKilled();
    static void changeValueZombieKilled();

    static bool hasSpokenToWizard();

    static void changeValueSpokeToWizard();

private:
    inline static bool isLookedAround[3][3] = {false};
    inline static bool isZombieKilled = false;
    inline static bool spokeToWizard = false;
};
