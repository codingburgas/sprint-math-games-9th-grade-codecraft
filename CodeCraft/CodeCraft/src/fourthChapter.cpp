#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../include/mainMenu.h"
#include "../include/fourthChapter.h"

using namespace std;

void fourthChapter(const string& playerName) {

    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
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
    printCenteredAt("[ CHAPTER 4: The Mountain of Multiples ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("The air grows thin as you ascend the steep slopes.", startY++, green);
    printCenteredAt("Ancient runes glow along the jagged rocks.", startY++, green);
    startY += 2;

    printCenteredAt("Press enter to continue...", startY, purple);
    _getch();

    // Puzzle screen
    clearScreen();
    startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                 THE ALTAR OF MULTIPLICATION             |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;

    printCenteredAt("A glowing stone platform emerges from the mountainside.", startY++, green);
    printCenteredAt("Numbers float above it, awaiting the correct product.", startY++, green);
    startY += 2;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                    SOLVE THE MULTIPLE                     |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;

    printCenteredAt("7 * 5 = ___", startY++, yellow);
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

        if (answer == 35) {
            solved = true;
            startY += 2;
            printCenteredAt("*** THE ALTAR SHINES WITH POWER! ***", startY++, cyan);
            startY++;
            printCenteredAt("The mountain trembles and the path solidifies.", startY++, green);
            startY++;

            printCenteredAt("[ 7 * 5 = 35 ]", startY++, yellow);
        }
        else {
            attempts++;
            startY += 2;

            if (attempts < 3) {
                printCenteredAt("The numbers shift... Incorrect.", startY++, green);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, purple);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 35.", startY++, green);
                printCenteredAt("The altar stabilizes anyway.", startY++, green);
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
    printCenteredAt("[ Summit of Multiples ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("You discover a glowing fragment embedded in the peak.", startY++, green);
    printCenteredAt("It radiates the power of multiplication.", startY++, green);
    startY += 2;

    printCenteredAt("Press enter to claim the stone...", startY, purple);
    _getch();

    // Stone collection screen
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|            *** EQUATION STONE FRAGMENT FOUND ***         |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY += 2;

    printCenteredAt("[ FOURTH STONE - Fragment of Multiplication ]", startY++, green);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 4 Complete! ]", startY++, green);
    startY += 2;

    printCenteredAt("Press ESC to return to menu...", startY, purple);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break;
        }
    }
}