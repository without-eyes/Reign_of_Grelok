#pragma once

#include "../action/interface/Command.h"
#include "../userinterface/menu/Menu.h"


class Inventory : public Command{
public:
    void execute() override;
    std::string getDescription() const override;

    static void show();
    static void addItem(const std::string& sItemName);
    static void removeItem(const std::string& sItemName);
    static std::string getItemDescription(const std::string& sItemName);

    inline static std::vector<std::string> vItems = {"Rusty Sword", "Drinking Flask"};
};