import java.util.*;
class lowBalanceException extends Exception{
    public lowBalanceException(String message){
        super(message);
    }
}
class Bank{
    int Acc_no;
    double balanace;
    String name;
    Bank(int Acc_no , double balanace , String name){
        this.Acc_no = Acc_no;
        this.balanace = balanace;
        this.name = name;
    }
    void deposite(int ammount){
        balanace += ammount;
        System.out.println("Modified balanace : " + balanace);
    }
    void withdrawl(int ammount){
        try{
            if(balanace < ammount){
                throw new lowBalanceException("low balance");
            }
        balanace -=ammount;
        System.out.println("Modified balanace : " + balanace);
        }catch(lowBalanceException e){
            System.out.println(e.getMessage());
        }
    }
}
public class extra {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Bank b1 = new Bank(1001,3456,"Aman");
        System.out.println("enter the ammount you want to deposit");
        int ammount = sc.nextInt();
        b1.deposite(ammount);
        System.out.println("enter the ammount you want to withdraw");
        int amm = sc.nextInt();
        b1.withdrawl(amm);

    }
}
