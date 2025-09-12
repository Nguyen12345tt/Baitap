/*VD4:Đọc và in ra màn hình các số trong tệp TapSo.txt*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int So;
    ifstream f1;
    f1.open("TapSo.txt");
    //while (f1>>So)
    //{
    //    cout<<So<<" ";
    //}
    while (!f1.eof())
    {
        f1>>So;
        cout<<So<<" ";
    }
        

    f1.close();

    return 0;
}