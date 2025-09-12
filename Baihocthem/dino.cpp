#include <iostream>
#include <conio.h>      // kbhit(), getch()
#include <windows.h>    // Sleep(), system("cls")
#include <ctime>        // time(), srand()
using namespace std;

int dinoY = 10;          // Vị trí Y của khủng long
bool isJumping = false;
int obstacleX = 50;      // Vị trí X của chướng ngại vật
int score = 0;

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawDino() {
    gotoxy(5, dinoY);
    cout << "  ʕ•ᴥ•ʔ";  // ASCII khủng long
}

void drawObstacle() {
    gotoxy(obstacleX, 10);
    cout << "|";
}

void clearScreen() {
    system("cls");
}

void updateGame() {
    if (isJumping) {
        dinoY = 7;
    } else {
        dinoY = 10;
    }

    obstacleX--;
    if (obstacleX < 0) {
        obstacleX = 50;
        score++;
    }

    // Va chạm
    if (obstacleX == 5 && dinoY == 10) {
        gotoxy(0, 12);
        cout << "💥 Game Over! Score: " << score << endl;
        exit(0);
    }
}

void input() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == ' ') {
            isJumping = true;
        } else if (ch == 'x' || ch == 'X') {
            exit(0);
        }
    } else {
        isJumping = false;
    }
}

int main() {
    srand(time(0));
    while (true) {
        clearScreen();
        drawDino();
        drawObstacle();
        gotoxy(0, 0);
        cout << "Score: " << score << "   (Space: Jump, X: Exit)";
        input();
        updateGame();
        Sleep(100);  // Delay 100ms
    }
    return 0;
}