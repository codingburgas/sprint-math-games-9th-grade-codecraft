#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"../include/mainMenu.h"
#include"../include/secondChapter.h"
#include "../include/thirdChapter.h"
using namespace std;


void secondChapter(const string& playerName) {

    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD purple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD red = FOREGROUND_RED | FOREGROUND_INTENSITY;
	

    clearScreen();
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 25) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    // Chapter Introduction
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ CHAPTER 2: The Bridge of Balance ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;
    printCenteredAt("A rushing river blocks your path.", startY++, green);
    printCenteredAt("An unstable bridge flickers ahead.", startY++, green);
    startY += 2;
    printCenteredAt("Press enter to continue...", startY, purple);
    _getch();

    // The Scales Puzzle
    clearScreen();
    startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                 THE SCALES OF EQUALITY                   |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;
    printCenteredAt("Two massive golden scales hover at the bridge's center.", startY++, green);
    startY += 2;

    // Display the puzzle
    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                  BALANCE THE SCALES                      |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;
    printCenteredAt("4 * 3 = ___ + 6", startY++, blue);
    startY += 2;

    // Puzzle solving loop
    int answer;
    int attempts = 0;
    bool solved = false;

    while (!solved && attempts < 3) {
        printCenteredAt("Enter your answer: ", startY, purple);
        int inputX = (width + 19) / 2;
        setCursorPosition(inputX, startY);

        cin >> answer;
        cin.ignore();

        if (answer == 6) {
            solved = true;
            startY += 2;
            printCenteredAt("*** PERFECT BALANCE! ***", startY++, green);
            startY++;
            printCenteredAt("The bridge solidifies with golden light!", startY++, green);
            startY++;

            printCenteredAt("[ 4 * 3 = 6 + 6 = 12 ]", startY++, blue);
        }
        else {
            attempts++;
            startY += 2;
            if (attempts < 3) {
                printCenteredAt("The scales shudder... Try again.", startY++, green);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, red);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 6.", startY++, green);
                printCenteredAt("The bridge stabilizes.", startY++, green);
            }
        }
    }

    startY += 2;
    printCenteredAt("Press enter to cross...", startY, purple);
    _getch();

    // Finding the Stone
    clearScreen();
    startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ The Far Side ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("You cross safely to the other side.", startY++, green);
    printCenteredAt("A glowing fragment is embedded in the keystone.", startY++, green);

    startY += 2;
    printCenteredAt("Press enter to claim the stone...", startY, purple);
    _getch();

    // Stone Collection
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|              *** EQUATION STONE OBTAINED ***             |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY += 2;

    printCenteredAt("[ THE SECOND STONE - Fragment of Multiplication ]", startY++, green);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 2 Complete! ]", startY++, green);
    startY += 2;
    printCenteredAt("Press enter to continue your journey...", startY, purple);
    _getch();

    thirdChapter(playerName);
}