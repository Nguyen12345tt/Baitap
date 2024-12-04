#include <iostream>
using namespace std;

int main() {
    int Ma_so_nhan_vien;
    double luong = 0, tong_thue_tieu_bang = 0, tong_thue_lien_bang = 0, tong_thue_thu_nhap = 0;

    while (true) {
        cout << "Nhập mã số nhân viên (0 để kết thúc): ";
        cin >> Ma_so_nhan_vien;
        if (Ma_so_nhan_vien == 0) {
            break;
        }

        double tong_luong, thue_tieu_bang, thue_lien_bang, thue_thu_nhap;
        cout << "Nhập tổng lương: ";
        cin >> tong_luong;
        while (tong_luong < 0) {
            cout << "Lỗi: Tổng lương không thể là số âm.\n";
            cout << "Nhập tổng lương: ";
            cin >> tong_luong;
        }

        cout << "Nhập thuế tiểu bang: ";
        cin >> thue_tieu_bang;
        while (thue_tieu_bang < 0 || thue_tieu_bang > tong_luong) {
            cout << "Lỗi: Thuế tiểu bang không hợp lệ.\n";
            cout << "Nhập thuế tiểu bang: ";
            cin >> thue_tieu_bang;
        }

        cout << "Nhập thuế liên bang: ";
        cin >> thue_lien_bang;
        while (thue_lien_bang < 0 || thue_lien_bang > tong_luong) {
            cout << "Lỗi: Thuế liên bang không hợp lệ.\n";
            cout << "Nhập thuế liên bang: ";
            cin >> thue_lien_bang;
        }

        cout << "Nhập thuế thu nhập: ";
        cin >> thue_thu_nhap;
        while (thue_thu_nhap < 0 || thue_thu_nhap > tong_luong) {
            cout << "Lỗi: Thuế thu nhập không hợp lệ.\n";
            cout << "Nhập thuế thu nhập: ";
            cin >> thue_thu_nhap;
        }

        if ((thue_tieu_bang + thue_lien_bang + thue_thu_nhap) > tong_luong) {
            cout << "Lỗi: Tổng thuế vượt quá tổng lương. Vui lòng nhập lại dữ liệu.\n";
            continue;
        }

        double net_pay = tong_luong - (thue_tieu_bang + thue_lien_bang + thue_thu_nhap);
        luong += tong_luong;
        tong_thue_tieu_bang += thue_tieu_bang;
        tong_thue_lien_bang += thue_lien_bang;
        tong_thue_thu_nhap += thue_thu_nhap;

        cout << "Nhân viên " << Ma_so_nhan_vien << " - Tổng lương: " << tong_luong
             << ", Thuế tiểu bang: " << thue_tieu_bang << ", Thuế liên bang: " << thue_lien_bang
             << ", Thuế thu nhập: " << thue_thu_nhap << ", Thanh toán ròng: " << net_pay << "\n";
    }

    cout << "\nBáo cáo tuần:\n";
    cout << "Tổng số tiền lương: " << luong << "\n";
    cout << "Tổng thuế tiểu bang: " << tong_thue_tieu_bang << "\n";
    cout << "Tổng thuế liên bang: " << tong_thue_lien_bang << "\n";
    cout << "Tổng thuế thu nhập: " << tong_thue_thu_nhap << "\n";
    cout << "Tổng thanh toán ròng: " << luong - (tong_thue_tieu_bang + tong_thue_lien_bang + tong_thue_thu_nhap) << "\n";
}
