import java.util.InputMismatchException;
import java.util.Scanner;

public class ChiaHaiSo {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try {
            System.out.print("Nhap vao so thu nhat (so bi chia): ");
            double soBiChia = scanner.nextDouble();

            System.out.print("Nhap vao so thu hai (so chia): ");
            double soChia = scanner.nextDouble();
            
            // Kiểm tra nếu số bị chia hoặc số chia là 0
            if (soBiChia == 0 || soChia == 0) {
                // Ném ra một ngoại lệ ArithmeticException một cách tường minh
                throw new ArithmeticException("Loi: Khong the chia cho so 0.");
            }
            
            double ketQua = soBiChia / soChia;
            System.out.println("Ket qua cua phep chia la: " + ketQua);
            
        } catch (InputMismatchException e) {
            // Bắt ngoại lệ nếu người dùng nhập không phải là số
            System.err.println("Loi: Vui long chi nhap so.");
        } catch (ArithmeticException e) {
            // Bắt ngoại lệ chia cho 0
            System.err.println(e.getMessage());
        } catch (Exception e) {
            // Bắt các ngoại lệ không mong muốn khác
            System.err.println("Da xay ra mot loi khong mong muon: " + e.getMessage());
        } finally {
            scanner.close(); // Đóng scanner để tránh rò rỉ tài nguyên
        }
    }
}
