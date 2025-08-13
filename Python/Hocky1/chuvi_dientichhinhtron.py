def tinh_chu_vi_dien_tich_hinh_tron(ban_kinh):
    pi_approx = 3.14
    chu_vi = 2 * pi_approx * ban_kinh
    dien_tich = pi_approx * (ban_kinh ** 2)
    return chu_vi, dien_tich

# Tính chu vi và diện tích hình tròn với bán kính = 10
ban_kinh = 10
ket_qua = tinh_chu_vi_dien_tich_hinh_tron(ban_kinh)

chu_vi, dien_tich = ket_qua
print("Với bán kính = " , ban_kinh)
print("Chu vi hình tròn là: ", chu_vi)
print("Diện tích hình tròn là:" ,dien_tich)