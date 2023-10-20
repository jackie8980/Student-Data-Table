#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student {
public:
    const static int daysArraySize = 3;
private:
    //data values
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[daysArraySize];
    DegreeProgram degreeprogram;
public:
    
    //constructors
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram);
    //destructor
    ~Student();
    
    //getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    //setters (mutators)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
    void setDays(int day[]);
    void setDegreeProgram(DegreeProgram degreeprogram);
    
    static void printHeader();
    
    void print();
};
