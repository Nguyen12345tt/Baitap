/* 1 số thao tác với bảng dữ liệu: INSERT, UPDATE, DELETE
Chú ý:
	- Giá trị kí tự, ngày cần có nháy đơn bao bọc (VD: 'London')
	- Nếu giá trị có dấu (Unicode) thì cần kí N ở phía trước (VD: N'Hà Nội')
	- Giá trị kiểu ngày tháng năm cần viết theo định dạng yyyy/mm/dd(VD: '2006/12/31')
	- Khóa chính không trùng nhau
	- Khóa ngoại: Giá trị của FK phải tồn tại trong bảng tham chiếu đến
*/
-- VD1: Chèn 3 tỉnh: Hà Nội, Hải Phòng, TP. Hồ Chí Minh vào bảng TINH với 3 mã tỉnh 
Insert into TINH(MaTinh, TenTinh) values (1, N'Hà Nội')
Insert into TINH(MaTinh, TenTinh) values (2, N'Hải Phòng')
Insert into TINH(MaTinh, TenTinh) values (3, N'TP.Hồ Chí Minh')

-- VD2: Chèn thông tin 1 đoàn viên ở Hà Nội và 1 đoàn viên ở Cà Mau. Giải thích
Insert into DOANVIEN(MaDoanVien, HoTen, NgaySinh, QueQuan)
			values (1, N'Đậu Hải Phong', '1990/12/31', N'Hồng Bàng', 2)
Insert into DOANVIEN(MaDoanVien, HoTen, NgaySinh, QueQuan)
			values (2, N'Nguyễn Ngọc Ân', '2000/12/31', N'Hồng Bàng', 5)

-- VD3: Cập nhật cho sinh viên Nguyễn Ngọc Ân có dân tộc Kinh với mã dân tộc là 1
Update DOANVIEN set MaDanToc=1 where HoTen = N'Nguyễn Ngọc Ân'

--> Lỗi khóa ngoại (FK) vì MaDanToc là 2 chưa tồn tại trong bảng DANTOC
--> Sửa như sau: Chèn 1 bản ghi Dân tộc Kinh có mã là 1 trong bảng DANTOC
Insert into DANTOC(MaDanToc, TenDanToc) values(1, N'Kinh')
--> Cập nhật lại
Update DOANVIEN set MaDanToc where HoTen = N'Nguyễn Ngọc Ân'