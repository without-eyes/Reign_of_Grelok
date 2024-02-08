#include "Menu.h"

void Menu::start(const std::vector<Command*>& vCommandList) {
    system("cls");

    std::vector<int> vLineColor(vCommandList.size(), 7);
    vLineColor[0] = 10;

    int nUserMenuPosition = 1;
    bool exitMenu = false;

    while (!exitMenu) {
        TextOutput::removeBlinkingUnderscore();

        short sX = 3, sY = 1;

        for (int i = 0; i < vCommandList.size(); i++) {
            TextOutput::placeStringOnScreen(sX, sY++);
            TextOutput::changeColor(vLineColor[i]);
            std::cout << "> " << vCommandList[i]->getDescription();
        }

        TextOutput::placeStringOnScreen(sX, sY + 3);
        TextOutput::changeColor(7);
        std::cout << "> " + sLowerText;

        TextOutput::addBlinkingUnderscore();

        userInput(vCommandList, nUserMenuPosition, exitMenu);

        fill(vLineColor.begin(), vLineColor.end(), 7);

        vLineColor[nUserMenuPosition - 1] = 10;
    }
}

void Menu::userInput(const std::vector<Command*>& vCommandList, int& nUserMenuPosition, bool& bExitMenu) {
    int key = _getch();

    if (key == 72 && (nUserMenuPosition >= 2 && nUserMenuPosition <= vCommandList.size())) {
        nUserMenuPosition--;
    } else if (key == 80 && (nUserMenuPosition >= 1 && nUserMenuPosition <= vCommandList.size() - 1)) {
        nUserMenuPosition++;
    } else if (key == '\r') {
        vCommandList[nUserMenuPosition - 1]->execute();
        bExitMenu = true;
    }
}

void Menu::start(const std::vector<std::string> &vItems) {
    system("cls");

    int nMenuSize = vItems.size() + 1;
    std::vector<int> vLineColor(nMenuSize, 7);
    vLineColor[0] = 10;

    sLowerText = "";
    int nUserInventoryPosition = 1;
    bool bExitInventory = false;

    while (!bExitInventory) {
        TextOutput::removeBlinkingUnderscore();

        short sX = 3, sY = 1;

        for (int i = 0; i < vItems.size(); i++) {
            TextOutput::placeStringOnScreen(sX, sY++);
            TextOutput::changeColor(vLineColor[i]);
            std::cout << "> " << vItems[i];
        }
        TextOutput::placeStringOnScreen(sX, sY++);
        TextOutput::changeColor(vLineColor[vItems.size()]);
        std::cout << "> Back";

        TextOutput::placeStringOnScreen(sX, sY + 3);
        TextOutput::changeColor(7);
        std::cout << "> " + sLowerText;

        TextOutput::addBlinkingUnderscore();

        userInput(vItems, nMenuSize, nUserInventoryPosition, bExitInventory, sLowerText);

        fill(vLineColor.begin(), vLineColor.end(), 7);

        vLineColor[nUserInventoryPosition - 1] = 10;
    }
}

void Menu::userInput(const std::vector<std::string> &vItems, int nMenuSize, int &nUserInventoryPosition, bool &bExitInventory, std::string& sItemDescription) {
    int key = _getch();

    if (key == 72 && (nUserInventoryPosition >= 2 && nUserInventoryPosition <= nMenuSize)) {
        nUserInventoryPosition--;
    } else if (key == 80 && (nUserInventoryPosition >= 1 && nUserInventoryPosition <= vItems.size())) {
        nUserInventoryPosition++;
    } else if (key == '\r') {
        if (nUserInventoryPosition == nMenuSize) {
            bExitInventory = true;
        } else {
            sItemDescription = Inventory::getItemDescription(vItems[nUserInventoryPosition - 1]);
        }
    }
}

void Menu::setLowerText(const std::string &sText) {
    sLowerText = sText;
}
