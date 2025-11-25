#include "ConsistencyChecker.h"
#include <iostream>
using namespace std;

bool ConsistencyChecker::checkCourseConflicts(Student& student, vector<Course>& courses) {
    vector<string> enrolled = student.getEnrolledCourses();

    // For simplicity, we assume no conflicts
    // In real system, would check time slots
    return false;
}

bool ConsistencyChecker::checkStudentOverload(Student& student, vector<Course>& courses, int maxCredits) {
    vector<string> enrolled = student.getEnrolledCourses();
    int totalCredits = 0;

    for (int i = 0; i < enrolled.size(); i++) {
        for (int j = 0; j < courses.size(); j++) {
            if (courses[j].getCourseCode() == enrolled[i]) {
                totalCredits += courses[j].getCredits();
                break;
            }
        }
    }

    if (totalCredits > maxCredits) {
        cout << "Student " << student.getStudentName()
            << " is overloaded with " << totalCredits
            << " credits (max: " << maxCredits << ")" << endl;
        return true;
    }

    return false;
}

bool ConsistencyChecker::checkPrerequisites(Student& student, vector<Course>& courses) {
    vector<string> enrolled = student.getEnrolledCourses();
    bool hasIssue = false;

    for (int i = 0; i < enrolled.size(); i++) {
        for (int j = 0; j < courses.size(); j++) {
            if (courses[j].getCourseCode() == enrolled[i]) {
                vector<string> prereqs = courses[j].getPrerequisites();

                for (int k = 0; k < prereqs.size(); k++) {
                    if (!student.hasCompletedCourse(prereqs[k])) {
                        cout << "Student " << student.getStudentName()
                            << " missing prerequisite " << prereqs[k]
                            << " for course " << enrolled[i] << endl;
                        hasIssue = true;
                    }
                }
                break;
            }
        }
    }

    return hasIssue;
}

bool ConsistencyChecker::checkCourseAssignments(vector<Course>& courses, vector<Faculty>& faculties) {
    bool hasIssue = false;

    for (int i = 0; i < courses.size(); i++) {
        bool assigned = false;

        for (int j = 0; j < faculties.size(); j++) {
            vector<string> assigned_courses = faculties[j].getAssignedCourses();
            for (int k = 0; k < assigned_courses.size(); k++) {
                if (assigned_courses[k] == courses[i].getCourseCode()) {
                    assigned = true;
                    break;
                }
            }
            if (assigned) break;
        }

        if (!assigned) {
            cout << "Course " << courses[i].getCourseCode()
                << " has no faculty assigned!" << endl;
            hasIssue = true;
        }
    }

    return hasIssue;
}

void ConsistencyChecker::performConsistencyCheck(
    vector<Student>& students,
    vector<Course>& courses,
    vector<Faculty>& faculties
) {
    cout << "\n=== CONSISTENCY CHECK ===" << endl;
    bool allGood = true;

    // Check student overloads and prerequisites
    cout << "\n--- Checking Students ---" << endl;
    for (int i = 0; i < students.size(); i++) {
        if (checkStudentOverload(students[i], courses, 18)) {
            allGood = false;
        }
        if (checkPrerequisites(students[i], courses)) {
            allGood = false;
        }
    }

    // Check course assignments
    cout << "\n--- Checking Course Assignments ---" << endl;
    if (checkCourseAssignments(courses, faculties)) {
        allGood = false;
    }

    if (allGood) {
        cout << "\nAll consistency checks PASSED!" << endl;
    }
    else {
        cout << "\nSome consistency issues found!" << endl;
    }
}