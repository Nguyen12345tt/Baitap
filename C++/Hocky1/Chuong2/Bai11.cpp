//Trịnh Anh Tuấn
//Mã sinh viên:1871020635
//Lớp: CNTT 18-09

#include <iostream>
#include <iomanip> // Thư viện để định dạng số
using namespace std;
int main() {
    float vay, bao_hiem, xang, dau, lop, bao_duong;

    cout << "Nhập chi phí hàng tháng cho khoản vay: ";
    cin >> vay;
    cout << "Nhập chi phí hàng tháng cho bảo hiểm: ";
    cin >> bao_hiem;
    cout << "Nhập chi phí hàng tháng cho xăng: ";
    cin >> xang;
    cout << "Nhập chi phí hàng tháng cho dầu: ";
    cin >> dau;
    cout << "Nhập chi phí hàng tháng cho lốp: ";
    cin >> lop;
    cout << "Nhập chi phí hàng tháng cho bảo dưỡng: ";
    cin >> bao_duong;

    float tong_chi_phi_hang_thang = vay + bao_hiem + xang + dau + lop + bao_duong;
    float tong_chi_phi_hang_nam = tong_chi_phi_hang_thang * 12;

    cout << fixed << setprecision(2);
    cout << "Tổng chi phí hàng tháng: $" << tong_chi_phi_hang_thang << endl;
    cout << "Tổng chi phí hàng năm: $" << tong_chi_phi_hang_nam << endl;

    return 0;
}
