#include <iostream>
using namespace std;

int main() {
    const int so = 10;
    int numbers[so];

    // Nhập mười giá trị vào mảng
    cout << "Nhập 10 giá trị vào mảng:" << endl;
    for (int i = 0; i < so; ++i) {
        cout << "Giá trị " << i+1 << ": ";
        cin >> numbers[i];
    }

    // Tìm giá trị lớn nhất và nhỏ nhất trong mảng
    int solonnhat = numbers[0];
    int sonhonhat = numbers[0];

    for (int i = 1; i < so; ++i) {
        if (numbers[i] > solonnhat) {
            solonnhat = numbers[i];
        }
        if (numbers[i] < sonhonhat) {
            sonhonhat = numbers[i];
        }
    }

    // Hiển thị giá trị lớn nhất và nhỏ nhất
    cout << "Giá trị lớn nhất: " << solonnhat << endl;
    cout << "Giá trị nhỏ nhất: " << sonhonhat << endl;

    return 0;
}
