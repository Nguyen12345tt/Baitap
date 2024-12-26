//Trịnh Anh Tuấn
//Mã sinh viên:1871020635
//Lớp: CNTT 18-09

#include <iostream>
using namespace std;
int main() {
    // Mức nước biển dâng lên mỗi năm (mm)
    int NuocBienDangLen1nam = 15; // 1.5 mm chuyển đổi sang đơn vị 0.1 mm để tránh dùng số thập phân

    // Tính mức nước biển dâng lên sau 5, 7 và 10 năm
    int NuocBienDangLensau5nam = NuocBienDangLen1nam * 5;
    int NuocBienDangLensau7nam = NuocBienDangLen1nam * 7;
    int NuocBienDangLensau10nam = NuocBienDangLen1nam * 10;

    // Hiển thị kết quả
    cout << "Mức nước biển sẽ tăng lên sau 5 năm: " << NuocBienDangLensau5nam / 10.0 << " mm" << endl;
    cout << "Mức nước biển sẽ tăng lên sau 7 năm: " << NuocBienDangLensau7nam / 10.0 << " mm" << endl;
    cout << "Mức nước biển sẽ tăng lên sau 10 năm: " << NuocBienDangLensau10nam / 10.0 << " mm" << endl;

}
