/*Bai3-6.cpp: Gợi ý bài 3-chương 6
Phân tích:
- Tạo 2 mảng: 1 mảng để lưu trữ tên, 1 mảng để lưu số lượng
- string Ten[5] ={"Nhẹ","Vừa", Ngọt, Nóng, chanh }
- int SoLuong[5]; //Mảng để nhập số lượng bán
- Như vậy,
        SoLuong[0] tương ứng với Ten[0]="Nhẹ"
        SoLuong[1] tương ứng với Ten[1]="Vừa"
        SoLuong[2] tương ứng với Ten[2]="Ngọt"
        SoLuong[3] tương ứng với Ten[3]="Nóng"
        SoLuong[4] tương ứng với Ten[4]="Chanh"
- Nhập vào số lượng bán (Nhập mảng SoLuong)
- Hiển thị doanh số bán hàng (In mảng Ten và mảng SoLuong)
- Tổng doanh số (Tổng mảng SoLuong)
- Mặt hàng bán chạy nhất (Tìm vị trí Max và in ra Ten tương ứng)
- Mặt hàng bán chậm nhất (Tìm vị trí Min và in ra Ten tương ứng)*/

#include<iostream>
using namespace std;
int main()
{
    string Ten[5]={"Nhẹ","Vừa","Ngọt","Nóng","Chanh"};
    int SoLuong[5]; //Nhập số lượng tương ứng với các tên

    //Nhập vào số lượng bán (Nhập mảng SoLuong)
    for(int i=0; i<5;i++)
    {
        cout<<"Nhập vào vị:"<<Ten[i]<<":";
        cin>>SoLuong[i];
    }
    //Hiển thị doanh số (In mảng Ten và mảng SoLuong)
    for(int i=0; i<5; i++)
    {
        cout<<Ten[i]<<"\t"<<SoLuong[i]<<endl;
    }
    //Tổng doanh số bán hàng (Tính tổng mảng SoLuong)
    int Tong=0;
    for(int i=0;i<5;i++)
    {
        Tong+=SoLuong[i];
    }
    cout<<"Tong doanh so ban hang la:"<<Tong<<endl;
    // Tìm mặt hàng bán chạy nhất (Tìm vị trí Max và in ra mảng Ten tương ứng)
    int Max=SoLuong[0];
    int vitriMax=0;
    for (int i=1; i<5; i++)
    {
        if (SoLuong[i]>Max)
        {
            Max=SoLuong[i];
            vitriMax=i;
        }
    }
    cout<<"Mặt hàng bán chạy nhất: "<<Ten[vitriMax]<<endl;
    // Tìm mặt hàng bán chậm nhất (Tìm vị trí Min và in ra mảng Ten tương ứng)
    int Min=SoLuong[0];
    int vitriMin=0;
    for (int i=1; i<5; i++)
    {
        if (SoLuong[i]<Min)
        {
            Min=SoLuong[i];
            vitriMin=i;
        }
    }
    cout<<"Mặt hàng bán chậm nhất: "<<Ten[vitriMin]<<endl;
    return 0;
}