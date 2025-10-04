-- Hàm in ra 1 danh sách

create function fn_ids_KhachHang()
returns @t table ( ma int, ten nvarchar(30))
as
begin
	insert into @t 
	select MaKhachHang, TenKhachHang from KHACHHANG
	return
end

select * from fn_ids_KhachHang()