# Nhập điểm số từ người dùng
diem_str = input("Nhập điểm số các môn học của sinh viên (ví dụ: 9,7,9,10,5,6): ")

# Tách chuỗi thành danh sách các chuỗi điểm
ds_diem_str = diem_str.split(",")

# Khởi tạo danh sách để lưu điểm số nguyên
ds_diem_int = []

# Chuyển đổi chuỗi điểm thành số nguyên và thêm vào danh sách
for diem in ds_diem_str:
    diem_so = int(diem.strip())  # strip() để loại bỏ khoảng trắng thừa
    ds_diem_int.append(diem_so)

# In thông tin tương tự như ví dụ mẫu
so_sinh_vien = len(ds_diem_int)
print("Tổng số sinh viên đã nhập điểm:", so_sinh_vien)

# Đếm số sinh viên đạt điểm >= 5
so_sinh_vien_dat = 0
for diem in ds_diem_int:
    if diem >= 5:
        so_sinh_vien_dat = so_sinh_vien_dat + 1
print("Số sinh viên đạt điểm >= 5 là:", so_sinh_vien_dat)

# Tìm điểm thấp nhất
if ds_diem_int:  # Kiểm tra xem danh sách có rỗng không
    diem_thap_nhat = min(ds_diem_int)
    print("Điểm thấp nhất trong lớp là:", diem_thap_nhat)
else:
    print("Không có điểm số nào được nhập để tìm điểm thấp nhất.")

# Tìm điểm cao nhất
if ds_diem_int:  # Kiểm tra xem danh sách có rỗng không
    diem_cao_nhat = max(ds_diem_int)
    print("Điểm cao nhất trong lớp là:", diem_cao_nhat)
else:
    print("Không có điểm số nào được nhập để tìm điểm cao nhất.")

# Thêm một số thao tác chuỗi tương tự ví dụ mẫu (không thực sự liên quan đến bài toán)
chuoi_mau = "Danh sach diem"
print(len(chuoi_mau))
n_dat = so_sinh_vien_dat
print("Số sinh viên đạt là: " + str(n_dat))
print(chuoi_mau.upper())
print(chuoi_mau.lower())
print(chuoi_mau.replace(' ', '_'))
