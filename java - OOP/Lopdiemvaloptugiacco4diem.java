// Lop Diem
class Diem {
    private int x;
    private int y;

    public Diem(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public double khoangCach(Diem d) {
        return Math.sqrt(Math.pow(this.x - d.getX(), 2) + Math.pow(this.y - d.getY(), 2));
    }

    public void hienThi() {
        System.out.println("(" + x + ", " + y + ")");
    }
}

// Lop TuGiac su dung ket tap lop Diem
class TuGiac {
    private Diem A, B, C, D; // Sửa lỗi: Khai báo đầy đủ 4 biến Diem

    public TuGiac(Diem A, Diem B, Diem C, Diem D) {
        this.A = A;
        this.B = B;
        this.C = C;
        this.D = D;
    }

    public void hienThiCacDinh() {
        System.out.println("Toa do cac dinh cua tu giac:");
        System.out.print("Diem A: ");
        A.hienThi();
        System.out.print("Diem B: ");
        B.hienThi();
        System.out.print("Diem C: ");
        C.hienThi();
        System.out.print("Diem D: ");
        D.hienThi();
    }

    public void hienThiCacCanhVaDoDai() {
        System.out.println("\nCac canh va do dai tuong ung:");
        System.out.printf("Canh AB: %.2f\n", A.khoangCach(B));
        System.out.printf("Canh BC: %.2f\n", B.khoangCach(C));
        System.out.printf("Canh CD: %.2f\n", C.khoangCach(D));
        System.out.printf("Canh DA: %.2f\n", D.khoangCach(A));
    }
}

public class Lopdiemvaloptugiacco4diem {
    public static void main(String[] args) {
        // Khoi tao 4 diem
        Diem diemA = new Diem(1, 1);
        Diem diemB = new Diem(2, 5);
        Diem diemC = new Diem(6, 4);
        Diem diemD = new Diem(5, 0);

        // Khoi tao tu giac
        TuGiac tuGiac = new TuGiac(diemA, diemB, diemC, diemD);

        // Hien thi toa do cac dinh cua tu giac
        tuGiac.hienThiCacDinh();

        // Hien thi cac canh va do dai
        tuGiac.hienThiCacCanhVaDoDai();
    }
}