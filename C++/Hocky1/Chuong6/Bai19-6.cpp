#include <iostream>
using namespace std;

const int SIZE = 3;
void displayBoard(char board[SIZE][SIZE]);
bool checkWin(char board[SIZE][SIZE], char player);
bool checkDraw(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE] = { {'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'} };
    int row, col;
    bool gameOver = false;
    char currentPlayer = 'X';

    while (!gameOver) {
        displayBoard(board);
        cout << "Người chơi " << (currentPlayer == 'X' ? "1" : "2") << " (" << currentPlayer << "), nhập hàng và cột (0-2): ";
        cin >> row >> col;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '*') {
            board[row][col] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Người chơi " << (currentPlayer == 'X' ? "1" : "2") << " (" << currentPlayer << ") là người chiến thắng!" << endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "Trò chơi hòa!" << endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Vị trí không hợp lệ, vui lòng nhập lại." << endl;
        }
    }

    return 0;
}

void displayBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '*') return false;
        }
    }
    return true;
}
