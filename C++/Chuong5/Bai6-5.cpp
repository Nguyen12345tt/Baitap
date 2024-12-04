#include <iostream>
using namespace std;

// Định nghĩa hàm để tính động năng
double kineticEnergy(double m, double v) {
    return 0.5 * m * v * v;
}

int main() {
    double m, v;

    // Yêu cầu người dùng nhập vào khối lượng và vận tốc của vật
    cout << "Nhập khối lượng của vật (kg): ";
    cin >> m;
    cout << "Nhập vận tốc của vật (m/s): ";
    cin >> v;

    // Gọi hàm kineticEnergy và in ra kết quả
    double ke = kineticEnergy(m, v);
    cout << "Động năng của vật là: " << ke  << endl;

    return 0;
}
