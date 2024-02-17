#include <rog/ui/menu/Menu.h>

#include <rog/ui/textoutput/TextOutput.h>
#include <iostream>
#include <conio.h>
#include <wincon.h>

void Menu::start(const std::vector<Command *> &commandList) {
    system("cls");

    std::vector<CHAR_INFO> lineColor(commandList.size());
    for (int i = 1; i < commandList.size(); ++i) {
        lineColor[i].Attributes = FOREGROUND_GREEN;
    }
    lineColor[0].Attributes = BACKGROUND_GREEN;

    int userMenuPosition = 1;
    bool exitMenu = false;

    while (!exitMenu) {
        TextOutput::removeBlinkingUnderscore();

        short sX = 3, sY = 1;

        for (int i = 0; i < commandList.size(); i++) {
            TextOutput::placeStringOnScreen(sX, sY++);
            TextOutput::changeColor(lineColor[i].Attributes);
            std::cout << "> " << commandList[i]->getDescription();
        }

        TextOutput::placeStringOnScreen(sX, sY + 3);
        TextOutput::changeColor(FOREGROUND_GREEN);
        std::cout << "> " + lowerText;

        TextOutput::addBlinkingUnderscore();

        userInput(commandList, userMenuPosition, exitMenu);

        for (int i = 0; i < commandList.size(); ++i) {
            lineColor[i].Attributes = FOREGROUND_GREEN;
        }

        lineColor[userMenuPosition - 1].Attributes = BACKGROUND_GREEN;
    }
}

void Menu::userInput(const std::vector<Command *> &commandList, int &userMenuPosition, bool &exitMenu) {
    int key = _getch();

    mciSendString("play ..\\other\\sounds\\ui_menu_prevnext.wav", NULL, 0, NULL);

    if (key == 72 && (userMenuPosition >= 2 && userMenuPosition <= commandList.size())) {
        userMenuPosition--;
    } else if (key == 80 && (userMenuPosition >= 1 && userMenuPosition <= commandList.size() - 1)) {
        userMenuPosition++;
    } else if (key == '\r') {
        mciSendString("play ..\\other\\sounds\\ui_menu_ok.wav", NULL, 0, NULL);
        commandList[userMenuPosition - 1]->execute();
        exitMenu = true;
    }
}

void Menu::start(const std::vector<Inventory::ItemType> &items) {
    system("cls");

    int menuSize = items.size() + 1;
    std::vector<CHAR_INFO> lineColor(menuSize);
    for (int i = 1; i < menuSize; ++i) {
        lineColor[i].Attributes = FOREGROUND_GREEN;
    }
    lineColor[0].Attributes = BACKGROUND_GREEN;

    lowerText = "";
    int userInventoryPosition = 1;
    bool exitInventory = false;

    while (!exitInventory) {
        TextOutput::removeBlinkingUnderscore();

        short sX = 3, sY = 1;

        for (int i = 0; i < items.size(); i++) {
            TextOutput::placeStringOnScreen(sX, sY++);
            TextOutput::changeColor(lineColor[i].Attributes);
            std::cout << "> " << Inventory::getItemName(items[i]);
        }
        TextOutput::placeStringOnScreen(sX, sY++);
        TextOutput::changeColor(lineColor[items.size()].Attributes);
        std::cout << "> Back";

        TextOutput::placeStringOnScreen(sX, sY + 3);
        TextOutput::changeColor(FOREGROUND_GREEN);
        std::cout << "> " + lowerText;

        TextOutput::addBlinkingUnderscore();

        userInput(items, userInventoryPosition, exitInventory);

        for (int i = 0; i < menuSize; ++i) {
            lineColor[i].Attributes = FOREGROUND_GREEN;
        }

        lineColor[userInventoryPosition - 1].Attributes = BACKGROUND_GREEN;
    }
}

void Menu::userInput(const std::vector<Inventory::ItemType> &items, int &userInventoryPosition, bool &exitInventory) {
    int key = _getch();

    mciSendString("play ..\\other\\sounds\\ui_menu_prevnext.wav", NULL, 0, NULL);

    int menuSize = items.size() + 1;
    if (key == 72 && (userInventoryPosition >= 2 && userInventoryPosition <= menuSize)) {
        userInventoryPosition--;
    } else if (key == 80 && (userInventoryPosition >= 1 && userInventoryPosition <= items.size())) {
        userInventoryPosition++;
    } else if (key == '\r') {
        mciSendString("play ..\\other\\sounds\\ui_menu_ok.wav", NULL, 0, NULL);

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
