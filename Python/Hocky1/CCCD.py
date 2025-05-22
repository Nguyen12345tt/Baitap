def xac_dinh_gioi_tinh_ma_tinh(cccd):
    ma_tinh = cccd[:3]
    ky_tu_gioi_tinh = int(cccd[3])

    gioi_tinh = None
    if ky_tu_gioi_tinh == 0 or ky_tu_gioi_tinh == 2:
        gioi_tinh = "Nam"
    elif ky_tu_gioi_tinh == 1 or ky_tu_gioi_tinh == 3:
        gioi_tinh = "Nữ"

    return {"gioi_tinh": gioi_tinh, "ma_tinh": ma_tinh}

# Nhập căn cước công dân từ người dùng
cccd_nhap = input("Nhập vào căn cước công dân: ")

# Phân tích và in kết quả
thong_tin = xac_dinh_gioi_tinh_ma_tinh(cccd_nhap)

if thong_tin:
    print(f"Giới tính: {thong_tin['gioi_tinh']}")
    print(f"Mã tỉnh: {thong_tin['ma_tinh']}")