#include <iostream>
using namespace std;

class Car{
    private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;

    public:
    Car(string b, string m, double f){
        brand = b;
        model = m;
        fuelCapacity = f;
        currentFuelLevel = 0;
    }
    void drive(double fuelUsed){
        if(currentFuelLevel - fuelUsed >= 0){
            currentFuelLevel -= fuelUsed;
        } else {
            cout << "Not enough fuel to drive. Current fuel level: " << currentFuelLevel << endl;
        }
        cout << "Remaining fuel level: " << currentFuelLevel << endl;
    }
    void refuel(double fuelAdded){
        if(currentFuelLevel + fuelAdded <= fuelCapacity){
            currentFuelLevel += fuelAdded;
        } else {
            currentFuelLevel = fuelCapacity;
            cout << "Maximum fuel capacity reached. Refueling to maximum capacity." << endl;
        }
        cout << "Refueled. Current fuel level: " << currentFuelLevel << endl;
    }
    void checkFuelStatus(){
        cout << "Fuel status: " << currentFuelLevel << "/" << fuelCapacity << endl;
        if(currentFuelLevel < fuelCapacity/4){
            cout << "Low fuel level. Please refuel." << endl;
        }
    }         
};

int main(){
    Car myCar("Toyota", "Camry", 12.5);
    myCar.drive(5.0);
    myCar.refuel(3.0);
    myCar.checkFuelStatus();
    return 0;
}