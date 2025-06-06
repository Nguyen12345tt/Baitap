# Các hàm tính toán cơ bản
def tinh_so_tieu_thu(chi_so_dau, chi_so_cuoi):
    return chi_so_cuoi - chi_so_dau

def tinh_tien_dien(so_tieu_thu):
    """Tính tiền điện (ví dụ với bảng giá đơn giản)."""
    # Đây là bảng giá điện bậc thang ví dụ
    if so_tieu_thu <= 50:
        return so_tieu_thu * 1728
    elif 50 < so_tieu_thu <= 100:
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
    """Tính tiền nước (ví dụ với bảng giá đơn giản)."""
    # Đây là bảng giá nước bậc thang ví dụ
    if so_tieu_thu <= 10:
        return so_tieu_thu * 5973
    elif so_tieu_thu <= 20:
        return 10 * 5973 + (so_tieu_thu - 10) * 7052
    else:
        return 10 * 5973 + 10 * 7052 + (so_tieu_thu - 20) * 8699

# Hàm hỗ trợ hiển thị danh sách hóa đơn
def hien_thi_danh_sach_hoa_don(danh_sach):
    """Hàm hỗ trợ hiển thị danh sách hóa đơn chi tiết."""
    if not danh_sach:
        print("Danh sách hóa đơn rỗng.")
        return
    for i, hd in enumerate(danh_sach):
        print(f"--- Hóa đơn số {i+1} ---")
        for key, value in hd.items():
            # Định dạng lại tên key để hiển thị đẹp hơn
            display_key = key.replace('_', ' ').title()
            if 'tien' in key or 'tong' in key:
                print(f"{display_key}: {value:,} VNĐ") # Định dạng tiền tệ
            else:
                print(f"{display_key}: {value}")

def them_hoa_don(data):
    print("\n--- Thêm Hóa Đơn ---")
    try:
        nam = int(input("Năm: "))
        thang = int(input("Tháng: "))
        if not (1 <= thang <= 12):
            print("Lỗi: Tháng phải là số nguyên từ 1 đến 12.")
            return
        if nam <= 0:
            print("Lỗi: Năm phải là số dương.")
            return
    except ValueError:
        print("Lỗi: Năm và Tháng phải là số nguyên. Vui lòng thử lại.")
        return

    ten_khach_hang = input("Tên khách hàng: ")
    if not ten_khach_hang.strip():
        print("Lỗi: Tên khách hàng không được để trống.")
        return

    try:
        chi_so_dau_dien = int(input("Chỉ số công tơ điện đầu: "))
        chi_so_cuoi_dien = int(input("Chỉ số công tơ điện cuối: "))
        if chi_so_dau_dien < 0 or chi_so_cuoi_dien < 0:
            print("Lỗi: Chỉ số công tơ không thể là số âm.")
            return
        if chi_so_dau_dien > chi_so_cuoi_dien:
            print("Lỗi: Chỉ số cuối điện không thể nhỏ hơn chỉ số đầu điện.")
            return
    except ValueError:
        print("Lỗi: Chỉ số công tơ điện phải là số nguyên. Vui lòng thử lại.")
        return

    try:
        chi_so_dau_nuoc = int(input("Chỉ số công tơ nước đầu: "))
        chi_so_cuoi_nuoc = int(input("Chỉ số công tơ nước cuối: "))
        if chi_so_dau_nuoc < 0 or chi_so_cuoi_nuoc < 0:
            print("Lỗi: Chỉ số công tơ không thể là số âm.")
            return
        if chi_so_dau_nuoc > chi_so_cuoi_nuoc:
            print("Lỗi: Chỉ số cuối nước không thể nhỏ hơn chỉ số đầu nước.")
            return
    except ValueError:
        print("Lỗi: Chỉ số công tơ nước phải là số nguyên. Vui lòng thử lại.")
        return

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
        ds_ky.sort(key=lambda x: (x['nam'], x['thang']))
        for ky in ds_ky:
            print(f"  Năm {ky['nam']}, Tháng {ky['thang']}: Điện = {ky['kw_dien']} kWh, Nước = {ky['m3_nuoc']} m³")

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

        try:
            choice_int = int(choice)
        except ValueError:
            print("Lựa chọn không hợp lệ. Vui lòng nhập một số.")
            continue

        if choice_int == 1:
            them_hoa_don(data)
        elif choice_int == 2:
            hien_thi_thong_tin_tieu_thu_va_chi_phi(data)
        elif choice_int == 3:
            hien_thi_thong_tin_thanh_toan(data)
        elif choice_int == 4:
            hien_thi_lich_su_tieu_thu(data)
        elif choice_int == 0:
            print("Cảm ơn bạn đã sử dụng chương trình!")
            break
        else:
            print("Lựa chọn không hợp lệ. Vui lòng thử lại.")

if __name__ == "__main__":
    main()