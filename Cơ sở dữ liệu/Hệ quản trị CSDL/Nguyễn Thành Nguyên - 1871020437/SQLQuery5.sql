-- VD 5: In ra tổng liên tiếp từ 1 đến 10
-- Nguyễn Thành Nguyên - 1871020437
-- Khai báo biến, cài đặt giá trị cho biến in ra kq
-- B1: Khai báo biến kiểu dữ liệu interger
-- B2: đặt giá trị của biến
-- B3: in ra kết quả
DECLARE @a INT
DECLARE @i INT
DECLARE @TONG INT 
SET @a = 10
SET @i = 1
SET @TONG = 0
WHILE @i <= @a
	BEGIN 
	IF @i > 5
		BREAK
		SET @TONG = @TONG + @i
		SET @i = @i + 1
	END
PRINT @TONG