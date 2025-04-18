#include <iostream>
#include <string>
using namespace std;

class Patient{
    protected:
    string name;
    string id;

    public:
    Patient(string name, string id): name(name), id(id){}

    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;
};

class InPatient: public Patient{
    public:
    InPatient(string name,string id): Patient(name,id){}
    void displayTreatment(){
        cout << "displaying inpatient " << name << " treatment" << endl;
    }
    void calculateCost(){
        cout << "calculating inpatient " << name << " cost" << endl;
    }
};

class OutPatient: public Patient{
    public:
    OutPatient(string name,string id): Patient(name,id){}
    void displayTreatment(){
        cout << "displaying outpatient " << name << " treatment" << endl;
    }
    void calculateCost(){
        cout << "calculating outpatient " << name << " cost" << endl;
    }
};

int main(){
    InPatient p1("shahira","101");
    OutPatient p2("bashair","102");

    p1.displayTreatment();
    p1.calculateCost();

    p2.displayTreatment();
    p2.calculateCost();

    return 0;
}
