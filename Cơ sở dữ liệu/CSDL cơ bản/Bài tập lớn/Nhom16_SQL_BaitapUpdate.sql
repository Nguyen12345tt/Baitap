-- 1. Cập nhật số điện thoại cho KhachHang -- 
update KhachHang
set SoDienThoai = '0987654321'
where MaKhachHang = 1;
-- 2. Cập nhật số điện thoại cho TaiXe -- 
update TaiXe
set SDT = '0912345678'
where MaTaiXe = 101; 
-- 3. Cập nhật số CMND cho HoSoBoSungCuaTaiXe --
update HoSoBoSungCuaTaiXe
set SoCMND = '123456789012'
where MaTaiXe = 101; 
