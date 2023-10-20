#include "student.h"
using namespace std;

//initializes a blank student template
Student::Student()
{
    this -> studentID = "";
    this -> firstName = "";
    this -> lastName = "";
    this -> emailAddress = "";
    this -> age = 0;
    for (int i = 0; i < daysArraySize; i++) {
        this -> daysInCourse[i] = 0;
    }
    this -> degreeprogram = DegreeProgram::SOFTWARE;
}

//mutators create the student object
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram) {
    this -> studentID = studentID;
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> emailAddress = emailAddress;
    this -> age = age;
    for (int i = 0; i < daysArraySize; i++) {
        this -> daysInCourse[i] = daysInCourse[i];
    }
    this -> degreeprogram = degreeprogram;
}

//deconstructor
Student::~Student () {}

//getters
string Student::getStudentID() {return this -> studentID;}
string Student::getFirstName() {return this -> firstName;}
string Student::getLastName() {return this -> lastName;}
string Student::getEmail() {return this -> emailAddress;}
int Student::getAge() {return this -> age;};
int* Student::getDaysInCourse() {return this -> daysInCourse;};
DegreeProgram Student::getDegreeProgram() {return this -> degreeprogram;}

void Student::setStudentID(string studentID) {this -> studentID = studentID;};
void Student::setFirstName(string firstName) {this -> firstName = firstName;};
void Student::setLastName(string lastName) {this -> lastName = lastName;};
void Student::setEmail(string emailAddress) {this -> emailAddress = emailAddress;};
void Student::setAge(int age) {this -> age = age;};
void Student::setDays(int daysInCourse[]) {
    for(int i = 0; i < daysArraySize; i++) {this -> daysInCourse[i] = daysInCourse[i];}
};
void Student::setDegreeProgram(DegreeProgram degreeprogram) {this -> degreeprogram = degreeprogram;}

void Student::printHeader() {
    cout << "Table format: Student ID | First Name | Email | Age | Days in Course | Degree Program\n";
}

//prints the student record
void Student::print() {
    cout << this -> getStudentID() << '\t';
    cout << this -> getFirstName() << '\t';
    cout << this -> getLastName() << '\t';
    cout << this -> getEmail() << '\t';
    cout << this -> getAge() << '\t';
    cout << this -> getDaysInCourse()[0] << '\t';
    cout << this -> getDaysInCourse()[1] << '\t';
    cout << this -> getDaysInCourse()[2] << '\t';
    cout << degreeProgramStrings[this -> getDegreeProgram()] << '\n';
};

