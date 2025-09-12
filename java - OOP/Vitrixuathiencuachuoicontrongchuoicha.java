import java.util.Scanner;
public class Vitrixuathiencuachuoicontrongchuoicha 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap chuoi cha: ");
        String chuoiCha = scanner.nextLine();
        System.out.print("Nhap chuoi con: ");
        String chuoiCon = scanner.nextLine();
        int viTri = chuoiCha.indexOf(chuoiCon);
        if (viTri != -1) 
        {
            System.out.println("Chuoi con xuat hien trong chuoi cha tai vi tri: " + viTri);
        } 
        else   
        {
            System.out.println("Chuoi con khong xuat hien trong chuoi cha.");
        }
    scanner.close();
    }
}
