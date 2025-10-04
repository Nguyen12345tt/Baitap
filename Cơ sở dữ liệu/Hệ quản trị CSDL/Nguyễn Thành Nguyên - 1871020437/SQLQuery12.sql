/*Bài 1: Tạo thủ tục hiển thị danh sách khách hàng 
• Yêu cầu: Tạo một thủ tục không có tham số, trả về danh sách tất cả khách hàng từ 
bảng KHACHHANG. */
-- B1: Tạo thủ tục không tham số
-- B2: Viết câu lệnh in ra danh sách khách hàng
-- B3: exec tên thủ tục
create proc lietkedskhachhang
as
begin
	select MaKhachHang, 
			TenKhachHang, 
			DiaChi, 
			DienThoai, 
			Email 
	from KHACHHANG
end

exec lietkedskhachhang

