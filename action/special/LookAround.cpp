#include "LookAround.h"

LookAround::LookAround(short sX, short sY) {
    if (sX == 0 && sY == 0)
        sLocationName = "Plains";
    else if (sX == 0 && sY == 1)
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

    }
}

std::string LookAround::getDescription() const {
    return "(" + sLocationName + ") Look Around";
}