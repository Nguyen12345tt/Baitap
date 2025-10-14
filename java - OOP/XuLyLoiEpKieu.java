import java.util.Scanner;

public class XuLyLoiEpKieu {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Vui lòng nhập vào một số thực: ");
        String userInput = scanner.nextLine();
        
        try {
            // Cố gắng chuyển đổi (ép kiểu) chuỗi người dùng nhập thành một số thực.
            // Lệnh Double.parseDouble() sẽ ném ra NumberFormatException
            // nếu chuỗi không chứa một định dạng số hợp lệ.
            double number = Double.parseDouble(userInput);
            
            // Nếu chuyển đổi thành công, in ra kết quả
            System.out.println("Bạn đã nhập thành công số: " + number);
            
        } catch (NumberFormatException e) {
            // Bắt chính xác ngoại lệ NumberFormatException
            System.err.println("LỖI: '" + userInput + "' không phải là một số thực hợp lệ.");
            System.err.println("Vui lòng chỉ nhập các số.");
        } finally {
            // Khối finally luôn được thực thi để đảm bảo tài nguyên được giải phóng
            System.out.println("Chương trình kết thúc.");
            scanner.close();
        }
    }
}
