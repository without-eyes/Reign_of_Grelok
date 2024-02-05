#include "TextOutput.h"

void TextOutput::addBlinkingUnderscore() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void TextOutput::removeBlinkingUnderscore() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void TextOutput::changeColor(const int nColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
}

void TextOutput::placeStringOnScreen(const short sX, const short sY) {
    COORD coordinates;
    coordinates.X = sX;
    coordinates.Y = sY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void TextOutput::typingEffectOutput(const char* text) {
    while (*text) {
        printf("%c\xDB", *text++);
        fflush(stdout);
        Sleep(5);
    }
}

void TextOutput::writeText(const std::vector<std::string>& text) {
    system("cls");

    TextOutput::removeBlinkingUnderscore();

    for (const std::string& line : text) {
        if (line != text.back()) {
            TextOutput::typingEffectOutput(("\n  " + line).c_str());
        } else {
            TextOutput::typingEffectOutput(("\n\n  > " + line).c_str());
        }
    }

    TextOutput::addBlinkingUnderscore();

    Sleep(4000);
    system("cls");

    TextOutput::removeBlinkingUnderscore();

    for (const std::string& line : text) {
        if (line != text.back()) {
            std::cout << "\n  " + line;
        } else {
            std::cout << "\n\n  > ";
        }
    }

    TextOutput::addBlinkingUnderscore();

    getch();
    system("cls");
}