import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * Giải thích codes:
 *
 * 1. Lớp `SinhVien`:
 *    - Một lớp POJO (Plain Old Java Object) đơn giản để chứa dữ liệu của một sinh viên, bao gồm `ten` và 
 *      `diem`.
 *    - Phương thức `toString()` được override để hiển thị thông tin sinh viên một cách rõ ràng.
 *
 * 2. Lớp `SapXepTheoTen` (Comparator 1):
 *    - `class SapXepTheoTen implements Comparator<SinhVien>`: Khai báo một lớp sẽ định nghĩa logic so 
 *      sánh cho các đối tượng `SinhVien`.
 *    - `@Override public int compare(SinhVien sv1, SinhVien sv2)`: Đây là phương thức cốt lõi của 
 *      `Comparator`. Nó nhận vào hai đối tượng `SinhVien` và phải trả về:
 *      - Một số âm: nếu `sv1` nên đứng trước `sv2`.
 *      - Một số dương: nếu `sv1` nên đứng sau `sv2`.
 *      - Số 0: nếu `sv1` và `sv2` bằng nhau theo tiêu chí so sánh.
 *    - `return sv1.getTen().compareTo(sv2.getTen());`: Tận dụng phương thức `compareTo` có sẵn của lớp 
 *      `String` để so sánh tên theo thứ tự từ điển (A-Z).
 *
 * 3. Lớp `SapXepTheoDiem` (Comparator 2):
 *    - Tương tự như `SapXepTheoTen`, nhưng logic so sánh khác.
 *    - `return Double.compare(sv1.getDiem(), sv2.getDiem());`: Sử dụng 
 *      phương thức `Double.compare()` để so sánh hai số double một cách an toàn và chính xác. 
 *      Cách này sẽ sắp xếp theo thứ tự điểm tăng dần.
 *      - (Để sắp xếp giảm dần, bạn chỉ cần đảo vị trí: `return Double.compare(sv2.getDiem(),  
 *      sv1.getDiem());`)
 *    - `return int compare(SinhVien sv1, SinhVien sv2)`: Sử dụng câu lệnh if để so sánh điểm
 *      - Trả về -1 nếu sv1.diem < sv2.diem
 *      - Trả về 1 nếu sv1.diem > sv2.diem
 *      - Trả về 0 nếu bằng nhau
 *
 * 4. Lớp `Sapxepsv2cach` (Lớp chính):
 *    - `List<SinhVien> danhSachSV = new ArrayList<>();`: Tạo một danh sách để chứa các đối tượng 
 * `SinhVien`.
 *    - `danhSachSV.add(...)`: Thêm một vài sinh viên mẫu vào danh sách.
 *    - `Collections.sort(danhSachSV, new SapXepTheoTen());`: Dòng lệnh này yêu cầu `Collections` sắp xếp 
 *      `danhSachSV`. Tham số thứ hai là một đối tượng `Comparator` (`new SapXepTheoTen()`), chỉ cho   
 *      `sort` biết *cách* để so sánh các sinh viên với nhau (dựa vào tên).
 *    - `Collections.sort(danhSachSV, new SapXepTheoDiem());`: Tương tự, nhưng lần này `sort` sẽ sử dụng 
 *      logic so sánh theo điểm.
 */

// 1. Lớp để biểu diễn đối tượng Sinh Viên
class SinhVien {
    private String ten;
    private double diem;

    public SinhVien(String ten, double diem) {
        this.ten = ten;
        this.diem = diem;
    }

    public String getTen() {
        return ten;
    }

    public double getDiem() {
        return diem;
    }

    @Override
    public String toString() {
        return "SinhVien{" + "ten='" + ten + '\'' + ", diem=" + diem + '}';
    }
}

// 2. Lớp Comparator để sắp xếp sinh viên theo Tên (A-Z)
class SapXepTheoTen implements Comparator<SinhVien> {
    @Override
    public int compare(SinhVien sv1, SinhVien sv2) {
        // Sử dụng phương thức compareTo của String để so sánh tên
        return sv1.getTen().compareTo(sv2.getTen());
    }
}

// 3. Lớp Comparator để sắp xếp sinh viên theo Điểm (tăng dần)
class SapXepTheoDiem implements Comparator<SinhVien> {
    @Override
    public int compare(SinhVien sv1, SinhVien sv2) {
        // Sử dụng câu lệnh if để so sánh điểm
        if (sv1.getDiem() < sv2.getDiem()) {
            return -1; // sv1 đứng trước sv2
        } else if (sv1.getDiem() > sv2.getDiem()) {
            return 1; // sv1 đứng sau sv2
        } else {
            return 0; // hai sinh viên bằng điểm nhau
        }
    }
}

// 4. Lớp chính để chạy thử nghiệm
public class Sapxepsv2cach {
    public static void main(String[] args) {
        // Tạo danh sách sinh viên
        List<SinhVien> danhSachSV = new ArrayList<>();
        danhSachSV.add(new SinhVien("Nguyen", 7.5));
        danhSachSV.add(new SinhVien("Quang", 8.0));
        danhSachSV.add(new SinhVien("Hoang", 6.5));
        danhSachSV.add(new SinhVien("Dang", 9.0));

        // --- Hiển thị danh sách ban đầu ---
        System.out.println("--- Danh sach sinh vien ban dau ---");
        for (SinhVien sv : danhSachSV) {
            System.out.println(sv);
        }

        // --- Sắp xếp và hiển thị theo TÊN ---
        System.out.println("\n--- Sap xep theo TEN (A-Z) ---");
        Collections.sort(danhSachSV, new SapXepTheoTen());
        for (SinhVien sv : danhSachSV) {
            System.out.println(sv);
        }

        // --- Sắp xếp và hiển thị theo ĐIỂM ---
        System.out.println("\n--- Sap xep theo DIEM (tang dan) ---");
        Collections.sort(danhSachSV, new SapXepTheoDiem());
        for (SinhVien sv : danhSachSV) {
            System.out.println(sv);
        }
    }
}
