import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class SinhVien {
    public String hoTen;
    public Double diemToan;
    public Double diemLy;
    public Double diemHoa;

    public Double getDiemTrungBinh() {
        return (diemToan + diemLy + diemHoa) / 3;
    }
}

public class Quanlysinhvien {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        ArrayList<SinhVien> danhSach = new ArrayList<>();
        try {
            int n = 0;
            do {
                try {
                     System.out.print("Nhap so luong sinh vien (n >= 2): ");
                     String input = sc.nextLine();
                     n = Integer.parseInt(input);
                     if (n < 2) {
                         System.out.println("So luong sinh vien phai >= 2. Vui long nhap lai.");
                     }
                } catch (NumberFormatException e) {
                     System.out.println("Nhap sai dinh dang, vui long nhap so nguyen!");
                }
            } while (n < 2);

            for (int i = 0; i < n; i++) {
                System.out.println("\n--- Nhap thong tin sinh vien thu " + (i + 1) + " ---");
                SinhVien sv = new SinhVien();
                
                System.out.print("Ho ten: ");
                sv.hoTen = sc.nextLine();

                sv.diemToan = nhapDiem("Toan");
                sv.diemLy = nhapDiem("Ly");
                sv.diemHoa = nhapDiem("Hoa");
                
                danhSach.add(sv);
            }

            if (danhSach.isEmpty()) {
                System.out.println("Danh sach diem rong. Chua co sinh vien.");
            } else {
                // Tinh diem trung binh va in ra
                System.out.println("\n=== DANH SACH SINH VIEN ===");
                for (SinhVien sv : danhSach) {
                    System.out.printf("Ho ten: %-20s | Diem TB: %.2f\n", sv.hoTen, sv.getDiemTrungBinh());
                }

                // Tim max min dung sort
                Collections.sort(danhSach, new Comparator<SinhVien>() {
                    @Override
                    public int compare(SinhVien sv1, SinhVien sv2) {
                        return sv1.getDiemTrungBinh().compareTo(sv2.getDiemTrungBinh());
                    }
                });

                System.out.println("\n=== SINH VIEN CO DIEM TRUNG BINH CAO NHAT VA THAP NHAT ===");
                SinhVien thapNhat = danhSach.get(0);
                SinhVien caoNhat = danhSach.get(danhSach.size() - 1);
                
                System.out.printf("Thap nhat: %s (%.2f)\n", thapNhat.hoTen, thapNhat.getDiemTrungBinh());
                System.out.printf("Cao nhat:  %s (%.2f)\n", caoNhat.hoTen, caoNhat.getDiemTrungBinh());
            }

        } catch (Exception e) {
            System.out.println("Da xay ra loi chuong trinh: " + e.getMessage());
            e.printStackTrace();
        } finally {
            if(sc != null) sc.close();
        }
    }

    public static Double nhapDiem(String mon) {
        Double diem = -1.0;
        do {
            try {
                System.out.print("Nhap diem " + mon + ": ");
                String input = sc.nextLine();
                diem = Double.parseDouble(input);
                if (diem < 0 || diem > 10) {
                    System.out.println("Diem phai tu 0 den 10. Vui long nhap lai.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Diem phai la so. Vui long nhap lai.");
            }
        } while (diem < 0 || diem > 10);
        return diem;
    }
}
