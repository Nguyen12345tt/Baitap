import json # Import thư viện json để làm việc với định dạng JSON (lưu/tải dữ liệu)
import os   # Import thư viện os để kiểm tra sự tồn tại của file (khi tải dữ liệu)

# --- Các hàm tính toán cơ bản ---
def tinh_so_tieu_thu(chi_so_dau, chi_so_cuoi):
    """
    Tính toán số lượng tiêu thụ (điện hoặc nước) dựa trên chỉ số đầu và cuối.
    Tham số:
        chi_so_dau (int): Chỉ số công tơ ban đầu.
        chi_so_cuoi (int): Chỉ số công tơ cuối cùng.
    Trả về:
        int: Số lượng tiêu thụ.
    """
    return chi_so_cuoi - chi_so_dau

def tinh_tien_dien(so_tieu_thu):
    """
    Tính tiền điện dựa trên số lượng điện tiêu thụ theo bảng giá bậc thang.
    Tham số:
        so_tieu_thu (int): Số kWh điện tiêu thụ.
    Trả về:
        float: Tổng số tiền điện phải trả.
    """
    # Đây là bảng giá điện bậc thang ví dụ (có thể thay đổi theo quy định thực tế)
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
    else: # Nếu tiêu thụ trên 400 kWh
        return 50 * 1728 + 50 * 2074 + 100 * 2503 + 100 * 2587 + 100 * 2834 + (so_tieu_thu - 400) * 2927

def tinh_tien_nuoc(so_tieu_thu):
    """
    Tính tiền nước dựa trên số lượng nước tiêu thụ theo bảng giá bậc thang.
    Tham số:
        so_tieu_thu (int): Số m³ nước tiêu thụ.
    Trả về:
        float: Tổng số tiền nước phải trả.
    """
    # Đây là bảng giá nước bậc thang ví dụ (có thể thay đổi theo quy định thực tế)
    if so_tieu_thu <= 10:
        return so_tieu_thu * 5973
    elif so_tieu_thu <= 20:
        return 10 * 5973 + (so_tieu_thu - 10) * 7052
    else: # Nếu tiêu thụ trên 20 m³
        return 10 * 5973 + 10 * 7052 + (so_tieu_thu - 20) * 8699

# --- Hàm hỗ trợ hiển thị danh sách hóa đơn ---
def hien_thi_danh_sach_hoa_don(danh_sach):
    """
    Hàm hỗ trợ hiển thị danh sách hóa đơn chi tiết ra console.
    Sử dụng để hiển thị toàn bộ hóa đơn hoặc kết quả tìm kiếm/lọc.
    Tham số:
        danh_sach (list): Danh sách các từ điển hóa đơn cần hiển thị.
    """
    if not danh_sach: # Kiểm tra nếu danh sách hóa đơn rỗng
        print("Danh sách hóa đơn rỗng.")
        return
    for i, hd in enumerate(danh_sach): # Duyệt qua từng hóa đơn trong danh sách
        print(f"--- Hóa đơn số {i+1} ---") # In tiêu đề cho từng hóa đơn
        for key, value in hd.items(): # Duyệt qua các cặp khóa-giá trị trong mỗi hóa đơn
            # Định dạng lại tên key (từ snake_case sang Title Case) để hiển thị đẹp hơn
            display_key = key.replace('_', ' ').title()
            if 'tien' in key or 'tong' in key: # Nếu là các trường liên quan đến tiền
                print(f"{display_key}: {value:,} VNĐ") # Định dạng tiền tệ có dấu phẩy và đơn vị VNĐ
            elif 'thanh_toan' in key: # Nếu là trường trạng thái thanh toán
                # Hiển thị "Đã thanh toán" hoặc "Chưa thanh toán" dựa trên giá trị boolean
                print(f"{display_key}: {'Đã thanh toán' if value else 'Chưa thanh toán'}")
            else: # Đối với các trường thông tin khác
                print(f"{display_key}: {value}")

def hien_thi_thong_tin_thanh_toan(data):
    """
    Hiển thị thông tin tổng quan về thanh toán của các hóa đơn.
    Bao gồm Năm, Tháng, Tên khách hàng, Tổng tiền và Trạng thái thanh toán.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Thông Tin Thanh Toán ---")
    if not data: # Kiểm tra nếu không có hóa đơn
        print("Không có hóa đơn nào để hiển thị thông tin thanh toán.")
        return
    for i, hd in enumerate(data): # Duyệt qua từng hóa đơn
        print(f"\n--- Hóa đơn số {i+1} ---")
        print(f"Năm: {hd['nam']}, Tháng: {hd['thang']}, Khách hàng: {hd['ten_khach_hang']}")
        print(f"    Tổng tiền phải thanh toán: {hd['tong_tien']:,} VNĐ")
        # Kiểm tra xem khóa 'da_thanh_toan' có tồn tại không trước khi truy cập
        if 'da_thanh_toan' in hd:
            trang_thai = "Đã thanh toán" if hd['da_thanh_toan'] else "Chưa thanh toán"
            print(f"    Trạng thái: {trang_thai}")
        else: # Xử lý trường hợp hóa đơn cũ không có trường này
            print("    Trạng thái: Không xác định (chưa cập nhật trường 'da_thanh_toan')")
        print("    (Chức năng này có thể được mở rộng để thêm hạn thanh toán và phương thức thanh toán)")

# --- Các chức năng chính ---
def them_hoa_don(data):
    """
    Thêm một hóa đơn điện nước mới vào danh sách dữ liệu.
    Yêu cầu người dùng nhập thông tin và tự động tính toán số tiêu thụ và tiền.
    Bao gồm kiểm tra hợp lệ của dữ liệu nhập vào.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn hiện có.
    """
    print("\n--- Thêm Hóa Đơn ---")
    try: # Bắt lỗi khi người dùng nhập sai định dạng số cho năm/tháng
        nam = int(input("Năm: "))
        thang = int(input("Tháng: "))
        if not (1 <= thang <= 12): # Kiểm tra tháng hợp lệ
            print("Lỗi: Tháng phải là số nguyên từ 1 đến 12.")
            return
        if nam <= 0: # Kiểm tra năm hợp lệ
            print("Lỗi: Năm phải là số dương.")
            return
    except ValueError:
        print("Lỗi: Năm và Tháng phải là số nguyên. Vui lòng thử lại.")
        return

    ten_khach_hang = input("Tên khách hàng: ")
    if not ten_khach_hang.strip(): # Kiểm tra tên khách hàng không rỗng
        print("Lỗi: Tên khách hàng không được để trống.")
        return

    try: # Bắt lỗi khi người dùng nhập sai định dạng số cho chỉ số điện
        chi_so_dau_dien = int(input("Chỉ số công tơ điện đầu: "))
        chi_so_cuoi_dien = int(input("Chỉ số công tơ điện cuối: "))
        if chi_so_dau_dien < 0 or chi_so_cuoi_dien < 0: # Kiểm tra chỉ số không âm
            print("Lỗi: Chỉ số công tơ không thể là số âm.")
            return
        if chi_so_dau_dien > chi_so_cuoi_dien: # Kiểm tra chỉ số cuối lớn hơn chỉ số đầu
            print("Lỗi: Chỉ số cuối điện không thể nhỏ hơn chỉ số đầu điện.")
            return
    except ValueError:
        print("Lỗi: Chỉ số công tơ điện phải là số nguyên. Vui lòng thử lại.")
        return

    try: # Bắt lỗi khi người dùng nhập sai định dạng số cho chỉ số nước
        chi_so_dau_nuoc = int(input("Chỉ số công tơ nước đầu: "))
        chi_so_cuoi_nuoc = int(input("Chỉ số công tơ nước cuối: "))
        if chi_so_dau_nuoc < 0 or chi_so_cuoi_nuoc < 0: # Kiểm tra chỉ số không âm
            print("Lỗi: Chỉ số công tơ không thể là số âm.")
            return
        if chi_so_dau_nuoc > chi_so_cuoi_nuoc: # Kiểm tra chỉ số cuối lớn hơn chỉ số đầu
            print("Lỗi: Chỉ số cuối nước không thể nhỏ hơn chỉ số đầu nước.")
            return
    except ValueError:
        print("Lỗi: Chỉ số công tơ nước phải là số nguyên. Vui lòng thử lại.")
        return

    # Tính toán số lượng tiêu thụ và tiền tự động
    so_kw_dien = tinh_so_tieu_thu(chi_so_dau_dien, chi_so_cuoi_dien)
    so_m3_nuoc = tinh_so_tieu_thu(chi_so_dau_nuoc, chi_so_cuoi_nuoc)
    tien_dien = tinh_tien_dien(so_kw_dien)
    tien_nuoc = tinh_tien_nuoc(so_m3_nuoc)

    # Tạo một từ điển mới chứa thông tin hóa đơn
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
        "tong_tien": tien_dien + tien_nuoc, # Tổng tiền điện và nước
        "da_thanh_toan": False # Mặc định là chưa thanh toán khi mới thêm
    }
    data.append(hoa_don_moi) # Thêm hóa đơn mới vào danh sách dữ liệu
    print("Hóa đơn đã được thêm (chỉ lưu trong phiên làm việc này).")

def hien_thi_thong_tin_tieu_thu_va_chi_phi(data):
    """
    Hiển thị thông tin chi tiết về lượng tiêu thụ điện/nước và chi phí
    cho tất cả hóa đơn trong danh sách.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Thông Tin Tiêu Thụ và Chi Phí ---")
    if not data: # Kiểm tra nếu danh sách hóa đơn rỗng
        print("Không có hóa đơn nào để hiển thị thông tin.")
        return
    for i, hd in enumerate(data): # Duyệt qua từng hóa đơn
        print(f"\n--- Hóa đơn số {i+1} ---")
        print(f"Năm: {hd['nam']}, Tháng: {hd['thang']}, Khách hàng: {hd['ten_khach_hang']}")
        print(f"    Điện:")
        print(f"      Chỉ số đầu: {hd['chi_so_dau_dien']}, Chỉ số cuối: {hd['chi_so_cuoi_dien']}")
        print(f"      Số kWh tiêu thụ: {hd['so_kw_dien']}, Thành tiền: {hd['tien_dien']:,} VNĐ")
        print(f"    Nước:")
        print(f"      Chỉ số đầu: {hd['chi_so_dau_nuoc']}, Chỉ số cuối: {hd['chi_so_cuoi_nuoc']}")
        print(f"      Số m³ tiêu thụ: {hd['so_m3_nuoc']}, Thành tiền: {hd['tien_nuoc']:,} VNĐ")
        print(f"    Tổng tiền: {hd['tong_tien']:,} VNĐ")
        # Thêm hiển thị trạng thái thanh toán nếu có trường này trong hóa đơn
        if 'da_thanh_toan' in hd:
            print(f"    Trạng thái thanh toán: {'Đã thanh toán' if hd['da_thanh_toan'] else 'Chưa thanh toán'}")

def sua_hoa_don(data):
    """
    Sửa thông tin của một hóa đơn đã tồn tại trong danh sách.
    Người dùng chọn hóa đơn theo số thứ tự và nhập thông tin mới.
    Các giá trị tính toán (tiêu thụ, tiền) sẽ được cập nhật lại.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Sửa Hóa Đơn ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn để sửa.")
        return
    hien_thi_danh_sach_hoa_don(data) # Hiển thị danh sách để người dùng chọn
    try: # Bắt lỗi nhập số thứ tự hóa đơn
        idx = int(input("Nhập số hóa đơn muốn sửa (ví dụ 1, 2, ...): ")) - 1 # Chuyển đổi sang index 0-based
        if not (0 <= idx < len(data)): # Kiểm tra index hợp lệ
            print("Số hóa đơn không hợp lệ.")
            return
    except ValueError:
        print("Đầu vào không hợp lệ. Vui lòng nhập một số.")
        return

    hd = data[idx] # Lấy hóa đơn cần sửa
    print(f"Đang sửa hóa đơn số {idx+1} của khách hàng: {hd['ten_khach_hang']}")

    # Cho phép người dùng nhập thông tin mới. Nếu để trống, giữ nguyên giá trị cũ.
    new_ten = input(f"Tên khách hàng mới (hiện tại: {hd['ten_khach_hang']}): ")
    if new_ten.strip(): # Nếu người dùng nhập tên mới
        hd['ten_khach_hang'] = new_ten

    try: # Bắt lỗi khi nhập chỉ số công tơ mới
        # Sửa chỉ số điện
        new_csd_dien = input(f"Chỉ số điện đầu mới (hiện tại: {hd['chi_so_dau_dien']}): ")
        if new_csd_dien.strip():
            new_csd_dien = int(new_csd_dien)
            if new_csd_dien < 0:
                print("Lỗi: Chỉ số không thể âm. Không sửa chỉ số điện đầu.")
            else:
                hd['chi_so_dau_dien'] = new_csd_dien

        new_csc_dien = input(f"Chỉ số điện cuối mới (hiện tại: {hd['chi_so_cuoi_dien']}): ")
        if new_csc_dien.strip():
            new_csc_dien = int(new_csc_dien)
            if new_csc_dien < 0:
                print("Lỗi: Chỉ số không thể âm. Không sửa chỉ số điện cuối.")
            elif new_csc_dien < hd['chi_so_dau_dien']: # Kiểm tra logic chỉ số cuối > chỉ số đầu
                print("Lỗi: Chỉ số cuối không thể nhỏ hơn chỉ số đầu. Không sửa chỉ số điện cuối.")
            else:
                hd['chi_so_cuoi_dien'] = new_csc_dien

        # Cập nhật các giá trị tính toán cho điện sau khi sửa chỉ số
        hd['so_kw_dien'] = tinh_so_tieu_thu(hd['chi_so_dau_dien'], hd['chi_so_cuoi_dien'])
        hd['tien_dien'] = tinh_tien_dien(hd['so_kw_dien'])

        # Tương tự cho nước
        new_csd_nuoc = input(f"Chỉ số nước đầu mới (hiện tại: {hd['chi_so_dau_nuoc']}): ")
        if new_csd_nuoc.strip():
            new_csd_nuoc = int(new_csd_nuoc)
            if new_csd_nuoc < 0:
                print("Lỗi: Chỉ số không thể âm. Không sửa chỉ số nước đầu.")
            else:
                hd['chi_so_dau_nuoc'] = new_csd_nuoc

        new_csc_nuoc = input(f"Chỉ số nước cuối mới (hiện tại: {hd['chi_so_cuoi_nuoc']}): ")
        if new_csc_nuoc.strip():
            new_csc_nuoc = int(new_csc_nuoc)
            if new_csc_nuoc < 0:
                print("Lỗi: Chỉ số không thể âm. Không sửa chỉ số nước cuối.")
            elif new_csc_nuoc < hd['chi_so_dau_nuoc']: # Kiểm tra logic chỉ số cuối > chỉ số đầu
                print("Lỗi: Chỉ số cuối không thể nhỏ hơn chỉ số đầu. Không sửa chỉ số nước cuối.")
            else:
                hd['chi_so_cuoi_nuoc'] = new_csc_nuoc

        # Cập nhật các giá trị tính toán cho nước sau khi sửa chỉ số
        hd['so_m3_nuoc'] = tinh_so_tieu_thu(hd['chi_so_dau_nuoc'], hd['chi_so_cuoi_nuoc'])
        hd['tien_nuoc'] = tinh_tien_nuoc(hd['so_m3_nuoc'])

        # Cập nhật tổng tiền
        hd['tong_tien'] = hd['tien_dien'] + hd['tien_nuoc']
        print("Hóa đơn đã được cập nhật.")

    except ValueError:
        print("Đầu vào chỉ số không hợp lệ. Vui lòng nhập số nguyên.")

def xoa_hoa_don(data):
    """
    Xóa một hóa đơn khỏi danh sách dữ liệu.
    Người dùng chọn hóa đơn theo số thứ tự.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Xóa Hóa Đơn ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn để xóa.")
        return
    hien_thi_danh_sach_hoa_don(data) # Hiển thị danh sách để người dùng chọn
    try: # Bắt lỗi nhập số thứ tự hóa đơn
        idx = int(input("Nhập số hóa đơn muốn xóa (ví dụ 1, 2, ...): ")) - 1 # Chuyển đổi sang index 0-based
        if not (0 <= idx < len(data)): # Kiểm tra index hợp lệ
            print("Số hóa đơn không hợp lệ.")
            return
        deleted_hd = data.pop(idx) # Xóa hóa đơn khỏi danh sách và lấy về hóa đơn đã xóa
        print(f"Đã xóa hóa đơn số {idx+1} của khách hàng {deleted_hd['ten_khach_hang']}.")
    except ValueError:
        print("Đầu vào không hợp lệ. Vui lòng nhập một số.")

def tim_kiem_hoa_don_theo_ten(data):
    """
    Tìm kiếm hóa đơn theo tên khách hàng (tìm kiếm một phần và không phân biệt chữ hoa/thường).
    Hiển thị các hóa đơn khớp tìm được.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Tìm Kiếm Hóa Đơn theo Tên Khách Hàng ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn để tìm kiếm.")
        return
    ten_can_tim = input("Nhập tên khách hàng muốn tìm: ").strip().lower() # Lấy tên và chuẩn hóa (bỏ khoảng trắng, chữ thường)
    # Lọc danh sách hóa đơn dựa trên việc tên khách hàng có chứa chuỗi tìm kiếm (không phân biệt chữ hoa/thường)
    ket_qua = [hd for hd in data if ten_can_tim in hd['ten_khach_hang'].lower()]
    if ket_qua: # Nếu có kết quả
        print("Kết quả tìm kiếm:")
        hien_thi_danh_sach_hoa_don(ket_qua) # Hiển thị các hóa đơn tìm được
    else: # Nếu không tìm thấy
        print(f"Không tìm thấy hóa đơn nào của khách hàng '{ten_can_tim}'.")

def tim_kiem_hoa_don_theo_thang_nam(data):
    """
    Tìm kiếm hóa đơn theo tháng và/hoặc năm.
    Người dùng có thể bỏ qua năm hoặc tháng để tìm kiếm rộng hơn.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Tìm Kiếm Hóa Đơn theo Tháng/Năm ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn để tìm kiếm.")
        return
    try: # Bắt lỗi nhập số cho năm/tháng
        # Lấy năm cần tìm. Nếu người dùng nhấn Enter, gán 0 (để bỏ qua tiêu chí này)
        nam_can_tim = int(input("Nhập năm muốn tìm (bỏ qua nếu không muốn tìm theo năm): ") or 0)
        # Lấy tháng cần tìm. Nếu người dùng nhấn Enter, gán 0 (để bỏ qua tiêu chí này)
        thang_can_tim = int(input("Nhập tháng muốn tìm (bỏ qua nếu không muốn tìm theo tháng): ") or 0)
    except ValueError:
        print("Đầu vào không hợp lệ. Vui lòng nhập số.")
        return

    ket_qua = [] # Danh sách lưu trữ kết quả tìm kiếm
    for hd in data: # Duyệt qua từng hóa đơn
        # Điều kiện khớp năm: Nếu nam_can_tim là 0 HOẶC năm của hóa đơn khớp
        match_nam = (nam_can_tim == 0) or (hd['nam'] == nam_can_tim)
        # Điều kiện khớp tháng: Nếu thang_can_tim là 0 HOẶC tháng của hóa đơn khớp
        match_thang = (thang_can_tim == 0) or (hd['thang'] == thang_can_tim)
        if match_nam and match_thang: # Nếu cả năm và tháng đều khớp
            ket_qua.append(hd) # Thêm hóa đơn vào kết quả

    if ket_qua: # Nếu có kết quả
        print("Kết quả tìm kiếm:")
        hien_thi_danh_sach_hoa_don(ket_qua) # Hiển thị các hóa đơn tìm được
    else: # Nếu không tìm thấy
        # In thông báo cụ thể dựa trên tiêu chí tìm kiếm
        print(f"Không tìm thấy hóa đơn nào trong năm {nam_can_tim if nam_can_tim != 0 else 'bất kỳ'} tháng {thang_can_tim if thang_can_tim != 0 else 'bất kỳ'}.")

def luu_du_lieu(data, filename="hoa_don.json"):
    """
    Lưu danh sách hóa đơn vào một file JSON.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn cần lưu.
        filename (str): Tên file JSON để lưu (mặc định là "hoa_don.json").
    """
    try:
        # Mở file ở chế độ ghi ('w') với mã hóa UTF-8
        with open(filename, 'w', encoding='utf-8') as f:
            # Sử dụng json.dump để ghi dữ liệu từ điển/list vào file.
            # indent=4 để định dạng JSON dễ đọc, ensure_ascii=False để hỗ trợ tiếng Việt.
            json.dump(data, f, indent=4, ensure_ascii=False)
        print(f"Dữ liệu đã được lưu vào file '{filename}'.")
    except Exception as e: # Bắt bất kỳ lỗi nào trong quá trình ghi file
        print(f"Lỗi khi lưu dữ liệu: {e}")

def tai_du_lieu(filename="hoa_don.json"):
    """
    Tải danh sách hóa đơn từ một file JSON.
    Tham số:
        filename (str): Tên file JSON để tải (mặc định là "hoa_don.json").
    Trả về:
        list: Danh sách các từ điển hóa đơn đã tải hoặc một danh sách rỗng nếu có lỗi/file không tồn tại.
    """
    if os.path.exists(filename): # Kiểm tra xem file có tồn tại không
        try:
            # Mở file ở chế độ đọc ('r') với mã hóa UTF-8
            with open(filename, 'r', encoding='utf-8') as f:
                data = json.load(f) # Tải dữ liệu JSON từ file
            print(f"Dữ liệu đã được tải từ file '{filename}'.")
            return data
        except json.JSONDecodeError: # Bắt lỗi nếu file JSON không hợp lệ
            print(f"Lỗi: File '{filename}' không phải là định dạng JSON hợp lệ. Bắt đầu với dữ liệu trống.")
            return []
        except Exception as e: # Bắt bất kỳ lỗi nào khác trong quá trình đọc file
            print(f"Lỗi khi tải dữ liệu: {e}")
            return []
    else: # Nếu file không tồn tại
        print(f"File '{filename}' không tồn tại. Bắt đầu với dữ liệu trống.")
        return []

def thong_ke_tong_tien_dien(data):
    """
    Thống kê tổng tiền điện theo từng tháng/năm có hóa đơn.
    Hiển thị tổng tiền điện cho mỗi kỳ (tháng/năm).
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Thống Kê Tổng Tiền Điện theo Tháng/Năm ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có dữ liệu để thống kê.")
        return
    stats = {} # Từ điển để lưu tổng tiền điện theo kỳ (tháng/năm)
    for hd in data: # Duyệt qua từng hóa đơn
        key = f"{hd['thang']}/{hd['nam']}" # Tạo khóa dạng "tháng/năm"
        if key not in stats: # Nếu kỳ này chưa có trong thống kê
            stats[key] = 0 # Khởi tạo tổng tiền cho kỳ này
        stats[key] += hd['tien_dien'] # Cộng dồn tiền điện vào kỳ tương ứng
    
    # Sắp xếp và in kết quả
    for ky, tong_tien in sorted(stats.items()):
        print(f"Tháng/Năm {ky}: {tong_tien:,} VNĐ")

def thong_ke_tong_tien_nuoc(data):
    """
    Thống kê tổng tiền nước theo từng tháng/năm có hóa đơn.
    Hiển thị tổng tiền nước cho mỗi kỳ (tháng/năm).
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Thống Kê Tổng Tiền Nước theo Tháng/Năm ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có dữ liệu để thống kê.")
        return
    stats = {} # Từ điển để lưu tổng tiền nước theo kỳ (tháng/năm)
    for hd in data: # Duyệt qua từng hóa đơn
        key = f"{hd['thang']}/{hd['nam']}" # Tạo khóa dạng "tháng/năm"
        if key not in stats: # Nếu kỳ này chưa có trong thống kê
            stats[key] = 0 # Khởi tạo tổng tiền cho kỳ này
        stats[key] += hd['tien_nuoc'] # Cộng dồn tiền nước vào kỳ tương ứng
    
    # Sắp xếp và in kết quả
    for ky, tong_tien in sorted(stats.items()):
        print(f"Tháng/Năm {ky}: {tong_tien:,} VNĐ")

# Chức năng mới: Liệt kê hóa đơn theo khách hàng cụ thể
def liet_ke_hoa_don_theo_khach_hang(data):
    """
    Liệt kê tất cả các hóa đơn của một khách hàng cụ thể.
    Người dùng nhập tên khách hàng, và chương trình tìm các hóa đơn khớp.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Liệt Kê Hóa Đơn theo Khách Hàng Cụ Thể ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn nào để tìm kiếm.")
        return
    
    ten_khach_hang_can_tim = input("Nhập tên khách hàng muốn liệt kê hóa đơn: ").strip() # Lấy tên và bỏ khoảng trắng thừa
    
    if not ten_khach_hang_can_tim: # Kiểm tra tên khách hàng không rỗng
        print("Tên khách hàng không được để trống.")
        return

    hoa_don_cua_khach_hang = [] # Danh sách lưu các hóa đơn của khách hàng tìm được
    # Chuẩn hóa tên khách hàng tìm kiếm để so sánh không phân biệt chữ hoa/thường
    ten_khach_hang_lower = ten_khach_hang_can_tim.lower() 

    for hd in data: # Duyệt qua từng hóa đơn
        if hd['ten_khach_hang'].lower() == ten_khach_hang_lower: # So sánh tên khách hàng
            hoa_don_cua_khach_hang.append(hd) # Thêm vào danh sách kết quả
    
    if hoa_don_cua_khach_hang: # Nếu tìm thấy hóa đơn
        print(f"\n--- Hóa đơn của khách hàng: {ten_khach_hang_can_tim} ---")
        hien_thi_danh_sach_hoa_don(hoa_don_cua_khach_hang) # Hiển thị các hóa đơn của khách hàng đó
    else: # Nếu không tìm thấy
        print(f"Không tìm thấy hóa đơn nào cho khách hàng '{ten_khach_hang_can_tim}'.")

def tim_hoa_don_dien_cao_nhat(data):
    """
    Tìm và hiển thị hóa đơn có số tiền điện cao nhất.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Hóa Đơn Tiền Điện Cao Nhất ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn để tìm kiếm.")
        return
    max_hd = None # Biến để lưu trữ hóa đơn có tiền điện cao nhất
    for hd in data: # Duyệt qua từng hóa đơn
        # Nếu max_hd chưa được gán HOẶC tiền điện của hóa đơn hiện tại cao hơn
        if max_hd is None or hd['tien_dien'] > max_hd['tien_dien']:
            max_hd = hd # Cập nhật max_hd
    if max_hd: # Nếu tìm thấy hóa đơn
        hien_thi_danh_sach_hoa_don([max_hd]) # Hiển thị hóa đơn đó (dưới dạng danh sách 1 mục)
    else: # Trường hợp không tìm thấy (thường không xảy ra nếu data không rỗng)
        print("Không tìm thấy hóa đơn tiền điện cao nhất.")

def hien_thi_lich_su_tieu_thu(data):
    """
    Hiển thị lịch sử tiêu thụ điện và nước của từng khách hàng.
    Thông tin được nhóm theo khách hàng và sắp xếp theo năm/tháng.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Lịch Sử Tiêu Thụ (Đơn Giản) ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn nào để hiển thị lịch sử tiêu thụ.")
        return
    lich_su = {} # Từ điển để nhóm dữ liệu theo tên khách hàng
    for hd in data: # Duyệt qua từng hóa đơn
        ten = hd['ten_khach_hang']
        if ten not in lich_su: # Nếu khách hàng chưa có trong từ điển lịch sử
            lich_su[ten] = [] # Tạo một danh sách rỗng cho khách hàng này
        # Thêm thông tin tiêu thụ của kỳ hiện tại vào danh sách của khách hàng
        lich_su[ten].append({
            "nam": hd['nam'],
            "thang": hd['thang'],
            "kw_dien": hd['so_kw_dien'],
            "m3_nuoc": hd['so_m3_nuoc']
        })

    for ten, ds_ky in lich_su.items(): # Duyệt qua từng khách hàng và lịch sử của họ
        print(f"\n--- Lịch sử tiêu thụ của khách hàng: {ten} ---")
        ds_ky.sort(key=lambda x: (x['nam'], x['thang'])) # Sắp xếp các kỳ theo năm rồi tháng
        for ky in ds_ky: # In thông tin tiêu thụ cho từng kỳ
            print(f"    Năm {ky['nam']}, Tháng {ky['thang']}: Điện = {ky['kw_dien']} kWh, Nước = {ky['m3_nuoc']} m³")

def tim_hoa_don_nuoc_cao_nhat(data):
    """
    Tìm và hiển thị hóa đơn có số tiền nước cao nhất.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Hóa Đơn Tiền Nước Cao Nhất ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn để tìm kiếm.")
        return
    max_hd = None # Biến để lưu trữ hóa đơn có tiền nước cao nhất
    for hd in data: # Duyệt qua từng hóa đơn
        # Nếu max_hd chưa được gán HOẶC tiền nước của hóa đơn hiện tại cao hơn
        if max_hd is None or hd['tien_nuoc'] > max_hd['tien_nuoc']:
            max_hd = hd # Cập nhật max_hd
    if max_hd: # Nếu tìm thấy hóa đơn
        hien_thi_danh_sach_hoa_don([max_hd]) # Hiển thị hóa đơn đó (dưới dạng danh sách 1 mục)
    else: # Trường hợp không tìm thấy (thường không xảy ra nếu data không rỗng)
        print("Không tìm thấy hóa đơn tiền nước cao nhất.")

def dat_trang_thai_thanh_toan(data):
    """
    Đặt hoặc thay đổi trạng thái thanh toán của một hóa đơn cụ thể.
    Người dùng chọn hóa đơn theo số thứ tự và chọn trạng thái mới.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Đặt Trạng Thái Thanh Toán ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn để đặt trạng thái.")
        return
    hien_thi_danh_sach_hoa_don(data) # Hiển thị danh sách để người dùng chọn
    try: # Bắt lỗi nhập số thứ tự hóa đơn
        idx = int(input("Nhập số hóa đơn muốn cập nhật trạng thái (ví dụ 1, 2, ...): ")) - 1 # Chuyển đổi sang index 0-based
        if not (0 <= idx < len(data)): # Kiểm tra index hợp lệ
            print("Số hóa đơn không hợp lệ.")
            return
        
        # Hiển thị trạng thái hiện tại của hóa đơn
        current_status = "Đã thanh toán" if data[idx]['da_thanh_toan'] else "Chưa thanh toán"
        print(f"Trạng thái hiện tại của hóa đơn số {idx+1}: {current_status}")
        
        # Hỏi người dùng trạng thái mới
        choice = input("Bạn muốn đánh dấu là 'đã thanh toán' (y) hay 'chưa thanh toán' (n)? ").lower()
        if choice == 'y':
            data[idx]['da_thanh_toan'] = True # Đặt là đã thanh toán
            print("Đã cập nhật trạng thái: Đã thanh toán.")
        elif choice == 'n':
            data[idx]['da_thanh_toan'] = False # Đặt là chưa thanh toán
            print("Đã cập nhật trạng thái: Chưa thanh toán.")
        else:
            print("Lựa chọn không hợp lệ. Không thay đổi trạng thái.")
    except ValueError:
        print("Đầu vào không hợp lệ. Vui lòng nhập một số.")

def hien_thi_hoa_don_chua_thanh_toan(data):
    """
    Hiển thị danh sách tất cả các hóa đơn đang ở trạng thái 'Chưa thanh toán'.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Hóa Đơn Chưa Thanh Toán ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn nào.")
        return
    # Lọc ra các hóa đơn mà trường 'da_thanh_toan' là False
    chua_thanh_toan = [hd for hd in data if not hd['da_thanh_toan']]
    if chua_thanh_toan: # Nếu có hóa đơn chưa thanh toán
        print("Danh sách các hóa đơn chưa thanh toán:")
        hien_thi_danh_sach_hoa_don(chua_thanh_toan) # Hiển thị chúng
    else: # Nếu không có hóa đơn nào chưa thanh toán
        print("Không có hóa đơn nào chưa thanh toán.")

def tinh_trung_binh_tieu_thu(data):
    """
    Tính và hiển thị mức tiêu thụ điện trung bình (kWh) và nước trung bình (m³)
    trên mỗi hóa đơn đã ghi nhận.
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
    """
    print("\n--- Tính Trung Bình Tiêu Thụ ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có dữ liệu để tính toán.")
        return
    
    # Tính tổng số kWh điện và tổng số m³ nước
    tong_kw = sum(hd['so_kw_dien'] for hd in data)
    tong_m3 = sum(hd['so_m3_nuoc'] for hd in data)
    so_hoa_don = len(data) # Lấy tổng số hóa đơn

    if so_hoa_don > 0: # Tránh chia cho 0 nếu không có hóa đơn
        trung_binh_kw = tong_kw / so_hoa_don
        trung_binh_m3 = tong_m3 / so_hoa_don
        print(f"Số hóa đơn đã ghi nhận: {so_hoa_don}")
        print(f"Trung bình tiêu thụ điện mỗi hóa đơn: {trung_binh_kw:.2f} kWh") # Định dạng 2 chữ số thập phân
        print(f"Trung bình tiêu thụ nước mỗi hóa đơn: {trung_binh_m3:.2f} m³") # Định dạng 2 chữ số thập phân
    else:
        print("Không có đủ dữ liệu để tính trung bình.")

def xuat_bao_cao_chi_tiet(data, filename="bao_cao_hoa_don.txt"):
    """
    Xuất một báo cáo chi tiết về tất cả các hóa đơn ra file văn bản (.txt).
    Tham số:
        data (list): Danh sách các từ điển hóa đơn.
        filename (str): Tên file để xuất báo cáo (mặc định là "bao_cao_hoa_don.txt").
    """
    print("\n--- Xuất Báo Cáo Chi Tiết ---")
    if not data: # Kiểm tra nếu danh sách rỗng
        print("Không có hóa đơn để xuất báo cáo.")
        return
    
    try:
        # Mở file ở chế độ ghi ('w') với mã hóa UTF-8
        with open(filename, 'w', encoding='utf-8') as f:
            f.write("BÁO CÁO CHI TIẾT HÓA ĐƠN ĐIỆN NƯỚC\n") # Ghi tiêu đề báo cáo
            f.write("=" * 40 + "\n\n") # Ghi đường kẻ phân cách
            
            for i, hd in enumerate(data): # Duyệt qua từng hóa đơn
                f.write(f"--- Hóa đơn số {i+1} ---\n") # Ghi số hóa đơn
                f.write(f"Năm: {hd['nam']}, Tháng: {hd['thang']}, Khách hàng: {hd['ten_khach_hang']}\n")
                f.write(f"    Điện:\n")
                f.write(f"      Chỉ số đầu: {hd['chi_so_dau_dien']}, Chỉ số cuối: {hd['chi_so_cuoi_dien']}\n")
                f.write(f"      Số kWh tiêu thụ: {hd['so_kw_dien']}, Thành tiền: {hd['tien_dien']:,} VNĐ\n") # Định dạng tiền
                f.write(f"    Nước:\n")
                f.write(f"      Chỉ số đầu: {hd['chi_so_dau_nuoc']}, Chỉ số cuối: {hd['chi_so_cuoi_nuoc']}\n")
                f.write(f"      Số m³ tiêu thụ: {hd['so_m3_nuoc']}, Thành tiền: {hd['tien_nuoc']:,} VNĐ\n") # Định dạng tiền
                f.write(f"    Tổng tiền: {hd['tong_tien']:,} VNĐ\n") # Định dạng tiền
                f.write(f"    Trạng thái thanh toán: {'Đã thanh toán' if hd['da_thanh_toan'] else 'Chưa thanh toán'}\n")
                f.write("-" * 20 + "\n") # Đường kẻ phân cách giữa các hóa đơn
            f.write("\n" + "=" * 40 + "\n") # Đường kẻ cuối báo cáo
            f.write("Kết thúc báo cáo.\n") # Ghi kết thúc báo cáo
        print(f"Báo cáo đã được xuất ra file '{filename}'.")
    except Exception as e: # Bắt bất kỳ lỗi nào trong quá trình ghi file
        print(f"Lỗi khi xuất báo cáo: {e}")

# --- Hàm Menu Chính ---
def main():
    """
    Hàm chính điều khiển luồng hoạt động của chương trình.
    Hiển thị menu, nhận lựa chọn của người dùng và gọi các chức năng tương ứng.
    """
    data = tai_du_lieu() # Tải dữ liệu hóa đơn từ file JSON khi khởi động chương trình

    while True: # Vòng lặp vô hạn để hiển thị menu liên tục cho đến khi người dùng chọn thoát
        print("\n--- Quản Lý Hóa Đơn Điện, Nước ---")
        print("1. Thêm hóa đơn")
        print("2. Sửa hóa đơn")
        print("3. Xóa hóa đơn")
        print("4. Hiển thị lịch sử tiêu thụ")
        print("5. Hiển thị thông tin tiêu thụ và chi phí")
        print("6. Hiển thị thông tin thanh toán")
        print("7. Hiển thị tất cả hóa đơn chi tiết")
        print("8. Tìm kiếm hóa đơn theo tên khách hàng")
        print("9. Tìm kiếm hóa đơn theo tháng/năm")
        print("10. Thống kê tổng tiền điện theo tháng/năm")
        print("11. Thống kê tổng tiền nước theo tháng/năm")
        print("12. Liệt kê hóa đơn theo khách hàng cụ thể")
        print("13. Tìm hóa đơn tiền điện cao nhất")
        print("14. Tìm hóa đơn tiền nước cao nhất")
        print("15. Đặt trạng thái thanh toán")
        print("16. Hiển thị hóa đơn chưa thanh toán")
        print("17. Tính trung bình tiêu thụ điện/nước")
        print("18. Xuất báo cáo chi tiết ra file (.txt)")
        print("0. Lưu dữ liệu và Thoát")

        choice = input("Chọn chức năng: ") # Nhận lựa chọn từ người dùng

        try:
            choice_int = int(choice) # Chuyển đổi lựa chọn sang số nguyên
        except ValueError: # Bắt lỗi nếu người dùng nhập không phải số
            print("Lựa chọn không hợp lệ. Vui lòng nhập một số.")
            continue # Tiếp tục vòng lặp để hiển thị lại menu

        # Xử lý các lựa chọn của người dùng bằng các câu lệnh if/elif
        if choice_int == 1:
            them_hoa_don(data)
        elif choice_int == 2:
            sua_hoa_don(data)
        elif choice_int == 3:
            xoa_hoa_don(data)
        elif choice_int == 7:
            hien_thi_danh_sach_hoa_don(data)
        elif choice_int == 5:
            hien_thi_thong_tin_tieu_thu_va_chi_phi(data)
        elif choice_int == 6:
            hien_thi_thong_tin_thanh_toan(data)
        elif choice_int == 4:
            hien_thi_lich_su_tieu_thu(data)
        elif choice_int == 8:
            tim_kiem_hoa_don_theo_ten(data)
        elif choice_int == 9:
            tim_kiem_hoa_don_theo_thang_nam(data)
        elif choice_int == 10:
            thong_ke_tong_tien_dien(data)
        elif choice_int == 11:
            thong_ke_tong_tien_nuoc(data)
        elif choice_int == 12: 
            liet_ke_hoa_don_theo_khach_hang(data)
        elif choice_int == 13:
            tim_hoa_don_dien_cao_nhat(data)
        elif choice_int == 14:
            tim_hoa_don_nuoc_cao_nhat(data)
        elif choice_int == 15:
            dat_trang_thai_thanh_toan(data)
        elif choice_int == 16:
            hien_thi_hoa_don_chua_thanh_toan(data)
        elif choice_int == 17:
            tinh_trung_binh_tieu_thu(data)
        elif choice_int == 18:
            xuat_bao_cao_chi_tiet(data)
        elif choice_int == 0: # Lựa chọn thoát chương trình
            luu_du_lieu(data) # Lưu dữ liệu trước khi thoát
            print("Cảm ơn bạn đã sử dụng chương trình!")
            break # Thoát vòng lặp while True, kết thúc chương trình
        else: # Lựa chọn không nằm trong danh sách
            print("Lựa chọn không hợp lệ. Vui lòng thử lại.")

if __name__ == "__main__":
    main() # Gọi hàm main để bắt đầu chương trình khi script được chạy trực tiếp