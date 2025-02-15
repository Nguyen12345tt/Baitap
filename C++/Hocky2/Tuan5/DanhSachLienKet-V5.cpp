#include <iostream>
#include <fstream>
using namespace std;

struct Sinhvien {
    int masv;       // Mã sinh viên
    string hoten;   // Họ tên sinh viên
    int namsinh;    // Năm sinh
};

typedef Sinhvien Item;
struct Node {
    Item Data;      // Dữ liệu của nút (sinh viên)
    Node *Next;     // Con trỏ đến nút tiếp theo
};

typedef Node *List; // Định nghĩa List là con trỏ tới Node

// Nguyên mẫu hàm
void Menu(List &L);                     // Menu
void KhoiTao(List &L);                  // Khởi tạo danh sách
bool KiemTraRong(List L);               // Kiểm tra danh sách có trống không
int LayDoDai(List L);                   // Lấy độ dài của danh sách
Node *TaoNut(Item sv);                  // Tạo một nút với dữ liệu sv
void ThemDau(List &L, Item sv);         // Thêm một nút vào đầu danh sách
void NhapDuLieu(Item &sv);              // Nhập dữ liệu cho sv
void HienThi(List L);                   // Hiển thị danh sách
void XoaDau(List &L);                   // Xóa nút đầu tiên
void ThemCuoi(List &L, Item sv);        // Thêm một nút vào cuối danh sách
void XoaCuoi(List &L);                  // Xóa nút cuối danh sách
void XoaViTriK(List &L, int k);         // Xóa nút ở vị trí k
void ThemViTriK(List &L, int k, Item sv);// Thêm một nút ở vị trí k
void GhiDanhSachVaoTep(List L);         // Ghi danh sách vào tệp
void DocTuTepVaoDanhSach(List &L);      // Đọc danh sách từ tệp

int main() {
    List L;
    Menu(L);
    return 0;
}

// Hàm đọc danh sách từ tệp
void DocTuTepVaoDanhSach(List &L) {
    ifstream f1;
    Item sv; // Khai báo sv ở đây

    f1.open("sinhvien.txt");
    while (f1 >> sv.masv) {
        f1.ignore();
        getline(f1, sv.hoten);
        f1 >> sv.namsinh;
        ThemDau(L, sv);
    }
    f1.close();
}

// Hàm ghi danh sách vào tệp
void GhiDanhSachVaoTep(List L) {
    ofstream f1;
    f1.open("sinhvien.txt");
    while (L != NULL) {
        f1 << L->Data.masv << endl;
        f1 << L->Data.hoten << endl;
        f1 << L->Data.namsinh << endl;
        L = L->Next;
    }
    f1.close();
}

// Hàm thêm một nút ở vị trí k
void ThemViTriK(List &L, int k, Item sv) {
    Node *p;
    List L1 = L;
    int ViTri = 1;

    p = TaoNut(sv);
    if (L == NULL) {
        L = p;
        return;
    }
    if (k == 1) {
        ThemDau(L, sv);
        return;
    }
    while (ViTri < k - 1) {
        ViTri++;
        L1 = L1->Next;
    }

    p->Next = L1->Next;
    L1->Next = p;
}

// Hàm xóa một nút ở vị trí k
void XoaViTriK(List &L, int k) {
    List L1 = L;
    int ViTri = 1;
    Node *p;

    if (L == NULL) {
        cout << "Danh sach dang rong!\n";
        return;
    }
    if (k > LayDoDai(L)) {
        cout << "Vuot qua do dai danh sach\n";
        return;
    }
    while (ViTri < k - 1) {
        ViTri++;
        L1 = L1->Next;
    }
    p = L1->Next;
    L1->Next = p->Next;
    delete p;
}

// Hàm xóa nút cuối danh sách
void XoaCuoi(List &L) {
    List L1 = L;

    if (L == NULL) {
        return;
    }
    if (L->Next == NULL) {
        delete L;
        L = NULL;
    } else {
        while (L1->Next->Next != NULL) {
            L1 = L1->Next;
        }
        delete L1->Next;
        L1->Next = NULL;
    }
}

// Hàm thêm một nút vào cuối danh sách
void ThemCuoi(List &L, Item sv) {
    Node *p;
    List L1 = L;

    p = TaoNut(sv);
    if (L == NULL) {
        L = p;
        return;
    }
    while (L1->Next != NULL) {
        L1 = L1->Next;
    }
    L1->Next = p;
}

// Hàm xóa nút đầu tiên
void XoaDau(List &L) {
    Node *p;
    if (L == NULL) {
        return;
    }
    p = L;
    L = L->Next;
    delete p;
}

// Hàm hiển thị danh sách
void HienThi(List L) {
    while (L != NULL) {
        cout << L->Data.masv << "\t" << L->Data.hoten << "\t" << L->Data.namsinh << endl;
        L = L->Next;
    }
}

// Hàm nhập dữ liệu cho sv
void NhapDuLieu(Item &sv) {
    cout << "Nhap thong tin:\n";
    cout << "Ma SV:";
    cin >> sv.masv;
    cin.ignore();
    cout << "Ho ten:";
    getline(cin, sv.hoten);
    cout << "Nam sinh:";
    cin >> sv.namsinh;
}

// Hàm thêm một nút vào đầu danh sách
void ThemDau(List &L, Item sv) {
    Node *p;
    p = TaoNut(sv);
    p->Next = L;
    L = p;
}

// Hàm tạo một nút với dữ liệu sv
Node *TaoNut(Item sv) {
    Node *p;
    p = new Node;
    p->Data = sv;
    p->Next = NULL;
    return p;
}

// Hàm lấy độ dài của danh sách
int LayDoDai(List L) {
    int DoDai = 0;
    while (L != NULL) {
        DoDai++;
        L = L->Next;
    }
    return DoDai;
}

// Hàm kiểm tra danh sách có trống không
bool KiemTraRong(List L) {
    return L == NULL;
}

// Hàm khởi tạo danh sách
void KhoiTao(List &L) {
    L = NULL;
}

// Hàm menu
void Menu(List &L) {
    int LuaChon;

    do {
        cout << "\nCAC CHUC NANG\n";
        cout << "1. Khoi tao\n";
        cout << "2. Kiem tra trong\n";
        cout << "3. Do dai danh sach\n";
        cout << "4. Them dau danh sach\n";
        cout << "5. Hien thi danh sach\n";
        cout << "6. Xoa dau danh sach\n";
        cout << "7. Them cuoi danh sach\n";
        cout << "8. Xoa cuoi danh sach\n";
        cout << "9. Xoa vi tri k\n";
        cout << "10. Them vi tri k\n";
        cout << "11. Ghi danh sach vao tep\n";
        cout << "12. Doc tu tep vao danh sach\n";
        cout << "0. Thoat khoi chuong trinh\n";
        cout << "Moi chon chuc nang (0-12)?"; // Phạm vi đã chỉnh sửa
        cin >> LuaChon;
        switch (LuaChon) {
            case 1:
                KhoiTao(L);
                cout << "Da khoi tao!\n";
                break;
            case 2:
                cout << (KiemTraRong(L) ? "Danh sach rong!\n" : "Danh sach khong rong!\n");
                break;
            case 3:
                cout << "Do dai danh sach la: " << LayDoDai(L) << endl;
                break;
            case 4: {
                Item sv;
                NhapDuLieu(sv);
                ThemDau(L, sv);
                cout << "Da them!\n";
                break;
            }
            case 5:
                HienThi(L);
                break;
            case 6:
                XoaDau(L);
                cout << "Da xoa!\n";
                break;
            case 7: {
                Item sv;
                NhapDuLieu(sv);
                ThemCuoi(L, sv);
                cout << "Da them!\n";
                break;
            }
            case 8:
                XoaCuoi(L);
                cout << "Da xoa!";
                break;
            case 9: {
                int k;
                cout << "Nhap vi tri can xoa:";
                cin >> k;
                XoaViTriK(L, k);
                cout << "Da xoa!";
                break;
            }
            case 10: {
                int k;
                Item sv;
                cout << "Nhap vi tri can them:";
                cin >> k;
                NhapDuLieu(sv);
                ThemViTriK(L, k, sv); // Thứ tự tham số đã chỉnh sửa
                cout << "Da them!\n";
                break;
            }
            case 11: {
                GhiDanhSachVaoTep(L);
                cout << "Da ghi xong!";
                break;
            }
            case 12: {
                DocTuTepVaoDanhSach(L);
                cout << "Da doc xong!";
                break;
            }
            case 0:
                cout << "Tam biet!";
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai.";
                break;
        }
    } while (LuaChon != 0);
}
