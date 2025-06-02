def hien_thi_thong_tin_tieu_thu_va_chi_phi(data):
    """Hiển thị thông tin chi tiết về lượng tiêu thụ và chi phí của tất cả hóa đơn."""
    print("\n--- Thông Tin Tiêu Thụ và Chi Phí ---")
    if not data:
        print("Không có hóa đơn nào để hiển thị thông tin.")
        return
    for i, hd in enumerate(data):
        print(f"\n--- Hóa đơn số {i+1} ---")
        print(f"Năm: {hd['nam']}, Tháng: {hd['thang']}, Khách hàng: {hd['ten_khach_hang']}")
        print(f"  Điện:")
        print(f"    Chỉ số đầu: {hd['chi_so_dau_dien']}, Chỉ số cuối: {hd['chi_so_cuoi_dien']}")
        print(f"    Số kWh tiêu thụ: {hd['so_kw_dien']}, Thành tiền: {hd['tien_dien']:,} VNĐ")
        print(f"  Nước:")
        print(f"    Chỉ số đầu: {hd['chi_so_dau_nuoc']}, Chỉ số cuối: {hd['chi_so_cuoi_nuoc']}")
        print(f"    Số m³ tiêu thụ: {hd['so_m3_nuoc']}, Thành tiền: {hd['tien_nuoc']:,} VNĐ")
        print(f"  Tổng tiền: {hd['tong_tien']:,} VNĐ")

def hien_thi_thong_tin_thanh_toan(data):
    """Hiển thị thông tin thanh toán của tất cả hóa đơn."""
    print("\n--- Thông Tin Thanh Toán ---")
    if not data:
        print("Không có hóa đơn nào để hiển thị thông tin thanh toán.")
        return
    for i, hd in enumerate(data):
        print(f"\n--- Hóa đơn số {i+1} ---")
        print(f"Năm: {hd['nam']}, Tháng: {hd['thang']}, Khách hàng: {hd['ten_khach_hang']}")
        print(f"  Tổng tiền phải thanh toán: {hd['tong_tien']:,} VNĐ")
        print("  (Chức năng này có thể được mở rộng để thêm hạn thanh toán và phương thức thanh toán)")

def hien_thi_lich_su_tieu_thu(data):
    """Hiển thị lịch sử tiêu thụ điện và nước theo khách hàng (đơn giản)."""
    print("\n--- Lịch Sử Tiêu Thụ (Đơn Giản) ---")
    if not data:
        print("Không có hóa đơn nào để hiển thị lịch sử tiêu thụ.")
        return
    lich_su = {}
    for hd in data:
        ten = hd['ten_khach_hang']
        if ten not in lich_su:
            lich_su[ten] = []
        lich_su[ten].append({
            "nam": hd['nam'],
            "thang": hd['thang'],
            "kw_dien": hd['so_kw_dien'],
            "m3_nuoc": hd['so_m3_nuoc']
        })

    for ten, ds_ky in lich_su.items():
        print(f"\n--- Lịch sử tiêu thụ của khách hàng: {ten} ---")
        for ky in ds_ky:
            print(f"  Năm {ky['nam']}, Tháng {ky['thang']}: Điện = {ky['kw_dien']} kWh, Nước = {ky['m3_nuoc']} m³")

def tinh_so_tieu_thu(chi_so_dau, chi_so_cuoi):
    return chi_so_cuoi - chi_so_dau

def tinh_tien_dien(so_tieu_thu):
    if so_tieu_thu <= 50:
        return so_tieu_thu * 1728
    elif so_tieu_thu <= 100:
        return 50 * 1728 + (so_tieu_thu - 50) * 2074
    elif so_tieu_thu <= 200:
        return 50 * 1728 + 50 * 2074 + (so_tieu_thu - 100) * 2503
    elif so_tieu_thu <= 300:
        return 50 * 1728 + 50 * 2074 + 100 * 2503 + (so_tieu_thu - 200) * 2587
    elif so_tieu_thu <= 400:
        return 50 * 1728 + 50 * 2074 + 100 * 2503 + 100 * 2587 + (so_tieu_thu - 300) * 2834
    else:
        return 50 * 1728 + 50 * 2074 + 100 * 2503 + 100 * 2587 + 100 * 2834 + (so_tieu_thu - 400) * 2927

def tinh_tien_nuoc(so_tieu_thu):
    if so_tieu_thu <= 10:
        return so_tieu_thu * 5973
    elif so_tieu_thu <= 20:
        return 10 * 5973 + (so_tieu_thu - 10) * 7052
    else:
        return 10 * 5973 + 10 * 7052 + (so_tieu_thu - 20) * 8699

def them_hoa_don(data):
    print("\n--- Thêm Hóa Đơn ---")
    nam = int(input("Năm: "))
    thang = int(input("Tháng: "))
    ten_khach_hang = input("Tên khách hàng: ")
    chi_so_dau_dien = int(input("Chỉ số công tơ điện đầu: "))
    chi_so_cuoi_dien = int(input("Chỉ số công tơ điện cuối: "))
    chi_so_dau_nuoc = int(input("Chỉ số công tơ nước đầu: "))
    chi_so_cuoi_nuoc = int(input("Chỉ số công tơ nước cuối: "))

    so_kw_dien = tinh_so_tieu_thu(chi_so_dau_dien, chi_so_cuoi_dien)
    so_m3_nuoc = tinh_so_tieu_thu(chi_so_dau_nuoc, chi_so_cuoi_nuoc)
    tien_dien = tinh_tien_dien(so_kw_dien)
    tien_nuoc = tinh_tien_nuoc(so_m3_nuoc)

    hoa_don_moi = {
        "nam": nam,
        "thang": thang,
        "ten_khach_hang": ten_khach_hang,
        "chi_so_dau_dien": chi_so_dau_dien,
        "chi_so_cuoi_dien": chi_so_cuoi_dien,
        "so_kw_dien": so_kw_dien,
        "tien_dien": tien_dien,
        "chi_so_dau_nuoc": chi_so_dau_nuoc,
        "chi_so_cuoi_nuoc": chi_so_cuoi_nuoc,
        "so_m3_nuoc": so_m3_nuoc,
        "tien_nuoc": tien_nuoc,
        "tong_tien": tien_dien + tien_nuoc
    }
    data.append(hoa_don_moi)
    print("Hóa đơn đã được thêm (chỉ lưu trong phiên làm việc này).")

def main():
    data = []

    while True:
        print("\n--- Quản Lý Hóa Đơn Điện, Nước ---")
        print("1. Thêm hóa đơn")
        print("2. Hiển thị thông tin tiêu thụ và chi phí")
        print("3. Hiển thị thông tin thanh toán")
        print("4. Hiển thị lịch sử tiêu thụ")
        print("0. Thoát")

        choice = input("Chọn chức năng: ")

        if choice == '1':
            them_hoa_don(data)
        elif choice == '2':
            hien_thi_thong_tin_tieu_thu_va_chi_phi(data)
        elif choice == '3':
            hien_thi_thong_tin_thanh_toan(data)
        elif choice == '4':
            hien_thi_lich_su_tieu_thu(data)
        elif choice == '0':
            print("Cảm ơn bạn đã sử dụng chương trình!")
            break
        else:
            print("Lựa chọn không hợp lệ. Vui lòng thử lại.")

if __name__ == "__main__":
    main()