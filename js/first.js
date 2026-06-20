// const product = {
//     title: "ball Pen",
//     rating: 4,
//     offer: 5,
//     price: 250
// };

// const profile = {

//     username : "xyz",
//     follower : 543,
//     following : 4,
//     post : 123, 
//     isFollow : true,
//     bio : "i am kndccsjinjihdnhhdjnhjdc c"
// };
// console.log(profile);
// let name = prompt("hello");
// console.log(name);

// let num = prompt("enter the number");

// if(num % 5 == 0){
//     console.log("multiple of 5");
// }else{
//     console.log("not a multiple of 5");
// }

// ( num % 5 === 0) ? consol.log("multiple of 5") : console.log("not a multiple of 5");

// Practice 3
// let name = prompt("enter your name: ");

// let user_name = '@';
// let n = name.length;
// name = name.concat(n);
// user_name = user_name.concat(name);
// console.log(new_user_name);

//practice 4
// let arr = ["aman" , "raman" , "rahul" , "saman" , "arjun", "sahil"];
// let sum = 0;
// for(let i = 0 ; i < arr.length ; i++){
//     sum +=arr[i];
// }
// sum /= arr.length;
// arr.push(40);
// arr.pop();

// // for(let val of arr){
// //     console.log(val);
// // }
// arr.shift();
// arr.unshift('aman');
// // arr.slice(sindex,endindex);
// // arr.slice(1,4);
// // console.log(arr.slice(1,4));
// arr.splice(2,2,"shagun","kamal");
// console.log(arr);

//practice 4.2

// let arr = ["Bloomberg" , "Microsoft" , "Uber" , "Google" , "IBM" , "Netflix"];
// console.log(arr);
// arr.shift();
// console.log(arr);

// arr.splice(1,1,"Ola");
// console.log(arr);

// arr.push("Amazon");
// console.log(arr);

//Practice 5

// function count_vowels(str){
//     let count = 0;
//     for(let char of str){
//         if(char === 'a' || char ==='e' || char === 'i' ||char === 'o' ||char === 'u'){
//             count++;
//         }
//     }
//     return count;
// }

// const ArrowCount_vowels = (str) => {
//     let count = 0;
//     for(let char of str){
//         if(char === 'a' || char ==='e' || char === 'i' ||char === 'o' ||char === 'u'){
//             count++;
//         }
//     }
//     return count;
// }

// let str = prompt("enter the string");
// let count = ArrowCount_vowels(str);
// console.log(count);



//Practical 5.2
// arr = [23,5,67,56,43,556];

// // arr.forEach((val)=>{
// //     console.log(val**2);
// // })

// let sq = (val)=>{
//     console.log(val**2);
// };

// let newArr = arr.map((val)=>{
//     return val**2;
// })
// console.log(newArr)

// let newArr1 = arr.filter((val) =>{
//     return val % 5 !== 0;
// })

// console.log(newArr1);
// arr.forEach(sq);


//Practical No 5.3

let n = prompt("enter number");
let arr = [];
for(let i = 0 ; i < n ; i++){
    arr[i] = i+1;
}
const output = arr.reduce((res,val) =>{
    return res +  val;
})

const output1 = arr.reduce((res,val) =>{
    return res *  val;
})

console.log(output);
console.log(output1);
