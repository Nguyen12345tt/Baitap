/*Bài 2-3: Viết hàm đệ quy để tìm ước số chung lớn nhất của a và b*/
#include <iostream>
using namespace std;
//Khai báo hàm nguyên mẫu
int USCLN(int a, int b); // Tìm và trả về USCLN của a và b
int main()
{
    cout<<USCLN(10,8);
    return 0;
}
int USCLN(int a, int b) // Tìm và trả về USCLN của a và b
{
    if (b==0)
    {
        return a;
    }
    return USCLN(b,a%b);
}