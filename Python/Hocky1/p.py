def dem_so_9(chuoi):
  """Đếm số lần xuất hiện của chữ số 9 trong một chuỗi.

  Args:
    chuoi: Chuỗi ký tự cần kiểm tra.

  Returns:
    Số lượng chữ số 9 có trong chuỗi.
  """
  dem = 0
  for ky_tu in chuoi:
    if ky_tu == '9':
      dem += 1
  return dem

# Nhập chuỗi từ người dùng
input_chuoi = input("Nhập vào một chuỗi: ")

# Đếm số lượng chữ số 9
so_luong_9 = dem_so_9(input_chuoi)

# In kết quả
print(f"Trong chuỗi '{input_chuoi}' có {so_luong_9} số 9.")