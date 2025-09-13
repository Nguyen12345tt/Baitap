import java.util.Scanner;
public class matranvuongcokichnxn {
    public static void main(String[] args) 
    {
        // Nhập kích thước ma trận vuông n x n và các phần tử của ma trận
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap kich thuoc ma tran vuong (n x n): ");
        int n = scanner.nextInt();
        int[][] matrix = new int[n][n];
        System.out.println("Nhap cac phan tu cua ma tran:");
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                matrix[i][j] = scanner.nextInt();
            }
        }
        
        // Gọi phương thức để hiển thị ma trận
        System.out.println("Ma tran vua nhap la:");
        hienThiMaTran(matrix);
        
        // Tính tổng các phần tử trên đường chéo chính
        int sum = 0;
        for (int i = 0; i < n; i++) 
        {
            sum += matrix[i][i];
        }
        System.out.println("Tong cac phan tu tren duong cheo chinh: " + sum);
        scanner.close();

        // Số chính phương trên đường chéo phụ
        System.out.print("Cac so chinh phuong tren duong cheo phu: ");
        for (int i = 0; i < n; i++) 
        {
            int soDuongCheoPhu = matrix[i][n - 1 - i];
            if (soChinhPhuong(soDuongCheoPhu)) 
            {
                System.out.print(soDuongCheoPhu + " ");
            }
        }
    }
    // Phương thức hiển thị ma trận
    public static void hienThiMaTran(int[][] matrix) 
    {
        int n = matrix.length;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // Số chính phương trên đường chéo phụ
    public static boolean soChinhPhuong(int n) {
        int sqrt = (int) Math.sqrt(n);
        return (sqrt * sqrt == n);
    }

}