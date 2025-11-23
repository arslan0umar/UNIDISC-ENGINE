#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {
    studentID = "";
    studentName = "";
}

Student::Student(string id, string name) {
    studentID = id;
    studentName = name;
}

string Student::getStudentID() const {
    return studentID;
}

string Student::getStudentName() const {
    return studentName;
}

vector<string> Student::getEnrolledCourses() const {
    return enrolledCourses;
}

vector<string> Student::getCompletedCourses() const {
    return completedCourses;
}

void Student::enrollCourse(string courseCode) {
    enrolledCourses.push_back(courseCode);
}

void Student::completeCourse(string courseCode) {
    completedCourses.push_back(courseCode);
    // Remove from enrolled
    for (int i = 0; i < enrolledCourses.size(); i++) {
        if (enrolledCourses[i] == courseCode) {
            enrolledCourses.erase(enrolledCourses.begin() + i);
            break;
        }
    }
}

bool Student::hasCompletedCourse(string courseCode) const {
    for (int i = 0; i < completedCourses.size(); i++) {
        if (completedCourses[i] == courseCode) {
            return true;
        }
    }
    return false;
}

void Student::display() const {
    cout << "Student ID: " << studentID << endl;
    cout << "Student Name: " << studentName << endl;
    if (!enrolledCourses.empty()) {
        cout << "Enrolled Courses: ";
        for (int i = 0; i < enrolledCourses.size(); i++) {
            cout << enrolledCourses[i] << " ";
        }
        cout << endl;
    }
    if (!completedCourses.empty()) {
        cout << "Completed Courses: ";
        for (int i = 0; i < completedCourses.size(); i++) {
            cout << completedCourses[i] << " ";
        }
        cout << endl;
    }
}