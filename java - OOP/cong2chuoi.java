public class cong2chuoi {
    public static void main(String[] args) {
        String str1 = "Dai hoc ";
        String str2 = "Dai Nam";
        String result = str1 + str2; // Sử dụng toán tử + để nối chuỗi
        System.out.println(result); // In ra: Dai hoc Dai Nam
        System.out.println("Chuỗi kết quả in hoa: " + result.toUpperCase());
        System.out.println("Chiều dài của chuỗi: " + result.length());
    }
}
