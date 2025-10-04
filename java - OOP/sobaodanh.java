/**
 * Giải thích codes:
 *
 * 1. Phương thức `printArray` (Generic Method):
 *    - `public static <E> void printArray(E[] inputArray)`: Đây là cú 
 *      pháp để khai báo một phương thức generic.
 *      - `<E>`: Đây là phần khai báo "tham số kiểu" (type parameter). 
 *      Nó báo cho trình biên dịch biết rằng `E` là một kiểu dữ liệu tạm 
 *      thời, sẽ được xác định khi phương thức được gọi. 
 *      Bạn có thể dùng bất kỳ ký tự nào khác (ví dụ: T, V), 
 *      nhưng `E` (viết tắt của Element) là một quy ước phổ biến.
 *      - `void`: Phương thức này không trả về giá trị nào.
 *      - `printArray(E[] inputArray)`: Phương thức nhận vào một 
 *      tham số là một mảng có kiểu `E`.
 *
 *    - `for (E element : inputArray)`: Vòng lặp "for-each" 
 *      duyệt qua từng `element` trong mảng `inputArray`. 
 *      Vì kiểu của mảng là `E`, nên kiểu của mỗi phần tử cũng là `E`.
 *
 *    - `System.out.printf("%s ", element);`: In ra từng phần tử. 
 *      `%s` được dùng vì phương thức `toString()` của mọi đối 
 *      tượng trong Java đều trả về một chuỗi, giúp nó hoạt động được 
 *      với mọi kiểu dữ liệu.
 *
 * 2. Phương thức `main`:
 *    - `Integer[] sbdArray = { 2025001, 2025002, 2025003 };`: Khai báo 
 *      và khởi tạo một mảng số nguyên (số báo danh). Lưu ý: phải dùng 
 *      lớp vỏ `Integer` thay vì kiểu nguyên thủy `int` vì generic không hoạt 
 *      động với các kiểu nguyên thủy.
 *    - `String[] tenArray = { "Nguyễn Văn An", "Trần Thị Bình", "Lê Văn Cường" };`: Khai báo và khởi tạo 
 *      một mảng chuỗi (họ tên).
 *    - `printArray(sbdArray);`: Gọi phương thức `printArray`. Tại đây, Java tự động suy ra rằng kiểu `E` 
 *      chính là `Integer` cho lần gọi này.
 *    - `printArray(tenArray);`: Gọi lại cùng một phương thức `printArray`. Lần này, Java suy ra rằng 
 *      kiểu `E` là `String`.
 *
 * => Lợi ích chính của generic method là bạn chỉ cần viết một phương thức `printArray` duy nhất có thể 
 *      hoạt động với nhiều kiểu dữ liệu khác nhau (Integer, String, Double,...) mà không cần viết 
 *      lại nhiều phiên bản của cùng một phương thức (overloading).
 */

public class sobaodanh {

    // 1. Xây dựng phương thức tổng quát (Generic Method) để in mảng
    public static <E> void printArray(E[] inputArray) {
        // Duyệt qua tất cả các phần tử trong mảng và in chúng
        for (E element : inputArray) {
            System.out.printf("%s ", element);
        }
        System.out.println(); // In xuống dòng sau khi hết mảng
    }

    public static void main(String[] args) {
        // 2. Thử nghiệm với mảng số báo danh (Integer)
        Integer[] sbdArray = { 2025001, 2025002, 2025003, 2025004 };

        System.out.println("Mang so bao danh sinh vien:");
        // Gọi phương thức generic với mảng Integer
        printArray(sbdArray);

        System.out.println(); // In một dòng trống để ngăn cách

        // 3. Thử nghiệm với mảng họ tên sinh viên (String)
        String[] tenArray = { "Nguyen Van An", "Tran Thi Binh", "Le Van Cuong" };

        System.out.println("Mang ho ten sinh vien:");
        // Gọi cùng phương thức generic đó với mảng String
        printArray(tenArray);
    }
}
