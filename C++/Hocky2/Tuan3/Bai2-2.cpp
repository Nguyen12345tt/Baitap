/* Bài 2-2: Viết hàm đệ quy để đếm số chữ số */
#include <iostream>
#include <cmath>
using namespace std;
// Khai báo hàm nguyên mẫu
int DemChuSo(int n);
int main()
{
    cout<<DemChuSo(9578);
    return 0;
}
//Định nghĩa hàm
int DemChuSo(int n) //Đếm và trả về chữ số
{
    n = abs(n); //Lấy trị tuyệt đối của n
    if (n<10)
    {
        return 1;
    }
    return 1 + DemChuSo(n/10);
}