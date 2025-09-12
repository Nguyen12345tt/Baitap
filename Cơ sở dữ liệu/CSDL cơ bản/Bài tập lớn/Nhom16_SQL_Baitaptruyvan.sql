select *
from KhachHang;

select HoTen, NgaySinh
from TaiXe
where GioiTinh = N'Nam' and NgaySinh > '1985-12-31';

select LoaiPhuongTien, count(BienSo) as SoLuong
from PhuongTien
group by LoaiPhuongTien;

select KH.TenKH
from KhachHang KH inner join LichTrinhVanChuyen LTVC on KH.MaKhachHang = LTVC.MaKhachHang inner join HoaDon HD on LTVC.MaLichTrinh = HD.MaLichTrinh
where HD.TongTien > 1000000
group by KH.TenKH;

select PT.LoaiPhuongTien, avg(LSBD.ChiPhiBaoDuong) as ChiPhiBaoDuongTrungBinh
from PhuongTien PT inner join LichSuBaoDuong LSBD on PT.BienSo = LSBD.BienSo
group by PT.LoaiPhuongTien;

select TX.HoTen
from TaiXe TX inner join HoSoBoSungCuaTaiXe HSBS on TX.MaTaiXe = HSBS.MaTaiXe;

select KH.TenKH, sum(HD.TongTien) as TongTienHoaDon
from KhachHang KH inner join LichTrinhVanChuyen LTVC ON KH.MaKhachHang = LTVC.MaKhachHang inner join HoaDon HD ON LTVC.MaLichTrinh = HD.MaLichTrinh
group by KH.TenKH
having sum(HD.TongTien) > 1000000
order by TongTienHoaDon desc;

select PT.BienSo, PT.LoaiPhuongTien, count(LSBD.MaBaoDuong) as SoLanBaoDuong
from PhuongTien PT inner join LichSuBaoDuong LSBD on PT.BienSo = LSBD.BienSo
where year(LSBD.NgayBaoDuong) = 2024
group by PT.BienSo, PT.LoaiPhuongTien
order by SoLanBaoDuong desc;

select BienSo, LoaiPhuongTien, NamSanXuat
from PhuongTien
where NamSanXuat > 2017;

select TX.HoTen
from TaiXe TX inner join PhanCongTaiXe_LichTrinh PCTL on TX.MaTaiXe = PCTL.MaTaiXe
where PCTL.VaiTro = N'Lái chính'
group by TX.HoTen
having count(PCTL.MaLichTrinh) >= 1;