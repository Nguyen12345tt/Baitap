-- 1. Chèn dữ liệu cho bảng KhachHang
insert into KhachHang (MaKhachHang, TenKH, DiaChi, SoDienThoai) values
(101, N'Công ty A', N'123 Nguyễn Huệ, TP.HCM', '0943212345'),
(102, N'Nguyễn Thị B', N'45 Hai Bà Trưng, Hà Nội', '0912234567'),
(103, N'Công ty C', N'78 Lê Lợi, Đà Nẵng', '0903345678'), 
(104, N'Phạm Văn D', N'90 Trần Phú, Cần Thơ', '0914456789'), 
(105, N'Tập đoàn E', N'10 Kim Mã, Hà Nội', '0905567890'); 
go

-- 2. Chèn dữ liệu cho bảng TaiXe
insert into TaiXe (MaTaiXe, HoTen, NgaySinh, GioiTinh, SDT, DiaChi) values
(201, N'Trần Văn An', '1980-05-15', N'Nam', '0981112233', N'1A Đường Số 1, TP.HCM'),
(202, N'Lê Thị Bình', '1985-11-20', N'Nữ', '0982223344', N'2B Đường Số 2, Hà Nội'),
(203, N'Phạm Minh Cường', '1975-02-28', N'Nam', '0983334455', N'3C Đường Số 3, Đà Nẵng'),
(204, N'Đỗ Hải Đăng', '1990-07-01', N'Nam', '0984445566', N'4D Đường Số 4, Cần Thơ'), 
(205, N'Hoàng Yến', '1992-09-10', N'Nữ', '0985556677', N'5E Đường Số 5, TP.HCM'); 
go

-- 3. Chèn dữ liệu cho bảng HoSoBoSungCuaTaiXe
insert into HoSoBoSungCuaTaiXe (MaTaiXe, SoCMND, NgayCapCMND, NoiCapCMND) values
(201, '123456789012', '2010-01-01', N'Công an TP.HCM'),
(202, '987654321098', '2012-03-15', N'Công an Hà Nội'), 
(203, '456789123456', '2005-06-20', N'Công an Đà Nẵng'),
(204, '321987654321', '2015-04-10', N'Công an Cần Thơ'),
(205, '654321987654', '2018-08-05', N'Công an TP.HCM');

-- 4. Chèn dữ liệu cho bảng PhuongTien
insert into PhuongTien (BienSo, LoaiPhuongTien, HangSanXuat, NamSanXuat) values
('51F-123.45', N'Xe tải thùng', N'Hino', 2018),
('29H-678.90', N'Xe container', N'Hyundai', 2019),
('43C-111.22', N'Xe tải đông lạnh', N'Fuso', 2017),
('65B-333.44', N'Xe khách 45 chỗ', N'Thaco', 2020),
('51D-555.66', N'Xe tải ben', N'Isuzu', 2016);
go

-- 5. Chèn dữ liệu cho bảng LichTrinhVanChuyen
insert into LichTrinhVanChuyen (MaLichTrinh, MaKhachHang, BienSoPhuongTien, KhoiLuongHang, TrangThai, GhiChu) values
(301, 101, '51F-123.45', N'2.5 tấn', N'Đã hoàn thành', N'Giao hàng nhanh chóng'),
(302, 102, '29H-678.90', N'1.0 tấn', N'Đang thực hiện', NULL), 
(303, 103, '51F-123.45', N'4.0 tấn', N'Đã hoàn thành', N'Đúng giờ'), 
(304, 104, '65B-333.44', NULL, N'Đã lên lịch', NULL), 
(305, 105, '51D-555.66', N'8.0 tấn', N'Đã hoàn thành', N'Thuận lợi'); 
go

-- 6. Chèn dữ liệu cho bảng PhanCongTaiXe_LichTrinh
insert into PhanCongTaiXe_LichTrinh (MaLichTrinh, MaTaiXe, VaiTro, NgayBatDau, NgayKetThuc) values
(301, 201, N'Lái chính', '2024-06-21', '2024-06-22'),
(302, 202, N'Lái chính', '2024-06-23', NULL),
(303, 201, N'Lái chính', '2024-06-22', '2024-06-23'),
(304, 204, N'Lái chính', '2024-06-24', '2024-06-24'),
(305, 205, N'Lái chính', '2024-06-24', '2024-06-24');
insert into PhanCongTaiXe_LichTrinh (MaLichTrinh, MaTaiXe, VaiTro, NgayBatDau, NgayKetThuc) values
(301, 203, N'Phụ xe', '2024-06-21', '2024-06-22');
go

-- 7. Chèn dữ liệu cho bảng LichSuBaoDuong
insert into LichSuBaoDuong (MaBaoDuong, BienSo, NgayBaoDuong, ChiPhiBaoDuong, NhaCungCapDV) values
(401, '51F-123.45', '2024-05-10', 1500000, N'Gara ABC'),
(402, '29H-678.90', '2024-04-01', 2500000, N'Cơ sở X'),
(403, '43C-111.22', '2024-06-15', 3000000, N'Trung tâm lạnh'),
(404, '51F-123.45', '2024-06-25', 500000, N'Gara ABC'),
(405, '65B-333.44', '2024-05-20', 2000000, N'Gara XYZ');
go

-- 8. Chèn dữ liệu cho bảng HoaDon
insert into HoaDon (MaHoaDon, MaLichTrinh, TongTien, GhiChu) values
(501, 301, 5000000.0, N'Hoàn tất thanh toán chuyến TP.HCM - HN'),
(502, 303, 2000000.0, N'Khách hàng thanh toán tại Cần Thơ'),
(503, 304, 1500000.0, N'Chờ xác nhận thanh toán'),
(504, 305, 1800000.0, N'Giao dịch tại kho'),
(505, 301, 500000.0,  N'Phát sinh thêm phí cầu đường');
go