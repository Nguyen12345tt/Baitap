//Trịnh Anh Tuấn
//Mã sinh viên:1871020635
//Lớp: CNTT 18-09

#include <iostream>
using namespace std;
int main() 
{
    int chiec_banh;
    float duong = 1.5f / 48;
    float bo = 1.0f / 48;
    float bot = 2.75f / 48;

    cout << "Nhập số lượng bánh bạn muốn làm: ";
    cin >> chiec_banh;

    float coc_duong = duong * chiec_banh;
    float coc_bo = bo * chiec_banh;
    float coc_bot = bot * chiec_banh;

    cout << "Để làm " << chiec_banh << " chiếc bánh, bạn cần:\n";
    cout << coc_duong << " cốc đường\n";
    cout << coc_bo << " cốc bơ\n";
    cout << coc_bot << " cốc bột\n";

}
