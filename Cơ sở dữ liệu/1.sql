/*
Tạo cơ sở dữ liệu (CSDL)
- Chú ý: Khi tạo CSDL cần mở CSDL Master
use master
- Cú pháp: 
	Create database TenCSDL;
*/
use master; --Mở CSDL master
go --để tạo thành nhóm lệnh
--Kiểm tra nếu CSDL QLDOANVIEN đã tồn tại thì xóa đi và tạo lại
if exists(select * from sysdatabases where name = 'QLDOANVIEN')
	Drop database QLDOANVIEN; -- Xóa CSDL QLDOANVIEN
go
Create database QLDOANVIEN; --Tạo CSDL QLDOANVIEN
go
use QLDOANVIEN; -- Mở CSDL QLDOANVIEN để tạo các bảng phía dưới
go
/*
Tạo bảng dữ liệu
- Chú ý: 
	+trước khi tạo bảng cần mở CSDL cần tạo bảng
	+ Khóa ngoại (FK) phải cùng kiểu và độ rộng với trường tham chiếu đến
use TenCSDL
- Cú pháp: 
	Create table TenBang(TenTruong1 Kiểu(Độ rộng),TenTruong2 Kiểu(Độ rộng),.....)
*/
Create table TINH(
			MaTinh int Primary key, 
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
go
Create table DOANVIEN(
			MaDoanVien int Primary Key, 
			HoTen nvarchar(30) not null, 
			NgaySinh Date not null, 
			QueQuan nvarchar(50), 
			MaTinh int references TINH(MaTinh),--MaTinh là FK tham chiếu đến trường MaTinh trong bảng TINH
			MaDanToc int references DANTOC(MaDanToc), 
			MaTonGiao int references TONGIAO(MaTonGiao)
			);
go
Create table HOATDONG(
			MaHoatDong int Primary Key, 
			TenHoatDong nvarchar(100) not null, 
			ThoiGian Date not null, 
			DiaDiem nvarchar(50) 
			);
Create table THAMGIA(
			MaDoanVien int references DOANVIEN(MaDoanVien), 
			MaHoatDong int references HOATDONG(MaHoatDong), 
			NhanXet nvarchar(50),
			constraint PK_THAMGIA primary key(MaDoanVien,MaHoatDong)
			)