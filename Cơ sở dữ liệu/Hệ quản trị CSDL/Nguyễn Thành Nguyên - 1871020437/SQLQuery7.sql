select * from VATTU
/* Ví dụ 7: Khai báo biến bảng và nhập dữ liệu cho biến 
Nhập dữ liệu cho biến
Tên sinh viên: Nguyễn Thành Nguyên
Mã sinh viên: 1871020437
B1: Khai báo biến T kiểu dữ liệu bảng
B2: Nhập giá trị vào cho biến
*/
declare @t table (mavt int, TenVT nvarchar(50), DVT nvarchar(50), SLT int)
insert into @t (mavt,TenVT,DVT,SLT) 
select MaVatTu, TenVatTu, DonViTinh, SoLuongTon from VatTu
select * from @t