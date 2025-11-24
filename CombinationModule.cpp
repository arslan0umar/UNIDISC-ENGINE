#include "CombinationModule.h"
#include <iostream>
using namespace std;

long long CombinationModule::factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long CombinationModule::combinations(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

long long CombinationModule::permutations(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / factorial(n - r);
}

void CombinationModule::generateCombinationsHelper(
    vector<string>& students,
    vector<vector<string>>& result,
    vector<string>& current,
    int start,
    int groupSize
) {
    if (current.size() == groupSize) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < students.size(); i++) {
        current.push_back(students[i]);
        generateCombinationsHelper(students, result, current, i + 1, groupSize);
        current.pop_back();
    }
}

vector<vector<string>> CombinationModule::generateCombinations(
    vector<string> students,
    int groupSize
) {
    vector<vector<string>> result;
    vector<string> current;

    if (groupSize > students.size()) {
        cout << "Group size cannot be larger than number of students!" << endl;
        return result;
    }

    generateCombinationsHelper(students, result, current, 0, groupSize);
    return result;
}

vector<ProjectGroup> CombinationModule::assignProjectGroups(
    vector<Student>& students,
    int groupSize
) {
    vector<ProjectGroup> groups;
    vector<string> availableStudents;

    // Get all student IDs
    for (int i = 0; i < students.size(); i++) {
        availableStudents.push_back(students[i].getStudentID());
    }

    // Assign students to groups
    int groupNumber = 1;
    for (int i = 0; i < availableStudents.size(); i += groupSize) {
        ProjectGroup group;
        group.groupNumber = groupNumber++;

        for (int j = i; j < i + groupSize && j < availableStudents.size(); j++) {
            group.members.push_back(availableStudents[j]);
        }

        groups.push_back(group);
    }

    return groups;
}

vector<LabSession> CombinationModule::assignLabSessions(
    vector<Student>& students,
    int sessionsCount,
    vector<string> timeSlots
) {
    vector<LabSession> sessions;

    int studentsPerSession = students.size() / sessionsCount;
    if (students.size() % sessionsCount != 0) {
        studentsPerSession++;
    }

    int studentIndex = 0;
    for (int i = 0; i < sessionsCount && studentIndex < students.size(); i++) {
        LabSession session;
        session.sessionName = "Lab Session " + to_string(i + 1);
        session.timeSlot = (i < timeSlots.size()) ? timeSlots[i] : "TBD";

        for (int j = 0; j < studentsPerSession && studentIndex < students.size(); j++) {
            session.students.push_back(students[studentIndex].getStudentID());
            studentIndex++;
        }

        sessions.push_back(session);
    }

    return sessions;
}

void CombinationModule::assignElectives(
    vector<Student>& students,
    vector<string> electiveCourses,
    int maxElectives
) {
    cout << "\n=== ELECTIVE ASSIGNMENT ===" << endl;
    cout << "Available Electives: ";
    for (int i = 0; i < electiveCourses.size(); i++) {
        cout << electiveCourses[i];
        if (i < electiveCourses.size() - 1) cout << ", ";
    }
    cout << endl;

    cout << "\nPossible elective combinations (choosing " << maxElectives
        << " from " << electiveCourses.size() << "): "
        << combinations(electiveCourses.size(), maxElectives) << endl;

    // Generate all possible elective combinations
    vector<vector<string>> electiveCombos = generateCombinations(electiveCourses, maxElectives);

    cout << "\nAssigning electives to students:" << endl;
    for (int i = 0; i < students.size(); i++) {
        int comboIndex = i % electiveCombos.size();
        cout << "\n" << students[i].getStudentName() << " (" << students[i].getStudentID() << "):" << endl;
        cout << "  Assigned Electives: ";
        for (int j = 0; j < electiveCombos[comboIndex].size(); j++) {
            cout << electiveCombos[comboIndex][j];
            if (j < electiveCombos[comboIndex].size() - 1) cout << ", ";
        }
        cout << endl;
    }
}

void CombinationModule::displayCombinations(vector<vector<string>> combos) {
    cout << "\n=== All Possible Combinations ===" << endl;
    cout << "Total: " << combos.size() << " combinations" << endl;

    for (int i = 0; i < combos.size(); i++) {
        cout << "Combination " << (i + 1) << ": { ";
        for (int j = 0; j < combos[i].size(); j++) {
            cout << combos[i][j];
            if (j < combos[i].size() - 1) cout << ", ";
        }
        cout << " }" << endl;
    }
}

void CombinationModule::displayProjectGroups(vector<ProjectGroup>& groups) {
    cout << "\n=== PROJECT GROUPS ASSIGNMENT ===" << endl;
    cout << "Total Groups: " << groups.size() << endl;

    for (int i = 0; i < groups.size(); i++) {
        cout << "\nGroup " << groups[i].groupNumber << ":" << endl;
        cout << "  Members: ";
        for (int j = 0; j < groups[i].members.size(); j++) {
            cout << groups[i].members[j];
            if (j < groups[i].members.size() - 1) cout << ", ";
        }
        cout << endl;
        cout << "  Size: " << groups[i].members.size() << " students" << endl;
    }
}

void CombinationModule::displayLabSessions(vector<LabSession>& sessions) {
    cout << "\n=== LAB SESSIONS ASSIGNMENT ===" << endl;
    cout << "Total Sessions: " << sessions.size() << endl;

    for (int i = 0; i < sessions.size(); i++) {
        cout << "\n" << sessions[i].sessionName << endl;
        cout << "  Time Slot: " << sessions[i].timeSlot << endl;
        cout << "  Students (" << sessions[i].students.size() << "): ";
        for (int j = 0; j < sessions[i].students.size(); j++) {
            cout << sessions[i].students[j];
            if (j < sessions[i].students.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}