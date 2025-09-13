import java.util.Scanner;
public class Student {
    public static String name;
    public static int age;
    public static String address;
    public static String phoneNumber;
    public static String email;
    public static String nganhhoc;
    public static String studentID;
    public static double GPA;
    private double diemToan;
    private double diemLy;
    private double diemHoa;

    Scanner sc = new Scanner(System.in);

    // Phương thức nhập điểm với validation
    private double nhapDiem(String tenMon) {
        double diem;
        do {
            System.out.print("Nhap diem mon " + tenMon + " (0-10): ");
            while (!sc.hasNextDouble()) {
                System.out.println("Diem khong hop le. Vui long nhap lai.");
                sc.next(); // Đọc bỏ giá trị không hợp lệ
            }
            diem = sc.nextDouble();
            if (diem < 0 || diem > 10) {
                System.out.println("Diem phai tu 0 den 10. Vui long nhap lai.");
            }
        } while (diem < 0 || diem > 10);
        return diem;
    }

    public void inputInfo() 
    {
        do
        {
            System.out.print("Nhap ten sinh vien (bat buoc): ");
            name = sc.nextLine();
            if (name.trim().isEmpty()) {
                System.out.println("Ten sinh vien khong duoc de trong. Vui long nhap lai.");
            }
        } 
        while (name.trim().isEmpty());
        do 
        {
            System.out.print("Nhap tuoi sinh vien (tu 18 den 25): ");
            while (!sc.hasNextInt()) 
            {
                System.out.println("Tuoi khong hop le. Vui long nhap lai.");
                sc.next(); // Đọc bỏ giá trị không hợp lệ
            }
            age = sc.nextInt();
            if (age < 18 || age > 25) {
                System.out.println("Tuoi phai tu 18 den 25. Vui long nhap lai.");
            }
        } 
        while (age < 18 || age > 25);
        sc.nextLine(); // Đọc bỏ ký tự newline
        do 
        {
            System.out.print("Nhap dia chi sinh vien (bat buoc): ");
            address = sc.nextLine();
            if (address.trim().isEmpty()) {
                System.out.println("Dia chi khong duoc de trong. Vui long nhap lai.");
            }
        }
        while (address.trim().isEmpty());
        do 
        {
            System.out.print("Nhap so dien thoai sinh vien (10 chu so): ");
            phoneNumber = sc.nextLine();
            if (!phoneNumber.matches("\\d{10}")) {
                System.out.println("So dien thoai khong hop le. Vui long nhap lai.");
            }
        } 
        while (!phoneNumber.matches("\\d{10}"));
        do
        {
            System.out.print("Nhap email sinh vien (bat buoc): ");
            email = sc.nextLine();
            if (email.trim().isEmpty() || !email.matches("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,6}$")) {
                System.out.println("Email khong hop le hoac bi bo trong. Vui long nhap lai.");
            }
        }
        while (email.trim().isEmpty() || !email.matches("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,6}$"));

        System.out.print("Nhap nganh hoc: ");
        nganhhoc = sc.nextLine();
        System.out.print("Nhap ma sinh vien: ");
        studentID = sc.nextLine();
        System.out.print("Nhap diem GPA: ");
        if (0 <= GPA && GPA <= 4) {
            GPA = sc.nextDouble();
        } else 
        {
            System.out.println("GPA khong hop le. Vui long nhap lai.");
            sc.close(); // Đóng scanner 
        }
        // Nhập điểm các môn
        this.diemToan = nhapDiem("Toan");
        this.diemLy = nhapDiem("Ly");
        this.diemHoa = nhapDiem("Hoa");
    }

    // Phương thức tính điểm trung bình
    public double tinhDiemTrungBinh() {
        return (diemToan + diemLy + diemHoa) / 3;
    }

    public void displayInfo() 
    {
        System.out.println("Ten sinh vien: " + name);
        System.out.println("Tuoi sinh vien: " + age);
        System.out.println("Dia chi sinh vien: " + address);
        System.out.println("So dien thoai sinh vien: " + phoneNumber);
        System.out.println("Email sinh vien: " + email);
        System.out.println("Nganh hoc: " + nganhhoc);
        System.out.println("Mã sinh viên: " + studentID);
        System.out.println("--- Điểm số ---");
        System.out.println("Điểm Toán: " + diemToan);
        System.out.println("Điểm Lý: " + diemLy);
        System.out.println("Điểm Hóa: " + diemHoa);
        System.out.println("GPA: " + GPA);
        System.out.printf("Điểm trung bình: %.2f\n", tinhDiemTrungBinh());
    }

    public static void main(String[] args) {
        Student student = new Student();
        student.inputInfo();
        System.out.println("\n--- Thông tin sinh viên ---");
        student.displayInfo();
    }

}
