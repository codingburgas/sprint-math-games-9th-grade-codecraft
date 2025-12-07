#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../include/mainMenu.h"
#include "../include/fifthChapter.h"
#include "../include/sixthChapter.h"


using namespace std;

void fifthChapter(const string& playerName) {

    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    WORD green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    WORD blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD purple = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    clearScreen();
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 25) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    // Chapter intro
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    printCenteredAt("[ CHAPTER 5: The Cavern of Division ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("The sound of dripping water echoes in the darkness.", startY++, green);
    printCenteredAt("Faint blue symbols pulse along the cavern walls.", startY++, green);
    startY += 2;

    printCenteredAt("Press enter to continue...", startY, yellow);
    _getch();

    // Puzzle screen
    clearScreen();
    startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                 THE DIVIDING CRYSTAL ALTAR               |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;

    printCenteredAt("A crystalline monolith hums with ancient energy.", startY++, purple);
    printCenteredAt("Its surface cracks open, revealing a glowing equation.", startY++, purple);
    startY += 2;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|                    SOLVE THE DIVISION                     |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY++;

    printCenteredAt("42 / 6 = ___", startY++, purple);
    startY += 2;

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

        if (answer == 7) {
            solved = true;
            startY += 2;
            printCenteredAt("*** THE CRYSTAL RINGS WITH PERFECT HARMONY! ***", startY++, cyan);
            startY++;
            printCenteredAt("Light floods the cavern, revealing hidden pathways.", startY++, green);
            startY++;

            printCenteredAt("[ 42 / 6 = 7 ]", startY++, blue);
        }
        else {
            attempts++;
            startY += 2;

            if (attempts < 3) {
                printCenteredAt("The crystal flickers... Incorrect.", startY++, green);
                printCenteredAt("(Attempts remaining: " + to_string(3 - attempts) + ")", startY++, red);
                startY++;
            }
            else {
                printCenteredAt("The correct answer was 7.", startY++, green);
                printCenteredAt("The crystal stabilizes on its own.", startY++, green);
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
    printCenteredAt("[ The Echoing Core ]", startY++, yellow);
    printCenteredAt("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", startY++, cyan);
    startY++;

    printCenteredAt("A small glowing shard rises from a pool of blue light.", startY++, green);
    printCenteredAt("It vibrates with the calm precision of division.", startY++, green);
    startY += 2;

    printCenteredAt("Press any key to claim the stone...", startY, purple);
    _getch();

    // Stone collection screen
    clearScreen();
    startY = (height - 12) / 2;
    if (startY < 0) startY = 0;

    printCenteredAt("+==========================================================+", startY++, cyan);
    printCenteredAt("|            *** EQUATION STONE FRAGMENT FOUND ***         |", startY++, yellow);
    printCenteredAt("+==========================================================+", startY++, cyan);
    startY += 2;

    printCenteredAt("[ FIFTH STONE - Fragment of Division ]", startY++, cyan);
    startY += 2;

    displayStoneProgress(startY);
    startY += 3;

    printCenteredAt("[ Chapter 5 Complete! ]", startY++, green);
    startY += 2;
    printCenteredAt("Press enter to continue your journey...", startY++, purple);
    _getch();

    sixthChapter(playerName);
}