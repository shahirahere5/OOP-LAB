#include <iostream>
#include <fstream>
#include <cstring>  
using namespace std;


struct InventoryItem {
    int itemID;
    char itemName[20];  


    InventoryItem(int id = 0, const char* name = "") {
        itemID = id;
        strncpy(itemName, name, sizeof(itemName)-1);  
        itemName[sizeof(itemName)-1] = '\0';  
    }
};

int main() {

    InventoryItem itemToWrite(101, "Widget");

    
    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

   
    outFile.write(reinterpret_cast<char*>(&itemToWrite), sizeof(itemToWrite));
    outFile.close(); 


    InventoryItem itemToRead;

    
    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

   
    inFile.read(reinterpret_cast<char*>(&itemToRead), sizeof(itemToRead));
    inFile.close();  

  
    cout << "Loaded Item ID: " << itemToRead.itemID << endl;
    cout << "Loaded Item Name: " << itemToRead.itemName << endl;

    return 0;
}
