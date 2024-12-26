/*Bai2-6
Phan tich:
- khai bao mang double Mua[12]; 
- Khi do: Mua[0] - thang 1, Mua[1] - thang 2, Mua[2] - thang 3, ..., Mua[11] - thang 12
- Nhap mang Mua
- Tinh tong, tb, max, min*/
#include<iostream>
using namespace std;
int main()
{
	double Mua[12];
	// Nhap luong mua(nhap mang)
	for(int i=0; i<12; i++)
	{
		cout<<"Nhap luong mua thang"<<i+1<<":"<<endl;
		cin>>Mua[i];
	}
	// Tinh tong
	double Tong=0;
	for(int i=0; i<12; i++)
	{
		Tong+=Mua[i];
	}
	cout<<"Tong luong mua la: "<<Tong<<endl;
	// trung binh luong mua
	double TB=Tong/12;
	cout<<"Trung binh luong mua la: "<<TB<<endl;
	// Tim thang co luong mua cao nhat
	double Max=Mua[0];
	int thangMax=1;
	for(int i=1; i<12; i++)
	{
		if(Mua[i]>Max)
		{
			Max=Mua[i];
			thangMax=i+1;
		}
	}
	cout<<"Thang co luong mua cao nhat la: "<<thangMax<<endl;
	// Tim thang co luong mua thap nhat
	double Min=Mua[0];
	int thangMin=1;
	for(int i=1; i<12; i++)
	{
		if(Mua[i]<Min)
		{
			Min=Mua[i];
			thangMin=i+1;
		}
	}
	cout<<"Thang co luong mua thap nhat la: "<<thangMin<<endl;
	
	return 0;
}