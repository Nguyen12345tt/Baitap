//Nguyễn Thành Nguyên
//Mã sinh viên:
//Lớp: CNTT 18-09

/*
B1:Nhập vào tháng,năm:
B2:Nếu tháng=1,3,5,7,8,10,12
        Số ngày là 31
    Nếu tháng=4,6,9,11
        Số ngày là 30
B3: Nếu tháng = 2 thì
    Nếu năm % 100 == 0 thì:
        Nếu năm % 400 == 0 thì:
        Số ngày là 29
        Ngược lại là 28
    Ngược lại(năm % 100 =/0)
        Nếu năm % 4 =0
        Số ngày là 29
        Ngược lại là 28
*/

#include<iostream>
using namespace std;
int main()
{
    int thang,nam,songay;
    cout<<"Nhap vao 1 thang(1-12):";
    cin>>thang;
    cout<<"Nhap vao 1 nam:";
    cin>>nam;
    if (thang==1 or thang==3 or thang==5 or thang==7 or thang==8 or thang==10 or thang==12)
    {
        cout<<"So ngay = 30";
    }
    else if (thang==4 or thang==6 or thang==9 or thang==11)
    {
        cout<<"So ngay = 31";
    }
    else if(thang==2)
    {
        if(nam % 100 == 0)
            if(nam % 400 ==0)
                {
                    cout<<"So ngay = 29";
                }
            else
                {
                    cout<<"So ngay = 28";
                }
        else
            if(nam % 4 ==0)
                {
                    cout<<"So ngay = 29";
                }
            else
                {
                    cout<<"So ngay = 28";
                }
    }
    return 0;
}