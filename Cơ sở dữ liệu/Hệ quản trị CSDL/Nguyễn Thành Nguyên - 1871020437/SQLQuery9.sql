-- VD 9: Nâng cấp vd2 thành thủ tục
-- Nguyễn Thành Nguyên - 1871020437
-- Tính giá trị a + b
-- B1: Khai báo biến kiểu dữ liệu int
-- B2: Đặt giá trị cho biến, tính toán tổng
-- B3: In ra kết quả
create proc sp_tinhtongab (@a int, @b int)
as
begin
	declare @tong int
	set @tong= @a + @b 
	print @tong
end

exec dbo.sp_tinhtongab @a = 11, @b =  10