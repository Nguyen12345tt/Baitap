#include<iostream>
#include<string>
using namespace std;
//Hàm getSales để nhập doanh số và kiểm tra tính hợp lệ
double getSales(string UnitName)
{
    double Sales;
    cout<<"Nhập doanh số bán hàng của "<<UnitName<<":";
    cin>>Sales;
    while(Sales<0)
    {
        cout<<"Doanh số không hợp lệ.Vui lòng nhập lại:";
        cin>>Sales;
    }
    return Sales;        
}
//Hàm findHighest để tìm đơn vị có số doanh thu cao nhất
void findHighest(double Dong_Bac, double Dong_Nam, double Tay_Bac, double Tay_Nam) {
    double highest = Dong_Bac;
    string highestUnit = "Đông Bắc";
    if (Dong_Nam>highest)
    {
        highest=Dong_Nam;
        highestUnit="Đông Nam";
    }
    if (Tay_Bac>highest)
    {
        highest=Tay_Bac;
        highestUnit="Tây Bắc";
    }
    if (Tay_Nam>highest)
    {
        highest=Tay_Nam;
        highestUnit="Tây Nam";
    }

    cout<<"Đơn vị có doanh số lớn nhất :"<< highestUnit << " với doanh số " << highest << " $"<<endl;
}

int main()
{
    double Dong_Bac,Dong_Nam,Tay_Bac,Tay_Nam;
    Dong_Bac=getSales("Đông Bắc");
    Dong_Nam=getSales("Đông Nam");
    Tay_Bac=getSales("Tây Bắc");
    Tay_Nam=getSales("Tây Nam");

    findHighest(Dong_Bac,Dong_Nam,Tay_Bac,Tay_Nam);
    return 0;
}