import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Giải thích codes:
 *
 * 1. `import ...`:
 *    - `ArrayList`: Một lớp triển khai của `List`, cho phép tạo ra một danh sách có kích thước động (có thể thêm, xóa phần tử dễ dàng).
 *    - `Collections`: Một lớp tiện ích chứa các phương thức static để thao tác trên các collection, trong đó có phương thức `sort()` để sắp xếp.
 *    - `List`: Là một interface, định nghĩa các hành vi chung cho một danh sách. Dùng `List` để khai báo biến là một thói quen tốt, giúp code linh hoạt hơn.
 *    - `Scanner`: Dùng để đọc dữ liệu người dùng nhập từ bàn phím.
 *
 * 2. `main` method:
 *    - `Scanner scanner = new Scanner(System.in);`: Tạo đối tượng Scanner.
 *    - `List<String> danhSachSinhVien = new ArrayList<>();`: Khai báo một `List` tên là `danhSachSinhVien` và khởi tạo nó bằng một `ArrayList`. List này được chỉ định chỉ chứa các phần tử kiểu `String`.
 *
 * 3. Vòng lặp `while (true)`:
 *    - Tạo một vòng lặp vô hạn để cho phép người dùng nhập nhiều tên.
 *    - `System.out.print(...)`: Hiển thị thông báo cho người dùng.
 *    - `String tenSV = scanner.nextLine();`: Đọc toàn bộ dòng người dùng nhập vào.
 *    - `if (tenSV.equalsIgnoreCase("done"))`: Kiểm tra xem người dùng có muốn kết thúc việc nhập liệu không. `equalsIgnoreCase` giúp bắt cả "done", "DONE", "Done",...
 *    - `break;`: Nếu người dùng nhập "done", lệnh này sẽ thoát khỏi vòng lặp `while`.
 *    - `danhSachSinhVien.add(tenSV);`: Nếu không phải "done", tên sinh viên sẽ được thêm vào cuối danh sách.
 *
 * 4. Sắp xếp và In kết quả:
 *    - `System.out.println("\n--- Danh sách sinh viên trước khi sắp xếp ---");`: In ra danh sách ban đầu.
 *    - `Collections.sort(danhSachSinhVien);`: Đây là dòng lệnh quan trọng. Nó sử dụng thuật toán sắp xếp hiệu quả để sắp xếp lại các phần tử trong `danhSachSinhVien` theo thứ tự từ điển (alphabetical order).
 *    - `System.out.println("\n--- Danh sách sinh viên sau khi sắp xếp (A-Z) ---");`: In ra danh sách sau khi đã được sắp xếp.
 *
 * 5. `scanner.close();`: Đóng đối tượng Scanner để giải phóng tài nguyên, tránh rò rỉ bộ nhớ.
 */

public class ListsvCNTT {

    public static void main(String[] args) {
        // Khởi tạo các đối tượng cần thiết
        Scanner scanner = new Scanner(System.in);
        List<String> danhSachSinhVien = new ArrayList<>();

        System.out.println("--- CHUONG TRINH NHAP DANH SACH SINH VIEN CNTT ---");
        System.out.println("(Nhap 'done' de ket thuc)");

        // Vòng lặp để nhập tên sinh viên
        while (true) {
            System.out.print("Nhap ho ten sinh vien: ");
            String tenSV = scanner.nextLine();

            // Nếu người dùng nhập 'done' thì dừng lại
            if (tenSV.equalsIgnoreCase("done")) {
                break;
            }

            // Thêm tên sinh viên vào danh sách
            danhSachSinhVien.add(tenSV);
        }

        // In ra danh sách trước khi sắp xếp
        System.out.println("\n--- Danh sach sinh vien truoc khi sap xep ---");
        System.out.println(danhSachSinhVien);

        // Sắp xếp danh sách theo thứ tự tăng dần của tên
        Collections.sort(danhSachSinhVien);

        // In ra danh sách sau khi đã sắp xếp
        System.out.println("\n--- Danh sach sinh vien sau khi sap xep (A-Z) ---");
        int stt = 1;
        for (String ten : danhSachSinhVien) {
            System.out.println(stt + ". " + ten);
            stt++;
        }

        // Đóng scanner
        scanner.close();
    }
}
