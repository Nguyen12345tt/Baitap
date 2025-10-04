/* Ví dụ 6: Khai báo biến bảng và nhập dữ liệu cho biến 
Nhập dữ liệu cho biến
Tên sinh viên: Nguyễn Thành Nguyên
Mã sinh viên: 1871020437
B1: Khai báo biến T kiểu dữ liệu bảng
B2: Nhập giá trị vào cho biến
*/
declare @t table (mavt int, TenVT nvarchar(10), DVT nvarchar(30), SLT int)
insert into @t (mavt,TenVT,DVT,SLT) values (1,N'Thang cuốn', N'Chiếc', 100)
select * from @t