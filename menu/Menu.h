#pragma once

#include "../action/interface/Command.h"

class Menu {
public:
    explicit Menu(const std::vector<Command*>& vCommandList);

    static void color(int nColor);
    static void placeText(short x, short y);

    [[noreturn]] void start();
    void userInput(int& nUserMenuPosition);

private:
    std::vector<Command*> vCommandList;
};