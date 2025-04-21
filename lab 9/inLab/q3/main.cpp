#include "lectureCourse.h"
#include "labCourse.h"
#include <iostream>
using namespace std;

int main(){
    Course* course1 = new LectureCourse("CS101",3);
    Course* course2 = new LabCourse("CS102",1);

    course1->displayInfo();
    course1->calculateGrade();

    course2->displayInfo();
    course2->calculateGrade();

    delete course1;
    delete course2;

    return 0;
}