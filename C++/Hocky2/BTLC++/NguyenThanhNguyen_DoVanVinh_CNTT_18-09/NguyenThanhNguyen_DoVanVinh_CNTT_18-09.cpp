#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Cấu trúc phong
struct Phong {
    int masoPhong; // Ma so phong
    string loaiPhong; //Loai phong 
    double giaPhong; //Gia cua phong
    double dientich; //Dien tich cua phong
    int soGiuong; // So giuong trong phong
    string loaiGiuong; //Giuong don/doi
    bool daDat; //Kiem tra xem phong da duoc dat hay chua
    Phong* prev;
    Phong* next;
};

// Con tro dau va cuoi danh sach
Phong* dau = nullptr;
Phong* cuoi = nullptr;

// Kiem tra phong
Phong* timPhong(int masoPhong) {
    Phong* temp = dau;
    while (temp) {
        if (temp->masoPhong == masoPhong) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

//Them phong moi
void themPhong() {
    int masoPhong,soGiuong;
    string loaiPhong, loaiGiuong;
    double giaPhong,dientich;
    cout << "Nhap ma so phong: ";
    cin >> masoPhong;
    cin.ignore(); // Xoa ky tu xuong dong sau khi nhap masoPhong

    if (timPhong(masoPhong)) {
        cout << "phong " << masoPhong << " đã tồn tại!" << endl;
        return;
    }

    cout << "Nhap loai phong: ";
    getline(cin, loaiPhong); 

    cout << "Nhap gia phong: ";
    cin >> giaPhong;

    cout << "Nhap dien tich phong( m² ): ";
    cin >> dientich;

    cout << "Nhap so giuong: ";
    cin >> soGiuong;

    cout << "Nhap loai giuong (doi/don): ";
    cin >> loaiGiuong;

    Phong* moi = new Phong{masoPhong, loaiPhong, giaPhong, dientich, soGiuong, loaiGiuong, false, nullptr, nullptr};
    if (!dau) {
        dau = cuoi = moi;
    } else {
        cuoi->next = moi;
        moi->prev = cuoi;
        cuoi = moi;
    }
    cout << "Them phong co ma so: " << masoPhong << " thanh cong!" << endl;
}

// Xoa phong
void xoaPhong(int soPhong) {
    Phong* phong = timPhong(soPhong);
    if (!phong) {
        cout << "Khong tim thay phong co ma so " << soPhong << " de xoa!" << endl;
        return;
    }
    if (phong->prev) {
        phong->prev->next = phong->next;
    } else {
        dau = phong->next;
    }
    if (phong->next) {
        phong->next->prev = phong->prev;
    } else {
        cuoi = phong->prev;
    }
    delete phong;
    cout << "Xoa phong co ma so " << soPhong << " thanh cong!" << endl;
}

// Dat phong
void datPhong(int masoPhong) {
    Phong* phong = timPhong(masoPhong);
    if (phong) {
        if (!phong->daDat) {
            phong->daDat = true;
            cout << "Phong co ma so " << masoPhong << " da duoc dat thanh cong!" << endl;
        } else {
            cout << "Phong co ma so " << masoPhong << " da duoc dat truoc do!" << endl;
        }
    } else {
        cout << "Khong tim thay phong co ma so " << masoPhong << "!" << endl;
    }
}

// Chinh sua thong tin phong
void chinhSuaPhong(int soPhong) {
    Phong* phong = timPhong(soPhong);
    if (phong) {
        cin.ignore(); // Xoa bo dem truoc khi nhap chuoi
        cout << "Nhap loai phong moi: ";
        getline(cin, phong->loaiPhong);
        cout << "Nhap gia phong moi: ";
        cin >> phong->giaPhong;
        cout << "Cap nhat thong tin phong co ma so " << soPhong << " thanh cong!" << endl;
    } else {
        cout << "Khong tim thay phong co ma so " << soPhong << "!" << endl;
    }
}

// Luu danh sach phong vao file
void luuDanhSachPhong() {
    ofstream file("danh_sach_phong.txt");
    if (!file) {
        cout << "Loi khi mo file de ghi!" << endl;
        return;
    }
    Phong* temp = dau;
    while (temp) {
        file << temp->masoPhong << " " << temp->loaiPhong << " " << temp->giaPhong << " " << temp->dientich << " " << temp->soGiuong << " " << temp->loaiGiuong << " " << temp->daDat << endl; // Thêm khoảng trắng giữa soGiuong và loaiGiuong
        temp = temp->next;
    }
    file.close();
    cout << "Luu danh sach phong thanh cong!" << endl;
}

// Hien thi danh sach phong
void hienThiPhong() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }
    Phong* temp = dau;
    while (temp) {
        cout << "Ma so phong: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
             << ", Gia: " << temp->giaPhong << " VND , Dien tich: " << temp->dientich 
             << "m², Trang thai: " << (temp->daDat ? "Da dat" : "Con trong") << endl;
        temp = temp->next;
    }
}

// Đọc danh sach phong tu file
void docDanhSachPhong() {
    ifstream file("danh_sach_phong.txt");
    if (!file) {
        cout << "Khong tim thay file co danh sach phong!" << endl;
        return;
    }
    int soPhong,soGiuong;
    string loaiPhong, loaiGiuong;
    double giaPhong,dientich;
    bool daDat;
    while (file >> soPhong >> loaiPhong >> giaPhong >> dientich >> soGiuong >> loaiGiuong >> daDat) {
        Phong* moi = new Phong{soPhong, loaiPhong, giaPhong, dientich, daDat};
        if (!dau) {
            dau = cuoi = moi;
        } else {
            cuoi->next = moi;
            moi->prev = cuoi;
            cuoi = moi;
        }
    }
    file.close();
    cout << "Doc danh sach phong tu file thanh cong!" << endl;
    hienThiPhong();
}

// Tim kiem phong theo loai
void timPhongTheoLoai(string loai) {
    Phong* temp = dau;
    bool found = false;
    while (temp) {
        if (temp->loaiPhong == loai) {
            cout << "Ma so phong: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", Gia: " << temp->giaPhong << " VND , Trang thai: "
                 << (temp->daDat ? "Da dat" : "Con trong") << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Khong tim thay phong thuoc loai " << loai << "!" << endl;
    }
}

// Hien thi phong theo so giuong va loai giuong
void hienThiPhongTheoSoGiuongVaLoaiGiuong(int soGiuong, string loaiGiuong) {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    bool timThay = false;
    Phong* temp = dau;

    cout << "Danh sach phong co " << soGiuong << " giuong " << loaiGiuong << ":\n";
    while (temp) {
        if (temp->soGiuong == soGiuong && (temp->loaiGiuong == loaiGiuong || (loaiGiuong == "đơn" && temp->loaiGiuong == "Đơn") || (loaiGiuong == "đôi" && temp->loaiGiuong == "Đôi"))) {
            cout << "Ma so: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", Gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich << " m²,"
                 << " Trang thai: " << (temp->daDat ? "Da dat" : "Con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Không có phòng nào thỏa mãn điều kiện!" << endl;
    }
}

// Huy dat phong
void huyDatPhong(int soPhong) {
    Phong* phong = timPhong(soPhong);
    if (phong) {
        if (phong->daDat) {
            phong->daDat = false;
            cout << "Huy dat phong " << soPhong << " thanh cong!" << endl;
        } else {
            cout << "Phong " << soPhong << " chua duoc dat nen khong the huy!" << endl;
        }
    } else {
        cout << "Khong tim thay phong " << soPhong << "!" << endl;
    }
}

// Tim phong co gia cao nhat
void timPhongGiaCaoNhat() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }
    Phong* temp = dau;
    Phong* phongGiaCaoNhat = dau;
    
    while (temp) {
        if (temp->giaPhong > phongGiaCaoNhat->giaPhong) {
            phongGiaCaoNhat = temp;
        }
        temp = temp->next;
    }

    cout << "Phong co gia cao nhat: " << endl;
    cout << "So phong: " << phongGiaCaoNhat->masoPhong << endl;
    cout << "Loai: " << phongGiaCaoNhat->loaiPhong << endl;
    cout << "Gia: " << phongGiaCaoNhat->giaPhong << "VND" << endl;
    cout << "Dien tich: " << phongGiaCaoNhat-> dientich << " m²" << endl;
    cout << "Trang thai: " << (phongGiaCaoNhat->daDat ? "Da dat" : "Con trong") << endl;
}


// Thong ke so luong phong con trong và da dat
void thongKePhong() {
    int soPhongDat = 0, soPhongTrong = 0;
    Phong* temp = dau;
    while (temp) {
        if (temp->daDat) {
            soPhongDat++;
        } else {
            soPhongTrong++;
        }
        temp = temp->next;
    }
    cout << "So phong da dat: " << soPhongDat << "\n";
    cout << "So phong con trong: " << soPhongTrong << "\n";
}

// Hien thi danh sach phong da dat
void hienThiPhongDaDat() {
    Phong* temp = dau;
    bool found = false;
    while (temp) {
        if (temp->daDat) {
            cout << "Ma so phong: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", gia: " << temp->giaPhong << " VND" "\n";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Khong co phong nao da duoc dat!" << endl;
    }
}

// Hien thi danh sach phong con trong
void hienThiPhongConTrong() {
    Phong* temp = dau;
    bool found = false;
    while (temp) {
        if (!temp->daDat) {
            cout << "Ma so phong: " << temp->masoPhong
                 << ", Loai: " << temp->loaiPhong
                 << ", Gia: " << temp->giaPhong << "VND"
                 << ", Dien tich: " << temp->dientich << " m²"
                 << "\n";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Khong co phong nao con trong!" << endl;
    }
}

// Tinh tong doanh thu tu cac phong da dat
void tinhTongDoanhThu() {
    double tongDoanhThu = 0;
    Phong* temp = dau;
    while (temp) {
        if (temp->daDat) {
            tongDoanhThu += temp->giaPhong;
        }
        temp = temp->next;
    }
    cout << "Tong doanh thu tu cac phong da dat: " << tongDoanhThu << " VND\n";
}

// Sap xep phong theo gia
void sapXepPhongTheoGiaTangDan() {
    if (!dau || !dau->next) {
        cout << "Danh sach phong trong hoac chi co mot phong, khong can sap xep!" << endl;
        return;
    }

    bool swapped;
    Phong* temp;
    Phong* last = nullptr;

    do {
        swapped = false;
        temp = dau;

        while (temp->next != last) {
            if (temp->giaPhong > temp->next->giaPhong) {
                // Hoan doi du lieu hai phong
                swap(temp->masoPhong, temp->next->masoPhong);
                swap(temp->loaiPhong, temp->next->loaiPhong);
                swap(temp->giaPhong, temp->next->giaPhong);
                swap(temp->daDat, temp->next->daDat);
                swapped = true;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);

    cout << "Danh sach phong da duoc sap xep theo gia tang dan!" << endl;
}

// Dat nhieu phong cung luc
void datNhieuPhong() {
    int soLuong;
    cout << "Nhap so luong phong can dat: ";
    cin >> soLuong;

    if (soLuong <= 0) {
        cout << "So luong phong khong hop le!" << endl;
        return;
    }

    for (int i = 0; i < soLuong; i++) {
        int maSoPhong;
        cout << "Nhap ma so phong thu " << (i + 1) << ": ";
        cin >> maSoPhong;

        Phong* phong = timPhong(maSoPhong);
        if (phong && !phong->daDat) {
            phong->daDat = true;
            cout << "Da dat phong " << maSoPhong << " thanh cong!" << endl;
        } else {
            cout << "Phong " << maSoPhong << " khong ton tai hoac da duoc dat!" << endl;
        }
    }
}

// Tim phong theo ma so
void timPhongTheoMaSo(int maSoPhong) {
    Phong* phong = timPhong(maSoPhong);
    if (phong) {
        cout << "Thong tin phong:\n";
        cout << "Ma so: " << phong->masoPhong << "\n";
        cout << "Loai phong: " << phong->loaiPhong << "\n";
        cout << "Gia phong: " << phong->giaPhong << "\n";
        cout << "Dien tich : " << phong->dientich << "m²\n";
        cout << "Trang thai: " << (phong->daDat ? "Da dat" : "Con trong") << "\n";
    } else {
        cout << "Khong tim thay phong co ma so " << maSoPhong << "!\n";
    }
}

//Dem xem co bao nhieu phong
int demSoLuongPhong() {
    int count = 0;
    Phong* temp = dau;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

//Xoa toan bo danh sach phong
void xoaToanBoDanhSachPhong() {
    if (!dau)
    {
        cout<<"Danh sach phong rong, khong co gi de xoa!"<<endl;
        return;
    }
    while (dau) {
        Phong* temp = dau;
        dau = dau->next;
        delete temp;
    }
    cuoi = nullptr;
    cout << "Toan bo danh sach phong da duoc xoa!" << endl;
}

// Sua gia phong
void suaGiaPhong(int maSoPhong, double giaMoi) {
    Phong* phong = timPhong(maSoPhong);
    if (giaMoi <= 0) {
        cout << "Gia moi khong hop le!" << endl;
        return;
    }
    phong->giaPhong = giaMoi;

    if (phong) {
        phong->giaPhong = giaMoi;
        cout << "Cap nhat gia phong thanh cong!" << endl;
    } else {
        cout << "Khong tim thay phong!" << endl;
    }
}

//Tim phong theo gia
void timPhongTheoGia(double giaMin, double giaMax) {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }
    bool timThay = false;
    Phong* temp = dau;
    while (temp) {
        if (temp->giaPhong >= giaMin && temp->giaPhong <= giaMax) {
            cout << "Ma so: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", Gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich 
                 << "m², Trang thai: " << (temp->daDat ? "Da dat" : "Con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }
    if (!timThay) {
        cout << "Khong co phong nao trong khoang gia nay." << endl;
    }
}

// Tim phong theo trang thai
void timPhongTheoTrangThai(string trangThai) {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }
    bool timThay = false;
    bool trangThaiBool = (trangThai == "Da dat");
    Phong* temp = dau;
    while (temp) {
        if (temp->daDat == trangThaiBool) {
            cout << "Ma so: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", Gia: " << temp->giaPhong << ", Dien tich: " << temp->dientich 
                 << "m², Trang thai: " << (temp->daDat ? "Da dat" : "Con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }
    if (!timThay) {
        cout << "Khong co phong nao theo trang thai nay." << endl;
    }
}

// Hien thi danh sach phong duoi dang bang
void hienThiPhongDangBang() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    // Tieu đe bang
    cout << "---------------------------------------------------------" << endl;
    cout << "| Ma so | Loai phong      | Gia       | Dien tich (m²) | Trang thai |" << endl;
    cout << "---------------------------------------------------------" << endl;

    Phong* temp = dau;
    while (temp) {
        cout << "| " << temp->masoPhong;
        cout << " | " << temp->loaiPhong;
        cout << " | " << temp->giaPhong << "VND";
        cout << " | " << temp->dientich;
        cout << " | " << (temp->daDat ? "Da dat" : "Con trong") << " |" << endl;
        temp = temp->next;
    }
    cout << "---------------------------------------------------------" << endl;
}

// Tim phong co dien tich lon nhat
void timPhongDienTichLonNhat() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    Phong* temp = dau;
    Phong* phongDienTichLonNhat = dau;

    while (temp) {
        if (temp->dientich > phongDienTichLonNhat->dientich) {
            phongDienTichLonNhat = temp;
        }
        temp = temp->next;
    }

    cout << "Phong co dien tich lon nhat:\n";
    cout << "Ma so: " << phongDienTichLonNhat->masoPhong << "\n";
    cout << "Loai phong: " << phongDienTichLonNhat->loaiPhong << "\n";
    cout << "Gia phong: " << phongDienTichLonNhat->giaPhong << " VND\n";
    cout << "Dien tich: " << phongDienTichLonNhat->dientich << " m²\n";
    cout << "Trang thai: " << (phongDienTichLonNhat->daDat ? "Da dat" : "Con trong") << "\n";
}

//Thong ke so giuong theo loai phong
void demSoGiuongTheoLoaiPhong() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    Phong* temp = dau;
    while (temp) {
        string loaiPhongHienTai = temp->loaiPhong;
        int tongSoGiuong = 0;
        Phong* temp2 = dau;

        // Đem so giuong cho loai phong hien tai
        while (temp2) {
            if (temp2->loaiPhong == loaiPhongHienTai) {
                tongSoGiuong += temp2->soGiuong;
            }
            temp2 = temp2->next;
        }

        // Kiem tra xem loai phong duoc in ra chua
        bool daIn = false;
        Phong* temp3 = dau;
        while (temp3 != temp) {
            if (temp3->loaiPhong == loaiPhongHienTai) {
                daIn = true;
                break;
            }
            temp3 = temp3->next;
        }

        // In ket qua neu loai phong chua duoc in
        if (!daIn) {
            cout << "Loai phong: " << loaiPhongHienTai << ", So giuong: " << tongSoGiuong << endl;
        }

        temp = temp->next;
    }
}

// Tinh tong so giuong trong tat ca cac phong
void tinhTongSoGiuong() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    int tongSoGiuong = 0;
    Phong* temp = dau;

    while (temp) {
        tongSoGiuong += temp->soGiuong;
        temp = temp->next;
    }

    cout << "Tong so giuong trong tat ca cac phong: " << tongSoGiuong << endl;
}

void hienThiPhongGiuongDoiConTrong() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    bool timThay = false;
    Phong* temp = dau;

    cout << "Cac phong co giuong doi con trong:\n";
    while (temp) {
        if (!temp->daDat && temp->loaiGiuong == "Doi"|| temp->loaiGiuong == "doi") {
            cout << "Ma so: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich
                 << " m², So giuong: " << temp->soGiuong << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Khong co phong giuong doi nao con trong!" << endl;
    }
}

// Tinh tong so phong co giuong doi
void tinhTongSoPhongGiuongDoi() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    int tongSoPhongGiuongDoi = 0;
    Phong* temp = dau;

    while (temp) {
        if (temp->loaiGiuong == "Doi"|| temp->loaiGiuong == "doi") {
            tongSoPhongGiuongDoi++;
        }
        temp = temp->next;
    }

    cout << "Tong so phong co giuong doi: " << tongSoPhongGiuongDoi << endl;
}

// Hien thi danh sach phong co giuong doi
void hienThiPhongGiuongDoi() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    bool timThay = false;
    Phong* temp = dau;

    cout << "Danh sach phong co giuong doi:\n";
    while (temp) {
        if (temp->loaiGiuong == "Doi" || temp->loaiGiuong == "doi") {
            cout << "ma so: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich
                 << " m², so giuong: " << temp->soGiuong << ", Trang thai: " << (temp->daDat ? "Da dat" : "con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Khong co phong giuong doi nao!" << endl;
    }
}

// Sap xep phong theo loai phong (tu A den Z)
void sapXepPhongTheoLoaiPhong() {
    if (!dau || !dau->next) {
        cout << "Danh sach phong trong hoặc chi co mot phong, khong can sap xep!" << endl;
        return;
    }

    bool swapped;
    Phong* temp;
    Phong* last = nullptr;

    do {
        swapped = false;
        temp = dau;

        while (temp->next != last) {
            if (temp->loaiPhong > temp->next->loaiPhong) {
                // Hoán đổi dữ liệu hai phong
                swap(temp->masoPhong, temp->next->masoPhong);
                swap(temp->loaiPhong, temp->next->loaiPhong);
                swap(temp->giaPhong, temp->next->giaPhong);
                swap(temp->dientich, temp->next->dientich);
                swap(temp->soGiuong, temp->next->soGiuong);
                swap(temp->loaiGiuong, temp->next->loaiGiuong);
                swap(temp->daDat, temp->next->daDat);
                swapped = true;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);

    cout << "Danh sach phong da duoc sap xep theo loai phong (tu A den Z)!" << endl;
}

// Hien thi cac phong co loai phong cu the
void hienThiPhongTheoLoaiPhong(string loaiPhong) {
    bool timThay = false;
    Phong* temp = dau;

    cout << "Danh sach phong loai " << loaiPhong << ":\n";
    while (temp) {
        if (temp->loaiPhong == loaiPhong) {
            cout << "Ma so: " << temp->masoPhong << ", gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich
                 << " m², so giuong: " << temp->soGiuong << ", loai giuong: " << temp->loaiGiuong
                 << ", Trang thai: " << (temp->daDat ? "Da dat" : "con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Khong co phong loai " << loaiPhong << "!" << endl;
    }
}

//Hien thi phong theo so giuong
void hienthiPhongTheoSoGiuong(int soGiuongCanTim) {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    bool timThay = false;
    Phong* temp = dau;

    cout << "Cac phong co " << soGiuongCanTim << " giuong:\n";
    while (temp) {
        if (temp->soGiuong == soGiuongCanTim) {
            cout << "Ma so: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich
                 << " m², loai giuong: " << temp->loaiGiuong
                 << ", Trang thai: " << (temp->daDat ? "Da dat" : "con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Khong co phong nao co " << soGiuongCanTim << " giuong!" << endl;
    }
}

//Hien thi phong theo loai giuong (Don/doi)
void hienthiPhongTheoLoaiGiuong(string loaiGiuongCanTim) {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    bool timThay = false;
    Phong* temp = dau;

    cout << "Cac phong co giuong loai " << loaiGiuongCanTim << ":\n";
    while (temp) {
        if (temp->loaiGiuong == loaiGiuongCanTim) {
            cout << "Ma so: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich
                 << " m², so giuong: " << temp->soGiuong
                 << ", Trang thai: " << (temp->daDat ? "Da dat" : "con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Khong co phong nao co giuong loai " << loaiGiuongCanTim << "!" << endl;
    }
}

//Sap xep phong theo dien tich tang dan
void sapXepPhongTheoDienTichTangDan() {
    if (!dau || !dau->next) {
        cout << "Danh sach phong trong hoặc chi co mot phong, khong can sap xep!" << endl;
        return;
    }

    bool swapped;
    Phong* temp;
    Phong* last = nullptr;

    do {
        swapped = false;
        temp = dau;

        while (temp->next != last) {
            if (temp->dientich > temp->next->dientich) {
                // Hoan doi du lieu hai phong
                swap(temp->masoPhong, temp->next->masoPhong);
                swap(temp->loaiPhong, temp->next->loaiPhong);
                swap(temp->giaPhong, temp->next->giaPhong);
                swap(temp->dientich, temp->next->dientich);
                swap(temp->soGiuong, temp->next->soGiuong);
                swap(temp->loaiGiuong, temp->next->loaiGiuong);
                swap(temp->daDat, temp->next->daDat);
                swapped = true;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);

    cout << "Danh sach phong da duoc sap xep theo dien tich tang dan!" << endl;
}

//Thong ke phong theo loai giuong (Don/doi)
void thongKePhongTheoLoaiGiuong() {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    int soPhongDon = 0, soPhongDoi = 0;
    Phong* temp = dau;

    while (temp) {
        if (temp->loaiGiuong == "Don" || temp->loaiGiuong == "don") {
            soPhongDon++;
        } else if (temp->loaiGiuong == "Doi" || temp->loaiGiuong == "doi") {
            soPhongDoi++;
        }
        temp = temp->next;
    }

    cout << "So phong giuong don: " << soPhongDon << endl;
    cout << "So phong giuong doi: " << soPhongDoi << endl;
}

//Tim phong theo loai giuong (Don/doi)
void timPhongTheoLoaiGiuong(string loaiGiuong) {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    bool timThay = false;
    Phong* temp = dau;

    cout << "Danh sach phong giuong " << loaiGiuong << ":\n";
    while (temp) {
        if (temp->loaiGiuong == loaiGiuong) {
            cout << "ma so: " << temp->masoPhong << ", loai: " << temp->loaiPhong
                 << ", gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich
                 << " m², so giuong: " << temp->soGiuong
                 << ", Trang thai: " << (temp->daDat ? "Da dat" : "Con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Khong co phong giuong " << loaiGiuong << "!" << endl;
    }
}

//Cap nhat so giuong của phong
void suaSoGiuongPhong(int maSoPhong, int soGiuongMoi) {
    Phong* phong = timPhong(maSoPhong);
    if (!phong) {
        cout << "Khong tim thay phong co ma so " << maSoPhong << "!" << endl;
        return;
    }

    if (soGiuongMoi <= 0) {
        cout << "So giuong moi khong hop le!" << endl;
        return;
    }

    phong->soGiuong = soGiuongMoi;
    cout << "So giuong phong " << maSoPhong << " da duoc cap nhat thanh cong!" << endl;
}

void hienThiPhongTheoGiaNhoHonHoacBang(double giaMax) {
    if (!dau) {
        cout << "Danh sach phong trong!" << endl;
        return;
    }

    bool timThay = false;
    Phong* temp = dau;

    cout << "Danh sach phong co gia nho hon hoac bang " << giaMax << " VND:\n";
    while (temp) {
        if (temp->giaPhong <= giaMax) {
            cout << "Ma so: " << temp->masoPhong << ", Loai: " << temp->loaiPhong
                 << ", gia: " << temp->giaPhong << " VND, Dien tich: " << temp->dientich
                 << " m², so giuong: " << temp->soGiuong
                 << ", Trang thai: " << (temp->daDat ? "Da dat" : "Con trong") << endl;
            timThay = true;
        }
        temp = temp->next;
    }

    if (!timThay) {
        cout << "Khong co phong nao co gia nho hon hoac bang " << giaMax << " VND!" << endl;
    }
}

// Hien thi menu
void menu() {
    int chon, soPhong, maSoPhong;
    string loaiPhong, trangThai;
    double gia, giaMin, giaMax;
    while (true) {
        cout << "==== MENU QUAN LY PHONG =====\n";
        cout << "1. Them phong moi\n";
        cout << "2. Kiem tra phong\n";
        cout << "3. Hien thi danh sach phong\n";
        cout << "4. Dat phong\n";
        cout << "5. Chinh sua thong tin phong\n";
        cout << "6. Xoa phong\n";
        cout << "7. Luu danh sach phong vao file\n";
        cout << "8. Doc danh sach phong tu file\n";
        cout << "9. Tim kiem phong theo loai\n";
        cout << "10. Hien thi phong co so giuong va loai giuong cu the\n";
        cout << "11. Huy dat phong\n";
        cout << "12. Tim phong co gia cao nhat\n";
        cout << "13. Thong ke so luong phong\n";
        cout << "14. Hien thi danh sach phong da dat\n";
        cout << "15. Hien thi danh sach phong con trong\n";
        cout << "16. Tinh tong doanh thu tu cac phong da dat\n";
        cout << "17. Sap xep phong theo gia (tang dan)\n";
        cout << "18. Dat nhieu phong cung luc\n";
        cout << "19. Xoa toan bo danh sach phong\n";
        cout << "20. Tim phong theo ma so phong\n";
        cout << "21. Hien thi tong so luong phong\n";
        cout << "22. Sua gia phong (neu co)\n";
        cout << "23. Tim kiem phong theo khoang gia (Tu X den Y)\n";
        cout << "24. Tim kiem phong theo trang thai (Da dat/Con trong)\n";
        cout << "25. Hien thi danh sach phong duoi dang bang\n";
        cout << "26. Tim phong co dien tich lon nhat\n";
        cout << "27. Thong ke so luong giuong theo loai phong\n";
        cout << "28. Tinh tong so giuong trong tat ca cac phong\n";
        cout << "29. Hien thi so phong co giuong doi con trong\n";
        cout << "30. Tinh tong so phong co giuong doi\n";
        cout << "31. Hien thi danh sach phong co giuong doi\n";
        cout << "32. Sap xep phong theo loai phong (A-Z)\n";
        cout << "33. Hien thi phong theo loai phong\n";
        cout << "34. Sap xep phong theo dien tich (tang dan)\n";
        cout << "35. Hien thi phong theo so giuong\n";
        cout << "36. Hien thi phong theo gia nho hon hoac bang mot gia tri cu the\n";
        cout << "37. Thong ke so phong theo loai giuong (don/doi)\n";
        cout << "38. Tim phong theo loai giuong (Don/doi)\n";
        cout << "39. Sua so giuong cua phong\n";
        cout << "40. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> chon;
        switch (chon) {
            case 1:
                themPhong();
                break;
            case 2:
                cout << "Nhap ma so phong can kiem tra: "; cin >> soPhong;
                if (timPhong(soPhong)) {
                    cout << "Phong " << soPhong << " co trong danh sach!" << endl;
                } else {
                    cout << "Phong " << soPhong << " khong ton tai!" << endl;
                }
                break;
            case 3:
                hienThiPhong();
                break;
            case 4:
                cout << "Nhap ma so phong can dat: "; cin >> soPhong;
                datPhong(soPhong);
                break;
            case 5:
                cout << "Nhap ma so phong can chinh sua: "; cin >> soPhong;
                chinhSuaPhong(soPhong);
                break;
            case 6:
                cout << "Nhap ma so phong can xoa: "; cin >> soPhong;
                xoaPhong(soPhong);
                break;
            case 7:
                luuDanhSachPhong();
                break;
            case 8:
                docDanhSachPhong();
                break;
            case 9:
                cout<<"Nhap loai phong can tim: ";
                cin>>loaiPhong;
                timPhongTheoLoai(loaiPhong);
                break;
                case 10: {
                    int soGiuong;
                    string loaiGiuong;
                    cout << "Nhap so giuong: ";
                    cin >> soGiuong;
                    cout << "Nhap loai giuong (don/doi): ";
                    cin.ignore();
                    getline(cin, loaiGiuong);
                    hienThiPhongTheoSoGiuongVaLoaiGiuong(soGiuong, loaiGiuong);
                    break;
                }
            case 11:
                cout<<"Nhap so phong can huy dat: ";
                cin>>soPhong;
                huyDatPhong(soPhong);
                break;
            case 12:
                timPhongGiaCaoNhat();
                break;
            case 13:
                thongKePhong();
                break;
            case 14:
                hienThiPhongDaDat();
                break;
            case 15:
                hienThiPhongConTrong();
                break;
            case 16:
                tinhTongDoanhThu();
                break;
            case 17:
                sapXepPhongTheoGiaTangDan();
                hienThiPhong();
                break;
            case 18:
                datNhieuPhong();
                break;
            case 19:
                xoaToanBoDanhSachPhong();
                break;
            case 20:
                cout<<"Nhap ma so phong can tim: ";
                cin>>maSoPhong;
                if (timPhong(maSoPhong))
                {
                    cout<<"Phong " << maSoPhong<<"da ton tai!"<<endl;
                }
                else
                {
                    cout<<"Khong tim thay phong co ma so trong danh sach "<<maSoPhong<<endl;
                }
                timPhongTheoMaSo(maSoPhong);
                break;
            case 21:
                cout << "Tong so luong phong: " << demSoLuongPhong() << endl;
                break;
            case 22:
                cout << "Nhap ma so phong can cap nhat gia: ";
                cin >> maSoPhong;
                cout << "Nhap gia moi: "; 
                cin >> gia;
                suaGiaPhong(maSoPhong,gia);
                break;
            case 23:
                cout << "Nhap khoang gia (min max): "; cin >> giaMin >> giaMax;
                timPhongTheoGia(giaMin, giaMax);
                break;
            case 24:
                if (!dau) {
                    cout << "Danh sach phong trong!" << endl;
                    break; // Ket thuc case 24 neu danh sach trong
                }
                cout << "Nhap trang thai phong (Da dat/Con trong): ";
                cin.ignore();
                getline(cin, trangThai);
                if (trangThai.empty()) {
                    cout << "Bạn chưa nhap trang thai phong!" << endl;
                    break;
                }
                timPhongTheoTrangThai(trangThai);
                break;
            case 25:
                hienThiPhongDangBang();
                break;
            case 26:
                timPhongDienTichLonNhat();
                break;
            case 27:
                demSoGiuongTheoLoaiPhong();
                break;
            case 28:
                tinhTongSoGiuong();
                break;
            case 29:
                hienThiPhongGiuongDoiConTrong();
                break;
            case 30:
                tinhTongSoPhongGiuongDoi();
                break;
            case 31:
                hienThiPhongGiuongDoi();
                break;
            case 32:
                sapXepPhongTheoLoaiPhong();
                hienThiPhong();
            case 33: {
                string loaiPhong;
                cout << "Nhap loai phong can tim: ";
                cin.ignore();
                getline(cin, loaiPhong);
                hienThiPhongTheoLoaiPhong(loaiPhong);
                break;
            }
            case 34:
                sapXepPhongTheoDienTichTangDan();
                hienThiPhong();
                break;
            case 35:
                cout << "Nhap so giuong can tim: ";
                cin >> soPhong;
                hienthiPhongTheoSoGiuong(soPhong);
                break;
            case 36: 
                double giaMax;
                cout<< "Nhap gia toi da: ";
                cin >> giaMax;
                hienThiPhongTheoGiaNhoHonHoacBang(giaMax);
                break;           
            case 37:
                thongKePhongTheoLoaiGiuong();
                break;
            case 38: {
                string loaiGiuong;
                cout << "Nhap loai giuong (Don/doi): ";
                cin.ignore();
                getline(cin, loaiGiuong);
                timPhongTheoLoaiGiuong(loaiGiuong);
                break;
            }
            case 39:
                cout << "Nhap ma so phong can sua so giuong: ";
                cin >> maSoPhong;
                cout << "Nhap so giuong moi: ";
                cin >> soPhong;
                suaSoGiuongPhong(maSoPhong, soPhong);
                break;
            case 40:
                cout<<"Da thoat khoi chuong trinh!\n";
                return;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    }
}

// Hàm main
int main() {
    menu();
    return 0;
}