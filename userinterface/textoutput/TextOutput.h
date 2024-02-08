#pragma once

#include "../../other/includes.h"

class TextOutput {
public:
    static void addBlinkingUnderscore();
    static void removeBlinkingUnderscore();
    static void changeColor(int nColor);
    static void placeStringOnScreen(short sX, short sY);
    static void writeText(const std::vector<std::string>& vText);

private:
    static void typingEffectOutput(const char* aText);
};