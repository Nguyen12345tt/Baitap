def tinh_dien_tich_hcn(chieu_dai=1, chieu_rong=1):
  dien_tich = chieu_dai * chieu_rong
  return dien_tich

# Các trường hợp sử dụng:
print("Diện tích không truyền tham số:", tinh_dien_tich_hcn())
print("Diện tích chỉ truyền chiều dài (5):", tinh_dien_tich_hcn(chieu_dai=5))
print("Diện tích chỉ truyền chiều rộng (10):", tinh_dien_tich_hcn(chieu_rong=10))
print("Diện tích truyền cả chiều dài (5) và chiều rộng (10):", tinh_dien_tich_hcn(5, 10))