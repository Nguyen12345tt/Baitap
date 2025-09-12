-- Xóa khách hàng có mã khách hàng là 1
delete from KhachHang
where MaKhachHang = 1;

-- Xóa lịch trình vận chuyển và các dữ liệu liên quan đến mã lịch trình là 101 
delete from PhanCongTaiXe_LichTrinh
where MaLichTrinh = 101;

delete from HoaDon
where MaLichTrinh = 101;

delete from LichTrinhVanChuyen
where MaLichTrinh = 101;

-- 
delete from LichSuBaoDuong
where BienSo = '51F-123.45';

delete from PhuongTien
where BienSo = '51F-123.45';