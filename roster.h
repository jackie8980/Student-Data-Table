#pragma once
#include "student.h"

class Roster
{
private:
    int lastIndex = -1; //static value for last index in array for increment value
    const static int numStudents = 5;
    Student* studentDataArray[numStudents];
    
public:
    void parse(string row);
    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeprogram);
    void printAll();
    void printByDegreeProgram(DegreeProgram degreeprogram);
    void printInvalidEmails();
    void printAverageDaysInCourse();
    void remove(string studentID);
    ~Roster(); //deconstructor
};
