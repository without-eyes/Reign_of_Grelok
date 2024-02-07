#include "Inventory.h"

void Inventory::execute() {
    Menu::start(vItems);
}

std::string Inventory::getDescription() const {
    return "Inventory";
}

void Inventory::show() {

}

void Inventory::addItem(const std::string& sItemName) {
    vItems.emplace_back(sItemName);
}

void Inventory::removeItem(const std::string& sItemName) {
    vItems.erase(std::find(vItems.begin(), vItems.end(), sItemName));
}

std::string Inventory::getItemDescription(const std::string &sItemName) {
    return "test";
}

