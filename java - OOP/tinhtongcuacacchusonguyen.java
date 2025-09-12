import java.util.Scanner;
public class tinhtongcuacacchusonguyen 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap so nguyen duong: ");
        int n = scanner.nextInt();
        scanner.close();
        int sum = 0; // Biến lưu tổng các chữ số
        while (n != 0) {
            int digit = n % 10; // Lấy chữ số cuối cùng
            sum += digit; // Cộng chữ số vào tổng
            n /= 10; // Loại bỏ chữ số cuối cùng
        }
        System.out.println("Tong cac chu so nguyen: " + sum);
    }
}