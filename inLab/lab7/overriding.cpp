#include <iostream>
using namespace std;

class Base{
    public:
    virtual void display(){ //virtual- override in derived class 
        cout << "Base display" << endl;
    }
};

class Derived : public Base{
    public:
    void display(){
        cout << "Derived display" << endl;
    }
};

int main(){
    // Base b1;
    // Derived d1;

    // b1.display();
    // d1.display();

    Base *ptr, b2;
    // ptr->display(); //not called,bcs it will find overriden func in derived bcs virtual
    Derived d2;
    //Base b2;

    ptr = &d2;
    ptr->display(); // Calls Derived display() since ptr points to Derived object, still runs base display bcs base ptr, early binding 
    // b2.display();

    ptr = &b2; // base ptr now points to Base object
    ptr->display(); // Calls base

    return 0;
}
