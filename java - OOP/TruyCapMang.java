import java.util.InputMismatchException;
import java.util.Scanner;

public class TruyCapMang {

    public static void main(String[] args) {
        // 1. Khởi tạo một mảng số nguyên với 5 phần tử.
        // Các chỉ số hợp lệ là 0, 1, 2, 3, 4.
        int[] numbers = {100, 200, 300, 400, 500};
        
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Mảng hiện tại có 5 phần tử, với chỉ số từ 0 đến 4.");
        System.out.print("Vui lòng nhập chỉ số của phần tử bạn muốn truy cập: ");
        
        try {
            // 2. Cố gắng đọc và truy cập phần tử mảng
            int index = scanner.nextInt();
            
            System.out.println("Đang truy cập phần tử tại chỉ số " + index + "...");
            
            // Dòng này có thể ném ra ArrayIndexOutOfBoundsException
            // nếu 'index' < 0 hoặc 'index' >= 5.
            int value = numbers[index];
            
            System.out.println("Thành công! Giá trị tại chỉ số " + index + " là: " + value);
            
        } catch (ArrayIndexOutOfBoundsException e) {
            // 3. Bắt ngoại lệ nếu chỉ số không hợp lệ
            System.err.println("LỖI: Chỉ số bạn nhập nằm ngoài phạm vi cho phép của mảng.");
            
        } catch (InputMismatchException e) {
            // Bắt thêm lỗi nếu người dùng không nhập số
            System.err.println("LỖI: Vui lòng chỉ nhập một số nguyên.");
            
        } finally {
            // 4. Khối finally luôn được thực thi
            System.out.println("------------------------------------");
            System.out.println("Khối try...catch đã thực thi xong. Chương trình kết thúc.");
            scanner.close(); // Đảm bảo scanner luôn được đóng
        }
    }
}
