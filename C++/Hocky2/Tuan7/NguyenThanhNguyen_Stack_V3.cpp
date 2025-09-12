/*NguyenThanhNguyen_Stack_V3.cpp
- Mô tả bằng lời các bước sau:
    Bài 1: Thêm phần tử vào ngăn xếp (Push)
    Bài 2: Lấy ra và xóa nút đi trả về qua sv
    Bài 3: Lấy phần tử đầu tiên nhưng không xóa
*/
/*
Bài 1:
B1: Tạo nút mới: Khởi tạo một nút mới (Node) để chứa giá trị của phần tử 
    mà bạn muốn thêm.
B2: Gán giá trị: Gán giá trị của phần tử mới cho nút mới này.
B3: Cập nhật liên kết: Đặt liên kết của nút mới này trỏ tới nút hiện tại đang ở đỉnh 
    của ngăn xếp.
B4: Cập nhật đỉnh ngăn xếp: Đặt nút mới này trở thành đỉnh mới của ngăn xếp.
Bài 2:
B1: Kiểm tra rỗng: Đầu tiên, kiểm tra xem ngăn xếp có rỗng không. Nếu ngăn xếp rỗng, 
    không thể lấy phần tử ra và cần xử lý trường hợp này.
B2: Lấy giá trị đỉnh: Nếu ngăn xếp không rỗng, lấy giá trị của phần tử ở đỉnh ngăn xếp.
B3: Cập nhật đỉnh ngăn xếp: Di chuyển đỉnh ngăn xếp xuống phần tử kế tiếp 
    (phần tử bên dưới).
B4: Xóa nút đỉnh: Giải phóng bộ nhớ của nút ban đầu (nút đỉnh cũ) để tránh rò rỉ bộ 
    nhớ.
B5: Trả về giá trị: Trả về giá trị của phần tử vừa lấy ra từ ngăn xếp.
Bài 3:
B1: Kiểm tra rỗng: Trước hết, kiểm tra xem ngăn xếp có rỗng không. Nếu ngăn xếp rỗng, 
    không có phần tử nào để lấy ra, và ta cần xử lý tình huống này.
B2: Lấy giá trị đỉnh: Nếu ngăn xếp không rỗng, lấy giá trị của phần tử ở đỉnh ngăn 
    xếp mà không thay đổi cấu trúc ngăn xếp.
B3: Trả về giá trị: Trả về giá trị của phần tử đó cho người gọi hàm.
*/