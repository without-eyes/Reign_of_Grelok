#pragma once

class LocationEvents {
public:
    static bool hasLookedAround(short positionX, short positionY);

    static void changeValueLookedAround(short positionX, short positionY);

    static bool hasFoundRawGemstone();

    static void changeValueFoundRawGemstone();

    static bool hasZombieKilled();

    static void changeValueZombieKilled();

    static bool hasExaminedGrave();

    static void changeValueExaminedGrave();

    static bool hasSpokenToWizard();

    static void changeValueSpokeToWizard();

    static bool hasUnlockedChapel();

    static void changeValueUnlockedChapel();

    static bool hasFilledFlask();

    static void changeValueFilledFlask();

    static bool hasKilledGrelok();

    static void changeValueKilledGrelok();

    static bool hasPressedVictory();

    static void changeValuePressedVictory();

private:
    inline static bool isLookedAround[3][3] = {false};
    inline static bool foundRawGemstone = false;
    inline static bool isZombieKilled = false;
    inline static bool examinedGrave = false;
    inline static bool spokeToWizard = false;
    inline static bool unlockedChapel = false;
    inline static bool filledFlask = false;
    inline static bool killedGrelok = false;
    inline static bool pressedVictory = false;
};
