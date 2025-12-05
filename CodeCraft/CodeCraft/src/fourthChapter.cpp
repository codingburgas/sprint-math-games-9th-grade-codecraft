#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../include/mainMenu.h"
#include "../include/fourthChapter.h"

using namespace std;

void fourthChapter(const string& playerName) {

    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

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

        printCenteredAt("Enter your answer: ", startY, yellow);
        int inputX = (width + 19) / 2;
        setCursorPosition(inputX, startY);

        cin >> answer;
        cin.ignore();

        if (answer == 35) {
            solved = true;
            startY += 2;
            printCenteredAt("*** THE ALTAR SHINES WITH POWER! ***", startY++, yellow);
            startY++;
            printCenteredAt("The mountain trembles and the path solidifies.", startY++, yellow);
            startY++;

            printCenteredAt("[ 7 * 5 = 35 ]", startY++, yellow);
        }
        else {
            attempts++;
            startY += 2;

            if (attempts < 3) {
                printCenteredAt("The numbers shift... Incorrect.", startY++, yellow);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, yellow);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 35.", startY++, yellow);
                printCenteredAt("The altar stabilizes anyway.", startY++, yellow);
            }
        }
    }

    startY += 2;
    printCenteredAt("Press any key to continue...", startY, yellow);
    _getch();

    // Stone discovery
    clearScreen();
    startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, yellow);
    printCenteredAt("[ Summit of Multiples ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, yellow);
    startY++;

    printCenteredAt("You discover a glowing fragment embedded in the peak.", startY++, yellow);
    printCenteredAt("It radiates the power of multiplication.", startY++, yellow);
    startY += 2;

    printCenteredAt("Press any key to claim the stone...", startY, yellow);
    _getch();

    // Stone collection screen
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, yellow);
    printCenteredAt("|            *** EQUATION STONE FRAGMENT FOUND ***         |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, yellow);
    startY += 2;

    printCenteredAt("[ FOURTH STONE - Fragment of Multiplication ]", startY++, yellow);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 4 Complete! ]", startY++, yellow);
    startY += 2;

    printCenteredAt("Press ESC to return to menu...", startY, yellow);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break;
        }
    }
}