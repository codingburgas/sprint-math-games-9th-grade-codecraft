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

    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 28) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    printCenteredAt("+============================================================+", startY++, cyan);
    printCenteredAt("|              >>> H O W   T O   P L A Y <<<                |", startY++, cyan);
    printCenteredAt("+============================================================+", startY++, cyan);
    startY++;

    printCenteredAt("Welcome to the Kingdom of Numeria!", startY++, cyan);
    startY++;
    printCenteredAt(">> THE STORY:", startY++, cyan);
    printCenteredAt("The Great Equation Stone has shattered! Without it,", startY++, cyan);
    printCenteredAt("chaos spreads across Numeria. As Ari, a Number Weaver,", startY++, cyan);
    printCenteredAt("you must find the missing fragments by solving puzzles.", startY++, cyan);
    startY++;
    printCenteredAt(">> YOUR MISSION:", startY++, cyan);
    printCenteredAt("* Solve mathematical challenges to restore balance", startY++, cyan);
    printCenteredAt("* Collect stone fragments hidden throughout the realm", startY++, cyan);
    printCenteredAt("* Face increasingly difficult puzzles as you progress", startY++, cyan);
    printCenteredAt("* You have 3 lives - losing all means starting over!", startY++, cyan);
    startY++;
    printCenteredAt(">> SCORING:", startY++, cyan);
    printCenteredAt("Easy Puzzles: 10 pts  |  Medium: 25 pts  |  Hard: 50 pts", startY++, cyan);
    printCenteredAt("Speed Bonus: Answer quickly for up to +20 extra points!", startY++, cyan);
    startY++;
    printCenteredAt(">> TIP: The wisest weavers think before they act!", startY++, cyan);

    startY += 2;
    printCenteredAt("Press ESC to return to menu...", startY, cyan);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break; // ESC key
        }
    }
}