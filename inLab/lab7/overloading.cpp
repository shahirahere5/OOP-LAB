#include <iostream>
using namespace std;

// int abc(int x,int y){
//     return x+y;
// }

// double abc(double x,double y){
//     return x+y;
// }

// float abc(float x,float y){
//     return x+y;
// }

class base{
    public:
    void display(int x){
        cout << "Display base int: " << x << endl;
    }

    void display(double x){
        cout << "Display base double: " << x << endl;
    }
};

class derived : public base{
    public:
    using base::display; //hidden existence in base class bcs overloaded
    void display(const char* c){ // equivalent to string
        cout << "Display derived char*: " << c << endl;
    }
};

int main(){
    // cout << "abc(): int " << abc(3,4) << endl;
    // cout << "abc(): double " << abc(3.5,4.5) << endl; // for float, write f w parameters. bcs float casting
    // cout << "abc(): float " << abc(3.5f,4.5f) << endl; // for float, write f w parameters. bcs float casting

    base b;
    b.display(3);
    b.display(3.5);


    derived d;
    d.display(3);
    d.display(3.5);
    d.display("Hello");

    return 0;
}
