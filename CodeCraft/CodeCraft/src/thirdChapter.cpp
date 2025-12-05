#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../include/mainMenu.h"
#include "../include/thirdChapter.h"
using namespace std;

void thirdChapter(const string& playerName) {

    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    clearScreen();
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 25) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    // Chapter intro
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, green);
    printCenteredAt("[ CHAPTER 3: The Forest of Fractions ]", startY++, green);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, green);
    startY++;

    printCenteredAt("Thick mist rolls between ancient trees.", startY++, green);
    printCenteredAt("Whispers of broken numbers echo through the forest.", startY++, green);
    startY += 2;

    printCenteredAt("Press any key to continue...", startY, green);
    _getch();

    // Puzzle screen
    clearScreen();
    startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, green);
    printCenteredAt("|               THE SHRINE OF FRACTION FLOW                |", startY++, green);
    printCenteredAt("+==========================================================+", startY++, green);
    startY++;

    printCenteredAt("A glowing stone altar rises from the forest floor.", startY++, green);
    printCenteredAt("Symbols swirl above it, forming a fractured equation.", startY++, green);
    startY += 2;

    printCenteredAt("+==========================================================+", startY++, green);
    printCenteredAt("|                     COMPLETE THE FLOW                     |", startY++, green);
    printCenteredAt("+==========================================================+", startY++, green);
    startY++;

    printCenteredAt("1/2 + 1/4 = ___", startY++, green);
    startY += 2;

    // Solve loop
    double answer;
    int attempts = 0;
    bool solved = false;

    while (!solved && attempts < 3) {

        printCenteredAt("Enter your answer (use decimal): ", startY, green);
        int inputX = (width + 36) / 2;
        setCursorPosition(inputX, startY);

        cin >> answer;
        cin.ignore();

        if (answer == 0.75) {
            solved = true;
            startY += 2;
            printCenteredAt("*** THE FLOW RETURNS TO BALANCE! ***", startY++, green);
            startY++;
            printCenteredAt("The altar glows brightly, illuminating the forest.", startY++, green);
            startY++;

            printCenteredAt("[ 1/2 + 1/4 = 0.75 ]", startY++, green);
        }
        else {
            attempts++;
            startY += 2;

            if (attempts < 3) {
                printCenteredAt("The symbols distort... Incorrect.", startY++, green);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, green);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 0.75.", startY++, green);
                printCenteredAt("The altar stabilizes on its own.", startY++, green);
            }
        }
    }

    startY += 2;
    printCenteredAt("Press any key to continue...", startY, green);
    _getch();

    // Stone discovery
    clearScreen();
    startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, green);
    printCenteredAt("[ Heart of the Forest ]", startY++, green);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, green);
    startY++;

    printCenteredAt("Roots part and reveal a glowing fragment.", startY++, green);
    printCenteredAt("You sense ancient fractional power within it.", startY++, green);
    startY += 2;

    printCenteredAt("Press any key to claim the stone...", startY, green);
    _getch();

    // Stone collection screen
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, green);
    printCenteredAt("|            *** EQUATION STONE FRAGMENT FOUND ***         |", startY++, green);
    printCenteredAt("+==========================================================+", startY++, green);
    startY += 2;

    printCenteredAt("[ THIRD STONE - Fragment of Fractions ]", startY++, green);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 3 Complete! ]", startY++, green);
    startY += 2;

    printCenteredAt("Press ESC to return to menu...", startY, green);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break;
        }
    }
}
