use master;
go

if exists (select * from sysdatabases where name = 'QLVANTAI')
	Drop database QLVANTAI;
go

Create database QLVANTAI;
go
use QLVANTAI;
go

-- 1. Bảng KhachHang
create table KhachHang (
    MaKhachHang int primary key,
    TenKH nvarchar(255) NOT NULL,
    DiaChi nvarchar(500),
    SoDienThoai varchar(12)
);
go

-- 2. Bảng TaiXe
create table TaiXe (
    MaTaiXe int primary key,
    HoTen nvarchar(255) not null,
    NgaySinh date,
    GioiTinh nvarchar(5),
    SDT varchar(12) not null,
    DiaChi nvarchar(500)
);
go

-- 3. Bảng HoSoBoSungCuaTaiXe
create table HoSoBoSungCuaTaiXe (
    MaTaiXe int primary key references TaiXe(MaTaiXe),
    SoCMND varchar(13),
    NgayCapCMND date,
    NoiCapCMND nvarchar(255)
);
go

-- 4. Bảng PhuongTien
create table PhuongTien (
    BienSo varchar(20) primary key,
    LoaiPhuongTien nvarchar(100) not null,
    HangSanXuat nvarchar(100),
    NamSanXuat int
);
go

-- 5. Bảng LichTrinhVanChuyen (Liên kết với KhachHang và PhuongTien)
create table LichTrinhVanChuyen (
    MaLichTrinh int primary key,
    MaKhachHang int references KhachHang(MaKhachHang), -- FK: KhachHang -> LichTrinhVanChuyen (1-N)
    -- Thêm BienSoPhuongTien để chỉ phương tiện chính cho chuyến đi (1-N)
    BienSoPhuongTien varchar(20) references PhuongTien(BienSo),
	KhoiLuongHang nvarchar(40),
    TrangThai nvarchar(50),
    GhiChu nvarchar(255)
);
go

-- 6. Bảng PhanCongTaiXe_LichTrinh (Bảng trung gian - Quan hệ N-N giữa LichTrinhVanChuyen và TaiXe)
create table PhanCongTaiXe_LichTrinh (
    MaLichTrinh int references LichTrinhVanChuyen(MaLichTrinh), -- FK
    MaTaiXe int references TaiXe(MaTaiXe), -- FK
    VaiTro nvarchar(100), -- Ví dụ: Lái chính, phụ xe
    NgayBatDau date,
    NgayKetThuc date,
    constraint PK_PhanCongTaiXe_LichTrinh primary key(MaLichTrinh, MaTaiXe) -- Khóa chính kép
);
go

-- 7. Bảng LichSuBaoDuong (Theo dõi bảo dưỡng phương tiện - Quan hệ 1-N từ PhuongTien)
create table LichSuBaoDuong (
    MaBaoDuong int primary key,
    BienSo varchar(20) references PhuongTien(BienSo), -- FK
    NgayBaoDuong date not null,
    ChiPhiBaoDuong int not null,
    NhaCungCapDV nvarchar(255),
);
go

-- 8. Bảng HoaDon (Quản lý hóa đơn - Quan hệ 1-N từ LichTrinhVanChuyen)
create table HoaDon (
    MaHoaDon int primary key,
    MaLichTrinh int not null references LichTrinhVanChuyen(MaLichTrinh),
    TongTien float not null,
    GhiChu nvarchar(500)
);
go
