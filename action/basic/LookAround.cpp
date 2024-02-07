#include "LookAround.h"

LookAround::LookAround() {
    if (Player::getX() == 0 && Player::getY() == 0)
        sLocationName = "Plains";
    else if (Player::getX() == 0 && Player::getY() == 1)
        sLocationName = "Mountainside";
}

void LookAround::execute() {
    std::vector<std::string> text;

    if (sLocationName == "Plains") {
        text.emplace_back("You are standing in a wide plain. Foothills stretch to the north,");
        text.emplace_back("where clouds gather around an ominous peak. A dirt path winds");
        text.emplace_back("from a lonely chapel to the east, through the plains where you're");
        text.emplace_back("standing, and south into a bustling town. Wispy mists gather");
        text.emplace_back("over marshland in the west, where a thin tower stands alone");
        text.emplace_back("in the bog.");

        text.emplace_back("You examine your surroundings...");

        TextOutput::writeText(text);

    } else if (sLocationName == "Mountainside") {
        text.emplace_back("You are on the craggy, windblasted face of a mountain. Stormclouds");
        text.emplace_back("coil above the summit, pelting you and the sparse vegetation with");
        text.emplace_back("torrential downpour. Far below, beyond the foothills, a wide");
        text.emplace_back("plain stretches across the southern horizon.\n");
        text.emplace_back("Grelok is here, spewing heresies.\n");
        text.emplace_back("A glint between the rocks catches your eye.");

        text.emplace_back(" You examine your surroundings...");

        TextOutput::writeText(text);
    }

    LocationEvents::changeValueLookedAround(Player::getX(), Player::getY());
}

std::string LookAround::getDescription() const {
    return "(" + sLocationName + ") Look Around";
}