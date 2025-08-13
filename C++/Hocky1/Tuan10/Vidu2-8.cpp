/*Vidu 2-8: MẢNG KIỂU DỮ LIỆU CÓ CẤU TRÚC
- Định nghĩa 1 kiểu dữ liệu Congnhan gồm các trường sau:
    + Họ tên kiểu String
    + Chức vụ kiểu String
    + Tiền lương float
- Khai báo 1 danh sách gồm 100 phần tử kiểu Congnhan
- Nhập thông tin của 3 công nhân
- In danh sách công nhân 
*/

#include<iostream>
using namespace std;
struct Congnhan
{
    string HoTen;
    string Chucvu;
    float Tienluong;
};
int main()
{
    Congnhan DSCN[100];
    //Nhập mảng danh sách công nhân
    for (int i=0;i<3;i++)
    {
        cout<<"Nhập họ tên công nhân "<<i+1<<":";
        getline(cin,DSCN[i].HoTen);
        cout<<"Nhập vào chức vụ công nhân "<<i+1<<":";
        getline(cin,DSCN[i].Chucvu);
        cout<<"Nhập vào tiền lương công nhân "<<i+1<<":";
        cin>>DSCN[i].Tienluong;
        cin.ignore();
    }
    
    //In danh sách công nhân
    for (int i=0; i<3; i++)
    {
        cout<<DSCN[i].HoTen<<"\t"<<DSCN[i].Chucvu<<"\t"<<DSCN[i].Tienluong<<endl;
    }

    //In danh sách công nhân có tiền lương > 1000 
    for (int i=0; i<3; i++)
    {
        if (DSCN[i].Tienluong>1000)
        {
            cout<<DSCN[i].HoTen<<"\t"<<DSCN[i].Chucvu<<"\t"<<DSCN[i].Tienluong<<endl;
        }
    }
    // Tính và in ra tổng Tienluong
    float Tong=0;
    for (int i=0; i<3; i++)
    {
        Tong+=DSCN[i].Tienluong;
    }
    cout<<"Tổng tiền lương là: "<<Tong<<endl;
    return 0;
}
