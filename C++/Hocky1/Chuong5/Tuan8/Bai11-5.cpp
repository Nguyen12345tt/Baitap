#include<iostream>
using namespace std;

// Khai báo hàm getScore để nhập 1 điểm và trả về qua tham chiếu
void getScore(int &Diem);

// Khai báo hàm findLowest. Truyền vào 5 điểm và trả về điểm có giá trị nhỏ nhất
int findLowest(int, int, int, int, int);

// Khai báo hàm calcAverage để tính điểm trung bình của 4 điểm cao nhất và in ra
void calcAverage(int, int, int, int, int);

int main() 
{
    int Diem1, Diem2, Diem3, Diem4, Diem5;

    // Nhập 5 đầu điểm
    getScore(Diem1); // Khi gọi hàm có tham số là tham chiếu thì cần truyền vào biến
    getScore(Diem2); // Không được truyền vào giá trị. VD: getScore(10) là SAI
    getScore(Diem3);
    getScore(Diem4);
    getScore(Diem5);

    // Tính và in ra điểm trung bình
    calcAverage(Diem1, Diem2, Diem3, Diem4, Diem5);

    return 0;
}

// Định nghĩa hàm getScore
void getScore(int &Diem) 
{
    cout << "Nhập vào điểm (0-100): ";
    cin >> Diem;
}

// Định nghĩa hàm findLowest
int findLowest(int D1, int D2, int D3, int D4, int D5) {
    int MinDiem = D1;
    if (D2 < MinDiem) MinDiem = D2;
    if (D3 < MinDiem) MinDiem = D3;
    if (D4 < MinDiem) MinDiem = D4;
    if (D5 < MinDiem) MinDiem = D5;
    return MinDiem;
}

// Định nghĩa hàm calcAverage
void calcAverage(int D1, int D2, int D3, int D4, int D5) {
    int MinDiem = findLowest(D1, D2, D3, D4, D5);
    int Total = D1 + D2 + D3 + D4 + D5 - MinDiem;
    double DiemTB = Total / 4.0;
    cout << "Trung bình 4 đầu điểm cao nhất là: " << DiemTB << endl;
}
