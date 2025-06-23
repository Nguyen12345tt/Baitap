use master;
go

if exists (select * from sysdatabases where name = 'QLVANTAI')
	Drop database QLVANTAI;
go
Create database QLVANTAI;
go
use QLVANTAI;
go

/*
Tạo bảng dữ liệu
- Chú ý:
	+ trước khi tạo bảng cần mở CSDL cần tạo bảng
	+ Khóa ngoại (FK) phải cùng kiểu và độ rộng với trường tham chiếu đến
use TenCSDL
- Cú pháp:
	Create table TenBang(TenTruong1 Kiểu(Độ rộng),TenTruong2 Kiểu(Độ rộng),.....)
*/

-- Bảng KhachHang
create table KhachHang (
    MaKhachHang int primary key,
    TenKH nvarchar(255) NOT NULL,
    DiaChi nvarchar(500),
    SoDienThoai int,
    Email varchar(100),
    MaSoThue varchar(20),
    LoaiKH nvarchar(50) not null
);
go

-- Bảng TaiXe
create table TaiXe (
    MaTaiXe int primary key,
    HoTen nvarchar(255) not null,
    NgaySinh date,
    GioiTinh nvarchar(5),
    SDT int not null,
    DiaChi nvarchar(500),
    SoBangLai varchar(50) not null,
    NgayCapBangLai date,
    NgayHetHanBangLai date,
    TrangThai nvarchar(50)
);
go

-- Bảng PhuongTien
create table PhuongTien (
    BienSo varchar(20) primary key,
    LoaiPhuongTien nvarchar(100) not null,
    HangSanXuat nvarchar(100),
    NamSanXuat int,
    TrongTai int,
    SoChoNgoi int,
    NgayDangKiemCuoi date,
    NgayHetHanDangKiem date,
    TinhTrang nvarchar(100)
);
go

-- Bảng LichTrinhVanChuyen
create table LichTrinhVanChuyen (
    MaLichTrinh int primary key,
    MaKhachHang int references KhachHang(MaKhachHang),
    NgayLapLT date,
    NgayKhoiHanhDuKien date not null,
    NgayKetThucDuKien date not null,
    DiaDiemXuatPhat nvarchar(500) not null,
    DiaDiemGiaoHang nvarchar(500) not null,
    LoaiHangHoa nvarchar(255),
    KhoiLuongHang float,
    ChiPhiDuKien int,
    TrangThaiLT nvarchar(50),
    NgayHoanThanhThucTe date,
    GhiChu nvarchar(255),
    DanhGiaChuyenDi nvarchar(500)
);
go

-- Bảng LichSuBaoDuong
create table LichSuBaoDuong (
    MaBaoDuong int primary key,
	BienSo varchar(20) references PhuongTien(BienSo),
    NgayBaoDuong date not null,
    LoaiBaoDuong nvarchar(200),
    MoTaCongViec nvarchar(500),
    ChiPhiBaoDuong int not null,
    NhaCungCapDV nvarchar(255),
    ChiSoKm int
);
go

-- Bảng trung gian LichTrinh_TaiXe
create table LichTrinh_TaiXe (
    MaLichTrinh int references LichTrinhVanChuyen(MaLichTrinh),
    MaTaiXe int references TaiXe(MaTaiXe),
    VaiTro nvarchar(100),
    NgayBatDau date,
    NgayKetThuc date,
    GhiChu nvarchar(550),
    constraint PK_LichTrinh_TaiXe primary key(MaLichTrinh, MaTaiXe)
);
go

-- Bảng trung gian LichTrinh_PhuongTien
CREATE TABLE LichTrinh_PhuongTien (
    MaLichTrinh INT references LichTrinhVanChuyen(MaLichTrinh),
    BienSo VARCHAR(20) references PhuongTien(BienSo),
    VaiTro NVARCHAR(100),
    GhiChu NVARCHAR(MAX),
    constraint PK_LichTrinh_PhuongTien primary key(MaLichTrinh, BienSo)
);
go

-- Bảng HoaDon (Đã chỉnh sửa theo phong cách QLDOANVIEN)
CREATE TABLE HoaDon (
    MaHoaDon INT PRIMARY KEY,
    MaLichTrinh INT NOT NULL references LichTrinhVanChuyen(MaLichTrinh), -- Đã di chuyển FK lên đây
    NgayLapHoaDon DATE NOT NULL,
    TongTien FLOAT NOT NULL,
    HinhThucThanhToan NVARCHAR(50),
    TrangThaiThanhToan NVARCHAR(50) NOT NULL,
    GhiChu NVARCHAR(500)
    -- Ràng buộc FOREIGN KEY đã được di chuyển lên cùng dòng với MaLichTrinh
);
go