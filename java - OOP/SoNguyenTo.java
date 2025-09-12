import java.util.Scanner;
public class SoNguyenTo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap mot so nguyen duong: ");
        int n = scanner.nextInt();
        if (n <= 0) {
            System.out.println("Vui long nhap mot so nguyen duong.");
        } else {
            if (isPrime(n)) {
                System.out.println(n + " la so nguyen to.");
            } else {
                System.out.println(n + " khong phai la so nguyen to.");
            }
        }
        scanner.close();
    }

    public static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
