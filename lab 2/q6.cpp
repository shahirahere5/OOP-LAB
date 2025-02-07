#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int rollNo;
    int marks[3];
};

int main(){
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for(int i = 0; i < n; i++){
        cout << "Enter name, roll number, and marks for student " << i+1 << ":" << endl;
        cin.ignore();
        getline(cin, students[i].name);
        cin >> students[i].rollNo;
        for(int j = 0; j < 3; j++){
            cin >> students[i].marks[j];
        }
    }

    cout << "Student Details:" << endl;
    for(int i = 0; i < n; i++){
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNo << endl;

        int total =0;
        for(int j = 0; j < 3; j++){
            total += students[i].marks[j];
        }
        cout << "average marks: " << total / 3.0 << endl;
    }

    delete[] students;
    return 0;
}