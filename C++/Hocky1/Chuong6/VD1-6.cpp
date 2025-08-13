/* MẢNG VÀ THUẬT TOÁN SẮP XẾP
- Mảng là 1 biến có thể lưu trữ nhiều nhiều giá có cùng kiểu
- Các giá trị được lưu liên tiếp nhau
- int a[5]; : Khai báo mảng có tên là a gồm 5 phần tử kiểu int
- Truy cập mảng thông qua các chỉ số. VD:a[0],a[1],...
- Chỉ số của mảng bắt đầu từ 0 và kết thúc là n-1.
    VD: int a[5]; thì gồm các phần tử a[0],a[1],a[2],a[3],a[4]
    a[5] là LỖI.
*/
#include<iostream>
using namespace std;
int main()
{
    int a[5]; //Khai báo mảng a gồm 5 phần tử kiểu int
    a[0]=99;
    a[1]=88;
    a[2]=a[1]+10;
    cout<<a[0]<<"\t"<<a[1]<<"\t"<<a[2];
}