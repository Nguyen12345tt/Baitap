/* 
Tạo cơ sở dữ liệu (CSDL)
- Chú ý: Khi tạo CSDL cần mở CSDL master bằng câu lệnh: use master
- Cú pháp: Create database TenCSDL;
*/
use master; -- Mở CSDL master
go --Để tạo thành nhóm lệnh
-- Kiểm tra nếu CSDL QLDOANVIEN đã tồn tại thì xóa đi và tạo lại
if exists (select * from sysdatabases where name = 'QLDOANVIEN')
	Drop database QLDOANVIEN;
go
Create database QLDOANVIEN; -- Tạo CSDL QLDOANVIEN
go
use QLDOANVIEN; -- Mở CSDL QLDOANVIEN để tạo các bảng phía dưới
go
/*
Tạo bảng dữ liệu
Chú ý: 
+ Trước khi tạo bảng cần mở CSDL cần tạo bảng: use TenCSDL
- Cú pháp: create table TenBang(TenTruong1 Kieu(Độ rộng), TenTruong2 Kiểu(Độ rộng),...
+ Khóa ngoại (FK) phải cùng kiểu và độ rộng với trường tham chiếu đến 
*/
Create table TINH(
		MaTinh int Primary Key, 
		TenTinh nvarchar(50) not null
		);
Create table DANTOC(
		MaDanToc int Primary Key, 
		TenDanToc nvarchar(50) not null
		);
Create table TONGIAO(
		MaTonGiao int Primary Key, 
		TenTonGiao nvarchar(50) not null
		);
Create table DOANVIEN(
		MaDoanVien int Primary Key, 
		HoTen nvarchar(50) not null, 
		NgaySinh date not null, 
		QueQuan nvarchar(50), 
		MaTinh int references TINH(MaTinh), 
		MaDanToc int references DANTOC(MaDanToc), 
		MaTonGiao int references TONGIAO(MaTonGiao)
		);
Create table HOATDONG(
		MaHoatDong int Primary Key, 
		TenHoatDong nvarchar(50) not null, 
		ThoiGian Date not null, 
		DiaDiem nvarchar(50) not null 
		);
Create table THAMGIA(
		MaDoanVien int references DOANVIEN(MaDoanVien), 
		MaHoatDong int references HOATDONG(MaHoatDong),
		NhanXet nvarchar(50),
		constraint PK_THAMGIA primary key (MaDoanVien,MaHoatDong)
		);