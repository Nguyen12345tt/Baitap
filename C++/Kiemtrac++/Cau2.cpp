#include<iostream>
using namespace std;
int main()
{
    int mucnuocbien=3;
    int sonam=10;
    cout<<"Năm \t mực nước biển tăng (mm)\n";
    for (int nam = 1; nam <= sonam; nam++)
    {
        int muctangsau10nam=mucnuocbien*nam;
        cout<<nam<<"\t"<<muctangsau10nam<<endl;
    }
    
}