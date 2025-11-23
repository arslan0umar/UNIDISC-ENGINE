#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string studentID;
    string studentName;
    vector<string> enrolledCourses; // Course codes
    vector<string> completedCourses; // Course codes

public:
    Student();
    Student(string id, string name);

    // Getters
    string getStudentID() const;
    string getStudentName() const;
    vector<string> getEnrolledCourses() const;
    vector<string> getCompletedCourses() const;

    // Operations
    void enrollCourse(string courseCode);
    void completeCourse(string courseCode);
    bool hasCompletedCourse(string courseCode) const;
    void display() const;
};

#endif