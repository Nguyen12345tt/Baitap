-- VD 9: Sửa vd1 -> thủ tục
-- Nguyễn Thành Nguyên - 1871020437
-- Khai báo biến, đặt giá trị cho biến để in ra kết quả
-- B1: Khai báo biến kiểu dữ liệu int
-- B2: Đặt giá trị cho biến
-- B3: In ra kết quả
create proc sp_inketqua_a
as
begin
	declare @a int
	set @a = 10
	print @a
end

-- Sử dụng dùng lệnh exec sp_inketqua_a bôi đoạn lệnh exec sp_inketqua_a ấn f5
exec sp_inketqua_a