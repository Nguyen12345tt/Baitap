import java.util.InputMismatchException;
import java.util.Scanner;

// 1. Định nghĩa một lớp Exception tùy chỉnh cho trường hợp phải thi lại.
// Kế thừa từ lớp Exception của Java.
class ThiLaiException extends Exception {
    public ThiLaiException(String message) {
        super(message); // Gọi constructor của lớp cha (Exception) để gán thông báo lỗi
    }
}

public class KiemTraDiemSinhVien {
    /**
     * Phương thức này kiểm tra điểm của sinh viên.
     * @param diem Điểm cần kiểm tra.
     * @throws ThiLaiException Ném ra ngoại lệ này nếu điểm < 5.
     */
    public static void kiemTraDiem(double diem) throws ThiLaiException {
        if (diem < 0 || diem > 10) {
            // Sử dụng IllegalArgumentException cho dữ liệu đầu vào không hợp lệ
            throw new IllegalArgumentException("Điểm không hợp lệ, phải nằm trong khoảng từ 0 đến 10.");
        }
        
        if (diem < 5.0) {
            // 2. Nếu điều kiện không đạt, ném ra ngoại lệ tùy chỉnh đã tạo.
            throw new ThiLaiException("Rất tiếc, với điểm " + diem + ", bạn phải thi lại.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Vui lòng nhập điểm của sinh viên: ");
        
        try {
            double diemNhap = scanner.nextDouble();
            
            // 3. Gọi phương thức có khả năng ném ra ngoại lệ
            kiemTraDiem(diemNhap);
            
            // Nếu không có ngoại lệ nào được ném, dòng này sẽ được thực thi
            System.out.println("Chúc mừng! Với điểm " + diemNhap + ", bạn đã qua môn.");
            
        } catch (ThiLaiException e) {
            // 4. Bắt chính xác ngoại lệ tùy chỉnh và xử lý
            System.err.println(e.getMessage());
            
        } catch (InputMismatchException e) {
            // Bắt lỗi nếu người dùng nhập không phải là số
            System.err.println("Lỗi: Dữ liệu nhập vào phải là một con số.");
            
        } catch (IllegalArgumentException e) {
            // Bắt lỗi nếu điểm nằm ngoài khoảng 0-10
            System.err.println("Lỗi: " + e.getMessage());
            
        } finally {
            System.out.println("---------------------------------");
            System.out.println("Quá trình kiểm tra điểm đã kết thúc.");
            scanner.close();
        }
    }
}
