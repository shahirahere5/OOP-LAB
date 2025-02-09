#include <iostream>
using namespace std;

class Wallet{
    private:
    string ownerName;
    double totalBalance;
    string transactionHistory;

    public:
    Wallet(string name,double balance){
         ownerName = name;
         totalBalance = balance;
         transactionHistory = "";
    }   
    void addMoney(double amount){
        totalBalance += amount;
        transactionHistory += "Added: $" + to_string(amount) + "\n";
    }
    void spendMoney(double amount){
        if(amount > totalBalance){
            cout << "Insufficient funds!" << endl;
        }else{
            totalBalance -= amount;
            transactionHistory += "Spent: $" + to_string(amount) + "\n";
        }
    }
    void displayHistory(){
        cout << "Transaction history for " << ownerName << ":" << endl;
        cout << transactionHistory;
    }
    double getBalance(){
        return totalBalance;
    }  
     
};

int main(){
    Wallet myWallet("saad", 1000.00);
    myWallet.addMoney(500.00);
    myWallet.spendMoney(200.00);
    myWallet.displayHistory();
    cout << "Current balance: $" << myWallet.getBalance() << endl;
    return 0;
}