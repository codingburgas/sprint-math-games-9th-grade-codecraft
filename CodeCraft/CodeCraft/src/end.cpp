#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../include/mainMenu.h"
#include "../include/end.h"
using namespace std;
void endGame(const string& playerName) {
    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    clearScreen();
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 25) / 2;
    if (startY < 0) startY = 0;
    displayTitle(startY);
    startY += 8;
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ FINAL CHAPTER: Restoration of Numeria ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;
    printCenteredAt("With the final fragment placed into the Great Equation Stone,", startY++, yellow);
    printCenteredAt("a blinding light sweeps across Numeria.", startY++, yellow);
    startY++;
    printCenteredAt("The land stabilizes. Numbers flow in harmony again.", startY++, yellow);
    printCenteredAt("You have restored balance to the world.", startY++, yellow);
    startY += 2;
    printCenteredAt("Press ENTER to witness the ending...", startY, cyan);
    _getch();
    // THE END SCREEN
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;
    printCenteredAt(" ########  ##    ##  ########      ########  ##    ##  ########  ", startY++, yellow);
    printCenteredAt("    ##     ##    ##  ##            ##        ###   ##  ##     ## ", startY++, yellow);
    printCenteredAt("    ##     ########  ######        ######    ####  ##  ##     ## ", startY++, yellow);
    printCenteredAt("    ##     ##    ##  ##            ##        ## ## ##  ##     ## ", startY++, yellow);
    printCenteredAt("    ##     ##    ##  ########      ########  ##  ####  ########  ", startY++, yellow);
    startY += 2;
    printCenteredAt("Thank you for playing, " + playerName + "!", startY++, green);

    startY += 2;
    printCenteredAt("Press ESC to return to main menu...", startY, cyan);
    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break;
        }
    }
}