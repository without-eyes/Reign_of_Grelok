#include <rog/action/basic/LookAround.h>

#include <rog/ui/textoutput/TextOutput.h>
#include <rog/action/special/LocationEvents.h>
#include <rog/player/Inventory.h>

void LookAround::execute() {
    std::vector<std::string> text;

    switch (getLocationType()) {

        case LocationType::Plains:
            text.emplace_back("You are standing in a wide plain. Foothills stretch to the north,");
            text.emplace_back("where clouds gather around an ominous peak. A dirt path winds");
            text.emplace_back("from a lonely chapel to the east, through the plains where you're");
            text.emplace_back("standing, and south into a bustling town. Wispy mists gather");
            text.emplace_back("over marshland in the west, where a thin tower stands alone");
            text.emplace_back("in the bog.");
            break;

        case LocationType::Mountainside:
            text.emplace_back("You are on the craggy, windblasted face of a mountain. Stormclouds");
            text.emplace_back("coil above the summit, pelting you and the sparse vegetation with");
            text.emplace_back("torrential downpour. Far below, beyond the foothills, a wide");
            text.emplace_back("plain stretches across the southern horizon.\n");

            text.emplace_back("Grelok is here, spewing heresies.\n");

            text.emplace_back("A glint between the rocks catches your eye.");
            break;

        case LocationType::Town:
            text.emplace_back("You're standing in the dusty market square of a quiet town. Many of");
            text.emplace_back("the shops and homes lie abandoned, and the citizens that can be seen");
            text.emplace_back("speak in hushed voices, casting furtive glances at the darkened skyline");
            text.emplace_back("in the distant north. The ringing of an anvil breaks the silence regularly,");
            text.emplace_back("where a mustachioed blacksmith bends over his work in a nearby tent.\n");

            text.emplace_back("The blacksmith is here, working.\n");

            text.emplace_back("A priest is here, drinking.");
            break;

        case LocationType::Chapel:
            text.emplace_back("You stand at the end of a dirt path, facing a small chapel. The");
            text.emplace_back("stucco walls are faded, many roof tiles are missing. The great oaken");
            text.emplace_back("doors are locked. The congregation is nowhere to be found. A small");
            text.emplace_back("cemetery of crooked headstones lies in the shadow of the cracked steeple.");
            text.emplace_back("The dirt path winds westward through a great, featureless plain.\n");

            if (!LocationEvents::hasZombieKilled()) {
                text.emplace_back("A zombie totters aimlessly nearby.\n");
            }

            if (Inventory::hasItem(Inventory::ItemType::BrassKey)) {
                text.emplace_back("The chapel doors are unlocked.");
                LocationEvents::changeValueUnlockedChapel();
            }

            text.emplace_back("There is an open grave nearby.");
            break;

        case LocationType::Swamp:
            text.emplace_back("You are standing on a narrow stone path in a dark marsh. Greasy bubbles");
            text.emplace_back("float to the top of the bog-waters on either side and pop lazily,");
            text.emplace_back("spattering your legs with muck and slime. A short, stone tower squats");
            text.emplace_back("here. No door is visible, and the stones are smooth and polished. A balcony");
            text.emplace_back("juts out midway up the tower's face. The heady smells of incense mix with");
            text.emplace_back("the nauseating stench of the swamp. The stone path unfurls eastward, towards");
            text.emplace_back("a broad plain beyond the marshes.\n");

            text.emplace_back("A wizard is here, gesticulating wildly from his balcony.");
            break;

    }

    text.emplace_back(" You examine your surroundings...");

    TextOutput::writeText(text);

    LocationEvents::changeValueLookedAround(Player::getX(), Player::getY());
}

std::string LookAround::getDescription() const {
    std::string locationName;

    switch (getLocationType()) {
        case LocationType::Plains:
            locationName = "Plains";
            break;
        case LocationType::Mountainside:
            locationName = "Mountainside";
            break;
        case LocationType::Town:
            locationName = "Town";
            break;
        case LocationType::Chapel:
            locationName = "Chapel";
            break;
        case LocationType::Swamp:
            locationName = "Swamp";
            break;
    }

    return "(" + locationName + ") Look Around";
}

LookAround::LocationType LookAround::getLocationType() {
    if (Player::getX() == 0 && Player::getY() == 0) {
        return LocationType::Plains;
    } else if (Player::getX() == 0 && Player::getY() == 1) {
        return LocationType::Mountainside;
    } else if (Player::getX() == 0 && Player::getY() == -1) {
        return LocationType::Town;
    } else if (Player::getX() == 1 && Player::getY() == 0) {
        return LocationType::Chapel;
    } else if (Player::getX() == -1 && Player::getY() == 0) {
        return LocationType::Swamp;
    }
}
