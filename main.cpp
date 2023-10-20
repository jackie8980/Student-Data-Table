#include "roster.h"

int main() {
    const string classRosterArray[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jackie,Li,jli68@wgu.edu,23,1,1,8,SOFTWARE"
    };
    
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 011658336" << endl;
    cout << "Name: Jackie Li" << endl << endl;
    
    
    const int numStudents = 5;
    Roster classRoster;
    
    for (int i = 0; i < numStudents; i++) {classRoster.parse(classRosterArray[i]);}
    cout << "studentData Table: " << std::endl;
    classRoster.printAll();
    cout << std::endl;
    
    cout << "Students with invalid Emails" << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    
    cout << "Average Days In Course:" << std::endl;
    classRoster.printAverageDaysInCourse();
    cout << std::endl;
    
    for (int i = 0; i < 3; i++) {
        cout << "Displaying by degree program: " << degreeProgramStrings[i] << std::endl;
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }
    
    cout << "Remove A3:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    cout << "Remove A3 again:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    
    return 0;
}
