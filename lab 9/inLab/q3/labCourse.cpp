#include <iostream>
#include "labCourse.h"
using namespace std;

LabCourse::LabCourse(string code, int credits): Course(code,credits){}

void LabCourse::calculateGrade(){
    cout << "calculating grade for lab course: " << courseCode << endl;
}

void LabCourse::displayInfo(){
    cout << "lab course code: " << courseCode << endl;
    cout << "credits: " << credits << endl;
}