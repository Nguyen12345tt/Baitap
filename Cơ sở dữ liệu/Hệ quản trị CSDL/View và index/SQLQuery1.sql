--Tạo 1 view trên 1 bảng với bảng vật tư
create view view_vattu
as
	select 
		MaVatTu, 
		TenVatTu, 
		DonViTinh, 
		GiaMua, 
		SoLuongTon
	from vattu
-- Câu lệnh sử dụng view (Tất cả các bảng)
select *
from view_vattu
-- Câu lệnh sử dụng view (Tùy số bảng)
select MaVatTu
from view_vattu
-- Câu lệnh chèn
insert into view_vattu 
	(MaVatTu, TenVatTu,DonViTinh, GiaMua, SoLuongTon)
values 
	(123,N'Cửa cuốn', N'Bộ', 2000000, 200),
	(321,N'Thang cuốn', N'Bộ', 2000000000, 100)
