#pragma once

class Player {
public:
    static void changeX(short newX);

    static void changeY(short newY);

    static short getX();

    static short getY();

private:
    inline static short positionX = 0;
    inline static short positionY = 0;
};