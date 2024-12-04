/* 2. Biến
    Biến được sử dụng để lưu trữ giá trị
    Cú pháp khai báo biến: từ_khóa tên_biến = giá_trị;
    Trong đó:
        - từ_khóa: sẽ có 3 loại là var, let, const
        - tên_biến: Đặt theo quy tắc con lạc đà (Camel case)
        - giá_trị: Giá trị của biến
    Chú ý: Kiểu dữ liệu của biến sẽ thay đổi theo giá trị của biến
    Sự khác nhau giữa các từ_khóa:
        - var: Khai báo biến toàn cục, hosting
        - let: Khai báo biến cục bộ
        - const: Khai báo hằng số */
var a = 3;
let b = 4;
const c = 5;
{
    var a = 6;
    let b = 7;
    const c = 8;
}
var s = a + b + c;
console.log ("s="+ s);