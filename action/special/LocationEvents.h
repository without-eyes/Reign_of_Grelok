#pragma once

class LocationEvents {
public:
    static bool isLookedAround(int x, int y);
    static void changeValueLookedAround(int x, int y);

private:
    inline static bool aIsLookedAround[3][3] = {false};
};
