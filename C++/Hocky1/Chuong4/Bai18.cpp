#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("People.txt");
    if (!inputFile) {
        cout << "Không thể mở tệp People.txt." << endl;
        return 1;
    }

    cout << "TĂNG TRƯỞNG DÂN SỐ PRAIRIEVILLE\n";
    cout << "(Mỗi kí tự ‘*’ đại diện cho 1.000 người)\n";

    int year, population;
    while (inputFile >> year >> population) {
        cout << year << " ";
        for (int i = 0; i < population; i++) {
            cout << '*';
        }
        cout << endl;
    }

    inputFile.close();
}
