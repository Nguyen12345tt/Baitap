#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream inputFile("Random.txt");
    if(!inputFile)
    {
        cout<<"Không thể tính được nếu không có file random.txt"<<endl;
    }
    int dem=0;
    int tong=0;
    int so;
    while (inputFile >> so)
    {
        dem++;
        tong +=so;
    }
    inputFile.close();
    if (dem==0)
    {
        cout<<"Tệp không chứa số nào"<<endl;
    }
    else
    {
        double gia_tri_trung_binh=tong/dem;
        cout<<"Số lượng các số trong tệp:"<<dem<<endl;
        cout<<"Tổng tất cả các số trong tệp:"<<tong<<endl;
        cout<<"Giá trị trung bình của tất cả các số trong tệp:"<<gia_tri_trung_binh<<endl;
    }

}