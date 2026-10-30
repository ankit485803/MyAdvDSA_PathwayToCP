

/* nkAccount using Encapsulation.

Question 2 : Create a class BankAccount with private attributes accountNumber and 
balance. Implement public methods deposit(), withdraw(), and getBalance() to 
manage the account. 


Constructor – Initializes the bank account.
Encapsulation – Keeps account details private.
Member functions – Deposit, withdraw, and retrieve balance


*/

#include <iostream>
#include <string>
using namespace std;


class BankAccount {  //rough works
private:
    int accountNum, balance;

public:
    //three methods
    void deposit() {
        cout << "deposit your money to account..\n";
    }

    void withdraw() {
        cout << "withdraw cash..\n";
    }

    void getBalance() {
        cout << "check bank balance..\n";
    }
    
};



int main() {


    return 0;
}



#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    //create Member functions – Deposit, withdraw, and retrieve balance
    // Constructor
    BankAccount(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully!" << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully!" << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Get current balance
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account(12345, 5000);

    cout << "current balance: " << account.getBalance() << endl;

    account.deposit(2000);
    account.withdraw(1500);

    cout << "After deposit & withdraw, Balance = " << account.getBalance() << endl;

    return 0;
}
