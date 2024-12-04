#include <iostream>
using namespace std;

int main() {
    int cent, nickel, dime, quarter;
    cout << "Nhập số cent (1 đô la bằng 100 cent): ";
    cin >> cent;
    cout << "Nhập số nickel (1 nickel bằng 5 cent): ";
    cin >> nickel;
    cout << "Nhập số dime (1 dime bằng 10 cent): ";
    cin >> dime;
    cout << "Nhập số quarter (1 quarter bằng 35 cent): ";
    cin >> quarter;

    int total = cent + (nickel * 5) + (dime * 10) + (quarter * 35);

    if (total == 100) {
        cout << "Bạn đã thắng! Tổng số tiền đúng bằng 1 đô la." << endl;
    } else if (total < 100) {
        cout << "Tổng số tiền nhỏ hơn 1 đô la." << endl;
    } else {
        cout << "Tổng số tiền lớn hơn 1 đô la." << endl;
    }

    return 0;
}
