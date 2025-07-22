#include <iostream>
using namespace std;
int main() {
    int dong = 5; // Số dòng của tam giác

    for (int i = 1; i <= dong; i++) {
        for (int j = 1; j <= dong - i; j++) {
            cout << " "; // In khoảng trắng
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*"; // In dấu sao
        }
        cout << endl; // Xuống dòng
    }
}
