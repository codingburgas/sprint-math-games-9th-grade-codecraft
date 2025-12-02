#pragma once
#include <string>

// Utility functions
void clearScreen();
void setCursorPosition(int x, int y);
void getConsoleSize(int& width, int& height);
void printCenteredAt(std::string text, int y);
void displayTitle(int startY);

// Main menu
void mainMenu();

// Menu actions (implemented elsewhere)
void displayMenu(int selectedOption);
void showInstructions();
void showHighScores();
void showSettings();
void startGame();