#include<iostream>
using namespace std;

// Hàm nguyên mẫu
double getLength();
double getWidth();
double getArea(double, double); // Hàm nguyên mẫu chưa cần tên của tham số, nhưng cần kiểu của tham số
void Display(double chieu_dai, double chieu_rong, double dien_tich);

int main() {
    double chieu_dai, chieu_rong, dien_tich;

    chieu_dai = getLength();
    chieu_rong = getWidth();
    dien_tich = getArea(chieu_dai, chieu_rong);
    Display(chieu_dai, chieu_rong, dien_tich);

    return 0;
}

// Định nghĩa hàm getLength
double getLength() {
    double chieu_dai;
    cout << "Nhập chiều dài của hình chữ nhật: ";
    cin >> chieu_dai;
    return chieu_dai;
}

// Định nghĩa hàm getWidth
double getWidth() {
    double chieu_rong;
    cout << "Nhập chiều rộng của hình chữ nhật: ";
    cin >> chieu_rong;
    return chieu_rong;
}

// Định nghĩa hàm getArea
double getArea(double chieu_dai, double chieu_rong) {
    return chieu_dai * chieu_rong;
}

// Định nghĩa hàm Display
void Display(double chieu_dai, double chieu_rong, double dien_tich) {
    cout << "Chiều dài là: " << chieu_dai << endl;
    cout << "Chiều rộng là: " << chieu_rong << endl;
    cout << "Diện tích là: " << dien_tich << endl;
}
