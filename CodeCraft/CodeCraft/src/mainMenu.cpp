#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "../include/mainMenu.h"
using namespace std;

void clearScreen() {
    system("cls");
}

void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void getConsoleSize(int& width, int& height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void printCenteredAt(string text, int y) {
    int width, height;
    getConsoleSize(width, height);

    int x = (width - (int)text.length()) / 2;
    if (x < 0) x = 0;

    setCursorPosition(x, y);
    cout << text;
}

void displayTitle(int startY) {
    printCenteredAt("##   ##  ##  ##  ##   ##  #####  #####   ####    ###", startY++);
    printCenteredAt(" ###  ##  ##  ##  ### ###  ##     ##  ##   ##    ## ##", startY++);
    printCenteredAt("  ## ####  ##  ##  ## # ##  #####  #####    ##   ##   ##", startY++);
    printCenteredAt("   ##  ###  ##  ##  ##   ##  ##     ##  ##   ##   #######", startY++);
    printCenteredAt("   ##   ##   ####   ##   ##  #####  ##   ## ####  ##   ##", startY++);
    startY++;
    printCenteredAt("~ The Kingdom of Numeria Awaits ~", startY);
}

void displayMenu(int selectedOption) {
    clearScreen();

    int width, height;
    getConsoleSize(width, height);

    int y = 2;
    displayTitle(y);

    y += 10; // space under title

    const char* options[] = {
        "Start Game",
        "Instructions",
        "High Scores",
        "Exit"
    };

    for (int i = 0; i < 4; i++) {
        string line;
        if (i == selectedOption)
            line = "> " + string(options[i]) + " <";
        else
            line = options[i];

        printCenteredAt(line, y++);
    }
}

void showInstructions() {
    clearScreen();
    printCenteredAt("Instructions screen...", 5);
    system("pause");
}

void showHighScores() {
    clearScreen();
    printCenteredAt("High Scores screen...", 5);
    system("pause");
}


void startGame() {
    clearScreen();
    printCenteredAt("Game starting...", 5);
    system("pause");
}

void mainMenu() {
    int selectedOption = 0;
    bool running = true;

    while (running) {
        displayMenu(selectedOption);

        int key = _getch();

        // Arrow keys send 0 or 224 first
        if (key == 0 || key == 224) {
            key = _getch();

            if (key == 72) {  // up
                selectedOption--;
                if (selectedOption < 0) selectedOption = 4;
            }
            else if (key == 80) { // down
                selectedOption++;
                if (selectedOption > 4) selectedOption = 0;
            }
        }
        else if (key == 13) { // ENTER
            switch (selectedOption) {
            case 0: startGame(); break;
            case 1: showInstructions(); break;
            case 2: showHighScores(); break;

            case 3: // EXIT
                clearScreen();
                {
                    int width, height;
                    getConsoleSize(width, height);
                    int y = height / 2;

                    printCenteredAt("+============================================================+", y++);
                    printCenteredAt("|   Thank you for saving Numeria, brave Number Weaver!       |", y++);
                    printCenteredAt("|   May the Great Equation Stone guide your path!            |", y++);
                    printCenteredAt("+============================================================+", y++);
                }
                Sleep(2000);
                running = false;
                break;
            }
        }
        else if (key == 27) { // ESC
            clearScreen();

            int width, height;
            getConsoleSize(width, height);

            printCenteredAt("Until we meet again, Number Weaver...", height / 2);
            Sleep(1000);

            running = false;
        }
    }
}