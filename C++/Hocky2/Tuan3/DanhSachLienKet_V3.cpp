//Cài đặt danh sách bằng con trỏ
#include<iostream>
using namespace std;
struct Sinhvien
{
	int masv;
	string hoten;
	int namsinh;
};
typedef Sinhvien Item; //Định nghĩa Item = Sinhvien
struct Node
{
	Item Data;
	Node *Next;
};
typedef Node *List; //Định nghĩa danh sách tên List

//Khai báo hàm nguyên mẫu
void Menu(List L);//Menu
void KhoiTao(List &L);//Khởi tạo danh sách
bool KiemTraRong(List L);//Kiểm tra danh sách L có trống không? true/false
int LayDoDai(List L);//Trả về độ dài của danh sách
//.....
int main()
{
	List L;
	
	Menu(L);
	
	return 0;
}
//Định nghĩa các hàm
bool KiemTraRong(List L)//Kiểm tra danh sách L có trống không? true/false
{
	if (L = NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Khởi tạo danh sách
void KhoiTao(List &L)
{
	L =NULL;
}
//Menu
void Menu(List L)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra trong\n";
		cout<<"3. Do dai danh sach\n";
		
		cout<<"0. Thoat khoi chuong trinh\n";
		cout<<"Moi chon chuc nang (0-19)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khoi tao
			{
				KhoiTao(L);
				cout<<"Da khoi tao!";
				break;
			}
			case 2://Kiem tra trong
			{
				if (KiemTraRong(L))// ~KiemTraRong(L) == true
				{
					cout<<"Danh sách rỗng!\n";
				}
				else
				{
					cout<<"Danh sách không rỗng!\n";
				}
				break;
			}
			
			case 0:
			{
				cout<<"Tam biet!";
				break;
			}		
		}
	}while(LuaChon!=0);
}