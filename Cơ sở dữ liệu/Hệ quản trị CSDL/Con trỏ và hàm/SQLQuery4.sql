-- Nâng cấp hàm tìm max
-- Tham số truyền a và b là số nguyên
-- Viết hàm tìm số lớn nhất trong a và b

create function fb_max(@a int, @b int)
returns int
as
begin
	declare @max int
	if @a > @b 
	begin
		set @max = @a
	end
	else if @b > @a
	begin
		set @max = @b
	end
	return @max
end
--gọi hàm
print dbo.fb_max (12, 50)

	