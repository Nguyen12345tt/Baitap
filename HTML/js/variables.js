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
//2.2. Kiểu dữ liệu
// Chú ý: Trong js sử dụng typeof để biết kiểu dữ liệu của biến
//2.2.1. Kiểu number
var a = 3;
console.log("Kiểu dữ liệu của biến a là:" + typeof a);
var d = 3.33333;
console.log("Kiểu dữ liệu của biến d là:" + typeof d);
//2.2.2. Kiểu string
var name = "Phạm Anh Tuấn";
console.log ("name =" + name);
console.log ("Biến name có kiểu dữ liệu là:" + typeof name);
//2.2.3. Kiểu boolean
var isSuccess = true;
console.log("isSuccess = " + isSuccess);
console.log("Biến isSuccess có kiểu dữ liệu là:" + typeof isSuccess);
//2.2.4. Kiểu null
var e = null;
console.log("e=" +e);
console.log("Biến e có kiểu dữ liệu là:" + typeof e);
//2.2.5. Kiểu undefined
var f;
console.log("f=" +f);
console.log("Kiểu dữ liệu của f là:" + typeof f);
//2.2.6. Kiểu đối tượng (object)
// Đối tượng là 1 thứ gì đó trong thực tế chúng ta có thể nhìn thấy, sờ thấy
// hoặc cảm nhận được
// Mọi đối tượng sẽ gồm 2 thành phần:
    // Thuộc tính (attributes):Thuộc tính của đối tượng
    // Hành vi (behaviors): Hành vi của đối tượng
var student={
    msv: 1871020678,
    name: "Hà Minh Vượng",
    address: "Hà Nội",
    gender:"Nữ",
    isAlone:true,
    nguoiyeu:{
        msv: 1971020000,
        name: "Như Hoa",
    },
    say(){
        console.log("Hello");
    }
}
//Muốn truy cập đến thuộc tính hoặc phương thức của đối tượng chúng ta sẽ thông qua dấu .
console.log("name:" + student.name);
console.log("address:" + student.address);
student.say()
console.log("Tên người yêu:" + student.nguoiyeu.name); 