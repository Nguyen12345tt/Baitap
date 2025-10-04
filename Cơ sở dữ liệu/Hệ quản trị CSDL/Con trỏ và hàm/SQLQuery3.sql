-- Viết hàm dựa trên cú pháp
-- yêu cầu hàm tính tổng 2 số nguyên a và b được truyền vào
create function fn_tinhtong(@a int, @b int)
returns int
as
begin
	declare @tong int
	set @tong = @a + @b
	return @tong
end
-- Gọi hàm
print dbo.fn_tinhtong(12,11)