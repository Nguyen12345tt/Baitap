#include<iostream>
#include<string>
using namespace std;
struct Sinhvien
{
    string HoTen;
    int Tuoi;
    string Email;
};

int main()
{
Sinhvien sv[5];
    for (int i=0;i<5;i++)
    {
        //Nhập thông tin sv
        cout<<"Nhập thông tin của sinh viên thứ "<<i+1<<":"<<endl;
        cout<<"Họ tên: ";
        if (i>0) cin.ignore();
        getline(cin, sv[i].HoTen);
        //Nhập tuổi
        cout<<"Nhập tuổi:";
        cin>>sv[i].Tuoi;
        //Nhập email
        cout<<"Nhập email:";
        cin.ignore();
        getline(cin,sv[i].Email);
        cout<<endl;
    }
    int Max=0;
    for (int i = 1; i <5; i++)
    {
        if (sv[i].Tuoi>sv[Max].Tuoi)
        {
            Max=i;
        }
    }
    
    cout<<"Sinh viên có số tuổi cao nhất là:"<<endl;
    cout<<"Họ tên:"<<sv[Max].HoTen<<endl;
    cout<<"Tuổi:"<<sv[Max].Tuoi<<endl;
    cout<<"Email:"<<sv[Max].Email<<endl;

    return 0;

}