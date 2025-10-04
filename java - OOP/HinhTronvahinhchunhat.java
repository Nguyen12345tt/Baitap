import java.util.Scanner;

/**
 * Giải thích codes:
 *
 * 1. Interface `Shape`:
 *    - `interface Shape`: Một interface là một "hợp đồng" hoàn toàn trừu tượng. Nó chỉ định nghĩa các phương thức mà một lớp phải triển khai nếu nó "implements" (cài đặt) interface này.
 *    - `double area();` và `double perimeter();`: Đây là các phương thức trừu tượng. Chúng không có phần thân và bất kỳ lớp nào cài đặt interface `Shape` đều bắt buộc phải cung cấp code xử lý cho hai phương thức này.
 *
 * 2. Lớp `Circle`:
 *    - `class Circle implements Shape`: Dòng này khai báo lớp `Circle` và "hứa" rằng nó sẽ triển khai tất cả các phương thức được định nghĩa trong interface `Shape`.
 *    - `@Override`: Annotation này cho biết các phương thức `area()` và `perimeter()` đang được định nghĩa lại từ interface.
 *    - `public double area()`: Cung cấp công thức tính diện tích hình tròn.
 *    - `public double perimeter()`: Cung cấp công thức tính chu vi (đường tròn).
 *
 * 3. Lớp `Rectangle`:
 *    - `class Rectangle implements Shape`: Tương tự như `Circle`, lớp này cũng cài đặt interface `Shape`.
 *    - Nó cung cấp các công thức tính diện tích và chu vi cụ thể cho hình chữ nhật.
 *
 * 4. Lớp `HinhTronvahinhchunhat` (Lớp chính):
 *    - `public static void main(String[] args)`: Điểm bắt đầu của chương trình.
 *    - Sử dụng `Scanner` để nhận dữ liệu đầu vào từ người dùng (bán kính, chiều rộng, chiều cao).
 *    - `Shape circle = new Circle(radius);`: Tạo một đối tượng `Circle`. Điều thú vị ở đây là chúng ta có thể khai báo biến với kiểu dữ liệu là `Shape` (interface) và khởi tạo nó bằng một đối tượng của lớp cài đặt interface đó (`Circle`).
 *    - `Shape rectangle = new Rectangle(width, height);`: Tương tự với hình chữ nhật.
 *    - `System.out.printf(...)`: In kết quả đã được tính toán ra màn hình, sử dụng các phương thức `area()` và `perimeter()` từ mỗi đối tượng.
 */

// 1. Tạo interface Shape
interface Shape {
    // Các phương thức trong interface mặc định là public và abstract
    double area();
    double perimeter();
}

// 2. Cài đặt interface cho lớp Circle
class Circle implements Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double area() {
        return Math.PI * radius * radius;
    }

    @Override
    public double perimeter() {
        return 2 * Math.PI * radius;
    }
}

// 3. Cài đặt interface cho lớp Rectangle
class Rectangle implements Shape {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double area() {
        return width * height;
    }

    @Override
    public double perimeter() {
        return 2 * (width + height);
    }
}

// 4. Lớp chính để chạy chương trình
public class HinhTronvahinhchunhat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // --- Xử lý Hình Tròn ---
        System.out.println("--- Nhập thông tin cho Hình Tròn ---");
        System.out.print("Nhập bán kính (radius): ");
        double radius = scanner.nextDouble();
        // Tạo đối tượng Circle, có thể khai báo bằng kiểu Shape (tính đa hình)
        Shape circle = new Circle(radius);

        // --- Xử lý Hình Chữ Nhật ---
        System.out.println("\n--- Nhập thông tin cho Hình Chữ Nhật ---");
        System.out.print("Nhập chiều rộng (width): ");
        double width = scanner.nextDouble();
        System.out.print("Nhập chiều cao (height): ");
        double height = scanner.nextDouble();
        // Tạo đối tượng Rectangle
        Shape rectangle = new Rectangle(width, height);

        // --- In kết quả ---
        System.out.println("\n--- Kết quả tính toán ---");
        System.out.printf("Hình Tròn      -> Diện tích: %.2f, Chu vi: %.2f\n", circle.area(), circle.perimeter());
        System.out.printf("Hình Chữ Nhật -> Diện tích: %.2f, Chu vi: %.2f\n", rectangle.area(), rectangle.perimeter());

        scanner.close();
    }
}
