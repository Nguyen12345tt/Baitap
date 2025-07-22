#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string HoTen,email;
    int Tuoi;
    ofstream f1;
    f1.open("canhan.txt");
    cout<<"Nhap vao ho ten:";
    getline(cin,HoTen);
    cout<<"Nhap vao tuoi:";
    cin>>Tuoi;
    cout<<"Nhap email:";
    cin>>email;
    f1<<HoTen<<endl;
    f1<<Tuoi<<endl;
    f1<<email<<endl;
    f1.close();
    return 0;
}