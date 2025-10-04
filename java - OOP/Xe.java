/**
 * Giải thích codes:
 *
 * 1. Interface `Vehicle`:
 *    - `interface Vehicle`: Định nghĩa một "hợp đồng" cho các lớp phương tiện giao thông.
 *    - `void start();` và `void stop();`: Bất kỳ lớp nào cài đặt (implements) interface `Vehicle` đều phải cung cấp một định nghĩa cụ thể cho hai hành động này.
 *
 * 2. Lớp `Car`:
 *    - `class Car implements Vehicle`: Khai báo lớp `Car` và cam kết sẽ triển khai các phương thức của `Vehicle`.
 *    - `private String hangXe;`, `private int soGhe;`: Các thuộc tính riêng của xe hơi, được đóng gói (private).
 *    - `public Car(...)`: Hàm khởi tạo để gán giá trị cho các thuộc tính khi tạo đối tượng mới.
 *    - `@Override public void start()`: Cài đặt phương thức `start` theo cách riêng của xe hơi, in ra thông báo tương ứng.
 *    - `@Override public void stop()`: Cài đặt phương thức `stop` cho xe hơi.
 *
 * 3. Lớp `Bike`:
 *    - `class Bike implements Vehicle`: Tương tự `Car`, lớp `Bike` cũng cài đặt interface `Vehicle`.
 *    - `private String hangXe;`, `private String loaiXe;`: Các thuộc tính riêng của xe máy.
 *    - `public Bike(...)`: Hàm khởi tạo cho xe máy.
 *    - `@Override public void start()`: Cài đặt phương thức `start` cho xe máy.
 *    - `@Override public void stop()`: Cài đặt phương thức `stop` cho xe máy.
 *
 * 4. Lớp `Xe` (Lớp chính):
 *    - `public static void main(String[] args)`: Điểm bắt đầu của chương trình.
 *    - `Vehicle myCar = new Car(...)`: Tạo một đối tượng `Car`. Chúng ta có thể dùng kiểu `Vehicle` để khai báo, thể hiện tính đa hình.
 *    - `Vehicle myBike = new Bike(...)`: Tạo một đối tượng `Bike`.
 *    - `myCar.start();`, `myCar.stop();`: Gọi các phương thức đã được cài đặt trong lớp `Car`.
 *    - `myBike.start();`, `myBike.stop();`: Gọi các phương thức đã được cài đặt trong lớp `Bike`.
 */

// 1. Tạo interface Vehicle
interface Vehicle {
    void start();
    void stop();
}

// 2. Xây dựng lớp Car
class Car implements Vehicle {
    private String hangXe;
    private int soGhe;

    public Car(String hangXe, int soGhe) {
        this.hangXe = hangXe;
        this.soGhe = soGhe;
    }

    @Override
    public void start() {
        System.out.println("Xe hơi hãng " + hangXe + " (" + soGhe + " chỗ) đang khởi động bằng nút bấm...");
    }

    @Override
    public void stop() {
        System.out.println("Xe hơi hãng " + hangXe + " đã tắt máy.");
    }
}

// 3. Xây dựng lớp Bike
class Bike implements Vehicle {
    private String hangXe;
    private String loaiXe; // "xe số" hoặc "xe ga"

    public Bike(String hangXe, String loaiXe) {
        this.hangXe = hangXe;
        this.loaiXe = loaiXe;
    }

    @Override
    public void start() {
        System.out.println("Xe máy " + hangXe + " (" + loaiXe + ") đang nổ máy...");
    }

    @Override
    public void stop() {
        System.out.println("Xe máy " + hangXe + " đã tắt máy.");
    }
}

// 4. Lớp chính để chạy chương trình
public class Xe {
    public static void main(String[] args) {
        // Tạo 1 đối tượng Car
        Vehicle myCar = new Car("Toyota", 7);

        // Tạo 1 đối tượng Bike
        Vehicle myBike = new Bike("Honda", "xe ga");

        System.out.println("--- Thử nghiệm xe hơi ---");
        // Gọi phương thức của đối tượng Car
        myCar.start();
        myCar.stop();

        System.out.println("\n--- Thử nghiệm xe máy ---");
        // Gọi phương thức của đối tượng Bike
        myBike.start();
        myBike.stop();
    }
}
