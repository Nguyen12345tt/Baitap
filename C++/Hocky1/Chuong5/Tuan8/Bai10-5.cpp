#include <iostream>
#include <cmath> // Thư viện cho hàm pow
using namespace std;

// Hàm trả về số tiền tương lai F khi truyền vào P,i,t
double futureValue(double P, double i, int t);
int main() 
{
    double P,i;
    int t;

    cout<<"Nhập số tiền ban đầu(P):";
    cin>>P;
    cout<<"Nhập lãi suất ngân hàng(i):";
    cin>>i;
    cout<<"Nhập số tháng gửi vào ngân hàng(t):";
    cin>>t;
    cout<<"Số tiền bạn có trong tương lai (F) là:"<<futureValue(P,i,t)<<endl;    
    return 0;
}
//Định nghĩa hàm futureValue
double futureValue(double P, double i, int t){
    double F;
    F= P * pow((1+i),t);
    return F;
}
