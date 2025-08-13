#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream f1;
    f1.open("thongtin.txt");
    f1<<"Nguyen Thanh Nguyen"<<endl;
    f1<<"18"<<endl;
    f1<<"thanhnguyennguyen496@gmail.com";
    f1.close();
    return 0;

}