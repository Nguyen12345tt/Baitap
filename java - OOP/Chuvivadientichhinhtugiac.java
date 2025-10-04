import java.util.Scanner;
// Lớp trừu tượng đại diện cho hình tứ giác (lớp cha)
abstract class TuGiac {
    abstract double tinhDienTich();
    abstract double tinhChuVi();
}

// Lớp hình vuông kế thừa từ lớp TuGiac (lớp con)
class HinhVuong extends TuGiac {
    private double canh;

    public HinhVuong(double canh) {
        this.canh = canh;
    }

    @Override
    double tinhDienTich() {
        return canh * canh;
    }

    @Override
    double tinhChuVi() {
        return 4 * canh;
    }
}

// Lớp hình chữ nhật kế thừa từ lớp TuGiac (lớp con)
class HinhChuNhat extends TuGiac {
    private double chieuDai;
    private double chieuRong;

    public HinhChuNhat(double chieuDai, double chieuRong) {
        this.chieuDai = chieuDai;
        this.chieuRong = chieuRong;
    }

    @Override
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }

    @Override
    double tinhChuVi() {
        return (chieuDai + chieuRong) * 2;
    }
}

// Lớp hình bình hành kế thừa từ lớp TuGiac (lớp con)
class HinhBinhHanh extends TuGiac {
    private double canhDay;
    private double canhBen;
    private double chieuCao;

    public HinhBinhHanh(double canhDay, double canhBen, double chieuCao) {
        this.canhDay = canhDay;
        this.canhBen = canhBen;
        this.chieuCao = chieuCao;
    }

    @Override
    double tinhDienTich() {
        return canhDay * chieuCao;
    }

    @Override
    double tinhChuVi() {
        return (canhDay + canhBen) * 2;
    }
}

// Lớp chính để tính các lớp hình tứ giác (Hình chữ nhật và Hình vuông)
public class Chuvivadientichhinhtugiac {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- MENU CHỌN HÌNH ---");
            System.out.println("1. Hình Vuông");
            System.out.println("2. Hình Chữ Nhật");
            System.out.println("3. Hình Bình Hành");
            System.out.println("0. Thoát chương trình");
            System.out.print("Vui lòng chọn loại hình bạn muốn tính: ");

            // Tạm thời xử lý lỗi nhập không phải số
            while (!scanner.hasNextInt()) {
                System.out.println("Lựa chọn không hợp lệ. Vui lòng nhập một số.");
                scanner.next(); // Đọc bỏ giá trị không hợp lệ
                System.out.print("Vui lòng chọn lại: ");
            }
            choice = scanner.nextInt();
            TuGiac hinh = null;

            switch (choice) {
                case 1:
                    System.out.print("Nhập cạnh hình vuông: ");
                    double canh = getValidDouble(scanner);
                    hinh = new HinhVuong(canh);
                    break;
                case 2:
                    System.out.print("Nhập chiều dài hình chữ nhật: ");
                    double chieuDai = getValidDouble(scanner);
                    System.out.print("Nhập chiều rộng hình chữ nhật: ");
                    double chieuRong = getValidDouble(scanner);
                    hinh = new HinhChuNhat(chieuDai, chieuRong);
                    break;
                case 3:
                    System.out.print("Nhập cạnh đáy hình bình hành: ");
                    double canhDay = getValidDouble(scanner);
                    System.out.print("Nhập cạnh bên hình bình hành: ");
                    double canhBen = getValidDouble(scanner);
                    System.out.print("Nhập chiều cao hình bình hành: ");
                    double chieuCao = getValidDouble(scanner);
                    hinh = new HinhBinhHanh(canhDay, canhBen, chieuCao);
                    break;
                case 0:
                    System.out.println("Đã thoát chương trình.");
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ. Vui lòng chọn lại.");
                    break;
            }

            if (hinh != null) {
                System.out.printf("--> Kết quả - Diện tích: %.2f, Chu vi: %.2f\n", hinh.tinhDienTich(), hinh.tinhChuVi());
            }

        } while (choice != 0);

        scanner.close();
    }

    // Hàm phụ trợ để nhập và kiểm tra số double hợp lệ (lớn hơn 0)
    public static double getValidDouble(Scanner sc) {
        double value;
        do {
            while (!sc.hasNextDouble()) {
                System.out.println("Giá trị không hợp lệ. Vui lòng nhập lại một số.");
                sc.next(); // Đọc bỏ giá trị không hợp lệ
                System.out.print("Vui lòng nhập lại: ");
            }
            value = sc.nextDouble();
            if (value <= 0) {
                System.out.println("Kích thước phải lớn hơn 0. Vui lòng nhập lại.");
                System.out.print("Vui lòng nhập lại: ");
            }
        } while (value <= 0);
        return value;
    }
}