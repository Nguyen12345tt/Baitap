/* NguyenThanhNguyen_SQL_Truyvan.sql
NGÔN NGỮ TRUY VẤN CÓ CẤU TRÚC - SQL
1. DDL - Ngôn ngữ định nghĩa dữ liệu
+ Create(Database,Table)
+ Alter(Database,Table)
+ Drop (Database,Table)

2.Ngôn ngữ thao tác dữ liệu 
+ Insert
+ Update
+ Delete

3. Truy vấn dữ liệu
*/
use DuAn_Mau
go
-- VD1: Hiển thị thông tin tất cả nhân viên
select * -- Lấy cái gì -- 
from NhanVien; -- Từ đâu -- 
-- VD2: Hiển thị Họ tên, phòng ban, tiền lương của tất cả nhân viên -- 
select -- Chiếu -- 
HoTen, PhongBan, Luong 
from NhanVien;
-- VD3: Hiển thị thông tin họ tên, phòng ban, tiền lương (Đổi tên cột lương thành chữ tiền lương) -- 
select HoTen, PhongBan, Luong as --Đổi tên -- 
TienLuong 
from NhanVien;
-- VD4: Hiển thị thông tin nhân viên có tiền lương cao hơn 15000 --
select * 
from NhanVien
where --Chọn (Từ đâu)--
Luong > 15000; 
-- VD4: Hiển thị thông tin nhân viên có tiền lương từ 15000 đến 20000 --
select * 
from NhanVien
where Luong >= 15000 and Luong <= 20000; -- Phép hội --
-- C2:
select * 
from NhanVien
where Luong between 15000 and 20000; -- Từ ... đến ... (between)
-- VD5: Hiển thị thông tin nhân viên ở phòng kế toán và kinh doanh
select * 
from NhanVien
where PhongBan = N'KếToán' or PhongBan = N'KinhDoanh'; -- Phép tuyển --
-- C2:
select * 
from NhanVien
where PhongBan in (N'KếToán', N'KinhDoanh');  -- Cái gì và cái gì
-- VD6: Hiển thị thông tin nhân viên có họ Nguyễn 
select * 
from NhanVien
where HoTen like N'Nguyễn%' -- % Tùy
-- VD7: Hiển thị họ tên, phòng ban, tiền lương của nhân viên có họ tên đệm là Thị   
select HoTen,PhongBan,Luong 
from NhanVien
where HoTen like N'%Thị%' -- % Tùy
-- Bài tập
select * from DuAn
select * from ThamGia
-- VD8. Hiển thị mã những dự án mà có mã nhân viên NV01 tham gia
select MaDA
from ThamGia
where MaNV = N'NV01';
-- VD9. Cho biết dự án có mã DA01 có những mã nhân viên nào tham gia
select MaNV
from ThamGia
where MaDA = N'DA01';
-- VD10. Cho biết mã nhân viên NV04 quản lý dự án nào
select MaNVQuanLy
from DuAn
where MaNVQuanLy  = N'NV04';
-- VD11. Hiển thị mã nhân viên tham gia dự án có số giờ từ 100 -> 180
select MaNV
from ThamGia
where SoGioLam >= 100 and SoGioLam <= 180
-- VD12. Hiển thị mã nhân viên tham gia những dự án có mã là DA01, DA02
select MaNV, MaDA
from ThamGia
where MaDA = N'DA01' or MaDA = N'DA02';
/* Một số câu lệnh gộp nhóm: COUNT(Đếm), SUM(Tổng), AVG(Trung bình), MAX(Lớn nhất), MIN(Nhỏ nhất),... */
-- VD13. Tính tổng số giờ làm của tất cả dự án
select SUM(SoGioLam) as TongSoGio
from ThamGia;
-- VD14. Hiển thị số giờ làm việc cao nhất, thấp nhất
select MAX(SoGioLam) as CaoNhat, MIN(SoGioLam) as ThapNhat
from ThamGia;
-- VD15. Tính tổng số giờ làm của dự án DA01
select SUM(SoGioLam) as TongSoGio
from ThamGia
where MaDA = N'DA01';
-- VD16. Tính tổng số giờ làm của nhân viên NV01
select SUM(SoGioLam) as TongSoGio
from ThamGia
where MaNV = N'NV01';
-- VD17. Hiển thị mã nhân viên và số dự án của từng nhân viên
select MaNV, COUNT(MaDA) as SoDuAn
from ThamGia
group by MaNV; -- Gộp những mã nhân viên giống nhau để đếm dự án
-- Chú ý: Khi group by thì trên Select có cột gì thì dưới group by phải có cột đó, trừ cột trong hàm tính toán
-- VD17. Hiển thị mã nhân viên và số dự án của những nhân viên có tham gia từ 2 dự án đổ lên
select MaNV, count(MaDA) as SoDuAn
from ThamGia
group by MaNV
having count(MaDA)>=2; --Having = where nhưng sau group by
-- VD18. Hiển thị mã nhân viên và tổng số giờ làm việc của từng nhân viên
select MaNV, sum(SoGioLam) as TongSoGio
from ThamGia
group by MaNV;
-- VD19. Hiển thị mã nhân viên và tổng số giờ làm việc của từng nhân viên có tổng giờ > 200
select MaNV, sum(SoGioLam) as TongSoGio
from ThamGia
group by MaNV
having sum(SoGioLam)>200;
-- VD20. Cho biết mã dự án, số nhân viên tham gia của từng dự án
select MaDA, count(MaNV) as SoNhanVien
from ThamGia
group by MaDA;
-- VD21. Cho biết mã dự án và số giờ làm lớn nhất, nhỏ nhất của từng dự án
select MaDA, Max(SoGioLam) as SoGioLamLonNhat, Min(SoGioLam) as SoGioLamNhoNhat
from ThamGia
group by MaDA;
-- VD22. Cho biết mã dự án, số nhân viên tham gia của từng dự án có từ 2 nhân viên tham gia
select MaDA, count(MaNV) as SoNhanVien
from ThamGia
group by MaDA
having count(MaNV)>=2;
/* 
Kết nối nhiều bảng
- Khi dữ liệu được lấy từ nhiều bảng khác nhau thì cần được thực hiện kết nối giữa các bảng
- Một số kiểu kết nối: inner join, nature join, left join, right join,... 
*/
-- VD23. Hiển thị thông tin nhân viên và mã dự án, số giờ làm mà nhân viên đó tham gia
select nv.*, MaDA, SoGioLam --nv.* là hiển thị tất cả trong bảng nhân viên
from NhanVien nv inner join ThamGia tg on nv.MaNV = tg.MaNV;
-- VD24. Hiển thị mã dự án, tên dự án, tên nhân viên quản lý
select MaDA, TenDuAn, HoTen
from DuAn DA inner join NhanVien nv on DA.MaNVQuanLy=nv.MaNV;
-- VD25. Hiển thị mã nhân viên, tên nhân viên và số lượng dự án tham gia
select nv.MaNV, HoTen, count(MaDA) as SoDuAn
from NhanVien nv inner join ThamGia tg on nv.MaNV = tg.MaNV
group by nv.MaNV, HoTen;
--VD26. Hiển thị mã nhân viên, tên nhân viên và tổng số giờ làm việc của từng nhân viên
select HoTen, sum(SoGioLam) as TongSoGio
from NhanVien nv inner join ThamGia tg on nv.MaNV = tg.MaNV
group by HoTen;
--VD27. Hiển thị mã nhân viên, tên nhân viên và tổng số giờ làm việc của từng nhân viên có tổng giờ >200
select nv.MaNV, sum(SoGioLam) as TongSoGio
from NhanVien nv inner join ThamGia tg on nv.MaNV = tg.MaNV
group by nv.MaNV, HoTen
having sum(SoGioLam)>200;
--VD28. Cho biết mã dự án, tên dự án số nhân viên tham gia của từng dự án
select da.MaDA, TenDuAn, count(MaNV) as SoNhanVien
from DuAn da inner join ThamGia tg on da.MaDA = tg.MaDA
group by da.MaDA, TenDuAn;
--VD29. Cho biết mã dự án, tên dự án và số giờ làm lớn nhất, nhỏ nhất của từng dự án
select da.MaDA,TenDuAn, Max(SoGioLam) as SoGioLamLonNhat, Min(SoGioLam) as SoGioLamNhoNhat
from DuAn da inner join ThamGia tg on da.MaDA = tg.MaDA
group by da.MaDA, TenDuAn;
--VD30. Cho biết mã dự án, tên dự án số nhân viên tham gia của từng dự án có từ 2 nhân viên tham gia
select da.MaDA, TenDuAn, count(MaNV) as SoNhanVien
from DuAn da inner join ThamGia tg on da.MaDa = tg.MaDA
group by da.MaDA, TenDuAn
having count(MaNV)>=2;

select da.TenDuAn, nv.HoTen
from DuAn da inner join NhanVien nv on da.MaNVQuanLy = nv.MaNV;

select NV.HoTen, avg(TG.SoGioLam) as TongSoGioTrungBinhTrenMoiDuAn
from NhanVien nv inner join ThamGia tg on NV.MaNV = TG.MaNV
group by NV.MaNV, NV.HoTen
order by TongSoGioTrungBinhTrenMoiDuAn desc; --order by: Sắp xếp, desc = descending(giảm dần), asc = ascending(tăng dần)

select nv.HoTen, nv.MaNV, count(tg.MaDA) as SoDuAnThamGia
from NhanVien nv inner join ThamGia tg on NV.MaNV = TG.MaNV
group by nv.HoTen, nv.MaNV
having count (MaDA)>=2;

select nv.HoTen, nv.MaNV, nv.ChucVu, nv.Luong
from NhanVien nv left join ThamGia tg on NV.MaNV = TG.MaNV
where TG.MaNV is NULL; -- is NULL là rỗng

select NV.HoTen, count(TG.MaDA) as TongSoDuAnThamGia
from NhanVien nv inner join ThamGia tg ON NV.MaNV = TG.MaNV
group by NV.MaNV, NV.HoTen;

select TG.MaDA, count(TG.MaNV) as SoNhanVienThamGia
from ThamGia TG
group by TG.MaDA
having count(TG.MaNV) > 1;

select NV.MaNV, HoTen, PhongBan,Luong
from NhanVien nv
where PhongBan = N'KinhDoanh' and Luong > 15000;

select DA.TenDuAn
from NhanVien nv inner join ThamGia tg on NV.MaNV = TG.MaNV inner join DuAn da on TG.MaDA = DA.MaDA
where NV.HoTen = N'Lê Hồng Cường';

select NV.HoTen, DA.TenDuAn
from NhanVien nv inner join ThamGia tg on NV.MaNV = TG.MaNV inner join DuAn da on TG.MaDA = DA.MaDA
where TG.SoGioLam > 100;

select DA.TenDuAn, sum(TG.SoGioLam) as TongSoGioLam
from DuAn da inner join ThamGia tg on DA.MaDA = TG.MaDA
group by DA.MaDA, DA.TenDuAn
order by TongSoGioLam desc;

select PhongBan, count(PhongBan) as SoNVTrongMoiPhong
from NhanVien
group by PhongBan;