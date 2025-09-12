#include <iostream>
using namespace std;

int main() {
    int a[100];
    int n;
    cout << "Nhập vào số phần tử (n < 100): ";
    cin >> n;
    
    // Sử dụng for để truy cập lần lượt các chỉ số của mảng
    // Nhập mảng
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // In mảng
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    
    return 0;
}
