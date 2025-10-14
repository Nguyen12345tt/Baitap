import java.util.Scanner;

public class XuLyNhieuNgoaiLe {

    public static void main(String[] args) {
        // Khởi tạo một mảng số nguyên có 5 phần tử
        int[] numbers = {10, 20, 30, 40, 50};
        
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Nhap vao mot chuoi de dung lam chi so mang: ");
        String userInput = scanner.nextLine();
        
        System.out.println("Mang cua chung ta co 5 phan tu, voi cac chi so tu 0 den 4.");
        
        try {
            // Bước 1: Cố gắng chuyển đổi chuỗi thành số nguyên
            // Có thể ném ra NumberFormatException
            System.out.println("Dang co gang chuyen '" + userInput + "' thanh so nguyen...");
            int index = Integer.parseInt(userInput);
            System.out.println("Chuyen doi thanh cong. Chi so ban chon la: " + index);
            
            // Bước 2: Cố gắng truy cập phần tử mảng bằng chỉ số vừa nhận được
            // Có thể ném ra ArrayIndexOutOfBoundsException
            System.out.println("Dang truy cap phan tu tai chi so " + index + "...");
            int value = numbers[index];
            
            // Nếu cả hai bước trên thành công
            System.out.println("Thanh cong! Gia tri tai chi so " + index + " la: " + value);
            
        } catch (NumberFormatException e) {
            // Bắt lỗi nếu chuỗi nhập vào không phải là định dạng số
            System.err.println("LOI: '" + userInput + "' khong the chuyen doi thanh so nguyen.");
            
        } catch (ArrayIndexOutOfBoundsException e) {
            // Bắt lỗi nếu chỉ số nằm ngoài phạm vi của mảng (0 đến 4)
            System.err.println("LOI: Chi so ban nhap nam ngoai pham vi hop le cua mang.");
            
        } catch (Exception e) {
            // Bắt các ngoại lệ không lường trước khác
            System.err.println("Da xay ra mot loi khong mong muon: " + e.getMessage());
            
        } finally {
            // Khối này luôn được thực thi
            System.out.println("Chuong trinh da thuc thi xong khoi try-catch.");
            scanner.close();
        }
    }
}
