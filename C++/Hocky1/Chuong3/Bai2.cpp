#include<iostream>
using namespace std;
int main()
{
    int sotunhien;
    cout<<"Nhap so tu nhien tu 1 den 10:";
    cin>>sotunhien;
    if (sotunhien< 1 || sotunhien>10)
    {
        cout<<"Nhap so khong hop le.Vui long nhap lai.";
    }  
    else
    switch (sotunhien)
    {
    case 1:cout<<"I"<<endl;
        break;
    case 2:cout<<"II"<<endl;
        break;
    case 3:cout<<"III"<<endl;
        break;
    case 4:cout<<"IV"<<endl;
        break;
    case 5:cout<<"V"<<endl;
        break;
    case 6:cout<<"VI"<<endl;
        break;
    case 7:cout<<"VII"<<endl;
        break;
    case 8:cout<<"VIII"<<endl;
        break;
    case 9:cout<<"IX"<<endl;
        break;
    case 10:cout<<"X"<<endl;
        break;
    }

return 0;
}