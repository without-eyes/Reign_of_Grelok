#include "rog/action/special/InvestigateGlintingObject.h"

void InvestigateGlintingObject::execute() {
    Menu::setLowerText("You take a rough gemstone from the rocks");
    Inventory::addItem("Raw Gemstone");
}

std::string InvestigateGlintingObject::getDescription() const {
    return "Investigate glinting object";
}
