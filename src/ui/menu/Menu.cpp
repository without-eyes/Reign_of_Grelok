#include "rog/ui/menu/Menu.h"
#include <iostream>
#include <conio.h>

void Menu::start(const std::vector<Command *> &commandList) {
    system("cls");

    std::vector<int> lineColor(commandList.size(), 7);
    lineColor[0] = 10;

    int userMenuPosition = 1;
    bool exitMenu = false;

    while (!exitMenu) {
        TextOutput::removeBlinkingUnderscore();

        short sX = 3, sY = 1;

        for (int i = 0; i < commandList.size(); i++) {
            TextOutput::placeStringOnScreen(sX, sY++);
            TextOutput::changeColor(lineColor[i]);
            std::cout << "> " << commandList[i]->getDescription();
        }

        TextOutput::placeStringOnScreen(sX, sY + 3);
        TextOutput::changeColor(7);
        std::cout << "> " + lowerText;

        TextOutput::addBlinkingUnderscore();

        userInput(commandList, userMenuPosition, exitMenu);

        fill(lineColor.begin(), lineColor.end(), 7);

        lineColor[userMenuPosition - 1] = 10;
    }
}

void Menu::userInput(const std::vector<Command *> &commandList, int &userMenuPosition, bool &exitMenu) {
    int key = _getch();

    if (key == 72 && (userMenuPosition >= 2 && userMenuPosition <= commandList.size())) {
        userMenuPosition--;
    } else if (key == 80 && (userMenuPosition >= 1 && userMenuPosition <= commandList.size() - 1)) {
        userMenuPosition++;
    } else if (key == '\r') {
        commandList[userMenuPosition - 1]->execute();
        exitMenu = true;
    }
}

void Menu::start(const std::vector<Inventory::ItemType> &items) {
    system("cls");

    int menuSize = items.size() + 1;
    std::vector<int> lineColor(menuSize, 7);
    lineColor[0] = 10;

    lowerText = "";
    int userInventoryPosition = 1;
    bool exitInventory = false;

    while (!exitInventory) {
        TextOutput::removeBlinkingUnderscore();

        short sX = 3, sY = 1;

        for (int i = 0; i < items.size(); i++) {
            TextOutput::placeStringOnScreen(sX, sY++);
            TextOutput::changeColor(lineColor[i]);
            std::cout << "> " << Inventory::getItemName(items[i]);
        }
        TextOutput::placeStringOnScreen(sX, sY++);
        TextOutput::changeColor(lineColor[items.size()]);
        std::cout << "> Back";

        TextOutput::placeStringOnScreen(sX, sY + 3);
        TextOutput::changeColor(7);
        std::cout << "> " + lowerText;

        TextOutput::addBlinkingUnderscore();

        userInput(items, userInventoryPosition, exitInventory);

        fill(lineColor.begin(), lineColor.end(), 7);

        lineColor[userInventoryPosition - 1] = 10;
    }
}

void Menu::userInput(const std::vector<Inventory::ItemType> &items, int &userInventoryPosition, bool &exitInventory) {
    int key = _getch();

    int menuSize = items.size() + 1;
    if (key == 72 && (userInventoryPosition >= 2 && userInventoryPosition <= menuSize)) {
        userInventoryPosition--;
    } else if (key == 80 && (userInventoryPosition >= 1 && userInventoryPosition <= items.size())) {
        userInventoryPosition++;
    } else if (key == '\r') {
        if (userInventoryPosition == menuSize) {
            exitInventory = true;
        } else {
            lowerText = Inventory::getItemDescription(items[userInventoryPosition - 1]);
        }
    }
}

void Menu::setLowerText(const std::string &text) {
    lowerText = text;
}
