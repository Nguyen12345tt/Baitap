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

    double tinhDienTich() {
        return canh * canh;
    }

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

    double tinhDienTich() {
        return chieuDai * chieuRong;
    }

    double tinhChuVi() {
        return (chieuDai + chieuRong) * 2;
    }
}

// Lớp chính để tính các lớp hình tứ giác (Hình chữ nhật và Hình vuông)
public class Chuvivadientichhinhtugiac {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập thông tin hình vuông
        System.out.print("Nhap canh hinh vuong: ");
        double canh = scanner.nextDouble();
        HinhVuong hinhVuong = new HinhVuong(canh);
        System.out.printf("Hinh vuong - Dien tich: %.2f, Chu vi: %.2f\n", hinhVuong.tinhDienTich(), hinhVuong.tinhChuVi());

        // Nhập thông tin hình chữ nhật
        System.out.print("Nhap chieu dai hinh chu nhat: ");
        double chieuDai = scanner.nextDouble();
        System.out.print("Nhap chieu rong hinh chu nhat: ");
        double chieuRong = scanner.nextDouble();
        HinhChuNhat hinhChuNhat = new HinhChuNhat(chieuDai, chieuRong);
        System.out.printf("Hinh chu nhat - Dien tich: %.2f, Chu vi: %.2f\n", hinhChuNhat.tinhDienTich(), hinhChuNhat.tinhChuVi());

        scanner.close();
    }
}