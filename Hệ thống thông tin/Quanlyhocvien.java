import java.util.ArrayList;
import java.util.Scanner;

// 1. Lop Cha
abstract class HocVien {
    String hoTen, diaChi, loaiCT; 

    public HocVien(String hoTen, String diaChi, String loaiCT) {
        this.hoTen = hoTen;
        this.diaChi = diaChi;
        this.loaiCT = loaiCT;
    }
    abstract double hocPhi();
    
    void hienThi() {
        System.out.printf("%s - %s - %s - Hoc phi: %.0f VND\n", hoTen, diaChi, loaiCT, hocPhi());
    }
}

// 2. Lop Con LT
class HocVienLT extends HocVien {
    int soBuoi; double donGia;
    public HocVienLT(String ten, String dc, String loai, int buoi, double gia) {
        super(ten, dc, loai); this.soBuoi = buoi; this.donGia = gia;
    }
    double hocPhi() { return soBuoi * donGia; }
}

// 2. Lop Con TH
class HocVienTH extends HocVien {
    int soGio; double donGia;
    public HocVienTH(String ten, String dc, String loai, int gio, double gia) {
        super(ten, dc, loai); this.soGio = gio; this.donGia = gia;
    }
    double hocPhi() { return soGio * donGia; }
}

// 3. Main
public class Quanlyhocvien {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<HocVien> list = new ArrayList<>();

        System.out.print("Nhap so luong SV: ");
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            sc.nextLine(); // Xu ly troi lenh
            System.out.println("\n--- Hoc vien " + (i + 1) + " ---");
            
            System.out.print("Ho ten: "); String ten = sc.nextLine();
            System.out.print("Dia chi: "); String dc = sc.nextLine();
            
            // Validate: Chi chap nhan DH, CD hoac Nghe (Khong dau)
            String loai;
            do {
                System.out.print("Loai chuong trinh (DH/CD/Nghe): ");
                loai = sc.nextLine();
            } while (!loai.matches("(?i)DH|CD|Nghe")); 

            System.out.print("Chon loai (1-Ly thuyet, 2-Thuc hanh): ");
            int chon = sc.nextInt();

            if (chon == 1) {
                System.out.print("Nhap So buoi & Don gia: ");
                // Nhap lien tiep so buoi roi den don gia
                list.add(new HocVienLT(ten, dc, loai.toUpperCase(), sc.nextInt(), sc.nextDouble()));
            } else {
                System.out.print("Nhap So gio & Don gia: ");
                list.add(new HocVienTH(ten, dc, loai.toUpperCase(), sc.nextInt(), sc.nextDouble()));
            }
        }

        System.out.println("\n--- XUAT DANH SACH ---");
        double tong = 0;
        for (HocVien hv : list) {
            hv.hienThi();
            tong += hv.hocPhi();
        }
        System.out.printf(">> TONG TIEN: %.0f VND", tong);
    }
}