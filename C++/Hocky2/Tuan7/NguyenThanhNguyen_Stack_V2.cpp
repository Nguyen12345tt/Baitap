/*NguyenThanhNguyen_Stack_V2.cpp
- Cài đặt ngăn xếp với kiểu dữ liệu Sinhvien gồm:
    + Mã SV kiểu int
    + Họ tên kiểu string
    + Năm sinh kiểu int
- Gồm các thao tác sau: Khởi tạo, kiểm tra rỗng, lấy độ dài, thêm vào (Push),
    lấy ra(Pop), In ngăn xếp,...
*/
#include<iostream>
using namespace std;
struct Sinhvien
{
    int MaSV;
    string HoTen;
    int NamSinh;
};

typedef Sinhvien Item; //Định nghĩa Item là kiểu int
struct Node //Định nghĩa 1 nút của ngăn xếp
{
    Item Data;
    Node *Next;
};
struct Stack //Định nghĩa 1 ngăn xếp tên Stack
{
    Node *Top;
};
//Khai báo hàm nguyên mẫu
void KhoiTao(Stack &S); // Khởi tạo ngăn xếp
bool KiemTraRong(Stack S); // Kiểm tra ngăn xếp rỗng
int DoDai(Stack S); // Lấy độ dài ngăn xếp
void ThemVao(Stack &S, Item value); // Thêm vào ngăn xếp
Item LayRa(Stack &S); // Lấy ra khỏi ngăn xếp
void InNganXep(Stack S); // In ngăn xếp

int main()
{
    Stack S; //Khai báo 1 ngăn xếp tên S
    KhoiTao(S);

    if (KiemTraRong(S))
    {
        cout<<"Danh sách rỗng!"<<endl;
    }
    else
    {
        cout<<"Danh sách không rỗng!"<<endl;
    }
    return 0;
}
//Định nghĩa hàm
void KhoiTao(Stack &S) //Khởi tạo ngăn xếp
{
    S.Top = NULL;
}
bool KiemTraRong(Stack S) // Kiểm tra ngăn xếp rỗng
{
    return S.Top = NULL;
}
int DoDai(Stack S)  //Lấy độ dài ngăn xếp
{
    int count = 0;
    Node* p = S.Top;
    while (p != NULL) {
        count++;
        p = p->Next;
    }
    return count;
}
void ThemVao(Stack &S, Item value) // Thêm vào ngăn xếp
{
    Node* newNode = new Node; 
    newNode->Data = value; 
    newNode->Next = S.Top; 
    S.Top = newNode;
}
Item LayRa(Stack &S) 
{
    if (KiemTraRong(S)) 
    {
        cout << "Ngăn xếp rỗng, không thể lấy phần tử!" << endl;
        Item nullValue = {0, "", 0}; // Giá trị trả về mặc định khi ngăn xếp rỗng
        return nullValue;
    }
    Node* temp = S.Top;
    Item poppedValue = temp->Data;
    S.Top = S.Top->Next;
    delete temp;
    return poppedValue;
}
void InNganXep(Stack S) {
    Node* p = S.Top;
    while (p != NULL) {
        cout << "MaSV: " << p->Data.MaSV << ", HoTen: " << p->Data.HoTen << ", NamSinh: " << p->Data.NamSinh << endl;
        p = p->Next;
    }
}