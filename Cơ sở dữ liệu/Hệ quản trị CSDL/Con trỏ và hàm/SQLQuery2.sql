-- Nguyễn Thành Nguyên - 1871020437
-- dùng vòng lặp while trong con trỏ
-- để dịch chuyển con trỏ trong các bản ghi (các dòng)
-- B1:
create proc sp_dskhcontro(@makh int)
as
declare contro cursor for
select MaKhachHang, TenKhachHang, DiaChi, DienThoai, Email from KHACHHANG
where MaKhachHang = @makh
-- B2:
open contro
declare @MaKhachHang int, @TenKhachHang nvarchar(30), @DiaChi nvarchar(30), @DienThoai char(10),
@Email nvarchar(100)
-- B3:
fetch contro into @MaKhachHang, @TenKhachHang, @DiaChi, @DienThoai, @Email
-- dùng vòng lặp while để dịch tới các bản ghi bằng @@fetch_status
while @@FETCH_STATUS = 0
begin
	print @MaKhachHang
	print @TenKhachHang
	print @DiaChi
	print @DienThoai 
	print @Email
end
-- B4:
close contro
deallocate contro
--Chạy thủ tục
exec sp_dskhcontro 2