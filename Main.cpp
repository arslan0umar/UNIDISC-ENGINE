#include <iostream>
#include <vector>
#include <limits>
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

// Helper functions
void displayMainMenu();
void clearScreen();
void pauseScreen();

// Course Management
void courseManagementMenu();
void addCourse();
void viewAllCourses();
void addPrerequisiteToCourse();

// Student Management
void studentManagementMenu();
void addStudent();
void viewAllStudents();
void enrollStudentInCourse();
void markCourseAsCompleted();

// Faculty Management
void facultyManagementMenu();
void addFaculty();
void viewAllFaculties();
void assignCourseToFaculty();

// Room Management
void roomManagementMenu();
void addRoom();
void viewAllRooms();
void assignRoomToCourse();
void freeRoomFromCourse(); 

// Discrete Structure Modules
void setOperationsMenu();
void inductionVerificationMenu();
void logicInferenceMenu();
void relationsMenu();
void functionsMenu();
void combinationsMenu();
void consistencyCheckMenu();

// Utility functions
Course* findCourseByCode(string code);
Student* findStudentByID(string id);
Faculty* findFacultyByID(string id);
Room* findRoomByNumber(string number);
void displayAvailableStudents();
void displayAvailableCourses();
void displayAvailableFaculties();
void displayAvailableRooms();

int main() {
    int choice;

    cout << "========================================" << endl;
    cout << "    UNIDISC ENGINE - FAST University   " << endl;
    cout << "  Discrete Structures Management System" << endl;
    cout << "========================================" << endl;

    while (true) {
        displayMainMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            pauseScreen();
            continue;
        }
        cin.ignore();

        switch (choice) {
        case 1:
            courseManagementMenu();
            break;
        case 2:
            studentManagementMenu();
            break;
        case 3:
            facultyManagementMenu();
            break;
        case 4:
            roomManagementMenu();
            break;
        case 5:
            setOperationsMenu();
            break;
        case 6:
            inductionVerificationMenu();
            break;
        case 7:
            logicInferenceMenu();
            break;
        case 8:
            relationsMenu();
            break;
        case 9:
            functionsMenu();
            break;
        case 10:
            combinationsMenu();
            break;
        case 11:
            consistencyCheckMenu();
            break;
        case 0:
            cout << "\n========================================" << endl;
            cout << "Thank you for using UNIDISC ENGINE!" << endl;
            cout << "========================================" << endl;
            return 0;
        default:
            cout << "\n Invalid choice! Please try again." << endl;
            pauseScreen();
        }
    }

    return 0;
}

void displayMainMenu() {
    clearScreen();
    cout << "\n|========================================|" << endl;
    cout << "|           MAIN MENU                    |" << endl;
    cout << "|========================================|" << endl;
    cout << "  1.  Course Management" << endl;
    cout << "  2.  Student Management" << endl;
    cout << "  3.  Faculty Management" << endl;
    cout << "  4.  Room Management" << endl;
    cout << "  5.  Set Operations Module" << endl;
    cout << "  6.  Induction & Prerequisites Verification" << endl;
    cout << "  7.  Logic & Inference Engine" << endl;
    cout << "  8.  Relations Module" << endl;
    cout << "  9.  Functions Module" << endl;
    cout << "  10. Combinations Module (Groups/Labs/Electives)" << endl;
    cout << "  11. Consistency Checker" << endl;
    cout << "  0.  Exit" << endl;
    cout << "========================================" << endl;
}

void clearScreen() {
    cout << "\n\n";
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

// ==================== UTILITY FUNCTIONS ====================

void displayAvailableStudents() {
    cout << "\nAvailable Students:" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << "  - " << students[i].getStudentID() << " ("
            << students[i].getStudentName() << ")" << endl;
    }
}

void displayAvailableCourses() {
    cout << "\nAvailable Courses:" << endl;
    for (int i = 0; i < courses.size(); i++) {
        cout << "  - " << courses[i].getCourseCode() << " ("
            << courses[i].getCourseName() << ")" << endl;
    }
}

void displayAvailableFaculties() {
    cout << "\nAvailable Faculties:" << endl;
    for (int i = 0; i < faculties.size(); i++) {
        cout << "  - " << faculties[i].getFacultyID() << " ("
            << faculties[i].getFacultyName() << ")" << endl;
    }
}

void displayAvailableRooms() {
    cout << "\nAvailable Rooms:" << endl;
    for (int i = 0; i < rooms.size(); i++) {
        cout << "  - " << rooms[i].getRoomNumber() << " ("
            << rooms[i].getRoomType() << ")" << endl;
    }
}

Course* findCourseByCode(string code) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getCourseCode() == code) {
            return &courses[i];
        }
    }
    return nullptr;
}

Student* findStudentByID(string id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getStudentID() == id) {
            return &students[i];
        }
    }
    return nullptr;
}

Faculty* findFacultyByID(string id) {
    for (int i = 0; i < faculties.size(); i++) {
        if (faculties[i].getFacultyID() == id) {
            return &faculties[i];
        }
    }
    return nullptr;
}

Room* findRoomByNumber(string number) {
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].getRoomNumber() == number) {
            return &rooms[i];
        }
    }
    return nullptr;
}

// ==================== COURSE MANAGEMENT ====================

void courseManagementMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "\n|========================================|" << endl;
        cout << "|      COURSE MANAGEMENT                 |" << endl;
        cout << "|========================================|" << endl;
        cout << "  1. Add New Course" << endl;
        cout << "  2. View All Courses" << endl;
        cout << "  3. Add Prerequisite to Course" << endl;
        cout << "  0. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addCourse();
            break;
        case 2:
            viewAllCourses();
            pauseScreen();
            break;
        case 3:
            addPrerequisiteToCourse();
            break;
        case 0:
            return;
        default:
            cout << " Invalid choice!" << endl;
            pauseScreen();
        }
    }
}

void addCourse() {
    clearScreen();
    cout << "\n=== ADD NEW COURSE ===" << endl;

    string code, name;
    int credits;

    cout << "Enter Course Code (e.g., CS101): ";
    getline(cin, code);

    if (findCourseByCode(code) != nullptr) {
        cout << " Course with this code already exists!" << endl;
        pauseScreen();
        return;
    }

    cout << "Enter Course Name: ";
    getline(cin, name);

    cout << "Enter Credits: ";
    cin >> credits;
    cin.ignore();

    if (credits <= 0) {
        cout << " Credits must be positive!" << endl;
        pauseScreen();
        return;
    }

    Course c(code, name, credits);
    courses.push_back(c);

    cout << "\n Course added successfully!" << endl;
    pauseScreen();
}

void viewAllCourses() {
    clearScreen();
    cout << "\n=== ALL COURSES ===" << endl;

    if (courses.empty()) {
        cout << "No courses available." << endl;
        return;
    }

    for (int i = 0; i < courses.size(); i++) {
        cout << "\n--- Course " << (i + 1) << " ---" << endl;
        courses[i].display();
    }
}

void addPrerequisiteToCourse() {
    clearScreen();
    cout << "\n=== ADD PREREQUISITE TO COURSE ===" << endl;

    if (courses.empty()) {
        cout << " No courses available." << endl;
        pauseScreen();
        return;
    }

    displayAvailableCourses();

    string courseCode, prereqCode;

    cout << "\nEnter Course Code: ";
    getline(cin, courseCode);

    Course* course = findCourseByCode(courseCode);
    if (course == nullptr) {
        cout << " Course not found!" << endl;
        pauseScreen();
        return;
    }

    cout << "Enter Prerequisite Course Code: ";
    getline(cin, prereqCode);

    if (findCourseByCode(prereqCode) == nullptr) {
        cout << " Prerequisite course not found!" << endl;
        pauseScreen();
        return;
    }

    course->addPrerequisite(prereqCode);
    cout << "\n Prerequisite added successfully!" << endl;
    pauseScreen();
}

// ==================== STUDENT MANAGEMENT ====================

void studentManagementMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "\n|========================================|" << endl;
        cout << "|      STUDENT MANAGEMENT                |" << endl;
        cout << "|========================================|" << endl;
        cout << "  1. Add New Student" << endl;
        cout << "  2. View All Students" << endl;
        cout << "  3. Enroll Student in Course" << endl;
        cout << "  4. Mark Course as Completed" << endl;
        cout << "  0. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewAllStudents();
            pauseScreen();
            break;
        case 3:
            enrollStudentInCourse();
            break;
        case 4:
            markCourseAsCompleted();
            break;
        case 0:
            return;
        default:
            cout << " Invalid choice!" << endl;
            pauseScreen();
        }
    }
}

void addStudent() {
    clearScreen();
    cout << "\n=== ADD NEW STUDENT ===" << endl;

    string id, name;

    cout << "Enter Student ID: ";
    getline(cin, id);

    if (findStudentByID(id) != nullptr) {
        cout << " Student with this ID already exists!" << endl;
        pauseScreen();
        return;
    }

    cout << "Enter Student Name: ";
    getline(cin, name);

    Student s(id, name);
    students.push_back(s);

    cout << "\n Student added successfully!" << endl;
    pauseScreen();
}

void viewAllStudents() {
    clearScreen();
    cout << "\n=== ALL STUDENTS ===" << endl;

    if (students.empty()) {
        cout << "No students available." << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << "\n--- Student " << (i + 1) << " ---" << endl;
        students[i].display();
    }
}

void enrollStudentInCourse() {
    clearScreen();
    cout << "\n=== ENROLL STUDENT IN COURSE ===" << endl;

    if (students.empty() || courses.empty()) {
        cout << " Please add students and courses first." << endl;
        pauseScreen();
        return;
    }

    displayAvailableStudents();

    string studentID;
    cout << "\nEnter Student ID: ";
    getline(cin, studentID);

    Student* student = findStudentByID(studentID);
    if (student == nullptr) {
        cout << " Student not found!" << endl;
        pauseScreen();
        return;
    }

    displayAvailableCourses();

    string courseCode;
    cout << "\nEnter Course Code: ";
    getline(cin, courseCode);

    if (findCourseByCode(courseCode) == nullptr) {
        cout << " Course not found!" << endl;
        pauseScreen();
        return;
    }

    student->enrollCourse(courseCode);
    cout << "\n Student enrolled successfully!" << endl;
    pauseScreen();
}

void markCourseAsCompleted() {
    clearScreen();
    cout << "\n=== MARK COURSE AS COMPLETED ===" << endl;

    if (students.empty()) {
        cout << " No students available." << endl;
        pauseScreen();
        return;
    }

    displayAvailableStudents();

    string studentID;
    cout << "\nEnter Student ID: ";
    getline(cin, studentID);

    Student* student = findStudentByID(studentID);
    if (student == nullptr) {
        cout << " Student not found!" << endl;
        pauseScreen();
        return;
    }

    displayAvailableCourses();

    string courseCode;
    cout << "\nEnter Course Code: ";
    getline(cin, courseCode);

    student->completeCourse(courseCode);
    cout << "\n Course marked as completed!" << endl;
    pauseScreen();
}

// ==================== FACULTY MANAGEMENT ====================

void facultyManagementMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "\n|========================================|" << endl;
        cout << "|      FACULTY MANAGEMENT                |" << endl;
        cout << "|========================================|" << endl;
        cout << "  1. Add New Faculty" << endl;
        cout << "  2. View All Faculties" << endl;
        cout << "  3. Assign Course to Faculty" << endl;
        cout << "  0. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addFaculty();
            break;
        case 2:
            viewAllFaculties();
            pauseScreen();
            break;
        case 3:
            assignCourseToFaculty();
            break;
        case 0:
            return;
        default:
            cout << " Invalid choice!" << endl;
            pauseScreen();
        }
    }
}

void addFaculty() {
    clearScreen();
    cout << "\n=== ADD NEW FACULTY ===" << endl;

    string id, name;

    cout << "Enter Faculty ID: ";
    getline(cin, id);

    if (findFacultyByID(id) != nullptr) {
        cout << " Faculty with this ID already exists!" << endl;
        pauseScreen();
        return;
    }

    cout << "Enter Faculty Name: ";
    getline(cin, name);

    Faculty f(id, name);
    faculties.push_back(f);

    cout << "\n Faculty added successfully!" << endl;
    pauseScreen();
}

void viewAllFaculties() {
    clearScreen();
    cout << "\n=== ALL FACULTIES ===" << endl;

    if (faculties.empty()) {
        cout << "No faculties available." << endl;
        return;
    }

    for (int i = 0; i < faculties.size(); i++) {
        cout << "\n--- Faculty " << (i + 1) << " ---" << endl;
        faculties[i].display();
    }
}

void assignCourseToFaculty() {
    clearScreen();
    cout << "\n=== ASSIGN COURSE TO FACULTY ===" << endl;

    if (faculties.empty() || courses.empty()) {
        cout << " Please add faculties and courses first." << endl;
        pauseScreen();
        return;
    }

    displayAvailableFaculties();

    string facultyID;
    cout << "\nEnter Faculty ID: ";
    getline(cin, facultyID);

    Faculty* faculty = findFacultyByID(facultyID);
    if (faculty == nullptr) {
        cout << " Faculty not found!" << endl;
        pauseScreen();
        return;
    }

    displayAvailableCourses();

    string courseCode;
    cout << "\nEnter Course Code: ";
    getline(cin, courseCode);

    if (findCourseByCode(courseCode) == nullptr) {
        cout << " Course not found!" << endl;
        pauseScreen();
        return;
    }

    faculty->assignCourse(courseCode);
    cout << "\n Course assigned successfully!" << endl;
    pauseScreen();
}

// ==================== ROOM MANAGEMENT ====================

void roomManagementMenu() {
    int choice;
    while (true) {
        clearScreen();
        cout << "\n|========================================|" << endl;
        cout << "|      ROOM MANAGEMENT                   |" << endl;
        cout << "|========================================|" << endl;
        cout << "  1. Add New Room" << endl;
        cout << "  2. View All Rooms" << endl;
        cout << "  3. Assign Room to Course" << endl;      
        cout << "  4. Free Room from Course" << endl;      
        cout << "  0. Back to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addRoom();
            break;
        case 2:
            viewAllRooms();
            pauseScreen();
            break;
        case 3:                    
            assignRoomToCourse();   
            break;                  
        case 4:                    
            freeRoomFromCourse();   
            break;                  
        case 0:
            return;
        default:
            cout << " Invalid choice!" << endl;
            pauseScreen();
        }
    }
}

void addRoom() {
    clearScreen();
    cout << "\n=== ADD NEW ROOM ===" << endl;

    string number, type;
    int capacity;

    cout << "Enter Room Number (e.g., R101): ";
    getline(cin, number);

    if (findRoomByNumber(number) != nullptr) {
        cout << " Room with this number already exists!" << endl;
        pauseScreen();
        return;
    }

    cout << "Enter Room Type (Lab/Classroom/Auditorium): ";
    getline(cin, type);

    cout << "Enter Capacity: ";
    cin >> capacity;
    cin.ignore();

    if (capacity <= 0) {
        cout << " Capacity must be positive!" << endl;
        pauseScreen();
        return;
    }

    Room r(number, type, capacity);
    rooms.push_back(r);

    cout << "\n Room added successfully!" << endl;
    pauseScreen();
}

void viewAllRooms() {
    clearScreen();
    cout << "\n=== ALL ROOMS ===" << endl;

    if (rooms.empty()) {
        cout << "No rooms available." << endl;
        return;
    }

    for (int i = 0; i < rooms.size(); i++) {
        cout << "\n--- Room " << (i + 1) << " ---" << endl;
        rooms[i].display();
    }
}

void assignRoomToCourse() {
    clearScreen();
    cout << "\n=== ASSIGN ROOM TO COURSE ===" << endl;

    if (rooms.empty() || courses.empty()) {
        cout << " Please add rooms and courses first." << endl;
        pauseScreen();
        return;
    }

    // Display only available rooms
    cout << "\nAvailable Rooms:" << endl;
    bool hasAvailable = false;
    for (int i = 0; i < rooms.size(); i++) {
        if (!rooms[i].getIsOccupied()) {
            cout << "  - " << rooms[i].getRoomNumber() << " ("
                << rooms[i].getRoomType() << ", Capacity: "
                << rooms[i].getCapacity() << ")" << endl;
            hasAvailable = true;
        }
    }

    if (!hasAvailable) {
        cout << " No available rooms! All rooms are occupied." << endl;
        pauseScreen();
        return;
    }

    string roomNumber;
    cout << "\nEnter Room Number: ";
    getline(cin, roomNumber);

    Room* room = findRoomByNumber(roomNumber);
    if (room == nullptr) {
        cout << " Room not found!" << endl;
        pauseScreen();
        return;
    }

    if (room->getIsOccupied()) {
        cout << " Room is already occupied by course: "
            << room->getAssignedCourse() << endl;
        cout << "Please free this room first before assigning to another course." << endl;
        pauseScreen();
        return;
    }

    displayAvailableCourses();

    string courseCode;
    cout << "\nEnter Course Code: ";
    getline(cin, courseCode);

    if (findCourseByCode(courseCode) == nullptr) {
        cout << " Course not found!" << endl;
        pauseScreen();
        return;
    }

    room->assignToCourse(courseCode);
    cout << "\n Room " << roomNumber << " assigned to course "
        << courseCode << " successfully!" << endl;
    pauseScreen();
}

void freeRoomFromCourse() {
    clearScreen();
    cout << "\n=== FREE ROOM FROM COURSE ===" << endl;

    if (rooms.empty()) {
        cout << " No rooms available." << endl;
        pauseScreen();
        return;
    }

    // Display only occupied rooms
    cout << "\nOccupied Rooms:" << endl;
    bool hasOccupied = false;
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].getIsOccupied()) {
            cout << "  - " << rooms[i].getRoomNumber() << " -> "
                << rooms[i].getAssignedCourse() << endl;
            hasOccupied = true;
        }
    }

    if (!hasOccupied) {
        cout << " No occupied rooms! All rooms are available." << endl;
        pauseScreen();
        return;
    }

    string roomNumber;
    cout << "\nEnter Room Number to free: ";
    getline(cin, roomNumber);

    Room* room = findRoomByNumber(roomNumber);
    if (room == nullptr) {
        cout << " Room not found!" << endl;
        pauseScreen();
        return;
    }

    if (!room->getIsOccupied()) {
        cout << " Room is already available!" << endl;
        pauseScreen();
        return;
    }

    string previousCourse = room->getAssignedCourse();
    room->freeRoom();
    cout << "\n Room " << roomNumber << " freed from course "
        << previousCourse << " successfully!" << endl;
    cout << "Room is now available for assignment." << endl;
    pauseScreen();
}

// ==================== SET OPERATIONS MODULE ====================

void setOperationsMenu() {
    clearScreen();
    cout << "\n|========================================|" << endl;
    cout << "|      SET OPERATIONS MODULE             |" << endl;
    cout << "|========================================|" << endl;

    if (students.empty() || courses.empty()) {
        cout << " Please add students and courses first." << endl;
        pauseScreen();
        return;
    }

    displayAvailableCourses();

    string course1, course2;

    cout << "\nEnter first course code: ";
    getline(cin, course1);

    cout << "Enter second course code: ";
    getline(cin, course2);

    // Get students enrolled in each course
    vector<string> set1, set2;

    for (int i = 0; i < students.size(); i++) {
        vector<string> enrolled = students[i].getEnrolledCourses();
        for (int j = 0; j < enrolled.size(); j++) {
            if (enrolled[j] == course1) {
                set1.push_back(students[i].getStudentID());
            }
            if (enrolled[j] == course2) {
                set2.push_back(students[i].getStudentID());
            }
        }
    }

    cout << "\n=== SET OPERATIONS RESULTS ===" << endl;
    SetOperations::displaySet(set1, "Students in " + course1);
    SetOperations::displaySet(set2, "Students in " + course2);

    vector<string> unionSet = SetOperations::unionSets(set1, set2);
    SetOperations::displaySet(unionSet, "Union (Either course)");

    vector<string> intersection = SetOperations::intersectionSets(set1, set2);
    SetOperations::displaySet(intersection, "Intersection (Both courses)");

    vector<string> difference = SetOperations::differenceSets(set1, set2);
    SetOperations::displaySet(difference, "Difference (" + course1 + " only)");

    cout << "\n--- Subset Operations ---" << endl;
    cout << "Is " << course1 << " students is a subset of " << course2 << " students? "
        << (SetOperations::isSubset(set1, set2) ? "Yes" : "No") << endl;
    cout << "Is " << course2 << " students is a subset of " << course1 << " students? "
        << (SetOperations::isSubset(set2, set1) ? "Yes" : "No") << endl;

    // Power set demo (limit to small sets)
    if (set1.size() <= 4) {
        cout << "\n--- Power Set of " << course1 << " students ---" << endl;
        vector<vector<string>> pset = SetOperations::powerSet(set1);
        SetOperations::displayPowerSet(pset, "Power Set");
    }
    else {
        cout << "\n--- Power Set ---" << endl;
        cout << "Power set size would be 2^" << set1.size() << " = ";
        int psize = 1;
        for (int i = 0; i < set1.size(); i++) psize *= 2;
        cout << psize << " (too large to display)" << endl;
    }

    pauseScreen();
}

// ==================== INDUCTION MODULE ====================

void inductionVerificationMenu() {
    clearScreen();
    cout << "\n|========================================|" << endl;
    cout << "|  INDUCTION & PREREQUISITES VERIFICATION|" << endl;
    cout << "|========================================|" << endl;

    if (students.empty() || courses.empty()) {
        cout << " Please add students and courses first." << endl;
        pauseScreen();
        return;
    }

    displayAvailableStudents();

    string studentID;
    cout << "\nEnter Student ID: ";
    getline(cin, studentID);

    Student* student = findStudentByID(studentID);
    if (student == nullptr) {
        cout << " Student not found!" << endl;
        pauseScreen();
        return;
    }

    displayAvailableCourses();

    string courseCode;
    cout << "\nEnter Course Code to verify: ";
    getline(cin, courseCode);

    if (findCourseByCode(courseCode) == nullptr) {
        cout << " Course not found!" << endl;
        pauseScreen();
        return;
    }

    InductionModule::verifyPrerequisiteChain(courseCode, courses, *student);

    pauseScreen();
}

// ==================== LOGIC & INFERENCE ====================

void logicInferenceMenu() {
    clearScreen();
    cout << "\n|========================================|" << endl;
    cout << "|    LOGIC & INFERENCE ENGINE            |" << endl;
    cout << "|========================================|" << endl;

    LogicEngine engine;

    int numRules;
    cout << "\nHow many rules do you want to add? ";
    cin >> numRules;
    cin.ignore();

    for (int i = 0; i < numRules; i++) {
        string condition, consequence, description;

        cout << "\n--- Rule " << (i + 1) << " ---" << endl;
        cout << "Enter condition (IF part): ";
        getline(cin, condition);

        cout << "Enter consequence (THEN part): ";
        getline(cin, consequence);

        cout << "Enter description: ";
        getline(cin, description);

        engine.addRule(condition, consequence, description);
    }

    engine.displayRules();

    int numFacts;
    cout << "\nHow many facts do you want to provide? ";
    cin >> numFacts;
    cin.ignore();

    vector<string> facts;
    for (int i = 0; i < numFacts; i++) {
        string fact;
        cout << "Fact " << (i + 1) << ": ";
        getline(cin, fact);
        facts.push_back(fact);
    }

    vector<string> conclusions = engine.performInference(facts);

    cout << "\n=== INFERRED CONCLUSIONS ===" << endl;
    if (conclusions.empty()) {
        cout << "No conclusions could be derived." << endl;
    }
    else {
        for (int i = 0; i < conclusions.size(); i++) {
            cout << "  " << (i + 1) << ". " << conclusions[i] << endl;
        }
    }

    pauseScreen();
}

// ==================== RELATIONS MODULE ====================

void relationsMenu() {
    clearScreen();
    cout << "\n|========================================|" << endl;
    cout << "|       RELATIONS MODULE                 |" << endl;
    cout << "|========================================|" << endl;

    cout << "\nSelect relation type:" << endl;
    cout << "1. Student-Course Relation" << endl;
    cout << "2. Faculty-Course Relation" << endl;
    cout << "3. Course-Room Relation" << endl;
    cout << "4. Custom Relation" << endl;

    int relType;
    cout << "\nEnter choice: ";
    cin >> relType;
    cin.ignore();

    RelationsModule relation;

    if (relType == 1) {
        // Student-Course
        if (students.empty() || courses.empty()) {
            cout << " Please add students and courses first." << endl;
            pauseScreen();
            return;
        }

        relation = RelationsModule("Student-Course Relation");

        int numPairs;
        cout << "\nHow many student-course pairs to add? ";
        cin >> numPairs;
        cin.ignore();

        for (int i = 0; i < numPairs; i++) {
            displayAvailableStudents();
            string studentID;
            cout << "\nPair " << (i + 1) << " - Enter Student ID: ";
            getline(cin, studentID);

            if (findStudentByID(studentID) == nullptr) {
                cout << " Student not found! Skipping this pair." << endl;
                continue;
            }

            displayAvailableCourses();
            string courseCode;
            cout << "Enter Course Code: ";
            getline(cin, courseCode);

            if (findCourseByCode(courseCode) == nullptr) {
                cout << " Course not found! Skipping this pair." << endl;
                continue;
            }

            relation.addPair(studentID, courseCode);
            cout << " Pair added!" << endl;
        }

    }
    else if (relType == 2) {
        // Faculty-Course
        if (faculties.empty() || courses.empty()) {
            cout << " Please add faculties and courses first." << endl;
            pauseScreen();
            return;
        }

        relation = RelationsModule("Faculty-Course Relation");

        int numPairs;
        cout << "\nHow many faculty-course pairs to add? ";
        cin >> numPairs;
        cin.ignore();

        for (int i = 0; i < numPairs; i++) {
            displayAvailableFaculties();
            string facultyID;
            cout << "\nPair " << (i + 1) << " - Enter Faculty ID: ";
            getline(cin, facultyID);

            if (findFacultyByID(facultyID) == nullptr) {
                cout << " Faculty not found! Skipping this pair." << endl;
                continue;
            }

            displayAvailableCourses();
            string courseCode;
            cout << "Enter Course Code: ";
            getline(cin, courseCode);

            if (findCourseByCode(courseCode) == nullptr) {
                cout << " Course not found! Skipping this pair." << endl;
                continue;
            }

            relation.addPair(facultyID, courseCode);
            cout << " Pair added!" << endl;
        }

    }
    else if (relType == 3) {
        // Course-Room
        if (courses.empty() || rooms.empty()) {
            cout << " Please add courses and rooms first." << endl;
            pauseScreen();
            return;
        }

        relation = RelationsModule("Course-Room Relation");

        int numPairs;
        cout << "\nHow many course-room pairs to add? ";
        cin >> numPairs;
        cin.ignore();

        for (int i = 0; i < numPairs; i++) {
            displayAvailableCourses();
            string courseCode;
            cout << "\nPair " << (i + 1) << " - Enter Course Code: ";
            getline(cin, courseCode);

            if (findCourseByCode(courseCode) == nullptr) {
                cout << " Course not found! Skipping this pair." << endl;
                continue;
            }

            displayAvailableRooms();
            string roomNumber;
            cout << "Enter Room Number: ";
            getline(cin, roomNumber);

            if (findRoomByNumber(roomNumber) == nullptr) {
                cout << " Room not found! Skipping this pair." << endl;
                continue;
            }

            relation.addPair(courseCode, roomNumber);
            cout << " Pair added!" << endl;
        }

    }
    else if (relType == 4) {
        // Custom relation
        relation = RelationsModule("Custom Relation");

        int numPairs;
        cout << "\nHow many pairs to add? ";
        cin >> numPairs;
        cin.ignore();

        for (int i = 0; i < numPairs; i++) {
            string first, second;
            cout << "\nPair " << (i + 1) << ":" << endl;
            cout << "  First element: ";
            getline(cin, first);
            cout << "  Second element: ";
            getline(cin, second);

            relation.addPair(first, second);
        }

    }
    else {
        cout << " Invalid choice!" << endl;
        pauseScreen();
        return;
    }

    relation.display();

    cout << "\n=== RELATION PROPERTIES ===" << endl;
    cout << "Reflexive:   " << (relation.isReflexive() ? " Yes" : " No") << endl;
    cout << "Symmetric:   " << (relation.isSymmetric() ? " Yes" : " No") << endl;
    cout << "Transitive:  " << (relation.isTransitive() ? " Yes" : " No") << endl;
    cout << "Equivalence: " << (relation.isEquivalence() ? " Yes" : " No") << endl;

    pauseScreen();
}

// ==================== FUNCTIONS MODULE ====================

void functionsMenu() {
    clearScreen();
    cout << "\n|========================================|" << endl;
    cout << "|       FUNCTIONS MODULE                 |" << endl;
    cout << "|========================================|" << endl;

    cout << "\nSelect function type:" << endl;
    cout << "1. Student -> Course Function" << endl;
    cout << "2. Course -> Faculty Function" << endl;
    cout << "3. Faculty -> Room Function" << endl;
    cout << "4. Custom Function" << endl;

    int funcType;
    cout << "\nEnter choice: ";
    cin >> funcType;
    cin.ignore();

    FunctionsModule function;
    vector<string> targetCodomain;

    if (funcType == 1) {
        // Student -> Course
        if (students.empty() || courses.empty()) {
            cout << " Please add students and courses first." << endl;
            pauseScreen();
            return;
        }

        function = FunctionsModule("Student -> Course Function");

        // Build codomain (all courses)
        for (int i = 0; i < courses.size(); i++) {
            targetCodomain.push_back(courses[i].getCourseCode());
        }

        int numMappings;
        cout << "\nHow many student->course mappings to add? ";
        cin >> numMappings;
        cin.ignore();

        for (int i = 0; i < numMappings; i++) {
            displayAvailableStudents();
            string studentID;
            cout << "\nMapping " << (i + 1) << " - Enter Student ID: ";
            getline(cin, studentID);

            if (findStudentByID(studentID) == nullptr) {
                cout << " Student not found! Skipping this mapping." << endl;
                continue;
            }

            displayAvailableCourses();
            string courseCode;
            cout << "Enter Course Code: ";
            getline(cin, courseCode);

            if (findCourseByCode(courseCode) == nullptr) {
                cout << " Course not found! Skipping this mapping." << endl;
                continue;
            }

            function.addMapping(studentID, courseCode);
            cout << " Mapping added!" << endl;
        }

    }
    else if (funcType == 2) {
        // Course -> Faculty
        if (courses.empty() || faculties.empty()) {
            cout << " Please add courses and faculties first." << endl;
            pauseScreen();
            return;
        }

        function = FunctionsModule("Course -> Faculty Function");

        // Build codomain (all faculties)
        for (int i = 0; i < faculties.size(); i++) {
            targetCodomain.push_back(faculties[i].getFacultyID());
        }

        int numMappings;
        cout << "\nHow many course->faculty mappings to add? ";
        cin >> numMappings;
        cin.ignore();

        for (int i = 0; i < numMappings; i++) {
            displayAvailableCourses();
            string courseCode;
            cout << "\nMapping " << (i + 1) << " - Enter Course Code: ";
            getline(cin, courseCode);

            if (findCourseByCode(courseCode) == nullptr) {
                cout << " Course not found! Skipping this mapping." << endl;
                continue;
            }

            displayAvailableFaculties();
            string facultyID;
            cout << "Enter Faculty ID: ";
            getline(cin, facultyID);

            if (findFacultyByID(facultyID) == nullptr) {
                cout << " Faculty not found! Skipping this mapping." << endl;
                continue;
            }

            function.addMapping(courseCode, facultyID);
            cout << " Mapping added!" << endl;
        }

    }
    else if (funcType == 3) {
        // Faculty -> Room
        if (faculties.empty() || rooms.empty()) {
            cout << " Please add faculties and rooms first." << endl;
            pauseScreen();
            return;
        }

        function = FunctionsModule("Faculty -> Room Function");

        // Build codomain (all rooms)
        for (int i = 0; i < rooms.size(); i++) {
            targetCodomain.push_back(rooms[i].getRoomNumber());
        }

        int numMappings;
        cout << "\nHow many faculty->room mappings to add? ";
        cin >> numMappings;
        cin.ignore();

        for (int i = 0; i < numMappings; i++) {
            displayAvailableFaculties();
            string facultyID;
            cout << "\nMapping " << (i + 1) << " - Enter Faculty ID: ";
            getline(cin, facultyID);

            if (findFacultyByID(facultyID) == nullptr) {
                cout << " Faculty not found! Skipping this mapping." << endl;
                continue;
            }

            displayAvailableRooms();
            string roomNumber;
            cout << "Enter Room Number: ";
            getline(cin, roomNumber);

            if (findRoomByNumber(roomNumber) == nullptr) {
                cout << " Room not found! Skipping this mapping." << endl;
                continue;
            }

            function.addMapping(facultyID, roomNumber);
            cout << " Mapping added!" << endl;
        }

    }
    else if (funcType == 4) {
        // Custom function
        function = FunctionsModule("Custom Function");

        int numMappings;
        cout << "\nHow many mappings to add? ";
        cin >> numMappings;
        cin.ignore();

        for (int i = 0; i < numMappings; i++) {
            string domain, codomain;
            cout << "\nMapping " << (i + 1) << ":" << endl;
            cout << "  Domain element: ";
            getline(cin, domain);
            cout << "  Codomain element: ";
            getline(cin, codomain);

            function.addMapping(domain, codomain);

            // Build target codomain
            bool found = false;
            for (int j = 0; j < targetCodomain.size(); j++) {
                if (targetCodomain[j] == codomain) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                targetCodomain.push_back(codomain);
            }
        }

    }
    else {
        cout << " Invalid choice!" << endl;
        pauseScreen();
        return;
    }

    function.display();

    cout << "\n=== FUNCTION PROPERTIES ===" << endl;
    cout << "Injective (One-to-One): "
        << (function.isInjective() ? " Yes" : " No") << endl;
    cout << "Surjective (Onto):      "
        << (function.isSurjective(targetCodomain) ? " Yes" : " No") << endl;
    cout << "Bijective:              "
        << (function.isBijective(targetCodomain) ? " Yes" : " No") << endl;

    pauseScreen();
}

// ==================== COMBINATIONS MODULE ====================

void combinationsMenu() {
    clearScreen();
    cout << "\n|========================================|" << endl;
    cout << "|   COMBINATIONS MODULE                  |" << endl;
    cout << "|========================================|" << endl;

    if (students.empty()) {
        cout << " Please add students first." << endl;
        pauseScreen();
        return;
    }

    cout << "\nSelect operation:" << endl;
    cout << "1. Assign Students to Project Groups" << endl;
    cout << "2. Assign Students to Lab Sessions" << endl;
    cout << "3. Assign Students to Electives" << endl;
    cout << "4. Generate All Combinations (View only)" << endl;

    int choice;
    cout << "\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        // Project Groups Assignment
        int groupSize;
        cout << "\nTotal students: " << students.size() << endl;
        cout << "Enter project group size: ";
        cin >> groupSize;
        cin.ignore();

        if (groupSize <= 0 || groupSize > students.size()) {
            cout << " Invalid group size!" << endl;
            pauseScreen();
            return;
        }

        cout << "\n=== COUNTING PRINCIPLES ===" << endl;
        cout << "C(" << students.size() << "," << groupSize << ") = "
            << CombinationModule::combinations(students.size(), groupSize)
            << " possible combinations" << endl;

        vector<ProjectGroup> groups = CombinationModule::assignProjectGroups(students, groupSize);
        CombinationModule::displayProjectGroups(groups);

    }
    else if (choice == 2) {
        // Lab Sessions Assignment
        int numSessions;
        cout << "\nTotal students: " << students.size() << endl;
        cout << "Enter number of lab sessions: ";
        cin >> numSessions;
        cin.ignore();

        if (numSessions <= 0 || numSessions > students.size()) {
            cout << " Invalid number of sessions!" << endl;
            pauseScreen();
            return;
        }

        vector<string> timeSlots;
        cout << "\nEnter time slots for " << numSessions << " sessions:" << endl;
        for (int i = 0; i < numSessions; i++) {
            string slot;
            cout << "Session " << (i + 1) << " time slot: ";
            getline(cin, slot);
            timeSlots.push_back(slot);
        }

        vector<LabSession> sessions = CombinationModule::assignLabSessions(
            students, numSessions, timeSlots
        );
        CombinationModule::displayLabSessions(sessions);

    }
    else if (choice == 3) {
        // Electives Assignment
        if (courses.empty()) {
            cout << " Please add courses first." << endl;
            pauseScreen();
            return;
        }

        int numElectives;
        cout << "\nHow many elective courses to choose from? ";
        cin >> numElectives;
        cin.ignore();

        if (numElectives <= 0 || numElectives > courses.size()) {
            cout << " Invalid number!" << endl;
            pauseScreen();
            return;
        }

        vector<string> electiveCourses;
        displayAvailableCourses();

        cout << "\nEnter " << numElectives << " elective course codes:" << endl;
        for (int i = 0; i < numElectives; i++) {
            string code;
            cout << "Elective " << (i + 1) << ": ";
            getline(cin, code);

            if (findCourseByCode(code) == nullptr) {
                cout << " Course not found! Skipping." << endl;
                continue;
            }
            electiveCourses.push_back(code);
        }

        if (electiveCourses.empty()) {
            cout << " No valid electives added!" << endl;
            pauseScreen();
            return;
        }

        int maxElectives;
        cout << "\nHow many electives can each student choose? ";
        cin >> maxElectives;
        cin.ignore();

        if (maxElectives <= 0 || maxElectives > electiveCourses.size()) {
            cout << " Invalid number!" << endl;
            pauseScreen();
            return;
        }

        CombinationModule::assignElectives(students, electiveCourses, maxElectives);

    }
    else if (choice == 4) {
        // View all combinations
        int groupSize;
        cout << "\nTotal students: " << students.size() << endl;
        cout << "Enter combination size: ";
        cin >> groupSize;
        cin.ignore();

        if (groupSize <= 0 || groupSize > students.size()) {
            cout << " Invalid size!" << endl;
            pauseScreen();
            return;
        }

        vector<string> studentIDs;
        for (int i = 0; i < students.size(); i++) {
            studentIDs.push_back(students[i].getStudentID());
        }

        cout << "\n=== COUNTING PRINCIPLES ===" << endl;
        cout << "Combinations C(" << students.size() << "," << groupSize << ") = "
            << CombinationModule::combinations(students.size(), groupSize) << endl;
        cout << "Permutations P(" << students.size() << "," << groupSize << ") = "
            << CombinationModule::permutations(students.size(), groupSize) << endl;

        vector<vector<string>> combos = CombinationModule::generateCombinations(
            studentIDs, groupSize
        );
        CombinationModule::displayCombinations(combos);

    }
    else {
        cout << " Invalid choice!" << endl;
    }

    pauseScreen();
}

// ==================== CONSISTENCY CHECKER ====================

void consistencyCheckMenu() {
    clearScreen();
    cout << "\n|========================================|" << endl;
    cout << "|      CONSISTENCY CHECKER               |" << endl;
    cout << "|========================================|" << endl;

    if (students.empty() || courses.empty() || faculties.empty()) {
        cout << " Please add students, courses, and faculties first." << endl;
        pauseScreen();
        return;
    }

    ConsistencyChecker::performConsistencyCheck(students, courses, faculties);

    pauseScreen();
}