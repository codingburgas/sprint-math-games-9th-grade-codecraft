#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"../include/mainMenu.h"
#include"../include/settings.h"
using namespace std;
bool soundOn = true;
bool storyModeOn = true;
bool timerOn = true;
int difficulty = 1;
bool hintSystemOn = true;

void showSettings() {
    clearScreen();
    
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD purple = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    while (true) {
        clearScreen();
        int y = startY;

        displayTitle(y);
        y += 8;

        printCenteredAt("+============================================================+", y++, cyan);
        printCenteredAt("|                 >>> S E T T I N G S <<<                   |", y++, yellow);
        printCenteredAt("+============================================================+", y++, cyan);
        y += 2;

        string diffTxt = (difficulty == 0 ? "Easy" :
            difficulty == 1 ? "Medium" : "Hard");

        printCenteredAt(("1) Sound Effects: " + string(soundOn ? "ON" : "OFF")).c_str(), y++, green);
        printCenteredAt(("2) Story Mode: " + string(storyModeOn ? "Enabled" : "Disabled")).c_str(), y++, blue);
        printCenteredAt(("3) Timer: " + string(timerOn ? "Enabled" : "Disabled")).c_str(), y++, cyan);
        printCenteredAt(("4) Difficulty: " + diffTxt).c_str(), y++, red);
        printCenteredAt(("5) Hint System: " + string(hintSystemOn ? "Available" : "Disabled")).c_str(), y++, yellow);

        y += 2;
        printCenteredAt("Press 1-5 to change settings, ESC to return...", y, purple);

        int key = _getch();

        if (key == 27) break; // ESC

        if (key == '1') soundOn = !soundOn;
        if (key == '2') storyModeOn = !storyModeOn;
        if (key == '3') timerOn = !timerOn;
        if (key == '4') {
            difficulty++;
            if (difficulty > 2) difficulty = 0;
        }
        if (key == '5') hintSystemOn = !hintSystemOn;
    }
}

