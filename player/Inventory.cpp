#include "Inventory.h"

Inventory::Inventory() {
    vItems.emplace_back("Rusty Sword");
    vItems.emplace_back("Drinking Flask");
}

Inventory::~Inventory() {

}

void Inventory::execute() {
    Menu::start(vItems);
}

std::string Inventory::getDescription() const {
    return "Inventory";
}


void Inventory::show() {

}

void Inventory::addItem(const std::string& sItemName) {

}

void Inventory::removeItem(const std::string& sItemName) {

}

std::string Inventory::getItemDescription(const std::string &sItemName) {
    return "test";
}

