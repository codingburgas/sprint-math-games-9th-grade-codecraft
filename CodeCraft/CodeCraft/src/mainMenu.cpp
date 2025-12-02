#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"../include/mainMenu.h"
#include"../include/startGame.h"
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

void printCenteredAt(string text, int y, WORD color = 7) {
    int width, height;
    getConsoleSize(width, height);

    int x = (width - (int)text.length()) / 2;
    if (x < 0) x = 0;

    setCursorPosition(x, y);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void drawDots() {
    int width, height;
    getConsoleSize(width, height);

    WORD dim = FOREGROUND_BLUE;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x += 4) {
            setCursorPosition(x, y);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), dim);
            cout << ".";
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void displayTitle(int startY) {
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    WORD yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    printCenteredAt("##   ##  ##  ##  ##   ##  #####  #####   ####    ###", startY++, cyan);
    printCenteredAt(" ###  ##  ##  ##  ### ###  ##     ##  ##   ##    ## ##", startY++, cyan);
    printCenteredAt("  ## ####  ##  ##  ## # ##  #####  #####    ##   ##   ##", startY++, cyan);
    printCenteredAt("   ##  ###  ##  ##  ##   ##  ##     ##  ##   ##   #######", startY++, cyan);
    printCenteredAt("   ##   ##   ####   ##   ##  #####  ##   ## ####  ##   ##", startY++, cyan);

    startY++;
    printCenteredAt("~ The Kingdom of Numeria Awaits ~", startY, yellow);
}

void displayMenu(int selectedOption) {
    clearScreen();

    int width, height;
    getConsoleSize(width, height);

    // Calculate starting Y position to center vertically
    int startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    // Menu box
    printCenteredAt("+==================================================+", startY++);
    printCenteredAt("|                                                  |", startY++);
    printCenteredAt("|          >>> M A I N   M E N U <<<               |", startY++);
    printCenteredAt("|                                                  |", startY++);
    printCenteredAt("+==================================================+", startY++);

    string menuItems[] = {
        "Begin Your Quest",
        "How to Play",
        "Hall of Heroes",
        "Settings",
        "Exit to Reality"
    };

    for (int i = 0; i < 5; i++) {
        string prefix = (i == selectedOption) ? " >>  " : "     ";
        string suffix = (i == selectedOption) ? "  << " : "     ";
        string line = "|" + prefix + menuItems[i];

        // Pad to fit box width
        while (line.length() < 51) line += " ";
        line += "|";

        printCenteredAt(line, startY++);
    }

    printCenteredAt("|                                                  |", startY++);
    printCenteredAt("+==================================================+", startY++);
    startY += 2;
    printCenteredAt("Use UP/DOWN arrows | ENTER to select | ESC to exit", startY);
}

void showInstructions() {
    clearScreen();
    drawDots();
    printCenteredAt("Instructions screen...", 5, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    system("pause");
}

void showHighScores() {
    clearScreen();
    drawDots();
    printCenteredAt("Show HighScores...", 5, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    system("pause");
}

void showSettings() {
    clearScreen();
    drawDots();
    printCenteredAt("Show settings...", 5, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    system("pause");
}

void mainMenu() {
    int selectedOption = 0;
    bool running = true;

    while (running) {
        displayMenu(selectedOption);

        int key = _getch();

        if (key == 0 || key == 224) {
            key = _getch();

            if (key == 72) { // up
                selectedOption--;
                if (selectedOption < 0) selectedOption = 4;
            }
            else if (key == 80) { // down
                selectedOption++;
                if (selectedOption > 4) selectedOption = 0;
            }
        }
        // Handle ENTER key
        else if (key == 13) {
            switch (selectedOption) {
            case 0:
                startGame();
                break;
            case 1:
                showInstructions();
                break;
            case 2:
                showHighScores();
                break;
            case 3:
                showSettings();
                break;
            case 4:
                clearScreen();
                int width, height;
                getConsoleSize(width, height);
                int y = height / 2;
                printCenteredAt("+============================================================+", y++);
                printCenteredAt("|   Thank you for saving Numeria, brave Number Weaver!     |", y++);
                printCenteredAt("|   May the Great Equation Stone guide your path!          |", y++);
                printCenteredAt("+============================================================+", y++);
                Sleep(2000);
                running = false;
                break;
            }
        }
        else if (key == 27) { // ESC
            clearScreen();
            drawDots();

            int width, height;
            getConsoleSize(width, height);

            printCenteredAt("Until we meet again, Number Weaver...", height / 2,
                FOREGROUND_RED | FOREGROUND_INTENSITY);
            Sleep(1000);

            running = false;
        }
    }
}

