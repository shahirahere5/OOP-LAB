#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
    string name;
    int age;
    string contactNumber;
    string address;

    public:
    Person(string n, int a, string c, string ad): name(n), age(a), contactNumber(c), address(ad){}

    virtual void displayInfo(){
        cout << "Name: " << name << ", Age: " << age << ", Contact Number: " << contactNumber << ", Address: " << address << endl;
    }

    void updateInfo(string n,int a,string c,string ad){
        name = n;
        age = a;
        contactNumber = c;
        address = ad;
        cout << "updated" << endl;
    }    
};

class Patient: public Person{
    protected:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

    public:
    Patient(string n, int a, string c, string ad, int id, string hist, string doc): Person(n,a,c,ad), patientID(id), medicalHistory(hist), doctorAssigned(doc){}

    void displayInfo() override {
        cout << "Patient ID: " << patientID << endl;
        Person::displayInfo();
        cout <<  "Medical History: " << medicalHistory << ", Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor: public Person{
    protected:
    string specialization;
    float consultationFee;
    string patientsList[5];
    int patientCount;

    public:
    Doctor(string n, int a, string c, string ad, string spec, float fee): Person(n,a,c,ad), specialization(spec), consultationFee(fee),patientCount(0){}

    void addPatient(string patientName){
        if(patientCount < 5){
            patientsList[patientCount++] = patientName;
            cout << patientName << " has been added to the patients list." << endl;
        }else{
            cout << "Patients list is full. Cannot add patient." << endl;
        }
    }    

    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << ", Consultation Fee: $" << consultationFee <<  endl;
        cout << "Patients list: \n";
        for(int i=0; i<patientCount ; i++){
            cout << patientsList[i] << endl;
        }
        cout << endl; 
    }
};

class Nurse : public Person{
    protected:
    string assignedWard;
    string shiftTimings;

    public:
    Nurse(string n, int a, string c, string ad, string ward, string timing): Person(n,a,c,ad), assignedWard(ward), shiftTimings(timing){}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << ", Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person{
    protected:
    string department;
    float salary;

    public:
    Administrator(string n, int a, string c, string ad, string dep, float s): Person(n,a,c,ad), department(dep), salary(s){}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << ", Salary: $" << salary << endl;
    }
};

int main(){
    Patient p1("shahira", 30, "123-456-7890", "123 Main St", 1, "Hypertension", "Dr. Smith");
    Doctor d1("hissham", 55, "987-654-3210", "456 Elm St", "Cardiology", 300.0);
    Nurse n1("ahmed", 45, "765-432-1098", "789 Oak St", "Cardiology Ward", "8:00 AM - 10:00 AM");
    Administrator admin1("talha",40,"123456","b-145","hr",9000);

    d1.addPatient("shahira");
    d1.addPatient("ahmed");

    p1.displayInfo();
    d1.displayInfo();
    n1.displayInfo();
    admin1.displayInfo();

    return 0;
}