import java.util.Scanner;

/**
 * Lớp PhepTinh chứa các phương thức được nạp chồng.
 */
class PhepTinh {
    
    public int tinhTong(int a, int b) {
        return a + b;
    }

    public int tinhTong(int a, int b, int c) {
        return a + b + c;
    }
}

/**
 * Lớp chính để kiểm tra kỹ thuật nạp chồng.
 * Tên lớp này trùng với tên tệp.
 */
public class Kythuatnapchong {
    public static void main(String[] args) {
        // Tạo một đối tượng của lớp PhepTinh
        PhepTinh pt = new PhepTinh();
        
        // Sử dụng try-with-resources để tự động đóng Scanner
        try (Scanner scanner = new Scanner(System.in)) {
            // --- KIỂM TRA TÍNH TỔNG 2 SỐ ---
            System.out.println("--- Tinh tong hai so ---");
            System.out.print("Nhap so thu nhat: ");
            int so1 = scanner.nextInt();
            System.out.print("Nhap so thu hai: ");
            int so2 = scanner.nextInt();

            // Gọi phương thức tinhTong với hai đối số
            int tongHaiSo = pt.tinhTong(so1, so2);
            System.out.println("Tong cua hai so la: " + tongHaiSo);

            System.out.println("\n--------------------\n");

            // --- KIỂM TRA TÍNH TỔNG 3 SỐ ---
            System.out.println("--- Tinh tong ba so ---");
            System.out.print("Nhap so thu nhat: ");
            int soA = scanner.nextInt();
            System.out.print("Nhap so thu hai: ");
            int soB = scanner.nextInt();
            System.out.print("Nhap so thu ba: ");
            int soC = scanner.nextInt();

            // Gọi phương thức tinhTong với ba đối số
            int tongBaSo = pt.tinhTong(soA, soB, soC);
            System.out.println("Tong cua ba so la: " + tongBaSo);
        }
    }
}
