#include <iostream>
using namespace std;

int main() {
    int sonam;
    do
    {
        cout << "Nhập số năm: ";
        cin >> sonam;
    }
    while (sonam<1);
    
    int sothang = sonam * 12;
    float tong_luong_mua;

    for (int nam = 1; nam <= sonam; ++nam) {
        for (int month = 1; month <= 12; ++month) {
            float luong_mua_theo_thang;
            do
            {
                cout << "Nhập lượng mưa cho tháng " << month << ", năm " << nam << ": ";
                cin >> luong_mua_theo_thang;
            }
            while(luong_mua_theo_thang<1);
            tong_luong_mua += luong_mua_theo_thang;
        }
    }

    float luong_mua_trung_binh = tong_luong_mua / sothang;
    cout << "Số tháng: " << sothang << endl;
    cout << "Tổng lượng mưa: " << tong_luong_mua << " đơn vị" << endl;
    cout << "Lượng mưa trung bình mỗi tháng: " << luong_mua_trung_binh << " đơn vị" << endl;

    return 0;
}
