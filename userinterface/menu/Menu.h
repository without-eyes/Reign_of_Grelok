#pragma once

#include "../../other/includes.h"
#include "../textoutput/TextOutput.h"
#include "../../action/interface/Command.h"
#include "../../player/Inventory.h"

class Menu {
public:
    static void start(const std::vector<Command*>& vCommandList);
    static void start(const std::vector<std::string>& vItems);

private:
    static void userInput(const std::vector<Command*>& vCommandList, int& nUserMenuPosition, bool& exitMenu);
    static void userInput(const std::vector<std::string>& vItems, int& nUserInventoryPosition, bool& exitInventory, std::string& itemDescription);
};