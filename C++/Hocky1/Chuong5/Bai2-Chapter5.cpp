#include <iostream>
using namespace std;

double getLength() {
    double chieu_dai;
    cout << "Nhập chiều dài của hình chữ nhật: ";
    cin >> chieu_dai;
    return chieu_dai;
}

double getWidth() {
    double chieu_rong;
    cout << "Nhập chiều rộng của hình chữ nhật: ";
    cin >> chieu_rong;
    return chieu_rong;
}

double getArea(double chieu_dai, double chieu_rong) {
    return chieu_dai * chieu_rong;
}

void Display(double chieu_dai, double chieu_rong, double dien_tich) 
{
    cout << "Chiều dài là: " << chieu_dai << endl;
    cout << "Chiều rộng là: " << chieu_rong << endl;
    cout << "Diện tích là: " << dien_tich << endl;
}

int main() {
    double chieu_dai = getLength();
    double chieu_rong = getWidth();
    double dien_tich = getArea(chieu_dai, chieu_rong);
    
    Display(chieu_dai, chieu_rong, dien_tich);
    
    return 0;
}
