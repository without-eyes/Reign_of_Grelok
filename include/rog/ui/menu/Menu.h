#pragma once

#include "rog/ui/textoutput/TextOutput.h"
#include "rog/action/interface/Command.h"
#include "rog/player/Inventory.h"

class Menu {
public:
    static void start(const std::vector<Command *> &commandList);

    static void start(const std::vector<Inventory::ItemType> &items);

    static void setLowerText(const std::string &text);

private:
    inline static std::string lowerText;

    static void userInput(const std::vector<Command *> &commandList, int &userMenuPosition, bool &exitMenu);

    static void
    userInput(const std::vector<Inventory::ItemType> &items, int &userInventoryPosition, bool &exitInventory);
};