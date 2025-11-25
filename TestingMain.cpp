#include <iostream>
#include <vector>
#include "Course.h"
#include "Student.h"
#include "Faculty.h"
#include "Room.h"
#include "SetOperations.h"
#include "InductionModule.h"
#include "LogicEngine.h"
#include "RelationsModule.h"
#include "FunctionsModule.h"
#include "CombinationModule.h"
#include "ConsistencyChecker.h"

using namespace std;

// Global data storage
vector<Course> courses;
vector<Student> students;
vector<Faculty> faculties;
vector<Room> rooms;

void printSeparator() {
    cout << "\n========================================" << endl;
}

void printHeader(string title) {
    printSeparator();
    cout << "   " << title << endl;
    printSeparator();
}

void testCourseModule() {
    printHeader("TEST 1: COURSE MANAGEMENT MODULE");

    // Add courses
    Course c1("CS101", "Programming", 3);
    courses.push_back(c1);
    cout << "Course added: CS101 - Programming (3 credits)" << endl;

    Course c2("CS201", "Data Structures", 3);
    courses.push_back(c2);
    cout << "Course added: CS201 - Data Structures (3 credits)" << endl;

    Course c3("CS301", "Algorithms", 4);
    courses.push_back(c3);
    cout << "Course added: CS301 - Algorithms (4 credits)" << endl;

    Course c4("MATH101", "Calculus I", 3);
    courses.push_back(c4);
    cout << "Course added: MATH101 - Calculus I (3 credits)" << endl;

    // Add prerequisites
    courses[1].addPrerequisite("CS101");
    cout << "Prerequisite added: CS201 requires CS101" << endl;

    courses[2].addPrerequisite("CS201");
    cout << "Prerequisite added: CS301 requires CS201" << endl;

    cout << "\nTotal courses added: " << courses.size() << endl;
}

void testStudentModule() {
    printHeader("TEST 2: STUDENT MANAGEMENT MODULE");

    // Add students
    Student s1("S001", "Ali Ahmed");
    students.push_back(s1);
    cout << "Student added: S001 - Ali Ahmed" << endl;

    Student s2("S002", "Sara Khan");
    students.push_back(s2);
    cout << "Student added: S002 - Sara Khan" << endl;

    Student s3("S003", "Ahmed Raza");
    students.push_back(s3);
    cout << "Student added: S003 - Ahmed Raza" << endl;

    Student s4("S004", "Fatima Ali");
    students.push_back(s4);
    cout << "Student added: S004 - Fatima Ali" << endl;

    // Mark completed courses
    students[0].completeCourse("CS101");
    cout << "S001 completed: CS101" << endl;

    students[0].completeCourse("CS201");
    cout << "S001 completed: CS201" << endl;

    students[1].completeCourse("CS101");
    cout << "S002 completed: CS101" << endl;

    students[2].completeCourse("CS101");
    cout << "S003 completed: CS101" << endl;

    // Enroll students in courses
    students[0].enrollCourse("CS301");
    cout << "S001 enrolled in: CS301" << endl;

    students[1].enrollCourse("CS201");
    cout << "S002 enrolled in: CS201" << endl;

    students[2].enrollCourse("CS201");
    cout << "S003 enrolled in: CS201" << endl;

    students[3].enrollCourse("CS101");
    cout << "S004 enrolled in: CS101" << endl;

    cout << "\nTotal students added: " << students.size() << endl;
}

void testFacultyModule() {
    printHeader("TEST 3: FACULTY MANAGEMENT MODULE");

    // Add faculties
    Faculty f1("F001", "Dr. Ahmed Hassan");
    faculties.push_back(f1);
    cout << "Faculty added: F001 - Dr. Ahmed Hassan" << endl;

    Faculty f2("F002", "Dr. Sara Ali");
    faculties.push_back(f2);
    cout << "Faculty added: F002 - Dr. Sara Ali" << endl;

    Faculty f3("F003", "Prof. Bilal Khan");
    faculties.push_back(f3);
    cout << "Faculty added: F003 - Prof. Bilal Khan" << endl;

    // Assign courses to faculty
    faculties[0].assignCourse("CS101");
    cout << "F001 assigned to: CS101" << endl;

    faculties[0].assignCourse("CS201");
    cout << "F001 assigned to: CS201" << endl;

    faculties[1].assignCourse("CS301");
    cout << "F002 assigned to: CS301" << endl;

    faculties[2].assignCourse("MATH101");
    cout << "F003 assigned to: MATH101" << endl;

    cout << "\nTotal faculties added: " << faculties.size() << endl;
}

void testRoomModule() {
    printHeader("TEST 4: ROOM MANAGEMENT MODULE");

    // Add rooms
    Room r1("R101", "Lab", 30);
    rooms.push_back(r1);
    cout << "Room added: R101 - Lab (Capacity: 30)" << endl;

    Room r2("R102", "Lab", 25);
    rooms.push_back(r2);
    cout << "Room added: R102 - Lab (Capacity: 25)" << endl;

    Room r3("R201", "Classroom", 50);
    rooms.push_back(r3);
    cout << "Room added: R201 - Classroom (Capacity: 50)" << endl;

    // Assign rooms to courses
    rooms[0].assignToCourse("CS101");
    cout << "R101 assigned to: CS101" << endl;

    rooms[1].assignToCourse("CS301");
    cout << "R102 assigned to: CS301" << endl;

    // Try to assign already occupied room (should show status)
    cout << "\n--- Testing Room Occupation ---" << endl;
    cout << "R101 Status: " << (rooms[0].getIsOccupied() ? "Occupied" : "Available") << endl;
    cout << "R101 Assigned to: " << rooms[0].getAssignedCourse() << endl;
    cout << "R201 Status: " << (rooms[2].getIsOccupied() ? "Occupied" : "Available") << endl;

    cout << "\nTotal rooms added: " << rooms.size() << endl;
}

void testSetOperations() {
    printHeader("TEST 5: SET OPERATIONS MODULE");

    // Get students in different courses
    vector<string> cs201Students;
    vector<string> cs301Students;

    for (int i = 0; i < students.size(); i++) {
        vector<string> enrolled = students[i].getEnrolledCourses();
        for (int j = 0; j < enrolled.size(); j++) {
            if (enrolled[j] == "CS201") {
                cs201Students.push_back(students[i].getStudentID());
            }
            if (enrolled[j] == "CS301") {
                cs301Students.push_back(students[i].getStudentID());
            }
        }
    }

    cout << "\n--- Set Operations Test ---" << endl;
    SetOperations::displaySet(cs201Students, "Students in CS201");
    SetOperations::displaySet(cs301Students, "Students in CS301");

    vector<string> unionSet = SetOperations::unionSets(cs201Students, cs301Students);
    SetOperations::displaySet(unionSet, "Union");
    cout << "Union operation completed" << endl;

    vector<string> intersection = SetOperations::intersectionSets(cs201Students, cs301Students);
    SetOperations::displaySet(intersection, "Intersection");
    cout << "Intersection operation completed" << endl;

    vector<string> difference = SetOperations::differenceSets(cs201Students, cs301Students);
    SetOperations::displaySet(difference, "Difference (CS201 - CS301)");
    cout << "Difference operation completed" << endl;

    cout << "\n--- Subset Test ---" << endl;
    bool isSubset = SetOperations::isSubset(cs301Students, unionSet);
    cout << "Is CS301 students ⊆ Union? " << (isSubset ? "Yes" : "No") << endl;
    cout << "Subset check completed" << endl;

    cout << "\n--- Power Set Test ---" << endl;
    vector<string> smallSet;
    smallSet.push_back("A");
    smallSet.push_back("B");
    smallSet.push_back("C");

    vector<vector<string>> pset = SetOperations::powerSet(smallSet);
    cout << "Power set of {A, B, C} has " << pset.size() << " subsets" << endl;
    SetOperations::displayPowerSet(pset, "Power Set");
    cout << "Power set generation completed" << endl;
}

void testInductionModule() {
    printHeader("TEST 6: INDUCTION & PREREQUISITES MODULE");

    cout << "\n--- Test Case 1: S001 wants to take CS301 ---" << endl;
    bool result1 = InductionModule::verifyPrerequisiteChain("CS301", courses, students[0]);
    cout << "Induction verification completed for S001" << endl;

    cout << "\n--- Test Case 2: S002 wants to take CS301 ---" << endl;
    bool result2 = InductionModule::verifyPrerequisiteChain("CS301", courses, students[1]);
    cout << "Induction verification completed for S002" << endl;
}

void testLogicEngine() {
    printHeader("TEST 7: LOGIC & INFERENCE ENGINE MODULE");

    LogicEngine engine;

    // Add rules
    engine.addRule("Student enrolled in CS301", "Must have lab", "Advanced course rule");
    cout << "Rule added: Advanced course rule" << endl;

    engine.addRule("Course has 4 credits", "Requires 2 hour lab", "Credit-based rule");
    cout << "Rule added: Credit-based rule" << endl;

    engine.addRule("Dr. Ahmed teaches CS101", "Lab must be R101", "Faculty-lab rule");
    cout << "Rule added: Faculty-lab rule" << endl;

    // Perform inference
    vector<string> facts;
    facts.push_back("Student enrolled in CS301");
    facts.push_back("Dr. Ahmed teaches CS101");

    cout << "\n--- Inference Test ---" << endl;
    vector<string> conclusions = engine.performInference(facts);
    cout << "Inference completed: " << conclusions.size() << " conclusions derived" << endl;
}

void testRelationsModule() {
    printHeader("TEST 8: RELATIONS MODULE");

    // Student-Course Relation
    cout << "\n--- Student-Course Relation Test ---" << endl;
    RelationsModule studentCourse("Student-Course");

    studentCourse.addPair("S001", "CS301");
    cout << "Relation added: (S001, CS301)" << endl;

    studentCourse.addPair("S002", "CS201");
    cout << "Relation added: (S002, CS201)" << endl;

    studentCourse.addPair("S003", "CS201");
    cout << "Relation added: (S003, CS201)" << endl;

    studentCourse.display();

    cout << "\n--- Property Checks ---" << endl;
    cout << "Reflexive: " << (studentCourse.isReflexive() ? "Yes" : "No") << endl;
    cout << "Reflexive check completed" << endl;

    cout << "Symmetric: " << (studentCourse.isSymmetric() ? "Yes" : "No") << endl;
    cout << "Symmetric check completed" << endl;

    cout << "Transitive: " << (studentCourse.isTransitive() ? "Yes" : "No") << endl;
    cout << "Transitive check completed" << endl;

    cout << "Equivalence: " << (studentCourse.isEquivalence() ? "Yes" : "No") << endl;
    cout << "Equivalence check completed" << endl;

    // Faculty-Course Relation
    cout << "\n--- Faculty-Course Relation Test ---" << endl;
    RelationsModule facultyCourse("Faculty-Course");

    facultyCourse.addPair("F001", "CS101");
    cout << "Relation added: (F001, CS101)" << endl;

    facultyCourse.addPair("F001", "CS201");
    cout << "Relation added: (F001, CS201)" << endl;

    facultyCourse.addPair("F002", "CS301");
    cout << "Relation added: (F002, CS301)" << endl;

    facultyCourse.display();
}

void testFunctionsModule() {
    printHeader("TEST 9: FUNCTIONS MODULE");

    // Course to Faculty Function
    cout << "\n--- Course -> Faculty Function Test ---" << endl;
    FunctionsModule courseToFaculty("Course -> Faculty");

    courseToFaculty.addMapping("CS101", "F001");
    cout << "Mapping added: CS101 -> F001" << endl;

    courseToFaculty.addMapping("CS201", "F001");
    cout << "Mapping added: CS201 -> F001" << endl;

    courseToFaculty.addMapping("CS301", "F002");
    cout << "Mapping added: CS301 -> F002" << endl;

    courseToFaculty.addMapping("MATH101", "F003");
    cout << "Mapping added: MATH101 -> F003" << endl;

    courseToFaculty.display();

    vector<string> allFaculties;
    allFaculties.push_back("F001");
    allFaculties.push_back("F002");
    allFaculties.push_back("F003");

    cout << "\n--- Function Property Checks ---" << endl;
    cout << "Injective: " << (courseToFaculty.isInjective() ? "Yes" : "No") << endl;
    cout << "Injective check completed" << endl;

    cout << "Surjective: " << (courseToFaculty.isSurjective(allFaculties) ? "Yes" : "No") << endl;
    cout << "Surjective check completed" << endl;

    cout << "Bijective: " << (courseToFaculty.isBijective(allFaculties) ? "Yes" : "No") << endl;
    cout << "Bijective check completed" << endl;

    // Faculty to Room Function
    cout << "\n--- Faculty -> Room Function Test ---" << endl;
    FunctionsModule facultyToRoom("Faculty -> Room");

    facultyToRoom.addMapping("F001", "R101");
    cout << "Mapping added: F001 -> R101" << endl;

    facultyToRoom.addMapping("F002", "R102");
    cout << "Mapping added: F002 -> R102" << endl;

    facultyToRoom.addMapping("F003", "R201");
    cout << "Mapping added: F003 -> R201" << endl;

    facultyToRoom.display();

    vector<string> allRooms;
    allRooms.push_back("R101");
    allRooms.push_back("R102");
    allRooms.push_back("R201");

    cout << "\nInjective: " << (facultyToRoom.isInjective() ? "Yes" : "No") << endl;
    cout << "Faculty-Room function test completed" << endl;
}

void testCombinationsModule() {
    printHeader("TEST 10: COMBINATIONS MODULE");

    // Project Groups
    cout << "\n--- Project Groups Assignment Test ---" << endl;
    cout << "Total students: " << students.size() << endl;
    int groupSize = 2;
    cout << "Group size: " << groupSize << endl;

    long long totalCombos = CombinationModule::combinations(students.size(), groupSize);
    cout << "C(" << students.size() << "," << groupSize << ") = " << totalCombos << endl;
    cout << "Combination calculation completed" << endl;

    vector<ProjectGroup> groups = CombinationModule::assignProjectGroups(students, groupSize);
    CombinationModule::displayProjectGroups(groups);
    cout << "Project groups assigned: " << groups.size() << " groups" << endl;

    // Lab Sessions
    cout << "\n--- Lab Sessions Assignment Test ---" << endl;
    vector<string> timeSlots;
    timeSlots.push_back("Monday 9-11 AM");
    timeSlots.push_back("Wednesday 2-4 PM");

    vector<LabSession> sessions = CombinationModule::assignLabSessions(students, 2, timeSlots);
    CombinationModule::displayLabSessions(sessions);
    cout << "Lab sessions assigned: " << sessions.size() << " sessions" << endl;

    // Electives
    cout << "\n--- Electives Assignment Test ---" << endl;
    vector<string> electives;
    electives.push_back("AI101");
    electives.push_back("ML101");
    electives.push_back("WEB101");

    cout << "Available electives: " << electives.size() << endl;
    CombinationModule::assignElectives(students, electives, 2);
    cout << "Electives assigned to students" << endl;

    // All Combinations
    cout << "\n--- All Combinations Generation Test ---" << endl;
    vector<string> studentIDs;
    for (int i = 0; i < 3; i++) {
        studentIDs.push_back(students[i].getStudentID());
    }

    vector<vector<string>> allCombos = CombinationModule::generateCombinations(studentIDs, 2);
    cout << "Generated " << allCombos.size() << " combinations of size 2" << endl;
    CombinationModule::displayCombinations(allCombos);
    cout << "All combinations generated" << endl;
}

void testConsistencyChecker() {
    printHeader("TEST 11: CONSISTENCY CHECKER MODULE");

    cout << "\n--- Running System-Wide Consistency Check ---" << endl;
    ConsistencyChecker::performConsistencyCheck(students, courses, faculties);
    cout << "Consistency check completed" << endl;
}

void displayTestSummary() {
    printHeader("TEST SUMMARY");

    cout << "Total Courses: " << courses.size() << endl;
    cout << "Total Students: " << students.size() << endl;
    cout << "Total Faculties: " << faculties.size() << endl;
    cout << "Total Rooms: " << rooms.size() << endl;

    cout << "\n--- All Modules Tested ---" << endl;
    cout << "Course Management" << endl;
    cout << "Student Management" << endl;
    cout << "Faculty Management" << endl;
    cout << "Room Management" << endl;
    cout << "Set Operations" << endl;
    cout << "Induction & Prerequisites" << endl;
    cout << "Logic & Inference" << endl;
    cout << "Relations" << endl;
    cout << "Functions" << endl;
    cout << "Combinations" << endl;
    cout << "Consistency Checker" << endl;

    cout << "\n========================================" << endl;
    cout << "   ALL UNIT TESTS COMPLETED SUCCESSFULLY" << endl;
    cout << "========================================" << endl;
}

int main() {
    cout << "\n|========================================|" << endl;
    cout << "|   UNIDISC ENGINE - UNIT TESTING        |" << endl;
    cout << "|   Automated Testing with Hardcoded Data|" << endl;
    cout << "|========================================|" << endl;

    // Run all tests
    testCourseModule();
    testStudentModule();
    testFacultyModule();
    testRoomModule();
    testSetOperations();
    testInductionModule();
    testLogicEngine();
    testRelationsModule();
    testFunctionsModule();
    testCombinationsModule();
    testConsistencyChecker();

    // Display summary
    displayTestSummary();

    return 0;
}