#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"../include/startGame.h"
#include"../include/mainMenu.h"
#include"../include/firstChapter.h"
using namespace std;


string playerName = "";

void startGame() {
    clearScreen();

    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD purple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 15) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    string playerName;
    printCenteredAt("+============================================================+", startY++, cyan);
    printCenteredAt("|            >>> B E G I N   Y O U R   Q U E S T <<<        |", startY++, yellow);
    printCenteredAt("+============================================================+", startY++, cyan);
    startY += 2;

    printCenteredAt("What is your name, brave Number Weaver? ", startY, green);

    // Position cursor for input
    int inputX = (width + 41) / 2;
    setCursorPosition(inputX, startY);
    getline(cin, playerName);

    clearScreen();
    startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    printCenteredAt("+============================================================+", startY++, cyan);
    printCenteredAt("  Welcome, " + playerName + " the Number Weaver!", startY++, yellow);
    printCenteredAt("+============================================================+", startY++, cyan);

    startY++;
    printCenteredAt("The Great Equation Stone calls to you", startY++, green);

    startY++;
    printCenteredAt("Long ago, the Kingdom of Numeria thrived in harmony...", startY++, green);
    printCenteredAt("The Great Equation Stone maintained balance across the realm.", startY++, green);
    printCenteredAt("", startY++, cyan);
    printCenteredAt("But one dark night, the stone SHATTERED into seven pieces!", startY++, green);
    printCenteredAt("Now chaos spreads: bridges vanish, doors refuse to open,", startY++, green);
    printCenteredAt("and magical creatures are trapped in broken spells.", startY++, green);

    startY += 2;
    printCenteredAt("Press enter to accept your destiny...", startY, purple);
    _getch();

	firstChapter(playerName);
}
