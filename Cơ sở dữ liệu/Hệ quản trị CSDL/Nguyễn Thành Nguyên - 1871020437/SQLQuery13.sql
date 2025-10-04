/* Bài 2: Tạo thủ tục với tham số để tìm kiếm vật tư theo mã 
• Yêu cầu: Tạo thủ tục nhận tham số MaVatTu và trả về thông tin vật tư tương ứng. 
*/

-- B1: Tạo thủ tục với tham số mavt kiểu int
-- B2: Câu lệnh tìm thông tin vật tư theo mã vật tư
-- B3: Đóng gói = f5 và chạy câu lệnh

create procedure sp_int_vattu(@ma int)
as
begin
	select [MaVatTu], 
		[TenVatTu], 
		[DonViTinh], 
		[GiaMua], 
		[SoLuongTon]
	from VATTU
	where MaVatTu = @MA
end
exec sp_int_vattu 101