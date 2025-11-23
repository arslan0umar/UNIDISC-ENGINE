#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int credits;
    vector<string> prerequisites; // List of prerequisite course codes

public:
    Course();
    Course(string code, string name, int cr);

    // Getters
    string getCourseCode() const;
    string getCourseName() const;
    int getCredits() const;
    vector<string> getPrerequisites() const;

    // Setters
    void addPrerequisite(string prereqCode);
    void display() const;
};

#endif