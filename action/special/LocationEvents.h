#pragma once

class LocationEvents {
public:
    static bool isGemstonePicked();
    static void changeValueGemstoneEvent();

private:
    inline static bool bIsGemstonePicked = false;
};
