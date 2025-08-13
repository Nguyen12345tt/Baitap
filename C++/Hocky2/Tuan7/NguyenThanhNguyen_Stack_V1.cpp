/*NguyenThanhNguyen_Stack_V1.cpp
- Ngăn xếp là danh sách mà thao tác thêm vào và lấy ra đều diễn ra tại 1 đầu (Top)
- Cài đặt ngăn xếp = con trỏ thì mỗi nút (phần tử) gồm 2 phần:
    + Data là kiểu dữ liệu: int, float, Sinhvien
    + Next là con trỏ trỏ đến nút tiếp theo
- Đứng đầu ngăn xếp là con trỏ Top, là nơi thêm vào (Push) và lấy ra (Pop)
- Phần tử cuối có Next trỏ vào NULL
- Ví dụ cài đặt ngăn xếp với kiểu int
- Một số thao tác với ngăn xếp: Khởi tạo, kiểm tra rỗng, lấy độ dài, thêm vào, lấy ra,
    tìm kiếm, in, ghi vào tệp, đọc từ tệp,...
*/
#include<iostream>
using namespace std;
typedef int Item; //Định nghĩa Item là kiểu int
struct Node //Định nghĩa 1 nút của ngăn xếp
{
    Item Data;
    Node *Next;
};
struct Stack //Định nghĩa 1 ngăn xếp tên Stack
{
    Node *Top;
};
int main()
{
    Stack S; //Khai báo 1 ngăn xếp tên S
    
    return 0;
}
