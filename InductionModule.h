#ifndef INDUCTIONMODULE_H
#define INDUCTIONMODULE_H

#include "Course.h"
#include "Student.h"
#include <vector>
using namespace std;

class InductionModule {
public:
    // Verify prerequisite chain using induction
    static bool verifyPrerequisiteChain(
        string targetCourse,
        vector<Course>& allCourses,
        Student& student
    );

    // Helper to find course by code
    static Course* findCourse(string courseCode, vector<Course>& courses);

    // Recursive verification with strong induction
    static bool verifyRecursive(
        string courseCode,
        vector<Course>& allCourses,
        Student& student,
        int depth
    );

    // Display prerequisite chain
    static void displayPrerequisiteChain(
        string courseCode,
        vector<Course>& allCourses,
        int depth
    );
};

#endif