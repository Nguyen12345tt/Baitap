create database TTKhachHang
go
use TTKhachHang 
go

CREATE TABLE THONGTIN (
	MaHoTen int primary key,
	Hoten nvarchar(50),
	CCCD  int NULL,
	GioiTinh nvarchar (20) NULL,
	NamSinh date NULL,
)
CREATE TABLE QUEQUAN (
	MaQueQuan int primary key,
	Thuongtru nvarchar (50),
	HienTai nvarchar (50),
);
CREATE TABLE DANTOC (
	MaDanToc int primary key,
	TenDanToc nvarchar ( 20),
);
CREATE TABLE TONGIAO (
	MaTonGiao int primary key,
	TenDanToc nvarchar (20),
);
CREATE TABLE NGHENGHIEP (
	MaNgheNghiep int primary key,
	TenNgheNghiep nvarchar (20),
);
CREATE TABLE QUOCTICH (
	MaQuocTich int primary key,
	TenQuocTich nvarchar (20),
);
 
go
insert THONGTIN values('123', 'Nguyễn Thành Nguyên', '0419028', 'M','2006')
insert THONGTIN values('456', 'Mai Trọng Thế', '10921', 'M', '2006')
insert THONGTIN values('789', 'Đặng Khánh Toàn', '0402', 'M', '2006')
insert QUEQUAN values('234', 'Chương Mỹ', 'Hà Nội')
insert QUEQUAN values('345', 'Sầm Sơn', 'Thanh Hóa')
insert QUEQUAN values('678', 'Thanh Chương', 'Nghệ An')
insert TONGIAO values ('00', 'Không')
insert TONGIAO values ('00', 'Không')
insert TONGIAO values ('00', 'Không')
insert DANTOC values ('01', ' Kinh')
insert DANTOC values ('01', ' Kinh')
insert DANTOC values ('01', ' Kinh')
insert QUOCTICH values ('02', ' Việt Nam')
insert QUOCTICH values ('02', ' Việt Nam')
insert QUOCTICH values ('02', ' Việt Nam')
insert NGHENGHIEP values ('001', 'Sinh Viên')
insert NGHENGHIEP values ('001', 'Nhân Viên')
insert NGHENGHIEP values ('001', 'Bác Sĩ')