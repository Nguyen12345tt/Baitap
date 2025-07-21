//
//Mã sinh viên:
//Lớp: CNTT 18-09

#include<iostream>
using namespace std;
int main()
{
    int giay,ngay,gio,phut,sodu;
    cout<<"Nhap so giay:";
    cin>>giay;
    ngay=giay / (24*60*60);
    sodu=ngay % (24*60*60);

    gio=sodu / (60*60);
    sodu=sodu % (60*60);

    phut=sodu / 60;
    sodu=sodu % 60;

    giay=sodu % 60;
    if (ngay>0)
    {
        cout<<ngay << " ngay";
    }
    if (gio>0)
    {
        cout<<gio<<" gio";
    }
    if(phut>0)
    {
        cout<<phut<<" phut";
    }
    if (giay>0)
    {
        cout<<giay<<" giay";
    }
    
    return 0;
}