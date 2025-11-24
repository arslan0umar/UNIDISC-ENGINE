#ifndef COMBINATIONMODULE_H
#define COMBINATIONMODULE_H

#include <vector>
#include <string>
#include "Student.h"
using namespace std;

// Structure to hold group assignment
struct ProjectGroup {
    int groupNumber;
    vector<string> members; // Student IDs
};

struct LabSession {
    string sessionName;
    string timeSlot;
    vector<string> students; // Student IDs
};

class CombinationModule {
public:
    // Calculate factorial
    static long long factorial(int n);

    // Calculate nCr (combinations)
    static long long combinations(int n, int r);

    // Calculate nPr (permutations)
    static long long permutations(int n, int r);

    // Generate all combinations of size r from given students
    static vector<vector<string>> generateCombinations(
        vector<string> students,
        int groupSize
    );

    // Assign students to project groups
    static vector<ProjectGroup> assignProjectGroups(
        vector<Student>& students,
        int groupSize
    );

    // Assign students to lab sessions
    static vector<LabSession> assignLabSessions(
        vector<Student>& students,
        int sessionsCount,
        vector<string> timeSlots
    );

    // Assign students to electives based on combinations
    static void assignElectives(
        vector<Student>& students,
        vector<string> electiveCourses,
        int maxElectives
    );

    // Display combinations
    static void displayCombinations(vector<vector<string>> combos);

    // Display project groups
    static void displayProjectGroups(vector<ProjectGroup>& groups);

    // Display lab sessions
    static void displayLabSessions(vector<LabSession>& sessions);

private:
    // Helper for generating combinations
    static void generateCombinationsHelper(
        vector<string>& students,
        vector<vector<string>>& result,
        vector<string>& current,
        int start,
        int groupSize
    );
};

#endif