#pragma once

#include <vector>
#include <string>

class TextOutput {
public:
    static void addBlinkingUnderscore();
    static void removeBlinkingUnderscore();
    static void changeColor(int nColor);
    static void placeStringOnScreen(short sX, short sY);
    static void writeText(const std::vector<std::string>& vText);

private:
    static void typingEffectOutput(const std::string &text);
};