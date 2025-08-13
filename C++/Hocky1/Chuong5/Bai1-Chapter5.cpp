#include<iostream>
using namespace std;

//Tính giá bán lẻ
double calculateRetail(double gia_ban_buon, double ti_le_phan_tram) {
    return gia_ban_buon + (gia_ban_buon * ti_le_phan_tram / 100);
}
int main()
{
    double gia_ban_buon,ty_le_phan_tram,gia_ban_le;
    //Nhập giá bán buôn
    cout<<"Nhập giá bán buôn của mặt hàng:";
    cin>>gia_ban_buon;
    while(gia_ban_buon<0)
    {
        cout<<"Giá bán buôn không được âm. Vui lòng thử lại.";
    }
    //Nhập tỉ lệ phần trăm
    cout<<"Nhập tỉ lệ phần trăm của mặt hàng:";
    cin>>ty_le_phan_tram;
    while (ty_le_phan_tram<0)
    {
        cout<<"Tỷ lệ phần trăm không được âm. Vui lòng thử lại.";
    }
    //Tính giá bán lẻ
    gia_ban_le=calculateRetail(gia_ban_buon,ty_le_phan_tram);
    //Hiển thị giá bán lẻ
    cout<<"Giá bán lẻ là:"<<gia_ban_le<<endl;
    return 0;
}
