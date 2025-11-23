#include "Course.h"
#include <iostream>
using namespace std;

Course::Course() {
    courseCode = "";
    courseName = "";
    credits = 0;
}

Course::Course(string code, string name, int cr) {
    courseCode = code;
    courseName = name;
    credits = cr;
}

string Course::getCourseCode() const {
    return courseCode;
}

string Course::getCourseName() const {
    return courseName;
}

int Course::getCredits() const {
    return credits;
}

vector<string> Course::getPrerequisites() const {
    return prerequisites;
}

void Course::addPrerequisite(string prereqCode) {
    prerequisites.push_back(prereqCode);
}

void Course::display() const {
    cout << "Course Code: " << courseCode << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Credits: " << credits << endl;
    if (!prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (int i = 0; i < prerequisites.size(); i++) {
            cout << prerequisites[i];
            if (i < prerequisites.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}