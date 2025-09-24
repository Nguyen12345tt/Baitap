USE master;
GO
IF exists(Select * from sysdatabases where name='QLVATTU')
	DROP DATABASE QLVATTU;
GO
--Tạo cơ sở dữ liệu
CREATE DATABASE QLVATTU;
GO
USE QLVATTU;
GO
--Tạo các bảng dữ liệu
CREATE TABLE KHACHHANG (
    MaKhachHang INT PRIMARY KEY,
    TenKhachHang NVARCHAR(100),
    DiaChi NVARCHAR(200),
    DienThoai NVARCHAR(15),
    Email NVARCHAR(100)
);
GO
CREATE TABLE VATTU (
    MaVatTu INT PRIMARY KEY,
    TenVatTu NVARCHAR(100),
    DonViTinh NVARCHAR(50),
    GiaMua DECIMAL(18, 2),
    SoLuongTon INT
);
GO
CREATE TABLE HOADON (
    MaHoaDon INT PRIMARY KEY,
    Ngay DATE,
    MaKhachHang INT,
    FOREIGN KEY (MaKhachHang) REFERENCES KHACHHANG(MaKhachHang)
);
GO
CREATE TABLE CHITIETHOADON (
    MaHoaDon INT,
    MaVatTu INT,
    SoLuongBan INT,
    GiaBan DECIMAL(18, 2),
    PRIMARY KEY (MaHoaDon, MaVatTu),
    FOREIGN KEY (MaHoaDon) REFERENCES HOADON(MaHoaDon),
    FOREIGN KEY (MaVatTu) REFERENCES VATTU(MaVatTu)
);
--Chèn dữ liệu
INSERT INTO KHACHHANG (MaKhachHang, TenKhachHang, DiaChi, DienThoai, Email)
VALUES 
(1, N'Trần Đăng Công', N'Hà Nội', '0123456789', 'a@example.com'),
(2, N'Đậu Hải Phong', N'Hồ Chí Minh', '0987654321', 'b@example.com'),
(3, N'Phạm Văn Tiệp', N'Đà Nẵng', '0912345678', 'c@example.com'),
(4, N'Nguyễn Ngọc Ân', N'Hà Nội', '0912345679', 'd@example.com'),
(5, N'Nguyễn Thanh Nhàn', N'Hồ Chí Minh', '0922334455', 'e@example.com'),
(6, N'Trần Thị Huệ', N'Đà Nẵng', '0933445566', 'f@example.com'),
(7, N'Lê Thị Phượng', N'Hải Phòng', '0944556677', 'g@example.com'),
(8, N'Nguyễn Thị Hương Giang', N'Cần Thơ', '0955667788', 'h@example.com');
GO
INSERT INTO VATTU (MaVatTu, TenVatTu, DonViTinh, GiaMua, SoLuongTon)
VALUES
(101, N'Sắt thép', N'Tấn', 15000, 200),
(102, N'Cát, đá', N'Tấn', 12000, 500),
(103, N'Gạch', N'Viên', 25000, 150),
(104, N'Vữa xây dựng', N'Xe', 5000, 100),
(105, N'Bê tông', N'Tấn', 12000, 300),
(106, N'Phụ gia xây dựng', 'Kg', 35000, 250),
(107, N'Sàn nhựa giả gỗ', 'M2', 20000, 400),
(108, N'Gạch ốp tường', 'Viên', 15000, 600),
(109, N'Tủ đựng quần áo', 'Chiếc', 20000, 700);
GO
INSERT INTO HOADON (MaHoaDon, Ngay, MaKhachHang)
VALUES
(1, '2024-11-20', 1),
(2, '2024-11-21', 2),
(3, '2024-11-22', 3),
(4, '2024-11-23', 4),
(5, '2024-11-24', 5),
(6, '2024-11-25', 6),
(7, '2024-11-26', 7),
(8, '2024-11-27', 8);
GO
INSERT INTO CHITIETHOADON (MaHoaDon, MaVatTu, SoLuongBan, GiaBan)
VALUES
(1, 101, 10, 16000), -- Hóa đơn 1 bán 10 Kg Bột mì với giá 16000
(1, 102, 5, 13000),  -- Hóa đơn 1 bán 5 Kg Gạo với giá 13000
(2, 103, 3, 26000),  -- Hóa đơn 2 bán 3 Lít Dầu ăn với giá 26000
(3, 104, 2, 6000),   -- Hóa đơn 3 bán 2 Kg Muối với giá 6000
(1, 105, 10, 17000),
(1, 106, 20, 13000),
(2, 104, 15, 27000),
(2, 105, 5, 5500),
(3, 105, 30, 13000),
(4, 106, 10, 36000),
(5, 107, 25, 21000),
(6, 108, 50, 16000),
(7, 109, 40, 21000),
(8, 101, 12, 17500);