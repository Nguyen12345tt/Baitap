/* Bài 2-5: Viết 1 hàm đệ quy để in ra 1 chuỗi ký tự theo thứ tự ngược*/
#include<iostream>
using namespace std;
//Khai báo hàm
void DaoNguocXau (string s, int n);
int main()
{
    DaoNguocXau("abcde",4);
    return 0;
}
//Định nghĩa hàm
void DaoNguocXau (string s, int n)
{
    if (n<0)
    {
        return;
    }
    cout<<s[n];
    DaoNguocXau(s,n-1);
}