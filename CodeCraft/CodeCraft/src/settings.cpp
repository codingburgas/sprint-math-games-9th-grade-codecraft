#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"../include/mainMenu.h"
#include"../include/settings.h"
using namespace std;
void showSettings() {
    clearScreen();
    WORD cyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    int width, height;
    getConsoleSize(width, height);
    int startY = (height - 18) / 2;
    if (startY < 0) startY = 0;

    displayTitle(startY);
    startY += 8;

    printCenteredAt("+============================================================+", startY++, cyan);
    printCenteredAt("|                 >>> S E T T I N G S <<<                   |", startY++, cyan);
    printCenteredAt("+============================================================+", startY++, cyan);
    startY += 2;

    printCenteredAt(">> Sound Effects: ON", startY++, cyan);
    printCenteredAt(">> Story Mode: Enabled", startY++, cyan);
    printCenteredAt(">> Timer: Enabled", startY++, cyan);
    printCenteredAt(">> Difficulty: Medium", startY++, cyan);
    printCenteredAt(">> Hint System: Available (costs 5 pts)", startY++, cyan);

    startY += 2;
    printCenteredAt("(Customization coming in future updates!)", startY++, cyan);
    startY += 2;
    printCenteredAt("Press ESC to return to menu...", startY, cyan);

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 27) break; // ESC key
        }
    }
}