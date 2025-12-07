#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"../include/mainMenu.h"
#include "../include/howToPlay.h"
using namespace std;
void showInstructions() {
    clearScreen();

    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    WORD blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD purple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 28) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    printCenteredAt("+============================================================+", startY++, cyan);
    printCenteredAt("|              >>> H O W   T O   P L A Y <<<                |", startY++, yellow);
    printCenteredAt("+============================================================+", startY++, cyan);
    startY++;

    printCenteredAt("Welcome to the Kingdom of Numeria!", startY++, blue);
    startY++;
    printCenteredAt(">> THE STORY:", startY++, red);
    printCenteredAt("The Great Equation Stone has shattered! Without it,", startY++, green);
    printCenteredAt("chaos spreads across Numeria. As Ari, a Number Weaver,", startY++, cyan);
    printCenteredAt("you must find the missing fragments by solving puzzles.", startY++, green);
    startY++;
    printCenteredAt(">> YOUR MISSION:", startY++, red);
    printCenteredAt("* Solve mathematical challenges to restore balance", startY++, green);
    printCenteredAt("* Collect stone fragments hidden throughout the realm", startY++, cyan);
    printCenteredAt("* Face increasingly difficult puzzles as you progress", startY++, green);
    printCenteredAt("* You have 3 lives!", startY++, cyan);
    startY++;

    printCenteredAt(">> TIP: The wisest weavers think before they act!", startY++, yellow);

    startY += 2;
    printCenteredAt("Press ESC to return to menu...", startY, purple);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break; // ESC key
        }
    }
}