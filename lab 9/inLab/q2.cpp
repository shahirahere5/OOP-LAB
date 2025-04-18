#include <iostream>
#include <string>
using namespace std;

class MenuItem{
    protected:
    string dishName;
    double price;

    public:
    MenuItem(string d,double p):dishName(d),price(p){}
    virtual void showDetails() = 0;
    virtual void prepare() =0;
};

class Appetizer: public MenuItem{
    public:
    Appetizer(string d, double p): MenuItem(d,p){}

    void showDetails(){
        cout << "appetizer: " << endl;
        cout << "dish name: " << dishName << endl;
        cout << "price: " << price << endl;
    }
    void prepare(){
        cout << "preparing appetizer " << dishName << endl;
    }
};

class MainCourse: public MenuItem{
    public:
    MainCourse(string d, double p): MenuItem(d,p){}

    void showDetails(){
        cout << "main course: " << endl;
        cout << "dish name: " << dishName << endl;
        cout << "price: " << price << endl;
    }
    void prepare(){
        cout << "preparing main course " << dishName << endl;
    }
};

int main(){
    Appetizer Appetizer("tikka",500.0);
    MainCourse MainCourse("biryani",1500.0);

    Appetizer.showDetails();
    Appetizer.prepare();

    MainCourse.showDetails();
    MainCourse.prepare();

    return 0;
}
