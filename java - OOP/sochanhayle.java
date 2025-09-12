import java.util.Scanner;
public class sochanhayle 
{
    public static void main(String[] args) 
    {
        int n;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap so nguyen duong: ");
        n = scanner.nextInt();
            if (n % 2 == 0)
            {
                System.out.printf("%d la so chan\n", n);
            } 
            else if (n % 2 != 0) 
            {
                System.out.printf("%d là số lẻ\n", n);
            }
            else 
            {
                System.out.println("Số bạn nhập không phải là số nguyên dương.");
            }
        scanner.close();
    }
}
