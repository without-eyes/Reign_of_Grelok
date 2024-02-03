#pragma once

#include "Inventory.h"

class Player {
public:
    static void changeX(short nValue);
    static void changeY(short nValue);

    static short getX();
    static short getY();

private:
    inline static short sX = 0;
    inline static short sY = 0;

    inline static Inventory inventory = Inventory();
};