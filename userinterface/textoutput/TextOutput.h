#pragma once

#include "../../other/includes.h"

class TextOutput {
public:
    static void addingBlinkingUnderscore();
    static void removeBlinkingUnderscore();
    static void changeColor(int nColor);
    static void placeStringOnScreen(short x, short y);
    static void writeText(const std::vector<std::string>& text);

private:
    static void typingEffectOutput(const char* text);
};