-- Nguyễn Thành Nguyên - 1871020437
-- Tạo con trỏ cho bảng KhachHang

-- Bước 1: Khai báo con trỏ
declare contro cursor for select MaKhachHang from KHACHHANG
-- Bước 2: Mở con trỏ, khai báo biến chứa các dữ liệu khi con trỏ thực hiện
open contro
declare @ma varchar(10)
-- Bước 3: Dùng con trỏ
fetch contro into @ma
print @Ma
-- Bước 4: Đóng con trỏ
close contro
-- Bước 5: Giải phóng ô nhớ chứa con trỏ
deallocate contro