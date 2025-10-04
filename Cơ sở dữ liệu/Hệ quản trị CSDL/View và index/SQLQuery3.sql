-- Kết nối 2 bảng với nhau
create view view_cthd_vattu
as
	select
		vt.MaVatTu,
		TenVatTu, 
		DonViTinh, 
		GiaMua, 
		SoLuongBan,
		GiaBan
	from CHITIETHOADON ct inner join Vattu vt on ct.MaVatTu = vt.MaVatTu
-- Insert dữ liệu vào view của 1 bảng
-- Chỉ thực hiện được trên view tạo từ 1 bảng (delete, update, insert) (Dữ liệu trên view)
insert into view_cthd_vattu(MaVatTu, TenVatTu, DonViTinh, GiaMua, SoLuongBan, GiaBan)
values (160,N'Cầu thang gỗ',N'Chiếc',100,200,300)

--Xóa cấu trúc view
drop view view_cthd_vattu

-- insert update delete ( Chỉ thực hiện được trên 1 bảng)
delete view_vattu where MaVatTu = 123
update view_vattu set SoLuongTon = 111 where MaVatTu = 110
select * from view_vattu