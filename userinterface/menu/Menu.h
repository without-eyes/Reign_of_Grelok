#pragma once

#include "../../other/includes.h"
#include "../textoutput/TextOutput.h"
#include "../../action/interface/Command.h"
#include "../../player/Inventory.h"

class Menu {
public:
    static void start(const std::vector<Command*>& vCommandList);
    static void start(const std::vector<std::string>& vItems);
    static void setLowerText(const std::string& sText);

private:
    inline static std::string sLowerText;

    static void userInput(const std::vector<Command*>& vCommandList, int& nUserMenuPosition, bool& bExitMenu);
    static void userInput(const std::vector<std::string>& vItems, int nMenuSize, int& nUserInventoryPosition, bool& bExitInventory, std::string& sItemDescription);
};