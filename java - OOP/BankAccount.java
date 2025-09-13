import java.util.Scanner;
public class BankAccount 
{
    // Thuộc tính (properties)
    private String tenChuTaiKhoan;
    private double soDu;

    // Phương thức khởi tạo (constructor) có tham số
    public BankAccount(String tenChuTaiKhoan, double soDu) 
    {
        this.tenChuTaiKhoan = tenChuTaiKhoan;
        this.soDu = soDu;
    }

    // Phương thức hiển thị thông tin tài khoản
    public void hienThiThongTin() 
    {
        System.out.println("---Thông tin tài khoản---");
        System.out.println("Tên chủ tài khoản: " + tenChuTaiKhoan);
        System.out.println("Số dư: " + soDu);
    }

    // Phương thức nạp tiền
    public void napTien(double soTien) 
    {
        if (soTien > 1000) 
        {
            soDu += soTien;
            System.out.println("Nạp tiền thành công. Số dư mới: " + soDu);
        } 
        else 
        {
            System.out.println("Số tiền nạp vào không hợp lệ.");
        }
    }

    // Phương thức rút tiền
    public void rutTien(double soTien) 
    {
        if (soTien > 1000 && soTien <= soDu) 
        {
            soDu -= soTien;
            System.out.println("Rút tiền thành công. Số dư mới: " + soDu);
        } 
        else 
        {
            System.out.println("Số tiền rút không hợp lệ hoặc số dư không đủ.");
        }
    }

    // Phương thức main để test
    public static void main(String[] args) 
    {
        // Tạo đối tượng Scanner để đọc dữ liệu từ người dùng
        Scanner scanner = new Scanner(System.in);

        // Yêu cầu người dùng nhập thông tin
        String tenChuTaiKhoan;
        do {
            System.out.print("Nhập tên chủ tài khoản (không được để trống): ");
            tenChuTaiKhoan = scanner.nextLine();
            if (tenChuTaiKhoan.trim().isEmpty()) {
                System.out.println("Tên chủ tài khoản không được để trống. Vui lòng nhập lại.");
            }
        } while (tenChuTaiKhoan.trim().isEmpty());

        double soDu;
        do {
            System.out.print("Nhập số dư ban đầu (không được là số âm): ");
            soDu = scanner.nextDouble();
            if (soDu < 0) {
                System.out.println("Số dư không được là số âm. Vui lòng nhập lại.");
            }
        } while (soDu < 0);
        scanner.nextLine(); // Tiêu thụ dòng mới còn lại

        // Tạo một đối tượng BankAccount với thông tin người dùng đã nhập
        BankAccount taiKhoanNguoiDung = new BankAccount(tenChuTaiKhoan, soDu);

        // Hiển thị thông tin tài khoản
        System.out.println("\n---Tạo tài khoản thành công!---");
        
        int luaChon;
        do 
        {
            System.out.println("\n---MENU---");
            System.out.println("1. Hiển thị thông tin tài khoản");
            System.out.println("2. Nạp tiền");
            System.out.println("3. Rút tiền");
            System.out.println("0. Thoát");
            System.out.print("Nhập lựa chọn của bạn: ");
            luaChon = scanner.nextInt();

            switch (luaChon) {
                case 1:
                    taiKhoanNguoiDung.hienThiThongTin();
                    break;
                case 2:
                    System.out.print("Nhập số tiền cần nạp: ");
                    double soTienNap = scanner.nextDouble();
                    taiKhoanNguoiDung.napTien(soTienNap);
                    break;
                case 3:
                    System.out.print("Nhập số tiền cần rút: ");
                    double soTienRut = scanner.nextDouble();
                    taiKhoanNguoiDung.rutTien(soTienRut);
                    break;
                case 0:
                    System.out.println("Cảm ơn bạn đã sử dụng dịch vụ!");
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ. Vui lòng chọn lại.");
                    break;
            }
        } 
        while (luaChon != 0);

        scanner.close();
    }
}
