def la_so_nguyen_to(n):
  if n <= 1:
    return False
  for i in range(2, n):
    if n % i == 0:
      return False
  return True

# Gọi hàm để kiểm tra số 47
so_can_kiem_tra = 47
if la_so_nguyen_to(so_can_kiem_tra):
  print(f"Số {so_can_kiem_tra} là số nguyên tố.")
else:
  print(f"{so_can_kiem_tra} không phải là số nguyên tố.")