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

void TextOutput::changeColor(const int nColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
}

void TextOutput::placeStringOnScreen(const short sX, const short sY) {
    COORD coordinates;
    coordinates.X = sX;
    coordinates.Y = sY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void TextOutput::typingEffectOutput(const char* aText) {
    while (*aText) {
        printf("%c\xDB", *aText++);
        fflush(stdout);
        Sleep(5);
    }
}

void TextOutput::writeText(const std::vector<std::string>& vText) {
    system("cls");

    TextOutput::removeBlinkingUnderscore();

    bool bEnterPressed = false;

    for (const std::string& sLine : vText) {
        if (_kbhit() && getch() == 13) {
            bEnterPressed = true;
            break;
        }

        if (sLine != vText.back()) {
            TextOutput::typingEffectOutput(("\n  " + sLine).c_str());
        } else {
            TextOutput::typingEffectOutput(("\n\n\n  > " + sLine).c_str());
        }
    }

    if (bEnterPressed) {
        system("cls");
        for (const std::string& sLine : vText) {
            if (sLine != vText.back()) {
                std::cout << "\n  " + sLine;
            } else {
                std::cout << "\n\n\n  > " + sLine;
            }
        }
    }

    TextOutput::addBlinkingUnderscore();

    Sleep(3000);
    system("cls");

    TextOutput::removeBlinkingUnderscore();

    for (const std::string& sLine : vText) {
        if (sLine != vText.back()) {
            std::cout << "\n  " + sLine;
        } else {
            std::cout << "\n\n\n  > ";
        }
    }

    TextOutput::addBlinkingUnderscore();

    getch();
    system("cls");
}