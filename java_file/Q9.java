import java.util.Scanner;

class Q9 {
    String name, address;
    int account_no;
    double balance;
    static int nextAccountNo = 1001; 

    Q9(String name, String address, double balance) {
        this.name = name;
        this.address = address;
        this.account_no = nextAccountNo++;
        this.balance = balance;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Account number: " + account_no);
        System.out.println("Balance: " + balance);
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("New balance: " + balance);
    }

    void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("Insufficient Balance...");
        } else {
            balance -= amount;
            System.out.println("Modified Balance: " + balance);
        }
    }

    void updateAddress(String newAddress) {
        address = newAddress;
        System.out.println("Updated Address: " + address);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Q9[] accounts = new Q9[10]; 
        int numAccounts = 0;
        int choice = 0,check  = 0;
        System.out.println("1 to create a user with all details");
        System.out.println("2 to display information and balance of user");
        System.out.println("3 to deposit more value in account");
        System.out.println("4 to withdraw amount from user");
        System.out.println("5 to change the address of the user");
        System.out.println("6 to exit");
        while (choice != 7) {
            
            check = 0;
            choice = sc.nextInt();
            sc.nextLine(); 

            switch (choice) {
                case 1:
                    if (numAccounts < accounts.length) {
                        System.out.print("Enter name: ");
                        String name = sc.nextLine();
                        System.out.print("Enter address: ");
                        String address = sc.nextLine();
                        System.out.print("Enter balance: ");
                        double balance = sc.nextDouble();
                        sc.nextLine();
                        accounts[numAccounts++] = new Q9(name, address, balance);
                    } else {
                        System.out.println("Account limit reached.");
                    }
                    break;

                case 2:
                    System.out.println("enter the account number : ");
                    int Account_no = sc.nextInt();
                    for(Q9 acc : accounts){
                        if(acc != null && acc.account_no == Account_no ){
                            acc.display();
                            check = 1;
                        }
                    }
                    if(check == 0){
                        System.out.println("No Account Found...........");
                    }
                    break;

                case 3:
                    System.out.print("Enter account number to deposit to: ");
                    int depositAccNo = sc.nextInt();
                    System.out.print("Enter the amount you want to add: ");
                    double amount = sc.nextDouble();
                    sc.nextLine(); 
                    for (Q9 acc : accounts) {
                        if (acc != null && acc.account_no == depositAccNo) {
                            acc.deposit(amount);
                            break;
                        }
                    }
                    break;

                case 4:
                    System.out.print("Enter account number to withdraw from: ");
                    int withdrawAccNo = sc.nextInt();
                    System.out.print("Enter the amount you want to withdraw: ");
                    amount = sc.nextDouble();
                    sc.nextLine(); 
                    for (Q9 acc : accounts) {
                        if (acc != null && acc.account_no == withdrawAccNo) {
                            acc.withdraw(amount);
                            break;
                        }
                    }
                    break;

                case 5:
                    System.out.print("Enter account number to update address: ");
                    int updateAccNo = sc.nextInt();
                    sc.nextLine(); 
                    System.out.print("Enter the new address: ");
                    String newAddress = sc.nextLine();
                    for (Q9 acc : accounts) {
                        if (acc != null && acc.account_no == updateAccNo) {
                            acc.updateAddress(newAddress);
                            break;
                        }
                    }
                    break;

                case 6:
                    System.out.println("Exiting code...");
                    break;

                default:
                    System.out.println("Invalid input...");
                    break;
            }
        }
        sc.close();
    }
}
