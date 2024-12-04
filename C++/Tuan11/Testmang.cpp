#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct nhanvat {
    string user;
    string pwd;
    string trangphuc;
    int capdo;
};

int main() {
    nhanvat* mang;
    int n;
    // Khai báo biến file
    ofstream out;
    //Mở file
    out.open("Nhanvat.txt");
    cout << "Nhập phần tử của mảng:" << endl;
    cin >> n;

    // Cú pháp cấp phát động
    mang = new nhanvat[n];

    // Nhập dữ liệu
    for (int i = 0; i < n; i++) {
        cout << "Nhân vật " << i + 1 << " user: ";
        cin >> mang[i].user;
        cout << "Nhân vật " << i + 1 << " password: ";
        cin >> mang[i].pwd;
        cout << "Nhân vật " << i + 1 << " trang phục: ";
        cin >> mang[i].trangphuc;
        cout << "Nhân vật " << i + 1 << " cấp độ: ";
        cin >> mang[i].capdo;
    }

    // In dữ liệu
    for (int i = 0; i < n; i++) {
        cout << "\nNhân vật " << i + 1 << ":\n";
        cout << "User: " << mang[i].user << "\n";
        cout << "Password: " << mang[i].pwd << "\n";
        cout << "Trang phục: " << mang[i].trangphuc << "\n";
        cout << "Cấp độ: " << mang[i].capdo << "\n";
    }

    // Thu hồi bộ nhớ
    delete[] mang;

    return 0;
}
