#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"../include/mainMenu.h"
#include"../include/firstChapter.h"
#include"../include/secondChapter.h"
using namespace std;

int stonesCollected = 0;

void displayStoneProgress(int startY) {
    stonesCollected++;

    string progress = "[ Equation Stones Collected: " + to_string(stonesCollected) + " / 6 ]";
    printCenteredAt(progress, startY, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    // Visual representation
    string stones = "[ ";
    for (int i = 0; i < 6; i++) {
        if (i < stonesCollected) {
            stones += "1 ";
        }
        else {
            stones += "0 ";
        }
    }
    stones += "]";
}

void firstChapter(const string& playerName) {

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
    printCenteredAt("[ CHAPTER 1: The Village of Ones ]", startY++, cyan);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;
    printCenteredAt("You stand before the ruins of the Great Equation Stone.", startY++, cyan);
    printCenteredAt("An ancient guardian appears, glowing with faint numbers.", startY++, cyan);
    startY++;
    printCenteredAt("'The Village of Ones holds the first fragment.'", startY++, cyan);
    startY += 2;
    printCenteredAt("Press any key to continue...", startY, cyan);
    _getch();

    // Journey to Village
    clearScreen();
    startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("Traveling to the Village of Ones", startY, cyan);
    startY += 3;

    printCenteredAt("A quaint village appears through the mist.", startY++, cyan);
    printCenteredAt("The ancient gate stands sealed before you.", startY++, cyan);
    printCenteredAt("Glowing symbols pulse across its surface.", startY++, cyan);
    startY += 2;
    printCenteredAt("Press any key to approach the gate...", startY, cyan);
    _getch();

    // The Gate Puzzle
    clearScreen();
    startY = (height - 22) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                    THE SEALED GATE                       |", startY++, cyan);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;
    printCenteredAt("The gate is locked. A magical sigil glows before you.", startY++, cyan);
    startY += 2;

    // Display the puzzle
    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                  RESTORE THE SIGIL                       |", startY++, cyan);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;
    printCenteredAt("The equation glows before you:", startY++, cyan);
    startY++;
    printCenteredAt("7 + 9 - ___ = 12", startY++, cyan);
    startY++;
    printCenteredAt("What number completes the sigil?", startY++, cyan);
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
        cin.ignore(); // Clear the newline

        if (answer == 4) {
            solved = true;
            startY += 2;
            printCenteredAt("*** CORRECT! ***", startY++, cyan);
            startY++;
            printCenteredAt("The sigil BLAZES with brilliant light!", startY++, cyan);
            printCenteredAt("The gate creaks open...", startY++, cyan);
            startY++;
        }
        else {
            attempts++;
            startY += 2;
            if (attempts < 3) {
                printCenteredAt("The sigil flickers... Try again.", startY++, cyan);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, cyan);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 4.", startY++, cyan);
                printCenteredAt("The gate opens reluctantly.", startY++, cyan);
            }
        }
    }

    startY += 2;
    printCenteredAt("Press any key to enter the village...", startY, cyan);
    _getch();

    // Inside the Village - Finding the Stone
    clearScreen();
    startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ Inside the Village of Ones ]", startY++, cyan);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    if (solved) {
        printCenteredAt("The villagers emerge, amazed by your skill.", startY++, cyan);
        startY++;
        printCenteredAt("An elderly woman approaches with a glowing fragment.", startY++, cyan);
        printCenteredAt("'The first stone. Five more await.'", startY++, cyan);
    }
    else {
        printCenteredAt("The villagers watch with cautious eyes.", startY++, cyan);
        startY++;
        printCenteredAt("An elderly woman approaches with a glowing fragment.", startY++, cyan);
        printCenteredAt("'The first stone. Practice harder for what's ahead.'", startY++, cyan);
    }

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

    printCenteredAt("[ THE FIRST STONE - Fragment of Addition ]", startY++, cyan);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 1 Complete! ]", startY++, cyan);
    startY += 2;
    printCenteredAt("Press enter to continue your journey...", startY, cyan);
    _getch();

    secondChapter(playerName);
}