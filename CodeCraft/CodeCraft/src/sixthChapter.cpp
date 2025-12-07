#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../include/mainMenu.h"
#include "../include/sixthChapter.h"

using namespace std;

void sixthChapter(const string& playerName) {

    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	WORD red = FOREGROUND_RED | FOREGROUND_INTENSITY;
	WORD blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	WORD purple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

    clearScreen();
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 25) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    // Chapter intro
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ CHAPTER 6: The Final Equation Gate ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("You enter a vast chamber of shifting numbers.", startY++, green);
    printCenteredAt("The Final Gate towers ahead, sealed by a complex equation.", startY++, green);
    startY += 2;

    printCenteredAt("Press enter to continue...", startY, purple);
    _getch();

    // Puzzle screen
    clearScreen();
    startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                   THE FINAL EQUATION GATE                |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;

    printCenteredAt("The air shimmers as the ultimate equation appears.", startY++, green);
    printCenteredAt("Only perfect mastery can unlock the gate.", startY++, green);
    startY += 2;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                     SOLVE THE EQUATION                    |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;

    printCenteredAt("(8 + 4) * 2 - 6 = ___", startY++, blue);
    startY += 2;

    // Solve loop
    int answer;
    int attempts = 0;
    bool solved = false;

    while (!solved && attempts < 3) {

        printCenteredAt("Enter your answer: ", startY, purple);
        int inputX = (width + 19) / 2;
        setCursorPosition(inputX, startY);

        cin >> answer;
        cin.ignore();

        if (answer == 20) {
            solved = true;
            startY += 2;
            printCenteredAt("*** THE GATE AWAKENS! ***", startY++, cyan);
            startY++;
            printCenteredAt("A thunderous roar echoes as the seal breaks.", startY++, green);
            startY++;

            printCenteredAt("[ (8 + 4) * 2 - 6 = 20 ]", startY++, blue);
        }
        else {
            attempts++;
            startY += 2;

            if (attempts < 3) {
                printCenteredAt("The gate rejects your answer.", startY++, green);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, red);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 20.", startY++, green);
                printCenteredAt("The equation stabilizes on its own.", startY++, green);
            }
        }
    }

    startY += 2;
    printCenteredAt("Press enter to continue...", startY, purple);
    _getch();

    // Stone discovery
    clearScreen();
    startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
	printCenteredAt("[ The Core of Numeria ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("The Final Stone rises before you,", startY++, green);
    printCenteredAt("shining with the combined power of all mathematics.", startY++, green);
    startY += 2;

    printCenteredAt("Press enter to claim the final stone...", startY, yellow);
    _getch();

    // Stone collection screen
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
	printCenteredAt("|         *** FINAL EQUATION STONE COMPLETED ***           |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY += 2;

    printCenteredAt("[ SIXTH STONE - Fragment of Mastery ]", startY++, green);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 6 Complete! ]", startY++, green);
    startY += 2;

	printCenteredAt("THE END", startY++, red);
	printCenteredAt("You completed all chapters!", startY++, green);
    printCenteredAt("Your journey in NUMERIA ended successfully!", startY++, green);
    startY += 2;

	printCenteredAt("Press ESC to return to menu...", startY, purple);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break;
        }
    }
}
