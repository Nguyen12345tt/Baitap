/* Vidu1-8: DỮ LIỆU CÓ CẤU TRÚC
- Dữ liệu có cấu trúc là dữ liệu do người lập trình định nghĩa
- Kiểu dữ liệu này gồm nhiều trường có kiểu dữ liệu khác nhau
- VD: Định nghĩa kiểu dữ liệu Sinhvien gồm các trường sau:
        + tên kiểu string
        + Tuổi int
        + Email kiểu string
=> Kiểu dữ liệu trên được định nghĩa như sau:
struct Sinhvien
{
    string Ten;
    int Tuoi;
    string Email;
};
- Kết thúc định nghĩa PHẢI có dấu ";"
- Để khai báo biến sv1 có kiểu Sinhvien được định nghĩa trên như sau:
Sinhvien sv1;
- Để khai báo 1 mảng DSSV gồm 100 phần tử kiểu Sinhvien như sau:
Sinhvien DSSV[100];
- Để làm việc với kiểu dữ liệu có cấu trúc, cần làm việc với từng trường.
- VD1: sv1.Ten; sv1.Tuoi; sv1.Email
- VD2: DSSV[i].Ten; DSSV[i].Tuoi; DSSV[i].Email
*/

#include<iostream>
using namespace std;
struct SinhVien
{
    string HoTen;
    int Tuoi;
    string Email;
};
int main()
{
    SinhVien sv1,sv2;

    cout<<"Nhập vào tên sinh viên 1:";
    getline(cin,sv1.HoTen);
    cout<<"Nhập vào tuổi sinh viên 1:";
    cin>>sv1.Tuoi;
    cout<<"Nhập vào email sinh viên 1:";
    cin>>sv1.Email;
    
    cin.ignore();
    cout<<"Nhập vào tên sinh viên 2:";
    getline(cin,sv2.HoTen);
    cout<<"Nhập vào tuổi sinh viên 2:";
    cin>>sv2.Tuoi;
    cout<<"Nhập vào email sinh viên 1:";
    cin>>sv2.Email;

    cout<<sv1.HoTen<<"\t"<<sv1.Tuoi<<"\t"<<sv1.Email<<endl;
    cout<<sv2.HoTen<<"\t"<<sv2.Tuoi<<"\t"<<sv2.Email<<endl;
    return 0;
}