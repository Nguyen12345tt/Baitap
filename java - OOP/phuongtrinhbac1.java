import java.util.Scanner;
public class phuongtrinhbac1 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập hệ số a: ");
        float a = scanner.nextFloat();
        System.out.print("Nhập hệ số b: ");
        float b = scanner.nextFloat();
        if(a == 0)
        {
            if(b == 0)
            {
                System.out.println("Phương trình vô số nghiệm");
            }
            else
            {
                System.out.println("Phương trình vô nghiệm");
            }
        }
        else
        {
            float x = -b/a;
            System.out.printf("Phương trình có nghiệm x = %f",x);
        }
        scanner.close();
    }
}