danh_sach_khach_hang = {}

while True:
    print("\n--- MENU ---")
    print("1. Thêm số điện thoại khách hàng")
    print("2. Tìm kiếm xem một số điện thoại có trong danh sách khách không")
    print("3. Xóa một số điện thoại ra khỏi danh sách khách hàng")
    print("4. Thoát")

    lua_chon = input("Nhập lựa chọn của bạn: ")

    if lua_chon == '1':
        so_dien_thoai = input("Nhập số điện thoại khách hàng: ")
        if so_dien_thoai in danh_sach_khach_hang:
            print("Số điện thoại này đã tồn tại trong danh sách.")
        else:
            ten_khach_hang = input(f"Nhập tên khách hàng cho số điện thoại {so_dien_thoai}: ")
            danh_sach_khach_hang[so_dien_thoai] = ten_khach_hang
            print(f"Đã thêm số điện thoại {so_dien_thoai} của khách hàng {ten_khach_hang} vào danh sách.")
    elif lua_chon == '2':
        so_dien_thoai_tim_kiem = input("Nhập số điện thoại cần tìm kiếm: ")
        if so_dien_thoai_tim_kiem in danh_sach_khach_hang:
            ten_khach_hang = danh_sach_khach_hang[so_dien_thoai_tim_kiem]
            print(f"Số điện thoại {so_dien_thoai_tim_kiem} thuộc về khách hàng: {ten_khach_hang}")
        else:
            print(f"Không tìm thấy số điện thoại {so_dien_thoai_tim_kiem} trong danh sách.")
    elif lua_chon == '3':
        so_dien_thoai_xoa = input("Nhập số điện thoại cần xóa: ")
        if so_dien_thoai_xoa in danh_sach_khach_hang:
            del danh_sach_khach_hang[so_dien_thoai_xoa]
            print(f"Đã xóa số điện thoại {so_dien_thoai_xoa} khỏi danh sách.")
        else:
            print(f"Không tìm thấy số điện thoại {so_dien_thoai_xoa} trong danh sách.")
    elif lua_chon == '4':
        print("Cảm ơn bạn đã sử dụng chương trình!")
        break
    else:
        print("Lựa chọn không hợp lệ. Vui lòng chọn lại.")