#include <iostream>
#include <string>
using namespace std;

class LowBalanceException {
public:
    string message;
    LowBalanceException(string msg) : message(msg) {}
    string what() { return message; }
};

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNum, double initialBalance) : accountHolder(name), accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw LowBalanceException("Insufficient balance for withdrawal.");
        }
        balance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << balance << endl;
    }

    void displayBalance() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    try {
        BankAccount account("Shreya Rawat", 123456, 5000);

        account.displayBalance();

        cout << "\nAttempting to withdraw 2000..." << endl;
        account.withdraw(2000);

        cout << "\nAttempting to withdraw 4000..." << endl;
        account.withdraw(4000);  // This will throw an exception

    } catch (LowBalanceException &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}