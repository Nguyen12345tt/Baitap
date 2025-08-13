#include <iostream>
using namespace std;

// Hàm để chuyển đổi từ độ F sang độ C
double celsius(double fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32);
}

int main() {
    // Sử dụng vòng lặp để hiển thị giá trị từ 0 đến 20 trong thang độ F
    for (int fahrenheit = 0; fahrenheit <= 20; ++fahrenheit) {
        double celsiusValue = celsius(fahrenheit);
        cout << "F: " << fahrenheit << " -> C: " << celsiusValue << endl;
    }

    return 0;
}
