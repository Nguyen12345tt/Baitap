-- VD 4: In ra 10 dòng từ 1 -> 10
-- Nguyễn Thành Nguyên - 1871020437
-- Khai báo biến, đặt giá trị cho biến để in ra kết quả
-- B1: Khai báo biến kiểu dữ liệu int
-- B2: Đặt giá trị cho biến
-- B3: In ra kết quả
declare @a int
declare @i int
set @a = 10
set @i = 1
while @i <= @a
	begin
		print @i
		set @i = @i + 1
	end