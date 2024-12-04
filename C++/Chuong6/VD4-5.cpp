/*VD4-5: Viet ham tinh tong hai so bat ky
- Ham co gia tri tra ve khong?
    + Co: tra ve tong cua 2 so -> tong cua 2 so kieu gi? float
- de tinh tong cua 2 so thi can truyen vao cai gi?
    + truyen vao 2 so bat ky(co 2 tham so truyen vao )
*/

#include<iostream>
using namespace std;
float TinhTong(float a, float b); // Khai báo hàm nguyên mẫu
void HienThi(float Tong); //Khai báo hàm HienThi
int main()
{
    float Tong;
    Tong = TinhTong(5,9);
    HienThi(Tong);
    return 0;
}
// Định nghĩa hàm TinhTong
float TinhTong(float a, float b)
{
    return a+b;
}
// Định nghĩa hàm HienThi để in ra màn hình Tong
void HienThi(float Tong)
{
    cout<<"Tong la:"<<Tong<<endl;
}