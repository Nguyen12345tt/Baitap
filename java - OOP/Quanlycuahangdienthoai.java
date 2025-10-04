import java.util.Scanner;
import java.util.ArrayList;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.time.LocalDate;
import java.util.Map;
import java.util.Comparator;

// ================= YÊU CẦU KỸ THUẬT: ĐÓNG GÓI & KẾ THỪA =================

// Lớp cha trừu tượng cho các sản phẩm
abstract class SanPham {
    private String maSP;
    private String ten;
    private double gia;
    private int soLuongTon;

    public SanPham(String maSP, String ten, double gia, int soLuongTon) {
        this.maSP = maSP;
        this.ten = ten;
        this.gia = gia;
        this.soLuongTon = soLuongTon;
    }

    // Getters and Setters (Encapsulation)
    public String getMaSP() { return maSP; }
    public String getTen() { return ten; }
    public void setTen(String ten) { this.ten = ten; }
    public double getGia() { return gia; }
    public void setGia(double gia) { this.gia = gia; }
    public int getSoLuongTon() { return soLuongTon; }
    public void setSoLuongTon(int soLuongTon) { this.soLuongTon = soLuongTon; }

    public abstract String getLoai(); // Phương thức trừu tượng để lớp con định nghĩa

    @Override
    public String toString() {
        return String.format("Mã SP: %-7s | Tên: %-20s | Loại: %-10s | Giá: %,.0f VND | Tồn kho: %d",
                maSP, ten, getLoai(), gia, soLuongTon);
    }
}

// Lớp con Điện thoại
class DienThoai extends SanPham {
    public DienThoai(String maSP, String ten, double gia, int soLuongTon) {
        super(maSP, ten, gia, soLuongTon);
    }

    @Override
    public String getLoai() {
        return "Điện thoại";
    }
}

// Lớp con Phụ kiện
class PhuKien extends SanPham {
    public PhuKien(String maSP, String ten, double gia, int soLuongTon) {
        super(maSP, ten, gia, soLuongTon);
    }

    @Override
    public String getLoai() {
        return "Phụ kiện";
    }
}

// Lớp Khách hàng
class KhachHang {
    private String maKH;
    private String ten;
    private String soDienThoai;
    private ArrayList<BaoHanh> danhSachBaoHanh;

    public KhachHang(String maKH, String ten, String soDienThoai) {
        this.maKH = maKH;
        this.ten = ten;
        this.soDienThoai = soDienThoai;
        this.danhSachBaoHanh = new ArrayList<>();
    }

    public String getMaKH() { return maKH; }
    public String getTen() { return ten; }
    public void setTen(String ten) { this.ten = ten; }
    public String getSoDienThoai() { return soDienThoai; }
    public void setSoDienThoai(String soDienThoai) { this.soDienThoai = soDienThoai; }
    public ArrayList<BaoHanh> getDanhSachBaoHanh() { return danhSachBaoHanh; }

    public void themBaoHanh(BaoHanh bh) {
        this.danhSachBaoHanh.add(bh);
    }

    @Override
    public String toString() {
        return String.format("Mã KH: %-7s | Tên: %-20s | SĐT: %s", maKH, ten, soDienThoai);
    }
}

// Lớp Bảo hành
class BaoHanh {
    private SanPham sanPham;
    private LocalDate ngayHetHan;

    public BaoHanh(SanPham sanPham, int thoiGianBaoHanhThang) {
        this.sanPham = sanPham;
        this.ngayHetHan = LocalDate.now().plusMonths(thoiGianBaoHanhThang);
    }

    @Override
    public String toString() {
        return String.format("Sản phẩm: %s (%s) | Hết hạn bảo hành: %s",
                sanPham.getTen(), sanPham.getMaSP(), ngayHetHan);
    }
}

// Lớp Hóa đơn
class HoaDon {
    private String maHD;
    private KhachHang khachHang;
    private ArrayList<SanPham> danhSachMua;
    private double tongTien;
    private boolean daThanhToan;

    public HoaDon(String maHD, KhachHang khachHang) {
        this.maHD = maHD;
        this.khachHang = khachHang;
        this.danhSachMua = new ArrayList<>();
        this.tongTien = 0;
        this.daThanhToan = false;
    }

    public void themSanPham(SanPham sp) {
        this.danhSachMua.add(sp);
        this.tongTien += sp.getGia();
        sp.setSoLuongTon(sp.getSoLuongTon() - 1); // Giảm tồn kho
    }
    
    public String getMaHD() { return maHD; }
    public ArrayList<SanPham> getDanhSachMua() { return danhSachMua; }
    public void setDaThanhToan(boolean daThanhToan) { this.daThanhToan = daThanhToan; }

    @Override
    public String toString() {
        return String.format("Mã HĐ: %-7s | Khách hàng: %s (%s) | Tổng tiền: %,.0f VND | Trạng thái: %s",
                maHD, khachHang.getTen(), khachHang.getMaKH(), tongTien, daThanhToan ? "Đã thanh toán" : "Chưa thanh toán");
    }
}

// ================= LỚP QUẢN LÝ CHÍNH =================
public class Quanlycuahangdienthoai {
    // YÊU CẦU KỸ THUẬT: COLLECTION FRAMEWORK (TreeMap, ArrayList)
    private static Map<String, SanPham> dsSanPham = new TreeMap<>();
    private static Map<String, KhachHang> dsKhachHang = new TreeMap<>();
    private static Map<String, HoaDon> dsHoaDon = new TreeMap<>();
    private static Scanner sc = new Scanner(System.in);
    private static int hoaDonCounter = 1;

    public static void main(String[] args) {
        // Thêm dữ liệu mẫu
        dsSanPham.put("IP15", new DienThoai("IP15", "iPhone 15 Pro", 34000000, 50));
        dsSanPham.put("SS23", new DienThoai("SS23", "Samsung Galaxy S23", 25000000, 30));
        dsSanPham.put("PK01", new PhuKien("PK01", "Ốp lưng iPhone 15", 350000, 100));
        dsKhachHang.put("KH01", new KhachHang("KH01", "Nguyễn Văn A", "0909123456"));
        dsKhachHang.put("KH02", new KhachHang("KH02", "Trần Thị B", "0987654321"));

        int choice;
        do {
            System.out.println("\n========= MENU QUẢN LÝ CỬA HÀNG =========");
            System.out.println("1. Quản lý Sản phẩm");
            System.out.println("2. Quản lý Khách hàng");
            System.out.println("3. Quản lý Hóa đơn");
            System.out.println("4. Tìm kiếm và Thống kê");
            System.out.println("0. Thoát");
            System.out.println("==========================================");
            choice = getIntInput("Nhập lựa chọn của bạn: ");

            switch (choice) {
                case 1: menuQuanLySanPham(); break;
                case 2: menuQuanLyKhachHang(); break;
                case 3: menuQuanLyHoaDon(); break;
                case 4: menuThongKe(); break;
                case 0: System.out.println("Đã thoát chương trình."); break;
                default: System.out.println("Lựa chọn không hợp lệ!");
            }
        } while (choice != 0);
    }

    // ================= MENU CON =================

    private static void menuQuanLySanPham() {
        // ... (Các chức năng thêm/sửa/xóa/hiển thị sản phẩm)
        System.out.println("\n--- Quản lý Sản phẩm ---");
        System.out.println("1. Thêm sản phẩm mới");
        System.out.println("2. Sửa thông tin sản phẩm");
        System.out.println("3. Xóa sản phẩm");
        System.out.println("4. Hiển thị danh sách sản phẩm");
        int choice = getIntInput("Nhập lựa chọn: ");
        switch(choice) {
            case 1:
                System.out.print("Chọn loại sản phẩm (1: Điện thoại, 2: Phụ kiện): ");
                int loai = getIntInput("");
                System.out.print("Nhập mã SP: ");
                String maSP = sc.nextLine();
                if (dsSanPham.containsKey(maSP)) {
                    System.out.println("Mã SP đã tồn tại!");
                    return;
                }
                System.out.print("Nhập tên SP: ");
                String tenSP = sc.nextLine();
                double gia = getDoubleInput("Nhập giá: ");
                int sl = getIntInput("Nhập số lượng tồn: ");
                if (loai == 1) {
                    dsSanPham.put(maSP, new DienThoai(maSP, tenSP, gia, sl));
                } else {
                    dsSanPham.put(maSP, new PhuKien(maSP, tenSP, gia, sl));
                }
                System.out.println("Thêm sản phẩm thành công!");
                break;
            case 4:
                System.out.println("\n--- Danh sách sản phẩm ---");
                dsSanPham.values().forEach(System.out::println);
                break;
            // Các case sửa, xóa có thể được thêm tương tự
            default: System.out.println("Chức năng đang phát triển.");
        }
    }

    private static void menuQuanLyKhachHang() {
        // ... (Các chức năng quản lý khách hàng và bảo hành)
        System.out.println("\n--- Quản lý Khách hàng ---");
        System.out.println("1. Thêm khách hàng mới");
        System.out.println("2. Xem danh sách khách hàng");
        System.out.println("3. Xem lịch sử bảo hành của khách hàng");
        int choice = getIntInput("Nhập lựa chọn: ");
        switch(choice) {
            case 1:
                System.out.print("Nhập mã KH: ");
                String maKH = sc.nextLine();
                if(dsKhachHang.containsKey(maKH)) {
                    System.out.println("Mã KH đã tồn tại!");
                    return;
                }
                System.out.print("Nhập tên KH: ");
                String tenKH = sc.nextLine();
                System.out.print("Nhập SĐT: ");
                String sdt = sc.nextLine();
                dsKhachHang.put(maKH, new KhachHang(maKH, tenKH, sdt));
                System.out.println("Thêm khách hàng thành công!");
                break;
            case 2:
                System.out.println("\n--- Danh sách khách hàng ---");
                dsKhachHang.values().forEach(System.out::println);
                break;
            case 3:
                System.out.print("Nhập mã KH cần xem bảo hành: ");
                KhachHang kh = dsKhachHang.get(sc.nextLine());
                if (kh != null) {
                    System.out.println("--- Lịch sử bảo hành của " + kh.getTen() + " ---");
                    if (kh.getDanhSachBaoHanh().isEmpty()) {
                        System.out.println("Khách hàng này chưa có sản phẩm nào được bảo hành.");
                    } else {
                        kh.getDanhSachBaoHanh().forEach(System.out::println);
                    }
                } else {
                    System.out.println("Không tìm thấy khách hàng.");
                }
                break;
            default: System.out.println("Chức năng đang phát triển.");
        }
    }

    private static void menuQuanLyHoaDon() {
        System.out.println("\n--- Quản lý Hóa đơn ---");
        System.out.println("1. Tạo hóa đơn mới");
        System.out.println("2. Cập nhật trạng thái thanh toán");
        System.out.println("3. Xem danh sách hóa đơn");
        int choice = getIntInput("Nhập lựa chọn: ");
        switch(choice) {
            case 1:
                System.out.print("Nhập mã KH mua hàng: ");
                KhachHang kh = dsKhachHang.get(sc.nextLine());
                if (kh == null) {
                    System.out.println("Mã khách hàng không tồn tại!");
                    return;
                }
                String maHD = "HD" + String.format("%03d", hoaDonCounter++);
                HoaDon hd = new HoaDon(maHD, kh);
                String maSP;
                do {
                    System.out.print("Nhập mã SP để thêm vào hóa đơn (nhập 'done' để kết thúc): ");
                    maSP = sc.nextLine();
                    if (dsSanPham.containsKey(maSP)) {
                        SanPham sp = dsSanPham.get(maSP);
                        if (sp.getSoLuongTon() > 0) {
                            hd.themSanPham(sp);
                            System.out.println("Đã thêm: " + sp.getTen());
                            // Thêm bảo hành cho sản phẩm
                            if(sp.getLoai().equals("Điện thoại")) {
                                kh.themBaoHanh(new BaoHanh(sp, 12)); // BH 12 tháng
                            } else {
                                kh.themBaoHanh(new BaoHanh(sp, 6)); // BH 6 tháng
                            }
                        } else {
                            System.out.println("Sản phẩm đã hết hàng!");
                        }
                    } else if (!maSP.equals("done")) {
                        System.out.println("Mã SP không tồn tại!");
                    }
                } while (!maSP.equals("done"));
                dsHoaDon.put(maHD, hd);
                System.out.println("Tạo hóa đơn thành công! " + hd);
                break;
            case 2:
                System.out.print("Nhập mã HĐ cần cập nhật thanh toán: ");
                HoaDon hoaDonToUpdate = dsHoaDon.get(sc.nextLine());
                if(hoaDonToUpdate != null) {
                    hoaDonToUpdate.setDaThanhToan(true);
                    System.out.println("Cập nhật thành công!");
                } else {
                    System.out.println("Không tìm thấy hóa đơn.");
                }
                break;
            case 3:
                System.out.println("\n--- Danh sách hóa đơn ---");
                dsHoaDon.values().forEach(System.out::println);
                break;
        }
    }

    private static void menuThongKe() {
        System.out.println("\n--- Tìm kiếm và Thống kê ---");
        System.out.println("1. Tìm sản phẩm theo tên");
        System.out.println("2. Thống kê sản phẩm bán chạy");
        int choice = getIntInput("Nhập lựa chọn: ");
        switch(choice) {
            case 1:
                System.out.print("Nhập tên sản phẩm cần tìm: ");
                String ten = sc.nextLine().toLowerCase();
                dsSanPham.values().stream()
                    .filter(sp -> sp.getTen().toLowerCase().contains(ten))
                    .forEach(System.out::println);
                break;
            case 2:
                Map<String, Integer> thongKe = new TreeMap<>();
                for (HoaDon hd : dsHoaDon.values()) {
                    for (SanPham sp : hd.getDanhSachMua()) {
                        thongKe.put(sp.getTen(), thongKe.getOrDefault(sp.getTen(), 0) + 1);
                    }
                }
                System.out.println("\n--- Thống kê sản phẩm bán chạy ---");
                thongKe.entrySet().stream()
                    .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                    .forEach(entry -> System.out.println(entry.getKey() + ": " + entry.getValue() + " lượt mua"));
                break;
            default: System.out.println("Chức năng đang phát triển.");
        }
    }

    // ================= HÀM TIỆN ÍCH =================

    // YÊU CẦU KỸ THUẬT: XỬ LÝ NGOẠI LỆ (try...catch)
    private static int getIntInput(String prompt) {
        while (true) {
            try {
                System.out.print(prompt);
                return Integer.parseInt(sc.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Lỗi: Vui lòng nhập một số nguyên hợp lệ.");
            }
        }
    }

    private static double getDoubleInput(String prompt) {
        while (true) {
            try {
                System.out.print(prompt);
                return Double.parseDouble(sc.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Lỗi: Vui lòng nhập một số hợp lệ.");
            }
        }
    }
}
