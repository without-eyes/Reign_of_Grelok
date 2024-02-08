#include "Inventory.h"

void Inventory::execute() {
    Menu::start(vItems);
}

std::string Inventory::getDescription() const {
    return "Inventory";
}

void Inventory::addItem(const std::string& sItemName) {
    vItems.emplace_back(sItemName);
}

void Inventory::removeItem(const std::string& sItemName) {
    vItems.erase(std::find(vItems.begin(), vItems.end(), sItemName));
}

bool Inventory::hasItem(const std::string &sItemName) {
    return std::find(vItems.begin(), vItems.end(), sItemName) != vItems.end();
}

std::string Inventory::getItemDescription(const std::string &sItemName) {
    if (sItemName == "Rusty Sword") {
        return "Your weapon. Rusty, but trusty.";
    } else if (sItemName == "Drinking Flask") {
        return "A very small flask to carry water.";
    } else if (sItemName == "Zombie Head") {
        return "The smell may make you unpopular...";
    } else if (sItemName == "Refined Gemstone") {
        return "A brilliant, faceted gemstone";
    } else if (sItemName == "Magical Shard") {
        return "The gem shard pulses with magical light...";
    } else if (sItemName == "Magic Sword") {
        return "An enchanted weapon to defeat Grelok";
    } else if (sItemName == "Brass Key") {
        return "Key given to you by the priest";
    } else if (sItemName == "Raw Gemstone") {
        return "This gemstone may be valuable...";
    }
}

