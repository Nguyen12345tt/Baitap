lienlacs = {}
for i in range(2):
    hoten = input("Họ và tên: ")
    sdt = input("Số điện thoại: ")
    lienlacs[hoten] = sdt
print(lienlacs)
hoten = input("Bạn muốn tìm số điện thoại của: ")
print("Số điện thoại là: ", lienlacs[hoten])
hoten = input("Bạn muốn xóa thông tin của: ")
del lienlacs[hoten]
print(lienlacs)