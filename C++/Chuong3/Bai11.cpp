#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Khởi tạo số ngẫu nhiên
    int so1 = rand() % 1000; // Số ngẫu nhiên từ 0 đến 99
    int so2 = rand() % 1000; // Số ngẫu nhiên từ 0 đến 99
    int ketqua;

    cout << "Phép toán: " << endl;
    cout << " " << so1 << endl;
    cout << "+" << endl;
    cout << " " << so2 <<endl;
    cout <<"----"<<endl;
    cout << "Nhập kết quả của bạn: ";
    cin >> ketqua;

    int tong = so1 + so2;
    if (ketqua == tong) {
        cout << "Chúc mừng! Bạn đã tính đúng." << endl;
    } else {
        cout << "Kết quả không chính xác. Kết quả đúng là: " << tong << endl;
    }

    return 0;
}
