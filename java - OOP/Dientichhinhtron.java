/**
 * Giải thích codes:
 * 
 * 1. Lớp trừu tượng `Shape2D`:
 *    - `abstract class Shape2D`: Đây là một "khuôn mẫu" chung cho các hình 2D, không thể tạo đối tượng trực tiếp từ nó.
 *    - `public static final double PI = 3.14159;`: Khai báo hằng số PI. `static` để có thể truy cập trực tiếp qua tên lớp (Shape2D.PI), `final` để giá trị không thể thay đổi.
 *    - `private String tenLoaiHinh;`: Thuộc tính để lưu tên của hình (ví dụ: "Hình tròn"). `private` thể hiện tính đóng gói, chỉ có thể truy cập qua các phương thức public.
 *    - `public Shape2D(String tenLoaiHinh)`: Hàm khởi tạo (constructor) của lớp cha, dùng để gán tên cho hình.
 *    - `public String getTenLoaiHinh()`: Phương thức để lấy ra tên của hình.
 *    - `public abstract double calculateArea();`: Đây là một phương thức trừu tượng. Nó chỉ có phần khai báo, không có phần thân (code xử lý). Bất kỳ lớp nào kế thừa từ `Shape2D` đều *bắt buộc* phải định nghĩa lại (implement) phương thức này để cung cấp công thức tính diện tích cụ thể cho riêng mình.
 *
 * 2. Lớp `Circle`:
 *    - `class Circle extends Shape2D`: Khai báo lớp `Circle` kế thừa tất cả các thuộc tính và phương thức (không phải private) từ `Shape2D`.
 *    - `private double radius;`: Khai báo thuộc tính bán kính riêng của hình tròn.
 *    - `public Circle(double radius)`: Hàm khởi tạo của lớp `Circle`.
 *    - `super("Hình tròn");`: Dòng này rất quan trọng. Nó gọi đến hàm khởi tạo của lớp cha (`Shape2D`) và truyền vào chuỗi "Hình tròn" để gán cho thuộc tính `tenLoaiHinh`. `super()` phải là dòng lệnh đầu tiên trong hàm khởi tạo của lớp con.
 *    - `this.radius = radius;`: Gán giá trị bán kính cho đối tượng hình tròn hiện tại.
 *    - `@Override`: Đây là một annotation, cho trình biên dịch biết rằng phương thức `calculateArea()` ngay sau nó là một phương thức được định nghĩa lại từ lớp cha.
 *    - `public double calculateArea()`: Đây là phần triển khai cụ thể của phương thức trừu tượng từ lớp `Shape2D`. Nó cung cấp công thức tính diện tích cho hình tròn: PI * bán kính * bán kính.
 *
 * 3. Lớp `demo` (Lớp kiểm thử):
 *    - `public static void main(String[] args)`: Điểm khởi đầu của chương trình.
 *    - `Circle myCircle = new Circle(5.0);`: Tạo một đối tượng (instance) cụ thể của lớp `Circle` với bán kính là 5.0.
 *    - `double area = myCircle.calculateArea();`: Gọi phương thức `calculateArea()` của đối tượng `myCircle` để tính diện tích và gán kết quả cho biến `area`.
 *    - `System.out.println(...)`: In kết quả ra màn hình. Chú ý cách chúng ta có thể gọi `myCircle.getTenLoaiHinh()`, một phương thức được kế thừa từ lớp cha `Shape2D`.
 */

// 1. Khai báo lớp trừu tượng Shape2D (Giao diện)
abstract class Shape2D {
    // Hằng số PI
    public static final double PI = 3.14159265359;

    // Thuộc tính tên loại hình
    private String tenLoaiHinh;

    // Constructor để gán tên
    public Shape2D(String tenLoaiHinh) {
        this.tenLoaiHinh = tenLoaiHinh;
    }

    // Phương thức để lấy tên loại hình
    public String getTenLoaiHinh() {
        return tenLoaiHinh;
    }

    // Phương thức trừu tượng để tính diện tích, lớp con bắt buộc phải triển khai
    public abstract double calculateArea();
}

// 2. Khai báo lớp Circle kế thừa từ Shape2D
class Circle extends Shape2D {
    // Thuộc tính riêng của hình tròn
    private double radius;

    // Constructor của lớp Circle
    public Circle(double radius) {
        // Gọi constructor của lớp cha (Shape2D) để đặt tên cho hình
        super("Hình tròn");
        // Gán giá trị cho bán kính
        this.radius = radius;
    }

    // Triển khai (implement) phương thức trừu tượng calculateArea từ lớp cha
    @Override
    public double calculateArea() {
        // Công thức tính diện tích hình tròn: PI * r^2
        return PI * radius * radius;
    }
}

// 3. Lớp chính để test chương trình
public class demo {
    public static void main(String[] args) {
        System.out.println("--- Chương trình kiểm tra tính kế thừa và lớp trừu tượng ---");

        // Tạo một đối tượng hình tròn với bán kính là 5.0
        Circle myCircle = new Circle(5.0);

        // Tính diện tích bằng cách gọi phương thức đã được triển khai trong lớp Circle
        double area = myCircle.calculateArea();

        // In kết quả ra màn hình
        // Có thể gọi getTenLoaiHinh() vì nó được kế thừa từ Shape2D
        System.out.println("Loại hình: " + myCircle.getTenLoaiHinh());
        System.out.printf("Diện tích của hình tròn với bán kính 5.0 là: %.2f\n", area);
    }
}
