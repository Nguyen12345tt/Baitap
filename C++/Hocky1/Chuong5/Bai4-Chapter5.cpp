#include<iostream>
#include<string>
using namespace std;
int getNamAccidents(string ten_khu_vuc)
{
    int so_vu_tai_nan;
    cout<< "Nhập số vụ tai nạn của khu vực " << ten_khu_vuc <<":";
    cin>>so_vu_tai_nan;
    while (so_vu_tai_nan<0)
    {
        cout<<"Số vụ tai nạn phải lớn hơn 0. Nhập lại đến khi giá trị lớn hơn 0:";
        cin>>so_vu_tai_nan;
    }
    return so_vu_tai_nan;
}
void findLowest(int Dong,int Nam,int Tay,int Bac,int trung_tam)
{
    int lowest = Dong;
    string ten_khu_vuc = "Đông";
    if (Nam<lowest)
    {
        lowest = Nam;
        ten_khu_vuc="Nam";
    }
    if (Tay<lowest)
    {
        lowest = Tay;
        ten_khu_vuc = "Tây";
    }
    if (Bac<lowest)
    {
        lowest = Bac;
        ten_khu_vuc = "Bắc";
    }
    if (trung_tam<lowest)
    {
        lowest = trung_tam;
        ten_khu_vuc = "Trung tâm";
    }
    
    cout<< "Khu vực có ít vụ tai nạn nhất là: " << ten_khu_vuc << " với số vụ: " <<  lowest << endl;
}
int main()
{
    int Dong = getNamAccidents("Đông");
    int Tay = getNamAccidents("Tây");
    int Nam = getNamAccidents("Nam");
    int Bac = getNamAccidents("Bắc");
    int trung_tam = getNamAccidents("Trung tâm");

    findLowest(Dong,Tay,Nam,Bac,trung_tam);

    return 0;
}
