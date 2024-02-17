#include <rog/action/special/InvestigateGlintingObject.h>

#include <rog/ui/menu/Menu.h>
#include <rog/action/special/LocationEvents.h>

void InvestigateGlintingObject::execute() {
    Menu::setLowerText("You take a rough gemstone from the rocks.");
    Inventory::addItem(Inventory::ItemType::RawGemstone);
    LocationEvents::changeValueFoundRawGemstone();
}

std::string InvestigateGlintingObject::getDescription() const {
    return "Investigate glinting object";
}
