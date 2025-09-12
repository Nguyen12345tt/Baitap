import re

def xu_ly_chuoi_dau_vao(chuoi_goc):
    """
    Thực hiện xử lý một chuỗi văn bản theo các quy tắc sau:
    - Thay thế các từ ngữ bạo lực bằng dấu *.
    - Chuẩn hóa chuỗi (xóa khoảng trắng thừa, đầu/cuối).
    - Xóa thông tin số điện thoại (bắt đầu bằng 091, 092, ...).

    Args:
        chuoi_goc (str): Chuỗi văn bản đầu vào từ người dùng.

    Returns:
        str: Chuỗi văn bản đã được xử lý.
    """

    # Bước 1: Thay thế các từ ngữ bạo lực bằng dấu *
    # Danh sách các từ ngữ bạo lực (sắp xếp từ dài đến ngắn để thay thế chính xác hơn)
    tu_bao_luc = {
        "giết người": "*********",  # 9 dấu *
        "đánh nhau": "*********",  # 9 dấu *
        "đổ máu": "******",      # 6 dấu *
        "máu": "***"             # 3 dấu *
    }

    chuoi_da_xu_ly = chuoi_goc

    # Thay thế từng từ bạo lực. Dùng re.IGNORECASE để không phân biệt chữ hoa/thường.
    # Dùng r"\bword\b" để đảm bảo chỉ thay thế từ riêng biệt, không phải một phần của từ khác.
    # Ví dụ: "đánh nhau" thay thế trước "đánh", "đổ máu" thay thế trước "máu"
    for tu, ky_tu_thay_the in tu_bao_luc.items():
        chuoi_da_xu_ly = re.sub(r"\b" + re.escape(tu) + r"\b", ky_tu_thay_the, chuoi_da_xu_ly, flags=re.IGNORECASE)

    # Bước 2: Chuẩn hóa chuỗi
    # Xóa khoảng trắng ở đầu và cuối chuỗi
    chuoi_da_xu_ly = chuoi_da_xu_ly.strip()
    # Xóa các khoảng trống thừa (thay thế 2+ khoảng trắng bằng 1 khoảng trắng)
    chuoi_da_xu_ly = re.sub(r'\s+', ' ', chuoi_da_xu_ly)

    # Bước 3: Xóa thông tin số điện thoại
    # Các đầu số điện thoại cần xóa (thêm các đầu số khác nếu cần)
    # Sử dụng re.compile để biên dịch regex một lần nếu dùng nhiều lần
    regex_sdt = re.compile(r'\b(091|092|093|094|096|097|098|086|088|089|070|079|077|076|078|032|033|034|035|036|037|038|039|081|082|083|084|085)\d{7}\b')
    # Thay thế số điện thoại bằng chuỗi rỗng
    chuoi_da_xu_ly = regex_sdt.sub('', chuoi_da_xu_ly)

    # Chuẩn hóa lại sau khi xóa SĐT (có thể tạo ra khoảng trắng thừa)
    chuoi_da_xu_ly = chuoi_da_xu_ly.strip()
    chuoi_da_xu_ly = re.sub(r'\s+', ' ', chuoi_da_xu_ly)

    return chuoi_da_xu_ly

# --- Chương trình chính ---
if __name__ == "__main__":
    print("Chương trình xử lý thông tin nhập vào:")
    print("Nhập 'exit' để thoát.")

    while True:
        thong_tin_nhap = input("Nhập thông tin của bạn: ")

        if thong_tin_nhap.lower() == 'exit':
            print("Kết thúc chương trình.")
            break

        chuoi_ket_qua = xu_ly_chuoi_dau_vao(thong_tin_nhap)
        print("Thông tin đã xử lý: ", chuoi_ket_qua)
        print("-" * 50)