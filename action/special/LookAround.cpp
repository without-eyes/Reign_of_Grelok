#include "LookAround.h"

LookAround::LookAround(short sX, short sY) {
    // Write smth
    if(sX == 0)
        sLocationName = "test";
    else
        sLocationName = "test2";
}

void LookAround::execute() {
    system("cls");
    std::cout << "testing game\n\n";
    system("pause");
    system("cls");
}

std::string LookAround::getDescription() const {
    return "(" + sLocationName + ") Look Around";
}