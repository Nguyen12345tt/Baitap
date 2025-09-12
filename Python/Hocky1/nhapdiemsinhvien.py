try:
    diem = float(input("Hãy nhập vào điểm: "))
    if (5 <= diem <= 10):
        print("Không thi lại")
    else:
        print ("Thi lại")
except ValueError as ve:
    print ("Hãy nhập vào 1 số thực")