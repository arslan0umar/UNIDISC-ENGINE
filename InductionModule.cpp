#include "InductionModule.h"
#include <iostream>
using namespace std;

Course* InductionModule::findCourse(string courseCode, vector<Course>& courses) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getCourseCode() == courseCode) {
            return &courses[i];
        }
    }
    return nullptr;
}

bool InductionModule::verifyRecursive(
    string courseCode,
    vector<Course>& allCourses,
    Student& student,
    int depth
) {
    // Base case: if course has no prerequisites
    Course* course = findCourse(courseCode, allCourses);
    if (course == nullptr) {
        cout << "Course " << courseCode << " not found!" << endl;
        return false;
    }

    vector<string> prereqs = course->getPrerequisites();

    // Base case: no prerequisites
    if (prereqs.empty()) {
        return true;
    }

    // Inductive step: check all prerequisites
    for (int i = 0; i < prereqs.size(); i++) {
        // Check if student has completed this prerequisite
        if (!student.hasCompletedCourse(prereqs[i])) {
            cout << "Missing prerequisite: " << prereqs[i]
                << " for course " << courseCode << endl;
            return false;
        }

        // Strong induction: recursively verify prerequisites of prerequisites
        if (!verifyRecursive(prereqs[i], allCourses, student, depth + 1)) {
            return false;
        }
    }

    return true;
}

bool InductionModule::verifyPrerequisiteChain(
    string targetCourse,
    vector<Course>& allCourses,
    Student& student
) {
    cout << "\n=== Verifying Prerequisite Chain Using Induction ===" << endl;
    cout << "Target Course: " << targetCourse << endl;
    cout << "Student: " << student.getStudentName() << endl;

    displayPrerequisiteChain(targetCourse, allCourses, 0);

    bool result = verifyRecursive(targetCourse, allCourses, student, 0);

    if (result) {
        cout << "\nAll prerequisites satisfied!" << endl;
    }
    else {
        cout << "\nPrerequisites not satisfied!" << endl;
    }

    return result;
}

void InductionModule::displayPrerequisiteChain(
    string courseCode,
    vector<Course>& allCourses,
    int depth
) {
    Course* course = findCourse(courseCode, allCourses);
    if (course == nullptr) return;

    // Print indentation
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << "-> " << courseCode << " (" << course->getCourseName() << ")" << endl;

    vector<string> prereqs = course->getPrerequisites();
    for (int i = 0; i < prereqs.size(); i++) {
        displayPrerequisiteChain(prereqs[i], allCourses, depth + 1);
    }
}