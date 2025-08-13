/* 
Tạo cơ sở dữ liệu (CSDL)
- Chú ý: Khi tạo CSDL cần mở CSDL master bằng câu lệnh: use master
- Cú pháp: Create database TenCSDL;
*/
use master; -- Mở CSDL master
go --Để tạo thành nhóm lệnh
-- Kiểm tra nếu CSDL QLBENHVIEN đã tồn tại thì xóa đi và tạo lại
if exists (select * from sysdatabases where name = 'QLBENHVIEN')
	Drop database QLBENHVIEN;
go
Create database QLBENHVIEN; -- Tạo CSDL QLBENHVIEN
go
use QLBENHVIEN; -- Mở CSDL QLBENHVIEN để tạo các bảng phía dưới
go
/*
Tạo bảng dữ liệu
Chú ý: 
+ Trước khi tạo bảng cần mở CSDL cần tạo bảng: use TenCSDL
- Cú pháp: create table TenBang(TenTruong1 Kieu(Độ rộng), TenTruong2 Kiểu(Độ rộng),...
+ Khóa ngoại (FK) phải cùng kiểu và độ rộng với trường tham chiếu đến 
*/
Create table BACSI(
		MaBacSi int Primary Key, 
		HoTen nvarchar(50) not null,
		DiaChi nvarchar(100) not null,
		DienThoai int not null
		);
Create table BENHNHAN(
		MaBenhNhan int Primary Key, 
		TenBenhNhan nvarchar(30) not null,
		DiaChi nvarchar(50) not null,
		CMT int not null
		);
Create table DIEUTRI(
		MaDieuTri int Primary Key, 
		TenDieuTri nvarchar(30) not null,
		Ngay Date not null,
		LieuPhapDieuTri nvarchar(50) not null,
		MaBacSi int references BACSI(MaBacSi),
		MaBenhNhan int references BENHNHAN(MaBenhNhan)
		);
Create table CHUYENKHOA(
		MaChuyenKhoa int Primary Key,
		TenChuyenKhoa nvarchar(50) not null
		);
Create table THAMGIA(
		MaChuyenKhoa int references CHUYENKHOA(MaChuyenKhoa),
		MaBacSi int references BACSI(MaBacSi),
		constraint PK_THAMGIA primary key (MaChuyenKhoa,MaBacSi)
		);
Create table YTA(
		MaYTa int Primary Key,
		TenYTa nvarchar(30) not null
		);
Create table CHAMSOC(
		MaYTa int references YTA(MaYTa),
		MaBenhNhan int references BENHNHAN(MaBenhNhan),
		constraint PK_CHAMSOC primary key (MaYTa,MaBenhNhan)
		NoiDungChamSoc nvarchar(50) not null
		);