#pragma once

#include "../action/interface/Command.h"

class Menu {
public:
    explicit Menu(const std::vector<Command*>& vCommandList);

    void start();

private:
    static void color(int nColor);
    static void placeText(short x, short y);
    static void removeBlinkingUnderscore();
    void userInput(int& nUserMenuPosition, bool& exitMenu);

    std::vector<Command*> vCommandList;
};