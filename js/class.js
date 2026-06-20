let data = "secret data";
class User{
    constructor(name,email){
        this.name = name;
        this.email=email;
    }

    viewData(){
        console.log("Data : " , data);
    }
}

class Admin extends User{
    constructor(name,email){
        super(name,email);
    }
}
let student1 = new User("user1" , "abshdb@gamil.com");
let student2 = new User("user2" , "hbihrviuahr@gmail.com");

student1.viewData();
student2.viewData();

let Admin1 = new Admin("admin" , "aajnbjsc.@gmail.com")