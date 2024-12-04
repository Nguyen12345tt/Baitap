/* VD3: Đọc lần lượt các thông tin như họ tên, tuổi, email từ tệp thongtin.txt vào các biến ten,tuoi,email*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f1;
    string HoTen,email;
    int Tuoi;
    
    f1.open("thongtin.txt");
    getline(f1,HoTen);
    f1>>Tuoi;
    f1>>email;
    f1.close();
    
    cout<<HoTen<<endl;
    cout<<Tuoi<<endl;
    cout<<email;

    return 0;
}