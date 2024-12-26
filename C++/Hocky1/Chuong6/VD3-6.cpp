/* Vidu3-6:Khởi tạo mảng*/
#include<iostream>
using namespace std;
int main()
{
    int a[]={44,33,77,99};//Tạo và khởi tạo giá trị cho mảng a gồm 4 phẩn tử
    //In mảng
    for (int i=0;i<4;i++)
        cout<<a[i]<<"\t";
    //Tính tổng mảng
    int Tong = 0;
    for (int i=0;i<4;i++)
        Tong+=a[i];
    cout<<"Tổng mảng là: "<<Tong<<endl;
    //Tìm giá trị lớn nhất trong mảng
    int max=a[0];
    for (int i=1;i<4;i++)
    {
        if (a[i]>max)
            max=a[i];
    }
    cout<<"Giá trị lớn nhất là: "<<max<<endl;
    return 0;
}