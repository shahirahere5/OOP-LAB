#include <iostream>
#include <string>
using namespace std;

struct Employee{
    string name;
    int hoursWorked;
    double hourlyRate;
};

int main(){
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    Employee* employee = new Employee[n];

    for(int i=0; i<n; i++){
        cout << "Enter name for employee " << i+1 << ":";
        cin.ignore();
        getline(cin, employee[i].name);

        cout << "Enter hours worked and hourly rate for " << employee[i].name << ": ";
    cin >> employee[i].hoursWorked >> employee[i].hourlyRate;
    }


    for(int i=0; i<n;i++){
        double pay = employee[i].hoursWorked * employee[i].hourlyRate;
        cout << "Employee " << i + 1 << " (" << employee[i].name << "): Pay = $" << pay << endl;
    }
    return 0;
}