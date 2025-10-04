-- VD 10: Thủ tục kiểm tra số chẵn lẻ
-- Nguyễn Thành Nguyên - 1871020437
-- Kiểm tra số chẵn hoặc lẻ
-- B1: Khai báo biến kiểu dữ liệu int
-- B2: Đặt giá trị cho biến, tính toán tổng
-- B3: In ra kết quả
create proc sp_kiemtrachanle(@a int)
as
begin
if @a % 2 = 1
	print N'A là số lẻ'
else
	print N'A là số chẵn'
end

--Chạy lệnh
exec sp_kiemtrachanle 102