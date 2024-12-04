#include <iostream>
#include <string>

struct DuAn {
    std::string TenDuAn;
    double TienDauTu;
};

int main() {
    int n;
    std::cout << "Nhập số lượng dự án: ";
    std::cin >> n;

    // Khai báo mảng động để lưu các dự án
    DuAn* danhSachDuAn = new DuAn[n];

    // Nhập thông tin cho từng dự án
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhập thông tin cho dự án " << i + 1 << ":\n";
        std::cin.ignore(); // Loại bỏ ký tự newline còn lại từ lần nhập trước
        std::getline(std::cin, danhSachDuAn[i].TenDuAn);
        std::cout << "Tiền đầu tư: ";
        std::cin >> danhSachDuAn[i].TienDauTu;
    }

    // Tính tổng tiền đầu tư
    double tongTienDauTu = 0;
    for (int i = 0; i < n; ++i) {
        tongTienDauTu += danhSachDuAn[i].TienDauTu;
    }

    // Tính số tiền đầu tư trung bình
    double tienDauTuTrungBinh = tongTienDauTu / n;

    // Hiển thị số tiền đầu tư trung bình
    std::cout << "\nSố tiền đầu tư trung bình của tất cả dự án: " << tienDauTuTrungBinh << " VND\n";

    // Hiển thị danh sách các dự án
    std::cout << "\nDanh sách các dự án đã nhập:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Dự án " << i + 1 << ": " << danhSachDuAn[i].TenDuAn
                  << ", Tiền đầu tư: " << danhSachDuAn[i].TienDauTu << " VND\n";
    }

    // Giải phóng bộ nhớ đã cấp phát cho mảng động
    delete[] danhSachDuAn;

    return 0;
}
