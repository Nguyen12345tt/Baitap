#include <iostream>
#include <cmath> // Thư viện cho hàm pow
using namespace std;

// Hàm để tính số tiền cần gửi hiện tại (Present Value)
double presentValue(double futureValue, double annualRate, int years) {
    return futureValue / pow(1 + annualRate, years);
}

int main() {
    double F, r;
    int N;

    // Yêu cầu người dùng nhập số tiền dự kiến nhận, lãi suất hàng năm và số năm gửi tiết kiệm
    cout << "Nhập số tiền dự kiến nhận trong tương lai (F): ";
    cin >> F;
    cout << "Nhập lãi suất hàng năm (r) (ví dụ: 0.05 cho 5%): ";
    cin >> r;
    cout << "Nhập số năm gửi tiết kiệm (N): ";
    cin >> N;

    // Gọi hàm presentValue để tính số tiền cần gửi hiện tại
    double P = presentValue(F, r, N);
    
    // In ra số tiền cần phải gửi hiện tại
    cout << "Số tiền cần phải gửi hiện tại là: " << P << " USD" << endl;

    return 0;
}
