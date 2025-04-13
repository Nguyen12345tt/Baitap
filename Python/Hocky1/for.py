n = int(input("Nhập số tự nhiên n: "))
giai_thua = 1
for i in range(1, n + 1):
    giai_thua = giai_thua * i
print("Giai thừa của", n, "là:", giai_thua)