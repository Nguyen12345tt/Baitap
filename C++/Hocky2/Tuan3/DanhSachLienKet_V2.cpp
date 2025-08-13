/*Danh sách liên kết - Phiên bản thứ 2
- Có thể cài đặt danh sách liên kết bằng:
    + Mảng
    + Con trỏ
- 2 loại danh sách:
    + Danh sách đơn
    + Danh sách đôi
        
        Cài đặt danh sách liên kết đơn bằng con trỏ
- Danh sách liên kết đơn gồm các phần tử được liên kết với nhau bằng con trỏ
- Mỗi phần tử gồm 2 phần:
    + Data: Là 1 kiểu dữ liệu: 
        VD: int, float, Sinhvien, Nhanvien,...
    + Next: Con trỏ trỏ đến phần tử tiếp theo
- Phần tử kết thúc danh sách có con trỏ Next trỏ đến NULL
- Mỗi danh sách cần có con trỏ trỏ ở đầu danh sách
    head,L,...
*/
#include<iostream>
using namespace std;
typedef int Item(); //Định nghĩa Item = int
struct Node //Phần tử (Node)
{
    Item Data;
    Node *Next;
};
typedef Node *List; // Định nghĩa danh sách tên List
// Định nghĩa thao tác (hàm) làm việc với cấu trúc trên
int main()
{

    return 0;
} 