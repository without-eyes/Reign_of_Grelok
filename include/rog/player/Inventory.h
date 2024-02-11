#pragma once

#include <string>
#include <vector>
#include "rog/action/interface/Command.h"


class Inventory : public Command {
public:
    enum class ItemType {
        RustySword,
        DrinkingFlask,
        ZombieHead,
        RefinedGemstone,
        MagicalShard,
        MagicSword,
        BrassKey,
        RawGemstone
    };

    void execute() override;
    std::string getDescription() const override;

    static void addItem(ItemType itemType);

    static void removeItem(ItemType itemType);

    static std::string getItemName(ItemType itemType);

    static bool hasItem(ItemType itemType);

    static std::string getItemDescription(ItemType itemType);

private:
    inline static std::vector<ItemType> items = {ItemType::RustySword, ItemType::DrinkingFlask};
};
