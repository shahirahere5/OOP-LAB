#include <iostream>
#include <string>
using namespace std;

struct Product{
    int product_id;
    string product_name;
    int quantity;
    double price;
};

int main(){
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    Product *inventory = new Product[n];

    for(int i = 0; i < n; i++){
        cout << "Enter product ID, name, quantity, and price for product " << i+1 << ":" << endl;
        cin >> inventory[i].product_id;
        cin.ignore();
        getline(cin,inventory[i].product_name);
        cin >> inventory[i].quantity >> inventory[i].price;
    }

    double totalValue = 0;
    cout << "\nProduct Inventory:\n";
    for(int i = 0; i < n; i++){
        double prodValue = inventory[i].quantity * inventory[i].price;
        totalValue += prodValue;
        cout << "product " << i+1 << ":" << inventory[i].product_name << endl;
        cout << "ID: " << inventory[i].product_id << endl;
        cout << "Quantity: " << inventory[i].quantity << endl;
        cout << "Price: $" << inventory[i].price << endl;
        cout << "Value: $" << prodValue << endl;
        cout << "------------------------" << endl;
    }
    cout << "\nTotal Value of Inventory: $" << totalValue << endl;

    delete[] inventory;

    return 0;    
}