#include <iostream>
using namespace std;

int main() 
{
    const int NUM_STORES = 5;
    int sales[NUM_STORES];

    // Nhập doanh số bán hàng cho 5 cửa hàng
    for (int i = 0; i < NUM_STORES; i++) 
    {
        do {
            cout << "Nhập vào doanh số bán hàng của cửa hàng thứ " << (i + 1) << ": ";
            cin >> sales[i];
            if(sales[i] < 100)
            {
                cout << "Lỗi: Mày phải nhập 100$ đổ lên\n";
            }
        } while (sales[i] < 100);
    }

    // Hiển thị biểu đồ dạng thanh
    cout << "\nSALES BAR CHART\n";
    cout << "(Mỗi * = $100)\n";

    for (int i = 0; i < NUM_STORES; i++)  // Sửa điều kiện vòng lặp
    {
        cout << "Cửa hàng " << (i + 1) << ": ";
        int num_stars = sales[i] / 100;  // Mỗi * tương ứng với $100 doanh thu
        for (int j = 0; j < num_stars; j++) 
        {
            cout << '*';
        }
        cout << endl;
    }
}
