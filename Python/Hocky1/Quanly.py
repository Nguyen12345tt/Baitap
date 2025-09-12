def menu():
    print("1. Nhập sinh viên vào danh sách")
    print("2. Tìm kiếm sinh viên có trong danh sách lớp không")
    print("3. Xóa sinh viên")
    print("4. Thoát")

def luachon():
    return input("Hãy chọn thao tác: ")

def timkiem(tentk, svs):
    ds = []
    for hoten in svs:
        if tentk in hoten:
            ds.append(hoten)
    return ds

sv = []
while True:
    menu()
    lc = luachon()
    if lc == '4':
        break
    elif lc == '1':
        tensv = input("Hãy nhập họ tên sinh viên: ")
        sv.append(tensv)
        print(sv)
    elif lc == '2':
        tentk = input("Hãy nhập vào tên sinh viên cần tìm: ")
        ds = timkiem(tentk, sv)
        for ten in ds:
            print(ten)
    elif lc == '3':
        tentk = input("Hãy nhập họ tên sinh viên cần xóa: ")
        sv.remove(tentk)
        print(sv)