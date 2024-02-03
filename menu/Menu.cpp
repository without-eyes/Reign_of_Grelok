#include "Menu.h"

Menu::Menu(const std::vector<Command*>& vCommandList) {
    this->vCommandList = vCommandList;
}

void Menu::start() {
    std::vector<int> vLineColor(vCommandList.size(), 7);
    vLineColor[0] = 10;
    int nUserMenuPosition = 1;
    bool exitMenu = false;

    removeBlinkingUnderscore();

    while (!exitMenu) {
        short sX = 3, sY = 1;

        for (int i = 0; i < vCommandList.size(); i++) {
            placeText(sX, sY++);
            color(vLineColor[i]);
            std::cout << "> " << vCommandList[i]->getDescription();
        }

        userInput(nUserMenuPosition, exitMenu);

        fill(vLineColor.begin(), vLineColor.end(), 7);

        vLineColor[nUserMenuPosition - 1] = 10;
    }
}


void Menu::removeBlinkingUnderscore() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Menu::color(const int nColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
}

void Menu::placeText(const short sX, const short sY) {
    COORD coordinates;
    coordinates.X = sX;
    coordinates.Y = sY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void Menu::userInput(int& nUserMenuPosition, bool& exitMenu) {
    int key = _getch();

    if (key == 72 && (nUserMenuPosition >= 2 && nUserMenuPosition <= vCommandList.size())) {
        nUserMenuPosition--;
    } else if (key == 80 && (nUserMenuPosition >= 1 && nUserMenuPosition <= vCommandList.size() - 1)) {
        nUserMenuPosition++;
    } else if (key == '\r') {
        vCommandList[nUserMenuPosition - 1]->execute();
        exitMenu = true;
    }
}