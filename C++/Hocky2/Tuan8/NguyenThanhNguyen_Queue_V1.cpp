/*Nguyễn Thành Nguyên - Queue - Phiên bản đầu tiên
- Hàng đợi (Queue) là danh sách các phần tử mà việc thêm vào và lấy ra ở 2 đầu khác
nhau
- Phần tử thêm vào trước thì sẽ lấy ra trước (FIFO - First In First Out - Vào trước
ra trước)
- Mỗi phần tử gồm 2 phần: Data & Next
- Quản lý bởi 2 con trỏ Front(Phía trước), Rear(Phía sau)*/

#include<iostream>
#include<string>
using namespace std;
struct Sinhvien
{
	int MaSV;
	string HoTen;
	int NamSinh;	
};
typedef Sinhvien Item; //Định nghĩa 1 nút của hàng đợi
struct Node
{
    Item Data;
    Node *Next;
};
struct Queue //Định nghĩa hàng đợi
{
    Node *Front;
    Node *Rear;
    int Count; //Lưu trữ số phần tử
};

//Khai báo hàm nguyên mẫu:
void Menu(Queue Q);//Menu các chức năng của ngăn xếp
void KhoiTao(Queue &Q);//Khởi tạo 
int LayDoDai(Queue Q); //Trả về độ dài của hàng đợi
bool KiemTraRong(Queue Q); //Kiểm tra hàng đợi có rỗng không (Trả về True/False)
Node *TaoNut(Item sv); //Tạo và trả về 1 nút có data là sv
void ThemVao(Queue &Q, Item sv); //Thêm phần tử sv vào hàng đợi
void NhapThongTin(Item &sv); //Nhập thông tin cho sv
void InHangDoi(Queue Q); //In hàng đợi
Item LayRa(Queue &Q); //Lấy ra, xóa đi và trả về phần tử ở Front
void TimKiemMaSV(Queue Q, int maSV);//Tìm kiếm sinh viên qua mã sinh viên
int main()
{
	Queue Q; //Khai báo 1 hàng đợi Q
	Menu(Q);
	return 0;
}
//Định nghĩa hàm
void TimKiemMaSV(Queue Q, int maSV) 
{
    Node* p = Q.Front; //Bắt đầu từ đầu hàng đợi
    while (p != NULL) //Duyệt qua từng nút 
    {
        if (p->Data.MaSV == maSV) //Nếu tìm thấy sinh viên có mã số tương ứng
        {
            cout << "Thông tin sinh viên:\n";
            cout << p->Data.MaSV << "\t" << p->Data.HoTen << "\t" << p->Data.NamSinh << endl;
            return; // Kết thúc tìm kiếm sv
        }
        p = p->Next; //Di chuyển đến nút tiếp theo
    }
    cout << "Không tìm thấy sinh viên có mã số " << maSV << endl; //Nếu không tìm thấy sv có mã số tương ứng
}
void KhoiTao(Queue &Q) //Khởi tạo
{
    Q.Front = NULL;
    Q.Rear = NULL;
    Q.Count = 0;
}
bool KiemTraRong(Queue Q) //Kiểm tra hàng đợi có rỗng không (Trả về True/False)
{
    if (Q.Count == 0)
        return true;
    else
        return false;
}
int LayDoDai(Queue Q) //Trả về độ dài của hàng đợi
{
    return Q.Count;
}
Node *TaoNut(Item sv) //Tạo và trả về 1 nút có data là sv
{
    Node *p;
    p = new Node;//Cấp phát ô nhớ cho p
    p -> Data = sv;//Gán sv cho data
    p -> Next = NULL;

    return p; //Trả về p
}
void ThemVao(Queue &Q, Item sv) //Thêm phần tử sv vào hàng đợi
{
    Node *p;
    p = TaoNut(sv);//(1) Tạo nút có data là sv
    if (KiemTraRong(Q))
    {
        Q.Front = p;
        Q.Rear = p;
        Q.Count++; //Khi thêm 1 nút thì Count tăng lên 1
        return;
    }
    Q.Rear -> Next = p;//(2) Tạo liên kết Rear và p
    Q.Rear = p; //(3) Di chuyển Rear về vị trí mới
    Q.Count++;
}
void NhapThongTin(Item &sv) //Nhập thông tin cho sv
{
    cout<<"Nhập thông tin sinh viên:\n";
    cout<<"Mã SV: ";
    cin>>sv.MaSV;
    cin.ignore();
    cout<<"Họ và tên: ";
    getline(cin,sv.HoTen);
    cout<<"Nam sinh: ";
    cin>>sv.NamSinh;
}
void InHangDoi(Queue Q) //In hàng đợi
{
    Node *p;
    p = Q.Front;
    while (p!=NULL)
    {
        cout<<p->Data.MaSV<<"\t"<<p->Data.HoTen<<"\t"<<p->Data.NamSinh<<endl;
        p = p->Next;
    }
}
Item LayRa(Queue &Q) //Lấy ra, xóa đi và trả về phần tử ở Front
{
    Node *p;
    Item sv;
    p = Q.Front;//Lưu lại địa chỉ Front cũ để giải phóng
    sv = Q.Front -> Data;//Lưu lại Data để trở về
    Q.Front = Q.Front -> Next;//Di chuyển Front sang nút mới
    delete p;//Giải phóng p (Địa chỉ cũ của Front)

    return sv;//Trả về sv
}
void Menu(Queue Q)//Menu
{
	int LuaChon;
	do
	{
		cout<<"---------------------------------------\n";
		cout<<"1. Khởi tạo\n";
		cout<<"2. Kiểm tra rỗng\n";
		cout<<"3. Lấy độ dài\n";
		cout<<"4. Thêm vào\n";
		cout<<"5. Lấy ra\n";
		cout<<"6. In hàng đợi\n";
        cout<<"7. Tìm kiếm mã sinh viên\n";
		
		cout<<"0. Thoát\n";
		cout<<"---------------------------------------\n";
		cout<<"Lựa chọn chức năng:";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khởi tạo
			{
				KhoiTao(Q);
                cout<<"Đã khởi tạo!\n";
                break;
			}
            case 2: //Kiểm tra hàng đợi rỗng
            {
                if (KiemTraRong(Q))
                {
                    cout<<"Hàng đợi rỗng!\n";
                }
                else
                {
                    cout<<"Hàng đợi không rỗng!\n";
                }
                break;
            }
            case 3: //Lấy độ dài của hàng đợi
            {
                cout<<"Độ dài hàng đợi là: "<<LayDoDai(Q)<<endl;
                break;
            }
            case 4:
            {
                Item sv;
                //Nhập thông tin cho sv
                NhapThongTin(sv);
                //Thêm sv vào hàng đợi
                ThemVao(Q,sv);
                break;
            }
            case 6: //In hàng đợi
            {
                InHangDoi(Q);
                break;
            }
            case 5://Lấy ra phần tử ở front của hàng đợi
            {
                Item sv;
                sv = LayRa(Q);
                cout<<sv.MaSV<<"\t"<<sv.HoTen<<"\t"<<sv.NamSinh<<"\t"<<endl;
                break;
            }
            case 7: //Tìm kiếm sv
            {
                int maSV;
                cout<<"Nhập mã số sinh viên cần tìm kiếm: ";
                cin>>maSV;
                TimKiemMaSV(Q, maSV);
                break;
            }            
			
			case 0: //Thoát
			{
				cout<<"Tạm biệt!\n";
				break;
			}
		}
	}while(LuaChon!=0);
}