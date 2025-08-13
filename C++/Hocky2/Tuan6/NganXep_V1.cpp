/* Ngăn Xếp - Phiên bản đầu tiên
- Tên tiếng Anh: Stack
- Ngăn xếp là danh sách đặc biệt, mà mọi hoạt động cho vào (Push) và lấy ra (Pop) đều
diễn ra ở 1 đầu (Top)
- Thao tác cho vào và lấy ra theo cách:
    Vào sau, ra trước (LIFO - Last In Fast Out)
- Mỗi nút của ngăn xếp gồm 2 phần:
    + Data: Kiểu dữ liệu: int, float, Sinhvien,...
    + Next: Con trỏ trỏ đến nút phía dưới
- Kết thúc ngăn xếp con trỏ Next trỏ đến NULL
- Đứng đầu ngăn xếp là con trỏ Top
*/
#include<iostream>
using namespace std;
typedef int Item;
struct Node //Định nghĩa 1 nút của ngăn xếp
{
    Item data;
    Node *next;
};
struct Stack //Định nghĩa 1 ngăn xếp trên Stack
{
    Node *Top;
};
int main()
{
    Stack S; //Khai báo 1 ngăn xếp tên S
    
    return 0;
}