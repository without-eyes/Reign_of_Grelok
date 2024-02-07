#pragma once

class LocationEvents {
public:
    static bool isLookedAround(int x, int y);
    static void changeValueLookedAround(int x, int y);
    static bool isGemstonePicked();
    static void changeValueGemstoneEvent();

private:
    inline static bool aIsLookedAround[3][3] = {false};
    inline static bool bIsGemstonePicked = false;
};
