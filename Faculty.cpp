#include "Faculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty() {
    facultyID = "";
    facultyName = "";
}

Faculty::Faculty(string id, string name) {
    facultyID = id;
    facultyName = name;
}

string Faculty::getFacultyID() const {
    return facultyID;
}

string Faculty::getFacultyName() const {
    return facultyName;
}

vector<string> Faculty::getAssignedCourses() const {
    return assignedCourses;
}

void Faculty::assignCourse(string courseCode) {
    assignedCourses.push_back(courseCode);
}

void Faculty::display() const {
    cout << "Faculty ID: " << facultyID << endl;
    cout << "Faculty Name: " << facultyName << endl;
    if (!assignedCourses.empty()) {
        cout << "Assigned Courses: ";
        for (int i = 0; i < assignedCourses.size(); i++) {
            cout << assignedCourses[i] << " ";
        }
        cout << endl;
    }
}