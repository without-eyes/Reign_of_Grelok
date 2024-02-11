#include <rog/player/Inventory.h>
#include "rog/ui/menu/Menu.h"
#include <algorithm>

void Inventory::execute() {
    Menu::start(items);
}

std::string Inventory::getDescription() const {
    return "Inventory";
}

void Inventory::addItem(ItemType itemType) {
    items.emplace_back(itemType);
}

void Inventory::removeItem(ItemType itemType) {
    items.erase(std::remove(items.begin(), items.end(), itemType), items.end());
}

std::string Inventory::getItemName(Inventory::ItemType itemType) {
    switch (itemType) {
        case ItemType::RustySword:
            return "Rusty Sword";
        case ItemType::DrinkingFlask:
            return "Drinking Flask";
        case ItemType::ZombieHead:
            return "Zombie Head";
        case ItemType::RefinedGemstone:
            return "Refined Gemstone";
        case ItemType::MagicalShard:
            return "Magical Shard";
        case ItemType::MagicSword:
            return "Magic Sword";
        case ItemType::BrassKey:
            return "Brass Key";
        case ItemType::RawGemstone:
            return "Raw Gemstone";
        default:
            return "Unknown Item";
    }
}

bool Inventory::hasItem(ItemType itemType) {
    return std::find(items.begin(), items.end(), itemType) != items.end();
}

std::string Inventory::getItemDescription(ItemType itemType) {
    switch (itemType) {
        case ItemType::RustySword:
            return "Your weapon. Rusty, but trusty.";
        case ItemType::DrinkingFlask:
            return "A very small flask to carry water.";
        case ItemType::ZombieHead:
            return "The smell may make you unpopular...";
        case ItemType::RefinedGemstone:
            return "A brilliant, faceted gemstone";
        case ItemType::MagicalShard:
            return "The gem shard pulses with magical light...";
        case ItemType::MagicSword:
            return "An enchanted weapon to defeat Grelok";
        case ItemType::BrassKey:
            return "Key given to you by the priest";
        case ItemType::RawGemstone:
            return "This gemstone may be valuable...";
        default:
            return "Unknown Item";
    }
}
