#include "LookAround.h"

void LookAround::execute() {
    std::vector<std::string> vText;

    if (Player::getX() == 0 && Player::getY() == 0) {

        vText.emplace_back("You are standing in a wide plain. Foothills stretch to the north,");
        vText.emplace_back("where clouds gather around an ominous peak. A dirt path winds");
        vText.emplace_back("from a lonely chapel to the east, through the plains where you're");
        vText.emplace_back("standing, and south into a bustling town. Wispy mists gather");
        vText.emplace_back("over marshland in the west, where a thin tower stands alone");
        vText.emplace_back("in the bog.");

    } else if (Player::getX() == 0 && Player::getY() == 1) {

        vText.emplace_back("You are on the craggy, windblasted face of a mountain. Stormclouds");
        vText.emplace_back("coil above the summit, pelting you and the sparse vegetation with");
        vText.emplace_back("torrential downpour. Far below, beyond the foothills, a wide");
        vText.emplace_back("plain stretches across the southern horizon.\n");

        vText.emplace_back("Grelok is here, spewing heresies.\n");

        vText.emplace_back("A glint between the rocks catches your eye.");

    } else if (Player::getX() == 1 && Player::getY() == 0) {

        vText.emplace_back("You stand at the end of a dirt path, facing a small chapel. The");
        vText.emplace_back("stucco walls are faded, many roof tiles are missing. The great oaken");
        vText.emplace_back("doors are locked. The congregation is nowhere to be found. A small");
        vText.emplace_back("cemetery of crooked headstones lies in the shadow of the cracked steeple.");
        vText.emplace_back("The dirt path winds westward through a great, featureless plain.\n");

        vText.emplace_back("A zombie totters aimlessly nearby.\n");

        vText.emplace_back("There is an open grave nearby.");

    } else if (Player::getX() == -1 && Player::getY() == 0) {

        vText.emplace_back("You are standing on a narrow stone path in a dark marsh. Greasy bubbles");
        vText.emplace_back("float to the top of the bog-waters on either side and pop lazily,");
        vText.emplace_back("spattering your legs with muck and slime. A short, stone tower squats");
        vText.emplace_back("here. No door is visible, and the stones are smooth and polished. A balcony");
        vText.emplace_back("juts out midway up the tower's face. The heady smells of incense mix with");
        vText.emplace_back("the nauseating stench of the swamp. The stone path unfurls eastward, towards");
        vText.emplace_back("a broad plain beyond the marshes.\n");

        vText.emplace_back("A wizard is here, gesticulating wildly from his balcony.");

    }

    vText.emplace_back(" You examine your surroundings...");

    TextOutput::writeText(vText);

    LocationEvents::changeValueLookedAround(Player::getX(), Player::getY());
}

std::string LookAround::getDescription() const {
    std::string sLocationName;

    if (Player::getX() == 0 && Player::getY() == 0) {
        sLocationName = "Plains";
    } else if (Player::getX() == 0 && Player::getY() == 1) {
        sLocationName = "Mountainside";
    } else if (Player::getX() == 1 && Player::getY() == 0) {
        sLocationName = "Chapel";
    } else if (Player::getX() == -1 && Player::getY() == 0) {
        sLocationName = "Swamp";
    }

    return "(" + sLocationName + ") Look Around";
}