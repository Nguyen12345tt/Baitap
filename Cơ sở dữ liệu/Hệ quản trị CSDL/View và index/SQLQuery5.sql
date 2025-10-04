-- index(Chỉ mục) trên bảng khách hàng
create index IDX_khachhang_tenKH on khachhang(tenkhachhang)
select * from KHACHHANG with (index(IDX_khachhang_tenKH)) 
where TenKhachHang like '%BÉ%'

-- VD câu lệnh đánh index
select * from KHACHHANG where DienThoai like '09%' and DiaChi = N'Hà Nội'
-- Tạo index cho câu lệnh trên
create index IDX_Dienthoai_DiaChi_KhachHang
on Khachhang(Dienthoai, diachi)

alter index 