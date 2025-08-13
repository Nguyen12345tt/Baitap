def tinh_chu_vi_dien_tich_hcn(chieu_dai, chieu_rong):
    chu_vi = 2 * (chieu_dai + chieu_rong)
    dien_tich = chieu_dai * chieu_rong
    return chu_vi, dien_tich

# Nhập chiều dài và chiều rộng từ người dùng
chieu_dai_str = input("Nhập chiều dài hình chữ nhật: ")
chieu_rong_str = input("Nhập chiều rộng hình chữ nhật: ")

# Cố gắng chuyển đổi sang số (có thể gây lỗi nếu không phải là số)
dai = float(chieu_dai_str)
rong = float(chieu_rong_str)

# Tính toán và in kết quả
chu_vi, dien_tich = tinh_chu_vi_dien_tich_hcn(dai, rong)
print(f"Chu vi hình chữ nhật là: {chu_vi}")
print(f"Diện tích hình chữ nhật là: {dien_tich}")