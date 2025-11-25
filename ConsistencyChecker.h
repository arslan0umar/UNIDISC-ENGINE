#ifndef CONSISTENCYCHECKER_H
#define CONSISTENCYCHECKER_H

#include "Student.h"
#include "Course.h"
#include "Faculty.h"
#include <vector>
using namespace std;

class ConsistencyChecker {
public:
    // Check if student has course conflicts (time overlaps)
    static bool checkCourseConflicts(Student& student, vector<Course>& courses);

    // Check if student is overloaded (too many credits)
    static bool checkStudentOverload(Student& student, vector<Course>& courses, int maxCredits);

    // Check if all prerequisites are met
    static bool checkPrerequisites(Student& student, vector<Course>& courses);

    // Check if course assignments are valid (each course has faculty)
    static bool checkCourseAssignments(vector<Course>& courses, vector<Faculty>& faculties);

    // Overall consistency check
    static void performConsistencyCheck(
        vector<Student>& students,
        vector<Course>& courses,
        vector<Faculty>& faculties
    );
};

#endif