//document.write("<h2>CNTT 18-09</h2>")
//Hiển thị thông báo
//alert("Xin chào các bạn");
//Giao tiếp với client sử dụng prompt
//var name =window.prompt("Nhập tên của bạn:");
//document.write("Họ tên:"+ name);
//Confirm với người dùng
//var result =confirm ("Bạn chắc chắn muốn chuyển sang youtube.com");
//if (result !="0")
//{
//    top.location = "https://youtube.com";
//}
// Lệnh console.log
console.log("Đố các bạn biết hiển thị ở đâu?");
/*Lệnh setTimeout(): Delay 1 khoảng thời gian sau đó sẽ thực hiện 1 câu lệnh hoặc khối lệnh
Cú pháp: setTimeout(function(), time)
Trong đó: 
    - function là hàm sẽ được thực thi
    - time là thời gian delay đơn vị miliseconds
1 seconds (1 giây) = 1000 miliseconds (1000 mili giây)
setTimeout(()=>{
    console.log("Đoạn text này sẽ hiển thị sau 5 giây ");
},5000)
Hàm setInternal(): Thực hiện 1 câu lệnh hoặc khối lệnh sau 1 khoảng thời gian đã được
xác định, thực hiện mãi mãi
Cú pháp: setInterval(function(),time)
Trong đó:
    function() hàm sẽ được thực thi
    time thời gian delay*/
setInterval(()=>{
    console.log("CNTT 18-09");
    console.log("Hello");
},1000)
