/* Ví dụ 1 - chương 7: CON TRỎ
- Khi khai báo 1 biến thì biến đó sẽ có 1 địa chỉ trên ô nhớ
- Biến con trỏ dùng để lưu địa chỉ
- VD: int *ptr; //Biến con trỏ ptr để lưu địa chỉ kiểu int
- Con trỏ là phần hay nhất của C++ vì:
    + Cấp phát và giải phóng ô nhớ trong quá trình chạy
    + Can thiệp vào địa chỉ của từng ô nhớ
    +...
*/

#include<iostream>
using namespace std;
int main()
{
    int x = 9; // Khai báo biến x kiểu int và có giá trị là 9

    cout<<x<<endl; //in ra 9
    cout<<&x<<endl; //in ra địa chỉ của biến x

    int *ptr; //Khai báo biến con trỏ ptr(hay gọi tắt là con trỏ ptr)

   //ptr = x; //SAI vì ptr chỉ lưu địa chỉ không lưu giá trị biến
   ptr = &x; //ĐÚNG vì ptr lưu địa chỉ của biến x
   cout<<ptr<<endl; //In ra địa chỉ đang lưu trữ ở con trỏ ptr (x)
   cout<<&ptr<<endl; // In ra địa chỉ của con trỏ ptr
   cout<<*ptr<<endl; // In ra giá trị tại ô nhớ mà con trỏ ptr đang trỏ tới
}