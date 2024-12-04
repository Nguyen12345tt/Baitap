//Trịnh Anh Tuấn
//Mã sinh viên:1871020635
//Lớp: CNTT 18-09

#include <iostream>
using namespace std;
int main()
{
    int gallons = 20;
    float so_dam_tren_thanh_pho = 23.5f;
    float so_dam_tren_duong_cao_toc = 28.9f;

    float Quang_duong_o_thanh_pho = gallons * so_dam_tren_thanh_pho;
    float Quang_duong_o_duong_cao_toc = gallons * so_dam_tren_duong_cao_toc;

    cout << "Quãng đường đi được trong thành phố: " << Quang_duong_o_thanh_pho << " dặm" << endl;
    cout << "Quãng đường đi được trên đường cao tốc: " << Quang_duong_o_duong_cao_toc << " dặm" << endl;

}
