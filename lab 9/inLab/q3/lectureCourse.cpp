#include <iostream>
#include "lectureCourse.h"
using namespace std;

LectureCourse::LectureCourse(string code, int credits):Course(code,credits){}

void LectureCourse::calculateGrade(){
    cout << "calculating grade for lecture course: " << courseCode << endl;
}

void LectureCourse::displayInfo(){
    cout << "lecture course code: " << courseCode << endl;
    cout << "credits: " << credits << endl;
}