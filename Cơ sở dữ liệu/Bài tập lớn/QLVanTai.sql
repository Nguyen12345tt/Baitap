use master;
go

if exists (select * from sysdatabases where name = 'QLVANTAI')
	Drop database QLVANTAI;
go
Create database QLVANTAI;
go
use QLVANTAI;
go

create table KhachHang (
    MaKhachHang int primary key,
    TenKH nvarchar(255) NOT NULL,
    DiaChi nvarchar(500),
    SoDienThoai int,
    Email varchar(100),
    MaSoThue varchar(20),
    LoaiKH nvarchar(50) not null
);

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

create table LichTrinhVanChuyen (
    MaLichTrinh int primary key,
    MaKH int not null, -- Khóa ngoại đến KhachHang
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
    DanhGiaChuyenDi nvarchar(500),

    FOREIGN KEY (MaKH) REFERENCES KhachHang(MaKhachHang)
);

create table LichSuBaoDuong (
    MaBaoDuong int primary key,
    BienSo varchar(20) not null, -- Khóa ngoại đến PhuongTien. Kích thước VARCHAR(20) khớp với PhuongTien
    NgayBaoDuong date not null,
    LoaiBaoDuong nvarchar(200),
    MoTaCongViec nvarchar(500),
    ChiPhiBaoDuong int not null,
    NhaCungCapDV nvarchar(255),
    ChiSoKm INT,

    FOREIGN KEY (BienSo) REFERENCES PhuongTien(BienSo)
);

-- 6. Bảng trung gian LichTrinh_TaiXe (Đã đổi tên)
CREATE TABLE LichTrinh_TaiXe (
    MaLichTrinh INT NOT NULL,
    MaTaiXe INT NOT NULL,
    VaiTro NVARCHAR(100),
    ThoiGianBatDau DATETIME,
    ThoiGianKetThuc DATETIME,
    GhiChu NVARCHAR(MAX),

    PRIMARY KEY (MaLichTrinh, MaTaiXe),
    FOREIGN KEY (MaLichTrinh) REFERENCES LichTrinhVanChuyen(MaLichTrinh),
    FOREIGN KEY (MaTaiXe) REFERENCES TaiXe(MaTaiXe)
);

-- 7. Bảng trung gian LichTrinh_PhuongTien (Đã đổi tên)
CREATE TABLE LichTrinh_PhuongTien (
    MaLichTrinh INT NOT NULL,
    BienSo VARCHAR(20) NOT NULL,
    VaiTro NVARCHAR(100),
    GhiChu NVARCHAR(MAX),

    PRIMARY KEY (MaLichTrinh, BienSo),
    FOREIGN KEY (MaLichTrinh) REFERENCES LichTrinhVanChuyen(MaLichTrinh),
    FOREIGN KEY (BienSo) REFERENCES PhuongTien(BienSo)
);
GO