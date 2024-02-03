#include "Menu.h"

Menu::Menu(const std::vector<Command*>& vCommandList) {
    this->vCommandList = vCommandList;
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

[[noreturn]] void Menu::start() {
    std::vector<int> vLineColor(vCommandList.size(), 7);
    int nUserMenuPosition = 1;

    while (true) {
        short sX = 10, sY = 5; // CHANGE

        for (int i = 0; i < vCommandList.size(); i++) {
            placeText(sX, sY++);
            color(vLineColor[i - 1]);
            std::cout << "> " << vCommandList[i]->getDescription();
        }

        userInput(nUserMenuPosition);

        fill(vLineColor.begin(), vLineColor.end(), 7);

        vLineColor[nUserMenuPosition - 1] = 10;
    }
}

void Menu::userInput(int& nUserMenuPosition) {
    int key = _getch();

    if (key == 72 && (nUserMenuPosition >=2 && nUserMenuPosition <= 5)) {
        nUserMenuPosition--;
    } else if (key == 80 && (nUserMenuPosition >=1 && nUserMenuPosition <= 4)) {
        nUserMenuPosition++;
    } else if (key == '\r') {
        vCommandList[nUserMenuPosition]->execute();
    }
}
