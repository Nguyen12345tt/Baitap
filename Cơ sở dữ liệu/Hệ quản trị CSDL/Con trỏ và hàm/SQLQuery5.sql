-- Hàm in ra 1 danh sách

create function fn_ids()
returns @t table ( ma int, ten nvarchar(30))
as
begin
	insert into @t values (1,N'Nguyễn Văn A'), (2, N'Nguyễn Văn B')
	return
end

select * from fn_ids()