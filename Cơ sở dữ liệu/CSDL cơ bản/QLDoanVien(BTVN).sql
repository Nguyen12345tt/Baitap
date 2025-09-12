----------------------------------------------------------------------
-- 1. Chèn >=5 bản ghi cho mỗi bảng trong CSDL QLDOANVIEN đã cài trên lớp
----------------------------------------------------------------------

-- Chèn dữ liệu vào bảng TINH
insert into TINH (MaTinh, TenTinh) values
(1, N'Hà Nội'),
(2, N'Hải Phòng'),
(3, N'TP.Hồ Chí Minh'),
(4, N'Đà Nẵng'),
(5, N'Cà Mau');
go

-- Chèn dữ liệu vào bảng DANTOC
insert into DANTOC (MaDanToc, TenDanToc) values
(1, N'Kinh'),
(2, N'Tày'),
(3, N'Thái'),
(4, N'Mường'),
(5, N'Nùng');
go

-- Chèn dữ liệu vào bảng TONGIAO
insert into TONGIAO (MaTonGiao, TenTonGiao) values 
(1, N'Không'),
(2, N'Phật giáo'),
(3, N'Công giáo'),
(4, N'Tin lành'),
(5, N'Hồi giáo');
GO

-- Chèn dữ liệu vào bảng HOATDONG
insert into HOATDONG (MaHoatDong, TenHoatDong, ThoiGian, DiaDiem) values 
(1, N'Mùa hè xanh', '2025-07-15', N'Bến Tre'),
(2, N'Hiến máu nhân đạo', '2025-06-01', N'Trường Đại học Đại Nam'),
(3, N'Dọn dẹp môi trường', '2025-08-20', N'Công viên Thống Nhất'),
(4, N'Tập huấn kỹ năng mềm', '2025-09-10', N'Trung tâm thanh thiếu niên'),
(5, N'Văn nghệ chào mừng', '2025-05-30', N'Nhà văn hóa');
go

-- Chèn dữ liệu vào bảng DOANVIEN (Tham chiếu TINH, DANTOC, TONGIAO)
insert into DOANVIEN (MaDoanVien, HoTen, NgaySinh, QueQuan, MaTinh, MaDanToc, MaTonGiao) values
(101, N'Ngô Văn Nguyên', '2006-01-15', N'Hồng Bàng', 2, 1, 1), -- Hải Phòng, Kinh, Không
(102, N'Trần Xuân Hưng', '2006-03-20', N'Quận 1', 3, 1, 2), -- TP.HCM, Kinh, Phật giáo
(103, N'Đậu Hải Phong', '1995-07-10', N'Long Xuyên', 1, 1, 1), -- Hà Nội, Kinh, Không
(104, N'Nguyễn Thành Nguyên', '2006-11-25', N'Thủ Đức', 1, 1, 1), -- Hà Nội, Kinh, Không
(105, N'Đặng Khánh Toàn', '2006-04-01', N'Hoàn Kiếm', 1, 4, 1); -- Hà Nội, Mường, Không
go

----------------------------------------------------------------------
-- 2. Viết >= 3 câu lệnh UPDATE cho các bảng trong CSDL QLDOANVIEN
----------------------------------------------------------------------

-- UPDATE 1: Cập nhật quê quán và tỉnh của một đoàn viên
update DOANVIEN
set QueQuan = N'Quận Hải Châu, Đà Nẵng', MaTinh = 4 -- Đà Nẵng
where MaDoanVien = 102;
go

-- UPDATE 2: Cập nhật thời gian và địa điểm của một hoạt động
update HOATDONG
set ThoiGian = '2025-07-20', DiaDiem = N'Khu du lịch sinh thái'
where MaHoatDong = 1; -- Hoạt động 'Mùa hè xanh'
go

-- UPDATE 3: Cập nhật tên dân tộc
update DANTOC
set TenDanToc = N'Thái (Tây Bắc)'
where MaDanToc = 3;
go

----------------------------------------------------------------------
-- 3. Viết >= 3 câu lệnh DELETE cho các bảng trong CSDL QLDOANVIEN
-- QUAN TRỌNG: Khi xóa, đảm bảo xóa bản ghi ở bảng con trước nếu có tham chiếu khóa ngoại.
----------------------------------------------------------------------

-- DELETE 1: Xóa một bản ghi tham gia cụ thể
-- Giả sử đoàn viên 104 không tham gia hoạt động 3 nữa
delete THAMGIA
where MaDoanVien = 104 and  MaHoatDong = 3;
go 

-- DELETE 2: Xóa một hoạt động (MaHoatDong = 4)
-- Hoạt động 4 không có trong bảng THAMGIA theo ví dụ chèn hiện tại, nên có thể xóa trực tiếp.
delete HOATDONG
where MaHoatDong = 4;
go

-- DELETE 3: Xóa một đoàn viên (MaDoanVien = 105)
-- Đoàn viên 105 có tham gia hoạt động 5. Cần xóa bản ghi liên quan trong THAMGIA trước.
delete THAMGIA 
where MaDoanVien = 105; -- Xóa bản ghi tham gia của đoàn viên 105
delete DOANVIEN 
where MaDoanVien = 105; -- Sau đó mới xóa đoàn viên
go

