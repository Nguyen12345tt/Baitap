#include <iostream>
using namespace std;

int main() 
{
    int n;
    int tong = 0;
        // Yêu cầu người dùng nhập một giá trị nguyên dương
    do 
    {
        cout << "Nhap mot gia tri nguyen duong: ";
        cin >> n;
        if (n <= 0) 
        {
            cout << "Gia tri khong hop le. Vui long nhap lai." << endl;
        }
    } 
    while (n <= 0);

    // Tính tổng của tất cả các số nguyên từ 1 đến n
    for (int i = 1; i <= n; ++i) 
    {
        tong += i;
    }

    // Hiển thị kết quả
    cout << "Tong cua tat ca cac so nguyen tu 1 den " << n << " la: " << tong << endl;

return 0;
}
