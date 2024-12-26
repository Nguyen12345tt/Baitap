#include<iostream>
using namespace std;
int main()
{
    //Nhập chiều dài và chiều rộng của hcn từ người dùng
    float chieu_dai1,chieu_rong1,chieu_dai2,chieu_rong2;
    cout<<"Nhap chieu dai cua hinh chu nhat 1:";
    cin>>chieu_dai1;
    cout<<"Nhap chieu rong cua hinh chu nhat 1:";
    cin>>chieu_rong1;
    cout<<"Nhap chieu dai cua hinh chu nhat 2:";
    cin>>chieu_dai2;
    cout<<"Nhap chieu rong cua hinh chu nhat 2:";
    cin>>chieu_rong2;
    //Tính diện tích của 2 hình chữ nhật
    double dien_tich1 = chieu_dai1*chieu_rong1;
    double dien_tich2 = chieu_dai2*chieu_rong2;
    //So sánh diện tích của 2 hình chữ nhật
    if (dien_tich1>dien_tich2)
    {
        cout<<"Diện tích của hình chữ nhật 1 lớn hơn diện tích của hình chữ nhật 2";
    }
    else if(dien_tich1<dien_tich2)
    {
        cout<<"Diện tích của hình chữ nhật 1 nhỏ hơn diện tích của hình chữ nhật 2";
    }
    else
    {
        cout<<"2 hình chữ nhật có diện tích bằng nhau";
    }
    return 0;
}