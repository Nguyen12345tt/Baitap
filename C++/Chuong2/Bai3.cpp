//Trịnh Anh Tuấn
//Mã sinh viên:1871020635
//Lớp: CNTT 18-09

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    //Nhập giá trị của 5 bài
    float bai1,bai2,bai3,bai4,bai5,diem_trung_binh;
    cout<<"Nhap diem bai 1:";
    cin>>bai1;
    cout<<"Nhap diem bai 2:";
    cin>>bai2;
    cout<<"Nhap diem bai 3:";
    cin>>bai3;
    cout<<"Nhap diem bai 4:";
    cin>>bai4;
    cout<<"Nhap diem bai 5:";
    cin>>bai5;
    //Tính điểm trung bình của cả 5 bài
    diem_trung_binh=(bai1+bai2+bai3+bai4+bai5)/5;
    cout << fixed << setprecision(1);
    cout<<"Diem trung binh cua 5 bai la:"<<diem_trung_binh<<endl;
}