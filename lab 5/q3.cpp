#include "iostream"
#include <string>
using namespace std;

class Employees{
    public:
    string name;
    string Designation;
    Employees( string n, string d): name(n), Designation(d){}
};
class projects{
    public:
    string title;
    string deadline;
    Employees *employee[10];
    int ecount=0;
    projects (string t, string d): title(t), deadline(d){}
    void addemployee(Employees *emp){
        if(ecount<10){
            employee[ecount++]=emp;
        }
    }
    void display(){
        cout<<"Project title: "<<title<<"Deadline: "<<deadline<<endl;
        for (int i = 0; i < ecount; i++)
        {
            cout<<"Employee name: "<<employee[i]->name<<"Employee Designation: "<<employee[i]->Designation;
        }
        
    }
};
int main(){
    projects p1("webhunt", "2 week");
    Employees e1("Shahira", "manager");
    p1.addemployee(&e1);
    p1.display();
}