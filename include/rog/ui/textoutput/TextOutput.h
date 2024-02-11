#pragma once

#include <vector>
#include <string>

class TextOutput {
public:
    static void addBlinkingUnderscore();
    static void removeBlinkingUnderscore();

    static void changeColor(int colorNumber);

    static void placeStringOnScreen(short positionX, short positionY);

    static void writeText(const std::vector<std::string> &text);

private:
    static void typingEffectOutput(const std::string &text);
};