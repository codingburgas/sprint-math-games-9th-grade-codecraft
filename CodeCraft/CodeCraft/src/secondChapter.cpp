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

    clearScreen();
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 25) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    // Chapter Introduction
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ CHAPTER 2: The Bridge of Balance ]", startY++, cyan);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;
    printCenteredAt("A rushing river blocks your path.", startY++, cyan);
    printCenteredAt("An unstable bridge flickers ahead.", startY++, cyan);
    startY += 2;
    printCenteredAt("Press any key to continue...", startY, cyan);
    _getch();

    // The Scales Puzzle
    clearScreen();
    startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                 THE SCALES OF EQUALITY                   |", startY++, cyan);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;
    printCenteredAt("Two massive golden scales hover at the bridge's center.", startY++, cyan);
    startY += 2;

    // Display the puzzle
    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                  BALANCE THE SCALES                      |", startY++, cyan);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;
    printCenteredAt("4 * 3 = ___ + 6", startY++, cyan);
    startY += 2;

    // Puzzle solving loop
    int answer;
    int attempts = 0;
    bool solved = false;

    while (!solved && attempts < 3) {
        printCenteredAt("Enter your answer: ", startY, cyan);
        int inputX = (width + 19) / 2;
        setCursorPosition(inputX, startY);

        cin >> answer;
        cin.ignore();

        if (answer == 6) {
            solved = true;
            startY += 2;
            printCenteredAt("*** PERFECT BALANCE! ***", startY++, cyan);
            startY++;
            printCenteredAt("The bridge solidifies with golden light!", startY++, cyan);
            startY++;

            printCenteredAt("[ 4 * 3 = 6 + 6 = 12 = 12 ]", startY++, cyan);
        }
        else {
            attempts++;
            startY += 2;
            if (attempts < 3) {
                printCenteredAt("The scales shudder... Try again.", startY++, cyan);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, cyan);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 6.", startY++, cyan);
                printCenteredAt("The bridge stabilizes.", startY++, cyan);
            }
        }
    }

    startY += 2;
    printCenteredAt("Press any key to cross...", startY, cyan);
    _getch();

    // Finding the Stone
    clearScreen();
    startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ The Far Side ]", startY++, cyan);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("You cross safely to the other side.", startY++, cyan);
    printCenteredAt("A glowing fragment is embedded in the keystone.", startY++, cyan);

    startY += 2;
    printCenteredAt("Press any key to claim the stone...", startY, cyan);
    _getch();

    // Stone Collection
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|              *** EQUATION STONE OBTAINED ***             |", startY++, cyan);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY += 2;

    printCenteredAt("[ THE SECOND STONE - Fragment of Multiplication ]", startY++, cyan);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 2 Complete! ]", startY++, cyan);
    startY += 2;
    printCenteredAt("Press enter to continue your journey...", startY, cyan);
    _getch();

    thirdChapter(playerName);
}