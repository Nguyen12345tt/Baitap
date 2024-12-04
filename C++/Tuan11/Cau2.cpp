#include<iostream>
using namespace std;
int main()
{
    int thoigian[]={2,4,6,8,10};
    int vantoc=60;
    cout<<"Thời gian (h)\tquãng đường (km):"<<endl;
    for (int i=0;i<5;i++)
    {
        cout<<thoigian[i]<< "h\t\t"<<thoigian[i]*vantoc <<"km\t\t" <<endl;
    }

    return 0;
}