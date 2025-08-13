#include<iostream>
using namespace std;
int main()
{
    int phuongthucthanhtoan;
    cout<<"Nhập lựa chọn phương thức thanh toán:"<<endl;
    cout<<"1.Thanh toán bằng tiền mặt"<<endl;
    cout<<"2.Thanh toán bằng thẻ"<<endl;
    cout<<"3.Thanh toán bằng ví điện tử";
    cin>>phuongthucthanhtoan;
    switch (phuongthucthanhtoan)
    {
    case 1:
        cout<<"Thanh toán bằng tiền mặt";
        break;
    case 2:
        cout<<"Thanh toán bằng thẻ";
        break; 
    case 3:
        cout<<"Thanh toán bằng ví điện tử";
        break;
    default:
        cout<<"Vui lòng chọn lại";
    }
    return 0;
}