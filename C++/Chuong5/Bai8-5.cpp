#include <iostream>
#include <cstdlib> // Thư viện cho hàm rand()
#include <ctime>   // Thư viện cho hàm time()
using namespace std;

// Hàm coinToss để tung đồng xu
void coinToss() {
    int toss = rand() % 2 + 1; // Sinh ra số ngẫu nhiên 1 hoặc 2
    if (toss == 1) {
        cout << "heads" << endl;
    } else {
        cout << "tails" << endl;
    }
}

int main() {
    srand(time(0)); // Đặt seed cho hàm rand() để sinh số ngẫu nhiên khác nhau mỗi lần chạy
    int numTosses;

    // Yêu cầu người dùng nhập số lần tung đồng xu
    cout << "Nhập số lần tung đồng xu: ";
    cin >> numTosses;

    int headsCount = 0;
    int tailsCount = 0;

    // Tung đồng xu và đếm số lần heads và tails
    for (int i = 0; i < numTosses; ++i) {
        int toss = rand() % 2 + 1;
        if (toss == 1) {
            cout << "heads" << endl;
            ++headsCount;
        } else {
            cout << "tails" << endl;
            ++tailsCount;
        }
    }

    // In ra số lần heads và tails
    cout << "Số lần heads: " << headsCount << endl;
    cout << "Số lần tails: " << tailsCount << endl;

    return 0;
}
