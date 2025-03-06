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