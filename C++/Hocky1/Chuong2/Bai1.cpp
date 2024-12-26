//Trịnh Anh Tuấn
//Mã sinh viên:1871020635
//Lớp: CNTT 18-09

#include<iostream>
using namespace std;
int main() {
    int gallons;
    int dam;
    
    cout << "Nhập số gallon xăng xe có thể chứa: ";
    cin >> gallons;
    
    cout << "Nhập số dặm xe có thể đi được khi đổ đầy xăng: ";
    cin >> dam;
    
    int so_dam_tren_gallon = dam / gallons;
    
    cout << "Số dặm có thể được lái đi trên mỗi gallon xăng: " << so_dam_tren_gallon << " dặm/gallon" << endl;
    
}
