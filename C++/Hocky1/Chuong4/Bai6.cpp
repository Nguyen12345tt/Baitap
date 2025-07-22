#include<iostream>
using namespace std;
int main()
{
    float toc_do;
    int thoi_gian;
    do
    {
        cout<<"Xe da di duoc bao nhieu km tren gio?";
        cin>>toc_do;
        if (toc_do<=0)
        {
            cout<<"Hay nhap lai toc do"<<endl;
        }
    } while (toc_do<=0);

    do
    {
        cout<<"Xe da di duoc bao nhieu gio?";
        cin>>thoi_gian;
        if (thoi_gian<=1)
        {
            cout<<"Hay nhap lai thoi gian"<<endl;
        }
    } while (thoi_gian<=1);
    cout<<"Khoang cach theo gio ma xe da di:"<<endl;
    cout<<"----------------------------------"<<endl;
    for (int i=1;i<=thoi_gian;i++)
    {
        int quang_duong=toc_do*i;
        cout<<i<<"\t"<<quang_duong<<endl;
    }    
    
}