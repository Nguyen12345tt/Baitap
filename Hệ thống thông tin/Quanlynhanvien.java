import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

// 1. Lop Cha Truu Tuong
abstract class NhanVien {
    protected String maNV;
    protected String hoTen;
    protected double luongCoBan;

    public NhanVien(String maNV, String hoTen, double luongCoBan) {
        this.maNV = maNV;
        this.hoTen = hoTen;
        this.luongCoBan = luongCoBan;
    }

    public abstract double tinhLuong();

    public void hienThi() {
        System.out.printf("Ma: %-5s | Ten: %-15s | Luong CB: %,.0f ", maNV, hoTen, luongCoBan);
    }
}

// 2. Lop Con Nhan Vien Van Phong
class NhanVienVanPhong extends NhanVien {
    private int soNgayLamViec;

    public NhanVienVanPhong(String maNV, String hoTen, double luongCoBan, int soNgayLamViec) {
        super(maNV, hoTen, luongCoBan);
        this.soNgayLamViec = soNgayLamViec;
    }

    @Override
    public double tinhLuong() {
        return luongCoBan + soNgayLamViec * 200000;
    }

    @Override
    public void hienThi() {
        super.hienThi();
        System.out.printf("| So ngay: %-2d | >> Tong luong: %,.0f VND\n", soNgayLamViec, tinhLuong());
    }
}

// 3. Lop Con Nhan Vien San Xuat
class NhanVienSanXuat extends NhanVien {
    private int soSanPham;

    public NhanVienSanXuat(String maNV, String hoTen, double luongCoBan, int soSanPham) {
        super(maNV, hoTen, luongCoBan);
        this.soSanPham = soSanPham;
    }

    @Override
    public double tinhLuong() {
        return luongCoBan + soSanPham * 250000;
    }

    @Override
    public void hienThi() {
        super.hienThi(); 
        System.out.printf("| So SP: %-4d   | >> Tong luong: %,.0f VND\n", soSanPham, tinhLuong());
    }
}

// 4. Class Main
public class QuanLyNhanVien {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<NhanVien> listNV = new ArrayList<>();

        System.out.print("Nhap so luong nhan vien: ");
        int n = sc.nextInt();

        // --- NHAP DU LIEU ---
        for (int i = 0; i < n; i++) {
            System.out.println("\n--- Nhap thong tin NV thu " + (i + 1) + " ---");
            sc.nextLine(); // Xu ly troi lenh

            System.out.print("Nhap Ma NV: ");
            String ma = sc.nextLine();

            System.out.print("Nhap Ho Ten: ");
            String ten = sc.nextLine();

            System.out.print("Nhap Luong Co Ban: ");
            double luongCB = sc.nextDouble();

            System.out.print("Chon loai (1-Van Phong, 2-San Xuat): ");
            int chon = sc.nextInt();

            if (chon == 1) {
                System.out.print("Nhap So ngay lam viec: ");
                int soNgay = sc.nextInt();
                // Them vao danh sach
                listNV.add(new NhanVienVanPhong(ma, ten, luongCB, soNgay));
            } else {
                System.out.print("Nhap So san pham: ");
                int soSP = sc.nextInt();
                // Them vao danh sach
                listNV.add(new NhanVienSanXuat(ma, ten, luongCB, soSP));
            }
        }

        // --- HIEN THI DANH SACH ---
        System.out.println("\n=== DANH SACH NHAN VIEN VUA NHAP ===");
        for (NhanVien nv : listNV) {
            nv.hienThi();
        }

        // --- SAP XEP GIAM DAN THEO LUONG ---
        Collections.sort(listNV, new Comparator<NhanVien>() {
            @Override
            public int compare(NhanVien nv1, NhanVien nv2) {
                // Mẹo: Muốn giảm dần thì lấy nv2 trừ nv1
                return Double.compare(nv2.tinhLuong(), nv1.tinhLuong());
            }
        });

        System.out.println("\n=== DANH SACH DA SAP XEP (GIAM DAN LUONG) ===");
        for (NhanVien nv : listNV) {
            nv.hienThi();
        }

        // --- TIM NHAN VIEN LUONG CAO NHAT ---
        // Sau khi sap xep giam dan, nguoi dau tien (index 0) chinh la nguoi cao nhat
        if (!listNV.isEmpty()) {
            System.out.println("\n=== NHAN VIEN CO LUONG CAO NHAT ===");
            listNV.get(0).hienThi();
        }
        
        sc.close();
    }
}