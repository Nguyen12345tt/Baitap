#include<iostream>
#include<fstream>
using namespace std;

struct Sinhvien
{
    int MaSV;
    string HoTen;
    int NamSinh;
};

typedef Sinhvien Item;

struct Node
{
    Item Data;
    Node *Next;
};

struct Stack
{
    Node *Top;
};

//Khai báo hàm nguyên mẫu:
void Menu(Stack S);
void KhoiTao(Stack &S);
bool KiemTraRong(Stack S);
int LayDoDai(Stack S);
Node *TaoNut(Item sv);
void Push(Stack &S, Item sv);
void NhapDuLieu(Item &sv);
Item Pop(Stack &S);
void InNganXep(Stack S);
void TimKiem(Stack S, int msv);
void GhiNganXepVaoTep(Stack S, const string& filename);
void DocTuTepVaoNganXep(Stack &S, const string& filename);
void TimSinhVienCoTuoiCaoNhat(Stack S);
void InTuoiTrungBinhCacSinhVien(Stack S);

int main()
{
    Stack S;
    Menu(S);
    return 0;
}

//Định nghĩa hàm:
void TimKiem(Stack S, int msv)
{
    if(KiemTraRong(S))
    {
        cout<<"Ngan xep rong!\n";
        return;
    }
    while(S.Top!=NULL)
    {
        if(S.Top->Data.MaSV == msv)
        {
            cout<<S.Top->Data.MaSV<<"\t"<<S.Top->Data.HoTen<<"\t"<<S.Top->Data.NamSinh<<endl;
            return;
        }
        S.Top = S.Top->Next;
    }
    cout<<"Khong tim thay!";
    return;
}

void InNganXep(Stack S)
{
    Item sv;
    while(S.Top!=NULL)
    {
        sv = Pop(S);
        cout<<sv.MaSV<<"\t"<<sv.HoTen<<"\t"<<sv.NamSinh<<endl;
    }
}

Item Pop(Stack &S)
{
    Item sv;
    Node *p;
    if(!KiemTraRong(S))
    {
        sv = S.Top->Data;
        p = S.Top;
        S.Top = S.Top->Next;
        delete p;
        return sv;
    }
}

void NhapDuLieu(Item &sv)
{
    cout<<"Nhap du lieu:\n";
    cout<<"Ma sinh vien:";
    cin>>sv.MaSV;
    cin.ignore();
    cout<<"Ho ten:";
    getline(cin,sv.HoTen);
    cout<<"Nam sinh:";
    cin>>sv.NamSinh;
}

void Push(Stack &S, Item sv)
{
    Node *p;
    p = TaoNut(sv);
    p->Next = S.Top;
    S.Top = p;
}

Node *TaoNut(Item sv)
{
    Node *p;
    p = new Node;
    p->Data = sv;
    p->Next = NULL;
    return p;
}

int LayDoDai(Stack S)
{
    int DoDai=0;
    while(S.Top!=NULL)
    {
        DoDai++;
        S.Top = S.Top->Next;
    }
    return DoDai;
}

bool KiemTraRong(Stack S)
{
    if(S.Top == NULL)
        return true;
    else
        return false;
}

void KhoiTao(Stack &S)
{
    S.Top =NULL;
}

void GhiNganXepVaoTep(Stack S, const string& filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Khong the mo tep!" << endl;
        return;
    }
    while (S.Top != NULL)
    {
        file << S.Top->Data.MaSV << "\t" << S.Top->Data.HoTen << "\t" << S.Top->Data.NamSinh << endl;
        S.Top = S.Top->Next;
    }
    file.close();
    cout << "Da ghi ngan xep vao tep!" << endl;
}

void DocTuTepVaoNganXep(Stack &S, const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Khong the mo tep!" << endl;
        return;
    }
    KhoiTao(S);
    Item sv;
    while (file >> sv.MaSV)
    {
        file.ignore();
        getline(file, sv.HoTen);
        file >> sv.NamSinh;
        Push(S, sv);
    }
    file.close();
    cout << "Da doc ngan xep tu tep!" << endl;
}

void TimSinhVienCoTuoiCaoNhat(Stack S)
{
    if (KiemTraRong(S))
    {
        cout << "Ngan xep rong!" << endl;
        return;
    }
    Node *maxNode = S.Top;
    while (S.Top != NULL)
    {
        if (S.Top->Data.NamSinh < maxNode->Data.NamSinh)
        {
            maxNode = S.Top;
        }
        S.Top = S.Top->Next;
    }
    cout << "Sinh vien co tuoi cao nhat: " << maxNode->Data.MaSV << "\t" << maxNode->Data.HoTen << "\t" << maxNode->Data.NamSinh << endl;
}

void InTuoiTrungBinhCacSinhVien(Stack S)
{
    if (KiemTraRong(S))
    {
        cout << "Ngan xep rong!" << endl;
        return;
    }
    int tongTuoi = 0;
    int soSV = 0;
    int namHienTai = 2023;
    while (S.Top != NULL)
    {
        tongTuoi += (namHienTai - S.Top->Data.NamSinh);
        soSV++;
        S.Top = S.Top->Next;
    }
    double tuoiTB = static_cast<double>(tongTuoi) / soSV;
    cout << "Tuoi trung binh cua cac sinh vien la: " << tuoiTB << endl;
}

void Menu(Stack S)
{
    int LuaChon;
    do
    {
        cout << "---------------------------------------\n";
        cout << "1. Khoi tao\n";
        cout << "2. Kiem tra rong\n";
        cout << "3. Lay do dai\n";
        cout << "4. Them vao - Push\n";
        cout << "5. Lay ra va xoa di - Pop\n";
        cout << "6. In ngan xep\n";
        cout << "7. Tim kiem\n";
        cout << "8. Ghi ngan xep vao tep\n";
        cout << "9. Doc tu tep vao ngan xep\n";
        cout << "10. Tim sinh vien co tuoi cao nhat\n";
        cout << "11. In ra tuoi trung binh cac sinh vien\n";
        cout << "0. Thoat\n";
        cout << "---------------------------------------\n";
        cout << "Lua chon chuc nang:";
        cin >> LuaChon;
        switch (LuaChon)
        {
            case 1:
                KhoiTao(S);
                cout << "Da khoi tao\n";
                break;
            case 2:
                if (KiemTraRong(S))
                {
                    cout << "Ngan xep rong!\n";
                } else {
                    cout << "Ngan xep khong rong!\n";
                }
                break;
            case 3:
                cout << "Do dai ngan xep la:" << LayDoDai(S) << endl;
                break;
            case 4:
                {
                    Item sv;
                    NhapDuLieu(sv);
                    Push(S, sv);
                    cout << "Da them!\n";
                }
                break;
            case 5:
                {
                    Item sv;
                    sv = Pop(S);
                    cout << sv.MaSV << "\t" << sv.HoTen << "\t" << sv.NamSinh << endl;
                }
                break;
            case 6:
                InNganXep(S);
                break;
            case 7:
                {
                    int msv;
                    cout << "Nhap ma sinh vien can tim: ";
                    cin >> msv;
                    TimKiem(S, msv);
                }
                break;
            case 8:
                {
                    string filename;
                    cout << "Nhap ten tep de ghi: ";
                    cin >> filename;
                    GhiNganXepVaoTep(S, filename);
                }
                break;
            case 9:
                {
                    string filename;
                    cout << "Nhap ten tep de doc: ";
                    cin >> filename;
                    DocTuTepVaoNganXep(S, filename);
                }
                break;
            case 10:
                TimSinhVienCoTuoiCaoNhat(S);
                break;
            case 11:
                InTuoiTrungBinhCacSinhVien(S);
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (LuaChon != 0);
}
