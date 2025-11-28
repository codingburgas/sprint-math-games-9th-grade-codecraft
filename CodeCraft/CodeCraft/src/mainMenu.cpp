#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
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
    drawDots();

    int y = 2;
    displayTitle(y);

    y += 10;

    const char* options[] = {
        "Start Game",
        "Instructions",
        "Exit"
    };

    WORD normalColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    WORD highlightColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    for (int i = 0; i < 3; i++) {
        string line = (i == selectedOption) ? "> " + string(options[i]) + " <" : options[i];
        WORD color = (i == selectedOption) ? highlightColor : normalColor;
        printCenteredAt(line, y++, color);
    }
}

void showInstructions() {
    clearScreen();
    drawDots();
    printCenteredAt("Instructions screen...", 5, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    system("pause");
}

void startGame() {
    clearScreen();
    drawDots();
    printCenteredAt("Game starting...", 5, FOREGROUND_RED | FOREGROUND_INTENSITY);
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
                if (selectedOption < 0) selectedOption = 2;
            }
            else if (key == 80) { // down
                selectedOption++;
                if (selectedOption > 2) selectedOption = 0;
            }
        }
        else if (key == 13) { // ENTER
            switch (selectedOption) {
            case 0: startGame(); break;
            case 1: showInstructions(); break;
            case 2:
                clearScreen();
                drawDots();
                {
                    int width, height;
                    getConsoleSize(width, height);
                    int y = height / 2;

                    WORD magenta = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;

                    printCenteredAt("+============================================================+", y++, magenta);
                    printCenteredAt("|   Thank you for saving Numeria, brave Number Weaver!       |", y++, magenta);
                    printCenteredAt("|   May the Great Equation Stone guide your path!            |", y++, magenta);
                    printCenteredAt("+============================================================+", y++, magenta);
                }
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

