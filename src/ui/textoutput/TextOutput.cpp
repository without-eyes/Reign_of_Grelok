#include "rog/ui/textoutput/TextOutput.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

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

void TextOutput::changeColor(const int colorNumber) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber);
}

void TextOutput::placeStringOnScreen(const short positionX, const short positionY) {
    COORD coordinates;
    coordinates.X = positionX;
    coordinates.Y = positionY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void TextOutput::typingEffectOutput(const std::string &text) {
    for (char symbol: text) {
        std::cout << symbol << std::flush;
        Sleep(5);
    }
}

void TextOutput::writeText(const std::vector<std::string> &text) {
    system("cls");

    TextOutput::removeBlinkingUnderscore();

    bool enterPressed = false;

    for (const std::string &line: text) {
        if (_kbhit() && getch() == 13) {
            enterPressed = true;
            break;
        }

        if (line != text.back()) {
            TextOutput::typingEffectOutput(("\n  " + line).c_str());
        } else {
            TextOutput::typingEffectOutput(("\n\n\n  > " + line).c_str());
        }
    }

    if (enterPressed) {
        system("cls");
        for (const std::string &line: text) {
            if (line != text.back()) {
                std::cout << "\n  " + line;
            } else {
                std::cout << "\n\n\n  > " + line;
            }
        }
    }

    TextOutput::addBlinkingUnderscore();

    Sleep(3000);
    system("cls");

    TextOutput::removeBlinkingUnderscore();

    for (const std::string &line: text) {
        if (line != text.back()) {
            std::cout << "\n  " + line;
        } else {
            std::cout << "\n\n\n  > ";
        }
    }

    TextOutput::addBlinkingUnderscore();

    getch();
    system("cls");
}