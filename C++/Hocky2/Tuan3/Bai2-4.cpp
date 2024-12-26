/*Bài 2-4: Viết hàm đệ quy để tính số Fibonaci ở vị trí n*/
#include<iostream>
using namespace std;
int Fibonacci(int n); //Tìm và trả về Fibonacci ở vị trí n
int main()
{
    cout<<Fibonacci(6);
    return 0;
}
//Định nghĩa hàm
int Fibonacci(int n)
{
    if (n<=1)
    {
        return n;
    }
    return Fibonacci(n-1) + Fibonacci(n-2);
}