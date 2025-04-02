#include <iostream>
using namespace std;

class Account;

void transferFunds(Account& from, Account& to, double amount);

class Manager{
    public:
    void deposit(Account& account, double amount);
    void withdraw(Account& account, double amount);
    void displayAccount(Account& account);
};

class Account{
    private:
    int accNum;
    double balance;

    public:
    Account(int a, double b){
        accNum = a;
        balance = b;
    }

    friend class Manager;

    friend void transferFunds(Account& from, Account& to, double amount);
};

void Manager::deposit(Account& account, double amount){
    if(amount < 0){
        cout << "Invalid deposit amount!" << endl;
        return;
    }else{
        account.balance += amount;
        cout << "Deposit successful. New balance: $" << account.balance << endl;
    }
};

void Manager::withdraw(Account& account, double amount){
    if( amount > 0 && amount <= account.balance){
        account.balance -= amount;
        cout << "Withdrawal successful. New balance: $" << account.balance << endl;
    }else{
        cout << "Invalid withdrawal amount or insufficient funds!" << endl;
    }
}

void Manager::displayAccount(Account& account){
    cout << "Account Number: " << account.accNum << endl;
    cout << "Balance: $" << account.balance << endl;
}

void transferFunds(Account& from, Account& to, double amount){
    if(amount > 0 && amount <= from.balance){
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer successful. New balance for " << from.accNum << ": $" << from.balance << endl;
        cout << "New balance for " << to.accNum << ": $" << to.balance << endl;
    } else{
        cout << "Invalid transfer amount or insufficient funds!" << endl;
    }
}

int main(){
    Account acc1(12345, 1000.00);
    Account acc2(67890, 500.00);

    Manager manager;

    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    manager.deposit(acc1, 500.00);
    manager.withdraw(acc2, 200.00);

    transferFunds(acc1, acc2, 300.00);

    return 0;
}