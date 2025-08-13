const member = {
    name: "Bùi Đức Anh",
    age: 19
}

function hello(){
    console.log("Hello, World!");
}

//1. Export default
//export default {member,hello};
//2. Export theo tên
//Cú pháp: export tên_biến hoặc export{variable1,variable2}
//export{member,hello}
//3. Import theo tên
//Cú pháp: import { tên_biến, tên_hàm} from url
// import{ member,hello} form "./member.js"
// console.log(member,name);
// console.log(member.age);
// hello();

//4. Import tất cả
import * as m from "./member.js"
console.log(m.member.name);
console.log(m.member.age);
m.hello();