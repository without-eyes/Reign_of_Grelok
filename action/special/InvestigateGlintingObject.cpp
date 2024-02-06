#include "InvestigateGlintingObject.h"

void InvestigateGlintingObject::execute() {
    Menu::sLowerText = " You take a rough gemstone from the rocks";
    Inventory::addItem("Raw Gemstone");
}

std::string InvestigateGlintingObject::getDescription() const {
    return "Investigate glinting object";
}
