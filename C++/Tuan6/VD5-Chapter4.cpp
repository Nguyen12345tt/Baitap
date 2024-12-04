/*VD5 */
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f1;
    int So,Tong=0,Dem=0;
    float TrungBinh;
    f1.open("TapSo.txt");
    while(!f1.eof())
    {
        f1>>So;
        Tong+=So; //Tương đương:Tong=Tong +So
        Dem++;
    }
    TrungBinh=Tong/Dem;
    f1.close();
    cout<<"Tong la:"<<Tong<<endl;
    cout<<"Trung binh cac so: "<<TrungBinh;


    return 0;
}