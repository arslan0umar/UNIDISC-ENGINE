#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <vector>
using namespace std;

class Faculty {
private:
    string facultyID;
    string facultyName;
    vector<string> assignedCourses; // Course codes

public:
    Faculty();
    Faculty(string id, string name);

    // Getters
    string getFacultyID() const;
    string getFacultyName() const;
    vector<string> getAssignedCourses() const;

    // Operations
    void assignCourse(string courseCode);
    void display() const;
};

#endif