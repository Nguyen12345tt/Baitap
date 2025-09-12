import java.util.Scanner;
public class uocsocuasonguyenduong 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập một số nguyên dương: ");
        int n = scanner.nextInt();
        if (n <= 0) 
        {
            System.out.println("Vui lòng nhập một số nguyên dương.");
        } 
        else 
        {
            lietkeUocSo(n);
            DemUocSo(n);
        }
        scanner.close();
    }
    public static void lietkeUocSo(int n) 
    {
        System.out.print("Các ước số của " + n + " là: ");
        for (int i = 1; i <= n; i++) 
        {
            if (n % i == 0) 
            {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
    public static void DemUocSo(int n) 
    {
        int count = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (n % i == 0) 
            {
                count++;
            }
        }
        System.out.println("Số lượng ước số của " + n + " là: " + count);
    }
}