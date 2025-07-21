#include<iostream>
using namespace std;
int main()
{
    float chieu_cao,can_nang,bmi;
    cout<<"Nhap chieu cao cua ban:";
    cin>>chieu_cao;
    cout<<"Nhap can nang cua ban:";
    cin>>can_nang;
    bmi=can_nang/(chieu_cao*chieu_cao);
    if(bmi>25)
    {
        cout<<"Ban beo qua.Hay an bot lai";
    }
    else if(bmi<18.5)
    {
        cout<<"Ban gay qua.Phai an them";
    }
    else
    {
        cout<<"Ban binh thuong";
    }
    return 0;

}