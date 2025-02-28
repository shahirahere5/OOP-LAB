1:

#include <iostream>
#include <string>
using namespace std;

class Employee{
    public:
    string name;
    float salary;

    
    Employee(string name, float salary) : name(name), salary(salary){}

    void displayDetails(){
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Manager : public Employee{
    public:
    float bonus;

    
    Manager(string name,float salary,float bonus) : Employee(name,salary), bonus(bonus){}
    void displayDetails(){
        Employee::displayDetails();
        cout << "Bonus: $" << bonus << endl;
    }
};

int main(){
    Manager hr("shahira",12000.0,2000.0);
    hr.displayDetails();
    return 0;
}


2:
#include <iostream>
using namespace std;

class Vehicle{
    protected:
    string brand;
    int speed;
    public:
    Vehicle(string brand,int speed): brand(brand),speed(speed){}

    void displayDetails(){
        cout << "brand: " << brand << endl;
        cout << "speed: " << speed << endl;
    }
};

class Car : public Vehicle{
    protected:
    int seats;
    public:
    Car(string brand,int speed,int seats) : Vehicle(brand,speed), seats(seats){}

    void displayDetails(){
        Vehicle :: displayDetails();
        cout << "seats: " << seats << endl;
    }
};

class ElectricCar: public Car{
    protected:
    int batteryLife;
    public:
    ElectricCar(string brand,int speed,int seats,int batteryLife): Car(brand,speed,seats),batteryLife(batteryLife){}

    void displayDetails(){
        Car :: displayDetails();
        cout << "battery life: " << batteryLife << endl;
    }
};

int main(){
    ElectricCar car("toyota",220,2,14);
    car.displayDetails();
    return 0;
}
