#include<iostream>
using namespace std;
int main()
{
    float can_nang,trong_luong;
    cout<<"Nhap can nang cua do vat:";
    cin>>can_nang;
    trong_luong=can_nang*9.8;
    if(trong_luong>100)
    {
        cout<<"Vat qua nang";
    }   
    else if(trong_luong<10)
    {
        cout<<"Vat qua nhe";
    }
    else
    {
        cout<<"Vat binh thuong";
    }
    return 0;
}