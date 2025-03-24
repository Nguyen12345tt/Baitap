/*NguyenThanhNguyen_BinaryTree_V1.cpp*/
#include<iostream>
using namespace std;
typedef int Item;
struct TNode //Định nghĩa 1 nút của cây gồm 3 phần:
{
    Item Data; //Dữ liệu
    TNode *left; //Con trỏ trỏ vào nút con bên trái
    TNode *right; //Con trỏ trỏ vào nút con bên phải
};
typedef TNode *Tree; //Định nghĩa 1 cây tree
//Khai báo hàm
void Menu(Tree T); //Menu các chức năng của cây
void KhoiTao(Tree &T); //Khởi tạo cây
bool KiemTraCayRong(Tree T); //Kiểm tra cây có rỗng hay không? (True/False)
void ThemNut(Tree &T, Item x); //Thêm nút có data là x vào cây T
void Duyet_Nut_Trai_Phai(Tree T); //Duyệt cây theo thứ tự: Nút-Trái-Phải
void Duyet_Trai_Nut_Phai(Tree T); //Duyệt cây theo thứ tự: Trái - Nút - Phải
void Duyet_Trai_Phai_Nut(Tree T); //Duyệt cây theo thứ tự: Trái - Phải - Nút
int Dem_So_Nut_La(Tree T); //Đếm và trả về số nút lá trong cây T
int Dem_So_Nut_2_Con(Tree T); //Đếm và trả về nút có 2 con
int main()
{
    Tree T;
    Menu(T);
    return 0;
}
//Định nghĩa hàm
int Dem_So_Nut_2_Con(Tree T) //Đếm và trả về nút có 2 con
{
    if (T == NULL) //Nếu cây rỗng thì không có nút
        return 0;
    else //Cây không rỗng
    {
    //Nút 2 con là nút mà bên trái và bên phải có con(Bên trái và phải đều khác NULL)
    if (T->left != NULL && T->right != NULL) //
        return 1;
    else
        {
            return Dem_So_Nut_2_Con(T->left) + Dem_So_Nut_2_Con(T->right);
        }
    }
}
int Dem_So_Nut_La(Tree T) //Đếm và trả về số nút lá trong cây T
{
    if (T == NULL) //Nếu cây rỗng thì số nút lá =0
        return 0;
    else //Cây không rỗng
    {
        //Nút lá là nút không có con(Bên trái và phải đều = NULL)
        if (T->left == NULL && T->right == NULL) //
            return 1;
        else
        {
            return Dem_So_Nut_La(T->left) + Dem_So_Nut_La(T->right);
        }
    }
}
void Duyet_Trai_Phai_Nut(Tree T)
{
    if (T != NULL)
    {
        Duyet_Trai_Phai_Nut(T -> left); //Ưu tiên duyệt trái
        Duyet_Trai_Phai_Nut(T -> right); //Ưu tiên duyệt phải
        cout<<T->Data<<"\t";
    }
}
void Duyet_Trai_Nut_Phai(Tree T) //Duyệt cây theo thứ tự: Trái - Nút - Phải
{
    if (T != NULL)
    {
        Duyet_Trai_Nut_Phai(T ->left); //Ưu tiên duyệt trái
        cout<<T->Data<<"\t";
        Duyet_Trai_Nut_Phai(T ->right); //Ưu tiên duyệt phải
    }
}
void Duyet_Nut_Trai_Phai(Tree T) //Duyệt cây theo thứ tự: Nút-Trái-Phải
{
    if (T !=NULL) //Khi cây khác rỗng thì duyệt
    {
        cout<<T->Data<<"\t"; //Xử lý (in ra) nút
        Duyet_Nut_Trai_Phai(T->left);
        Duyet_Nut_Trai_Phai(T->right);
    }
}
void ThemNut(Tree &T, Item x) //Thêm nút có data là x vào cây T
{
    if (T == NULL) //Nếu nút rỗng thì tạo mới
    {
        T = new TNode;//Cấp phát ô nhớ cho nút T
        T -> Data = x;//Gán x cho data
        T -> left = NULL; 
        T -> right = NULL;
    }
    else //Nếu có nút thì nhỏ hơn cho bên trái, lớn hơn cho bên phải
    {
        if (x < T->Data) //x nhỏ hơn thì cho bên trái
        {
            ThemNut(T->left,x);
        }
        else //x lớn hơn hoặc bằng thì cho bên phải
        {
            ThemNut(T->right,x);
        }
    }
}
void KhoiTao(Tree &T) //Khởi tạo cây
{
    T = NULL;
}
bool KiemTraCayRong(Tree T) //Kiểm tra cây có rỗng hay không? (True/False)
{
    if (T == NULL)
        return true;
    else
        return false;
}
void Menu(Tree T)//Menu các chức năng của cây
{
	int LuaChon;
	do
	{
		cout<<"---------------------------------------\n";
		cout<<"1. Khởi tạo cây\n";
		cout<<"2. Kiểm tra cây rỗng\n";
        cout<<"3. Thêm nút\n";
        cout<<"4. Duyệt cây theo thứ tự: Nút - Trái - Phải\n";
        cout<<"5. Duyệt cây theo thứ tự: Trái - Nút - Phải\n";
        cout<<"6. Duyệt cây theo thứ tự: Trái - Phải - Nút\n";
        cout<<"7. Đếm số nút lá trong cây\n";
        cout<<"8. Đếm số nút có 2 con\n";
		cout<<"0. Thoát\n";
		cout<<"---------------------------------------\n";
		cout<<"Lựa chọn chức năng:";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khởi tạo
			{
                KhoiTao(T);
                cout<<"Đã khởi tạo!\n";
                break;
			}
            case 2: //Kiểm tra cây rỗng
            {
                if (KiemTraCayRong(T))
                {
                    cout<<"Cây đang rỗng!\n";
                }
                else
                {
                    cout<<"Cây không rỗng!\n";
                }
                break;
            }
            case 3://Thêm nút có data x vào cây
            {
                Item x;
                //Nhập thông tin cho x
                cout<<"Nhập giá trị x:";
                cin>>x;
                //Thêm x vào cây
                ThemNut(T,x);
                break;
            }
            case 4://Duyệt cây theo thứ tự: Nút - Trái - Phải
            {
                cout<<"Nút-Trái-Phải:\n";
                Duyet_Nut_Trai_Phai(T);
                cout<<endl;
                break;
            }
            case 5://Duyệt cây theo thứ tự: Trái - Nút - Phải
            {
                cout<<"Trái - Nút - Phải:\n";
                Duyet_Trai_Nut_Phai(T);
                cout<<endl;
                break;
            }
            case 6:
            {
                cout<<"Trái - Phải - Nút:\n";
                Duyet_Trai_Phai_Nut(T);
                cout<<endl;
                break;
            }
            case 7: //Đếm số nút lá
            {
                cout<<"Số nút lá là:"<<Dem_So_Nut_La(T)<<endl;
                break;
            }
            case 8: //Đếm số nút có 2 con
            {
                cout<<"Số nút có 2 con là:"<<Dem_So_Nut_2_Con(T)<<endl;
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
