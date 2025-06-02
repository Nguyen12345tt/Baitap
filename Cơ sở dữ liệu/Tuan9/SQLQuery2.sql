/*
1 số thao tác sửa, xóa với bảng dữ liệu
*/
--VD1: Xp
--VD2: Xóa cột Email trong bảng DOANVIEN --
Alter table DOANVIEN
		drop column Email;
-- VD3: Xóa bảng TINH
Could not drop object 'TINH' because it is referenced by a FOREIGN
--> Xử lý: 