#include <iostream>
using namespace std;
int main() 
{
    float so1, so2;

    cout << "Nhập số thứ nhất: ";
    cin >> so1;
    cout << "Nhập số thứ hai: ";
    cin >> so2;

    int max = (so1 > so2) ? so1 : so2;
    int min = (so1 < so2) ? so1 : so2;

    cout << "Số lớn hơn là: " << max << endl;
    cout << "Số nhỏ hơn là: " << min;

    return 0;

}
