#pragma once

#include "course.h"
#include <iostream>
using namespace std;

class LabCourse: public Course{
    public:
    LabCourse(string code, int credits);
    void calculateGrade() override;
    void displayInfo() override;
};