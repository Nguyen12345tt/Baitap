import java.util.Scanner;

public class Hinhchunhat {
    private double chieuDai;
    private double chieuRong;

    // Phương thức khởi tạo - chỉ gán giá trị
    public Hinhchunhat(double chieuDai, double chieuRong) {
        this.chieuDai = chieuDai;
        this.chieuRong = chieuRong;
    }

    // Phương thức tính diện tích
    public double tinhDienTich() {
        return chieuDai * chieuRong;
    }

    // Phương thức tính chu vi
    public double tinhChuVi() {
        return 2 * (chieuDai + chieuRong);
    }

    // Phương thức main để test
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double dai, rong;

        // Nhập và kiểm tra chiều dài
        do {
            System.out.print("Nhập chiều dài (phải lớn hơn 0): ");
            while (!sc.hasNextDouble()) {
                System.out.println("Giá trị không hợp lệ. Vui lòng nhập lại.");
                sc.next(); // Đọc bỏ giá trị không hợp lệ
            }
            dai = sc.nextDouble();
            if (dai <= 0) {
                System.out.println("Chiều dài phải lớn hơn 0.");
            }
        } while (dai <= 0);

        // Nhập và kiểm tra chiều rộng
        do {
            System.out.print("Nhập chiều rộng (phải lớn hơn 0): ");
            while (!sc.hasNextDouble()) {
                System.out.println("Giá trị không hợp lệ. Vui lòng nhập lại.");
                sc.next(); // Đọc bỏ giá trị không hợp lệ
            }
            rong = sc.nextDouble();
            if (rong <= 0) {
                System.out.println("Chiều rộng phải lớn hơn 0.");
            }
        } while (rong <= 0);

        // Tạo đối tượng sau khi đã có giá trị hợp lệ
        Hinhchunhat hcn = new Hinhchunhat(dai, rong);

        System.out.println("\n--- Kết quả ---");
        System.out.println("Diện tích hình chữ nhật: " + hcn.tinhDienTich());
        System.out.println("Chu vi hình chữ nhật: " + hcn.tinhChuVi());
        
        sc.close();
    }
}
