import sympy as sp

x = sp.Symbol('x')
n = int(input("Nhập số lượng công thức cần tính giới hạn: "))

for i in range(n):
    print(f"\n--- Công thức số {i+1} ---")
    expr_input = input("Nhập biểu thức (ví dụ: sin(x)/x): ")
    a_input = input("Nhập điểm cần lấy giới hạn (ví dụ: 0, 1, oo, -oo): ")
    direction = input("Nhập chiều lấy giới hạn (+, -, hoặc trống nếu 2 phía): ").strip()

    try:
        expr = sp.sympify(expr_input)
        a = sp.sympify(a_input)

        # Nếu người dùng không nhập gì, thì không truyền tham số dir
        if direction in ('+', '-'):
            limit_result = sp.limit(expr, x, a, dir=direction)
        else:
            limit_result = sp.limit(expr, x, a)

        print(f"Giới hạn của {expr_input} khi x -> {a_input}{' từ ' + direction if direction in ('+', '-') else ''}: {limit_result}")
    except Exception as e:
        print("Lỗi khi tính giới hạn:", e)