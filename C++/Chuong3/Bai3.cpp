#include <iostream>
using namespace std;
int main() {
    int ngay, thang, nam;

    cout << "Nhập ngày: ";
    cin >> ngay;
    cout << "Nhập tháng: ";
    cin >> thang;
    cout << "Nhập năm (2 chữ số cuối): ";
    cin >> nam;

    if (ngay*thang==nam)
    {
        cout << "Ngày " << ngay << "/" << thang << "/" << nam << " là ngày phép thuật!" << endl;
    } 
    else 
    {
        cout << "Ngày " << ngay << "/" << thang << "/" << nam << " không phải là ngày phép thuật." << endl;
    }

    return 0;
}
