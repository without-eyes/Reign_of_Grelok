#include "rog/action/special/InvestigateGlintingObject.h"

void InvestigateGlintingObject::execute() {
    Menu::setLowerText("You take a rough gemstone from the rocks");
    Inventory::addItem(Inventory::ItemType::RawGemstone);
}

std::string InvestigateGlintingObject::getDescription() const {
    return "Investigate glinting object";
}
