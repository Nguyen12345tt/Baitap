import java.util.Scanner;
class ThongTin 
{
    private String ten;
    private int tuoi;
    private double luong;
    
    public ThongTin(String ten, int tuoi, double luong) {
        this.ten = ten;
        this.tuoi = tuoi;
        this.luong = luong;
    }

    // --- BAT DAU THEM GETTERS ---
    public String getTen() {
        return this.ten;
    }

    public int getTuoi() {
        return this.tuoi;
    }

    public double getLuong() {
        return this.luong;
    }
    // --- KET THUC THEM GETTERS ---
}
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập tên: ");
        String ten = scanner.nextLine();
        System.out.print("Nhập tuổi: ");
        int tuoi = scanner.nextInt();
        System.out.print("Nhập lương: ");
        double luong = scanner.nextDouble();

        ThongTin thongTin = new ThongTin(ten, tuoi, luong);
        System.out.println("Thông tin đã nhập:");
        System.out.println("Tên: " + thongTin.getTen());
        System.out.println("Tuổi: " + thongTin.getTuoi());
        System.out.println("Lương: " + String.format("%,.0f", thongTin.getLuong()) + " VND");
    }
}