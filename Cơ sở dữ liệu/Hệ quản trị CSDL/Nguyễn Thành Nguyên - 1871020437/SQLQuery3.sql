-- VD 3
-- Nguyễn Thành Nguyên - 1871020437
-- Kiểm tra số chẵn hoặc lẻ
-- B1: Khai báo biến kiểu dữ liệu int
-- B2: Đặt giá trị cho biến, tính toán tổng
-- B3: In ra kết quả
declare @a int
set @a = 10
if @a % 2 = 1
begin
	print N'A là số lẻ'
end
else
begin
	print N'A là số chẵn'
end