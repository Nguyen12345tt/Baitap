/**/
#include<iostream>
#include<string>
using namespace std;

// Hàm nguyên mẫu
double getSales(string);
void findHighest(double, double, double, double);

int main() {
    double DongBac, DongNam, TayBac, TayNam;

    DongBac = getSales("Đông Bắc");
    DongNam = getSales("Đông Nam");
    TayBac = getSales("Tây Bắc");
    TayNam = getSales("Tây Nam");

    findHighest(DongBac, DongNam, TayBac, TayNam);

    return 0;
}

// Định nghĩa hàm getSales
double getSales(string DonVi) {
    double DoanhSo;
    cout << "Nhập vào doanh số của " << DonVi << ": ";
    cin >> DoanhSo;
    while (DoanhSo < 0) {
        cout << "Doanh số phải lớn hơn 0. Hãy nhập lại doanh số: ";
        cin >> DoanhSo;
    }
    return DoanhSo;
}

// Định nghĩa hàm findHighest
void findHighest(double DongBac, double DongNam, double TayBac, double TayNam) {
    string MaxTen = "Đông Bắc";
    double MaxDS = DongBac;

    if (DongNam > MaxDS) {
        MaxTen = "Đông Nam";
        MaxDS = DongNam;
    }
    if (TayBac > MaxDS) {
        MaxTen = "Tây Bắc";
        MaxDS = TayBac;
    }
    if (TayNam > MaxDS) {
        MaxTen = "Tây Nam";
        MaxDS = TayNam;
    }

    cout << "Đơn vị có doanh số cao nhất là: " << MaxTen << " với doanh số: " << MaxDS << endl;
}
