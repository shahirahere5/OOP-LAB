#include "iostream"
#include <string>
using namespace std;
class Car{
    string brand;
    string model;
    float rentalprice;
    bool availabilitystatus;
    public:
    Car(){
        brand="Unknown";
        model="Generic";
        rentalprice=0.0;
        availabilitystatus=true;
    }
    void update(string b, string m, float r){
        brand=b; model=m; rentalprice=r;
    }
    bool availaibility(){
        return availabilitystatus;
    }
    void rent(){
        if(availabilitystatus){
            availabilitystatus=false;
            cout<<"Car is Rented"<<endl;
        }
        else{
            cout<<"Car not Available!";
        }
    }
};
int main(){
    Car c1;
    c1.update("Corolla", "Toyota", 500.5);
    c1.rent();
    return 0;
}