/* Ví dụ 4-6: Một số hàm thao tác với mảng
- Hàm nhập mảng
- Hàm in mảng
- Hàm tính và trả về tổng của các phần tử trong mảng
- Hàm tính và trả về trung bình các phần tử trong mảng
- Hàm tìm và trả về Min
- Hàm tìm và trả về Max
- Hàm tìm phần tử x trong mảng.
    + Nếu có trả về chỉ số của phần tử x trong mảng
    + Nếu không có thì trả về -1
- Hàm sắp xếp các phần tử trong mảng (tăng/giảm)
*/
#include<iostream>
using namespace std;
// Khai báo hàm nguyên mẫu
void NhapMang(int a[],int n); // Nhập mảng
void InMang(int a[],int n); // In mảng
int TongMang(int a[], int n); // Tính tổng các phần tử trong mảng
int TrungBinhMang(int a[], int n); // Tính trung bình của các phần tử trong mảng
int Max(int a[], int n); // Tìm và trả về GTLN
int Min(int a[], int n); // Tìm và trả về GTNN
int TimX(int a[], int n, int x); // 
void SapXep(int a[],int n);

int main()
{
    int a[100];
    int n; //Số lượng phần tử của mảng được nhập vào

    cout<<"Nhập số lượng phần tử của mảng:";
    cin >>n;
    //Gọi các hàm để thực hiện
    NhapMang(a,n);
    InMang(a,n);
    cout<<"Tong mang la:"<<TongMang(a,n)<<endl;
    cout<<"Trung binh mang la:"<<TrungBinhMang(a,n)<<endl;
    cout<<"Giá trị lớn nhất của mảng:"<<Max(a,n)<<endl;
    cout<<"Giá trị nhỏ nhất của mảng:"<<Min(a,n)<<endl;
    int vitri = TimX(a,n,10); //Tìm giá trị 10 trong mảng a, gía trị trả về gán cho biến vitri
    if (vitri==-1) //Không tìm thấy
    {
        cout<<"Không tìm thấy x!";
    }
    else
    {
        cout<<"Tìm thấy tại chỉ số:"<<vitri<<endl;
    }

//Sắp xếp mảng
    SapXep(a,n);
    InMang(a,n); // In ra mảng sau khi sắp xếp

    return 0;
}
//Định nghĩa hàm
void NhapMang(int a[], int n)
{
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
void InMang(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
int TongMang(int a[], int n)
{
    int Tong=0;
    for(int i=0;i<n;i++)
    {
        Tong+=a[i];
    }
    return Tong;
}
int TrungBinhMang(int a[], int n)
{
    int Tong=0;
    for(int i=0;i<n;i++)
    {
        Tong+=a[i];
    }
    return Tong/n;
}
int Max(int a[], int n)
{
    int Max = a[0];
    for (int i=1;i<n;i++)
    {
        if (a[i]>Max)
        {
            Max = a[i];
        }
    }
    return Max;
}
int Min(int a[], int n)
{
    int Min = a[0];
    for (int i=1;i<n;i++)
    {
        if (a[i]<Min)
        {
            Min = a[i];
        }
    }
    return Min;
}
int TimX(int a[], int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if (a[i]==x)
        {
            return i; //Tìm thấy và trả về chỉ số i và thoát khỏi hàm
        }
    }
    return -1; //Không tìm thấy trường hợp nào thì trả về -1
}
void SapXep(int a[],int n)
{
    int tam;
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i]>a[j]) //Nếu phần tử trước > phần tử sau thì đổi chỗ
            {
                tam=a[i];
                a[i]=a[j];
                a[j]=tam;
            }
        }
    }
}