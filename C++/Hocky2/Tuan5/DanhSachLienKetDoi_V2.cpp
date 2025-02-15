/*DanhSachLienKetDoi-V2
*/
#include<iostream>
#include<fstream>
using namespace std;
struct Sinhvien
{
	int Masv;
	string HoTen;
	int NamSinh;
};
typedef Sinhvien Item;//Định nghĩa Item chính là kiểu Sinhvien
//Định nghĩa 1 phần tử (1 node)
struct Node
{
	Item Data;//Dữ liệu: int, float, Sinhvien, Nhanvien,...
	Node *Next;//Con trỏ trỏ đến nút tiếp theo
	Node *Prev;//Con trỏ trỏ đến nút phía trước
};
struct DoubleList//Định nghĩa DSLKĐ tên là DoubleList
{
	Node *Head;
	Node *Tail;
};
//Khai báo hàm nguyên mẫu
void Menu(DoubleList L);//Thực đơn lựa chọn chức năng
void KhoiTao(DoubleList L); //Khởi tạo danh sách đôi
bool KiemTraRong(DoubleList L);//Kiểm tra rỗng: True/False
int LayDoDai(DoubleList L);//Trả về độ dài danh sách đôi
Node *TaoNut(Item sv);//Tạo và về 1 nút có data là sv
void ThemDau(DoubleList &L, Item sv); //Thêm sv vào đầu ds
void ThemCuoi(DoubleList &L, Item sv); //Thêm sv vào cuối ds
void NhapDuLieu(Item &sv);//Nhập dữ liệu cho tham số sv
void HienThi(DoubleList L);//Hiển thị nội dung danh sách
void GhiDanhSachVaoTep(DoubleList L);// Ghi ds vào tệp sinhvien.txt
void XoaDau(DoubleList &L, Item sv); //Xóa đầu danh sách
void ThemViTriK(DoubleList &L, Item sv, int k); //Thêm vị trí k vào ds
void XoaViTriK(DoubleList &L, Item sv, int k); //Xóa vị trí k trong ds
int main()
{
	DoubleList L;

	Menu(L);
	return 0;
}
// Định nghĩa hàm
void GhiDanhSachVaoTep(DoubleList L)//Ghi ds vào tệp sinhvien.txt
{
    ofstream f1;
    f1.open("Sinhvien.txt");
	f1.close();
    while (L.Head != NULL)
	{
		//Ghi từng trường của data vào tệp
		//Mỗi trường trên 1 dòng, mỗi sv gồm 3 dòng
		f1<<L.Head->Data.Masv<<endl;
		f1<<L.Head->Data.HoTen<<endl;
		f1<<L.Head->Data.NamSinh<<endl;

		L.Head = L.Head ->Next;
	}
	f1.close();
    cout << "Danh sách đã được ghi vào tệp!" << endl;
}

void HienThi(DoubleList L)//Hiển thị nội dung danh sách
{
	while (L.Head != NULL)
	{
		cout<<L.Head->Data.Masv<<"\t"<<L.Head->Data.HoTen<<"\t"<<L.Head->Data.NamSinh<<endl;
		L.Head = L.Head -> Next;
	}
}
void ThemCuoi(DoubleList &L, Item sv) //Thêm sv vào cuối ds
{
	Node *p;

	p = TaoNut(sv); //Tạo nút p với data là sv
	if (KiemTraRong(L))
	{
		L.Head = p;
		L.Tail = p;
		return;
	}

	p -> Prev = L.Tail;//Tạo liên kết p và tail
	L.Tail -> Next = p;//Tạo liên kết tail với p
	L.Tail = p;//Di chuyển Tail vào vị trí cuối mới
}
void NhapDuLieu(Item &sv)//Nhập dữ liệu cho tham số sv
{
	cout<<"Nhap thong tin:\n";
	cout<<"Ma SV:";
	cin>>sv.Masv;
	cin.ignore();
	cout<<"Ho ten:";
	getline(cin,sv.HoTen);
	cout<<"Nam sinh:";
	cin>>sv.NamSinh;
}
void ThemDau(DoubleList &L, Item sv) //Thêm sv vào đầu ds
{
	Node *p;

	p = TaoNut(sv); //Tạo nút có data là sv
	if (KiemTraRong(L)) //Nếu danh sách đang rỗng
	{
		L.Head = p;
		L.Tail = p;
		return;
	}

	p -> Next = L.Head; //Tạo liên kết p và head
	L.Head -> Prev = p; //Tạo liên kết giữa head và p
	L.Head = p;//Di chuyển head sang vị trí đầu mới
}
Node *TaoNut(Item sv)//Tạo và về 1 nút có data là sv
{
	Node *p;

	p = new Node;//Cấp phát ô nhớ
	p -> Data = sv; //Gán sv cho data
	p -> Next = NULL;
	p -> Prev = NULL;

	return p; //Trả về nút p vừa tạo
}
int LayDoDai(DoubleList L)//Trả về độ dài danh sách đôi
{
	int DoDai = 0;
	/*
	while (L.Head != NULL)
	{
		DoDai++;
		L.Head = L.Head -> Next;
	}
	*/
	//C2:
	while (L.Tail != NULL)
	{
		DoDai++;
		L.Tail = L.Tail -> Prev;
	}
	return DoDai;
}
bool KiemTraRong(DoubleList L) //Kiểm tra rỗng: True/False
{
	if(L.Head == NULL || L.Tail == NULL)
		return true;
	else
		return false;
}
void KhoiTao(DoubleList L) //Khởi tạo danh sách đôi
{
	L.Head = NULL;
	L.Tail = NULL;
}
void XoaDau(DoubleList L)
{
	if (!KiemTraRong(L))
	{
		Node *p = L.Head;
		L.Head = L.Head -> Next;//Di chuyển head sang vị trí mới

		if (L.Head != NULL)
		{
			L.Head -> Prev = NULL;
		}
		else
		{
			L.Tail = NULL;
		}
	}
}
void XoaCuoi(DoubleList &L)
{
	if (!KiemTraRong(L))
	{
		Node *p = L.Tail;
		L.Tail = L.Tail -> Prev;//Di chuyển Tail lên trước

		if (L.Tail != NULL)
		{
			L.Tail -> Next = NULL;
		}
		else
		{
			L.Head = NULL;
		}
		
		delete p; //Giải phóng (Xóa) nút cuối
	}
}
void XoaViTriK(DoubleList &L, int k)
{
	if (k <= 0 || KiemTraRong(L))
	{
		return;
	}
	if (k == 1)
	{
		XoaDau(L);
		return;
	}

	int i = 1;
	Node *p = L.Head;
	while (p != NULL && i < k)
	{
		p = p -> Next;
		i++;
	}
	if (p == NULL)
		return;
}
void XoaDau(DoubleList &L, Item sv) //Xóa đầu danh sách
{
	if (!KiemTraRong(L))
	{
		Node *p = L.Head;
		L.Head = L.Head -> Next;
		if (L.Head != NULL)
		{
			L.Head -> Prev = NULL; 
		}
		else
		{
			L.Tail = NULL;
		}
		delete p;
	}
}
void ThemViTriK(DoubleList &L, Item sv, int k) //Thêm vị trí k vào ds
{
    if (k <= 0 || KiemTraRong(L))
    {
        return;
    }
    if (k == 1)
    {
        ThemDau(L, sv);
        return;
    }

    Node *p = L.Head;
    int i = 1;
    while (p != NULL && i < k )
    {
        p = p -> Next;
        i++;
    }
    if (p == NULL)
    {
        return;
    }

    Node *q = TaoNut(sv);
    q -> Prev = p -> Prev;
    q -> Next = p;
    if (p -> Prev != NULL)
    {
        p -> Prev -> Next = q;
    }
    else
    {
        L.Head = q;
    }
    p -> Prev = q;
}

//Menu
void Menu(DoubleList L)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra trong\n";
		cout<<"3. Do dai danh sach\n";
		cout<<"4. Them dau danh sach\n";
		cout<<"5. Hien thi danh sach\n";
		cout<<"6. Xoa dau danh sach\n";
		cout<<"7. Them cuoi danh sach\n";
		cout<<"8. Xoa cuoi danh sach\n";
		cout<<"9. Xoa vi tri k\n";
		cout<<"10. Them vi tri k\n";
		cout<<"11. Ghi danh sach vao tep\n";
		cout<<"12. Doc tu tep vao danh sach\n";
		
		cout<<"0. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (0-19)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khoi tao
			{
				KhoiTao(L);
				cout<<"Đã khởi tạo!\n";
				break;
			}
			case 2: //Kiểm tra danh sách rỗng
			{
				if (KiemTraRong(L))
					cout<<"Danh sách rỗng!\n";
				else
					cout<<"Danh sách không rỗng!\n";
				break;
			}
			case 3: // Độ dài danh sách
			{
				cout<<"Độ dài danh sách là:"<<LayDoDai(L)<<endl;
				break;
			}
			case 4: //Thêm sv vào đầu danh sách
			{
				Item sv;
				NhapDuLieu(sv);
				ThemDau(L,sv);
				cout<<"Da them!\n";
				break;
			}
			case 5: //Hiển thị danh sách
			{
				HienThi(L);
				break;
			}
			case 7: //Thêm sv vào cuối ds
			{
				Item sv;
				NhapDuLieu(sv);
				ThemCuoi(L,sv);
				cout<<"Đã thêm!\n";
				break;
			}
			case 11://Chức năng ghi ds vào tệp
			{
				GhiDanhSachVaoTep(L);
				cout<<"Đã ghi xong!\n";
				break;
			}
			case 0:
			{
				cout<<"Tam biet!";
				break;
			}
			case 6:
			{
				Item sv;
				XoaDau(L,sv);
				cout<<"Đã xóa đầu danh sách!\n";
				break;
			}		
			case 10:
			{
				Item sv;
				NhapDuLieu(sv);
				int k;
				cout<<"Nhập vị trí cần thêm (k):";
				cin>>k;
				ThemViTriK(L,sv,k);
				cout<<"Đã thêm vào vị trí " << k <<"!\n";
				break;
			}
		}
	}while(LuaChon!=0);
}