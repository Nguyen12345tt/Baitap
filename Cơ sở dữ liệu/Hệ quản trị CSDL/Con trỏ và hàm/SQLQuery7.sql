-- ví dụ 8: trả ra một bảng

create function fn_dsKH_diachi(@diachi nvarchar(100))
returns table
as
return (select * from KHACHHANG where DiaChi = @diachi)

select * from dbo.fn_dsKH_diachi(N'Hà Nội')