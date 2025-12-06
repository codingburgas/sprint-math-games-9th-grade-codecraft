#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../include/mainMenu.h"
#include "../include/fifthChapter.h"


using namespace std;

void fifthChapter(const string& playerName) {

    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    clearScreen();
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 25) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    // Solve loop
    int answer;
    int attempts = 0;
    bool solved = false;

    while (!solved && attempts < 3) {

        printCenteredAt("Enter your answer: ", startY, cyan);
        int inputX = (width + 19) / 2;
        setCursorPosition(inputX, startY);

        cin >> answer;
        cin.ignore();

        if (answer == 7) {
            solved = true;
            startY += 2;
            printCenteredAt("*** THE CRYSTAL RINGS WITH PERFECT HARMONY! ***", startY++, cyan);
            startY++;
            printCenteredAt("Light floods the cavern, revealing hidden pathways.", startY++, cyan);
            startY++;

            printCenteredAt("[ 42 / 6 = 7 ]", startY++, cyan);
        }
        else {
            attempts++;
            startY += 2;

            if (attempts < 3) {
                printCenteredAt("The crystal flickers... Incorrect.", startY++, cyan);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, cyan);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 7.", startY++, cyan);
                printCenteredAt("The crystal stabilizes on its own.", startY++, cyan);
            }
        }
    }

    startY += 2;
    printCenteredAt("Press any key to continue...", startY, cyan);
    _getch();

    // Stone discovery
    clearScreen();
    startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ The Echoing Core ]", startY++, cyan);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("A small glowing shard rises from a pool of blue light.", startY++, cyan);
    printCenteredAt("It vibrates with the calm precision of division.", startY++, cyan);
    startY += 2;

    printCenteredAt("Press any key to claim the stone...", startY, cyan);
    _getch();

    // Stone collection screen
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|            *** EQUATION STONE FRAGMENT FOUND ***         |", startY++, cyan);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY += 2;

    printCenteredAt("[ FIFTH STONE - Fragment of Division ]", startY++, cyan);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 5 Complete! ]", startY++, cyan);
    startY += 2;

    printCenteredAt("Press ESC to return to menu...", startY, cyan);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break;
        }
    }
}