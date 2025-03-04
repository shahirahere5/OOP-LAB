#include "iostream"
#include <string>
using namespace std;

class Doctors
{
    private:
    string name, specialization;
    int experience;
    public:
    Doctors(string name, string specialization, int experience): name(name), specialization(specialization), experience(experience){}
    void display(){
        cout<<"Doctor name: "<<name<<"  Specialization: "<<specialization<<"    Experience: "<<experience<<" years"<<endl;
    }
};
class Hospital{
    private:
    string name;
    Doctors* doctors[10];
    int count;
    public:
    Hospital(string n):name(n), count(0){}
    void addDoctor(Doctors* d){
        if(count<10){
        doctors[count++]=d;}
        else{
            cout<<"Can't add more doctors!"<<endl;
        }
    }
    void display(){
        cout<<"Hospital name:"<<name<<"\nList of Doctors:"<<endl;
        for (int i = 0; i < count; i++)
        {
            doctors[i]->display();
        }
    }
};

int main(){
    Hospital h1("Shifa Hospital");
    Doctors d1("Dr. Rida", "Cardiology", 10);
    Doctors d2("Dr. Zafar", "Neurology", 8);
    Doctors d3("Dr. Qamar", "Orthopedics", 12);
    h1.addDoctor(&d1);
    h1.addDoctor(&d2);
    h1.addDoctor(&d3);
    h1.display();
    return 0;
}