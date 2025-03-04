#include "iostream"
#include <cstring>
using namespace std;

class Apartment
{
public:
    int ID;
    string address;
    char* ownername;
    Apartment(int i, string addr, char* owner) : ID(i), address(addr){
        ownername = new char[strlen(owner)+1];
        strcpy(ownername, owner);
    }
    Apartment(Apartment &obj):ID(obj.ID), address(obj.address)
    {
        ownername = new char[strlen(obj.ownername) + 1];
        strcpy(ownername, obj.ownername);
    }
    void display()
    {
        cout << "ID: " << ID << ", Address: " << address << ", Name: " << ownername << endl;
    }
    ~Apartment(){
        delete[] ownername;
    }
};

int main(){
    Apartment a1(1, "L block", "Shahira");
    Apartment a2=a1;
    a1.display();
    
    a2.display();
    return 0;
}