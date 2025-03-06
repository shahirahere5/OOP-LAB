#include <iostream>
#include <string>
using namespace std;

class Account{
    protected:
    int accountNumber;
    float balance;

    public:
    Account(int a,float b){
        accountNumber = a;
        balance = b;
    }

    void displayDetails(){
        cout << "accNum: " << accountNumber << endl;
        cout << "balance: " << balance << endl;
    }
};

class SavingsAccount: public Account{
    protected:
    float interestRate;

    public:
    SavingsAccount(int a,float b,float i): Account(a,b){
        interestRate = i;
    }

    void displayDetails(){
        Account::displayDetails();
        cout << "interest rate: "<< interestRate << endl;
    }
};

class CheckingAccount : public Account{
    protected:
    float overdraftLimit;

    public:
    CheckingAccount(int a,float b,float o): Account(a,b){
        overdraftLimit = o;
    }

    void displayDetails(){
        Account::displayDetails();
        cout << "overdraft limit: " << overdraftLimit << endl;
    }
};

int main(){
    SavingsAccount s1(11425,10000.0,5.6);
    CheckingAccount c1(22456,500.0,12.2);
    s1.displayDetails();
    c1.displayDetails();
    return 0;
}