#include<iostream>
using namespace std;
int main()
{
    int diem;
    cout<<"Nhập điểm của khách hàng:";
    cin>>diem;
    if (diem>500)
    {
        cout<<"Khách hàng VIP";
    }
    else if (diem > 300 and diem <500)
    {
        cout<<"Khách hàng GOLD";
    }
    else
    {
        cout<<"Khách hàng BAC";
    }
    
    return 0;
}