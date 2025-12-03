#include <iostream>
#include <windows.h>
#include <conio.h>
#include"../include/leaderBoard.h"
#include"../include/mainMenu.h"
using namespace std;
void showHighScores() {
    clearScreen();
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 20) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    printCenteredAt("+============================================================+", startY++,cyan);
    printCenteredAt("|            >>> H A L L   O F   H E R O E S <<<            |", startY++, cyan);
    printCenteredAt("+============================================================+", startY++, cyan);
    startY++;

    printCenteredAt("+--------+---------------------+-------------+----------+", startY++, cyan);
    printCenteredAt("|  RANK  |    NUMBER WEAVER    |  FRAGMENTS  |   DATE   |", startY++, cyan);
    printCenteredAt("+--------+---------------------+-------------+----------+", startY++, cyan);
    printCenteredAt("|  1st   |  EquationMaster     |    7/7      | 10/12/24 |", startY++, cyan);
    printCenteredAt("|  2nd   |  NumeriaChampion    |    6/7      | 09/12/24 |", startY++, cyan);
    printCenteredAt("|  3rd   |  StoneSeeker        |    5/7      | 08/12/24 |", startY++, cyan);
    printCenteredAt("|  4th   |  MathWizard_ARI     |    4/7      | 07/12/24 |", startY++, cyan);
    printCenteredAt("|  5th   |  PuzzleSolver99     |    4/7      | 06/12/24 |", startY++, cyan);
    printCenteredAt("+--------+---------------------+-------------+----------+", startY++, cyan);

    startY += 2;
    printCenteredAt("Press ESC to return to menu...", startY,cyan);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break; // ESC key
        }
    }
}