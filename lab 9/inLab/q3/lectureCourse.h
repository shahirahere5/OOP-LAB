#pragma once

#include <iostream>
#include "course.h"
using namespace std;

class LectureCourse : public Course{
    public:
    LectureCourse(string code, int credits);
    void calculateGrade() override;
    void displayInfo() override;
};