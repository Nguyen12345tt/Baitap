/* Gợi ý: Bài 18-Chương 4:
- Hiểu: Đọc số từ 1 tệp-> chuyển thành số * -> In ra
- Thuật toán:
B1: Mở tệp People.txt
B2: Nam = 1900;
B3: Đọc từng số trong tệp lưu vào biến DanSo;
        -SoSao = DanSo/1000;
        -In ra: Nam
        -for(int i=1;i<=SoSao;i++)
            in ra:"*
        -Xuống dòng
        -Nam+=20; */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int DanSo,SoSao,Nam=1900;
    ifstream f1;
    f1.open("People.txt");

    cout << "TĂNG TRƯỞNG DÂN SỐ PRAIRIEVILLE\n";
    cout << "(Mỗi kí tự ‘*’ đại diện cho 1.000 người)\n";

    while (f1>>DanSo)
    {
        SoSao=DanSo/1000;
        cout<<Nam<<"  ";
        for(int i=1;i<=SoSao;i++)
            cout<<"*";
        cout<<endl;
        Nam+=20;
    }
    f1.close();
    
return 0;
    
}
