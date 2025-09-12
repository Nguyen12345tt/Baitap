while True:
    print("Chọn một hành động:")
    print("1. Nhập sinh viên vào danh sách")
    print("2. Tìm kiếm sinh viên có trong ds lớp hay không")
    print("3. Xóa sinh viên")
    print("4. Thoát")

    lua_chon = input("Nhập lựa chọn: ")

    if lua_chon == '4':
        print("Đang thoát chương trình...")
        break
    else:
        print("Lựa chọn không hợp lệ.")

print("Chương trình đã kết thúc.")