#include "roster.h"

void Roster::parse(string studentdata)
{
    //determin student degree program by using last letter of string
    DegreeProgram dp = SOFTWARE;
    if (studentdata.back() == 'Y') {
        dp = SECURITY;
    } else if (studentdata.back() == 'K') {
        dp = NETWORK;
    }
    
    //separation of string using commas to begin substring, then comma for end. Comma + 1 (start) is the start of next substring
    int rightComma = studentdata.find(",");
    string sID = studentdata.substr(0, rightComma);
    
    int start = rightComma + 1;
    rightComma = studentdata.find(",", start);
    string sFirstName = studentdata.substr(start, rightComma - start);
    
    start = rightComma + 1;
    rightComma = studentdata.find(",", start);
    string sLastName = studentdata.substr(start, rightComma - start);
    
    start = rightComma + 1;
    rightComma = studentdata.find(",", start);
    string sEmail = studentdata.substr(start, rightComma - start);
    
    start = rightComma + 1;
    rightComma = studentdata.find(",", start);
    int sAge = stod(studentdata.substr(start, rightComma - start));
    
    start = rightComma + 1;
    rightComma = studentdata.find(",", start);
    int sDay1 = stod(studentdata.substr(start, rightComma - start));
    start = rightComma + 1;
    rightComma = studentdata.find(",", start);
    int sDay2 = stod(studentdata.substr(start, rightComma - start));
    start = rightComma + 1;
    rightComma = studentdata.find(",", start);
    int sDay3 = stod(studentdata.substr(start, rightComma - start));
    
    add(sID, sFirstName, sLastName, sEmail, sAge, sDay1, sDay2, sDay3, dp);
}

void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int sDay1, int sDay2, int sDay3, DegreeProgram dp)
{
    int daysInCourse[3] = {sDay1, sDay2, sDay3};
    studentDataArray[++lastIndex] = new Student(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse, dp);
}

//prints entire student table
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        Roster::studentDataArray[i]->print();
    };
}

//prints roster by degree program
void Roster::printByDegreeProgram(DegreeProgram dp)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::studentDataArray[i] -> getDegreeProgram() == dp) studentDataArray[i] -> print();
    }
    cout << std::endl;
}

//prints table of students with invalid emails
void Roster::printInvalidEmails()
{
    bool invalidEmails = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string emailAddress = (studentDataArray[i] -> getEmail());
        //If ' ' is found, it is invalid. Otherwise if either '@' or '.' is missing, it is also invalid
        if (emailAddress.find(' ') != string::npos || emailAddress.find('.') == string::npos || emailAddress.find('@') == string::npos) {
            invalidEmails = true;
            cout << emailAddress << std::endl;
        }
    }
    if(!invalidEmails) cout << "All emails are valid" << std::endl;
}

//calculates average days students too per course
void Roster::printAverageDaysInCourse()
{
    for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << studentDataArray[i] -> getStudentID() << ": ";
        cout << (studentDataArray[i] -> getDaysInCourse()[0] + studentDataArray[i] -> getDaysInCourse()[1] + studentDataArray[i] -> getDaysInCourse()[2])/3.0 << std::endl;
    }
    cout << std::endl;
}

//takes input of student id to remove that student from table if found
void Roster::remove(string id)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (studentDataArray[i]->getStudentID() == id)
        {
            success = true;
            if (i < numStudents - 1)
            {
                Student* temp = studentDataArray[i];
                studentDataArray[i] = studentDataArray[numStudents - 1];
                studentDataArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << id << " removed from roster." << endl << std::endl;
        this->printAll();
    }
    else cout << id << " studentID not found" << std::endl << std::endl;
}

//deconstructor to free memory being used
Roster::~Roster()
{
    cout << "Releasing memory..." << std::endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Deleted student #" << i + 1 << std::endl;
        delete studentDataArray[i];
        studentDataArray[i] = nullptr;
    }
}
