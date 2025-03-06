#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
    string name;
    int age;

    public:
    Person(string n, int a){
        name = n;
        age = a;
    }

    void displayDetails(){
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : public Person{
    protected:
    string subject;

    public:
    Teacher(string n, int a, string sub) : Person(n, a){
        subject = sub;
    }
    
    void displayDetails(){
        Person::displayDetails();
        cout << ", Subject: " << subject << endl;
    }
};

class Researcher : public Person{
    protected:
    string researchArea;

    public:
    Researcher(string n,int a,string r) : Person(n,a){
        researchArea = r;
    }

    void displayDetails(){
        cout << ", Research Area: " << researchArea << endl;
    }

};  

class Professor: public Teacher, public Researcher{
    protected:
    int publications;

    public:
    Professor(string n,int a,string sub,string area, int pub):Teacher(n,a,sub),Researcher(n,a,area){
        publications = pub;
    };

    void displayDetails(){
        Teacher:: displayDetails();
        Researcher:: displayDetails();
        cout << "publications: " << publications << endl;
    }
};

int main(){
    Professor p1("shahira",19,"cs","mvc",23);
    p1.displayDetails();
    return 0;
}