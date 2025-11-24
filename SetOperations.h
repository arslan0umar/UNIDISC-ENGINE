#ifndef SETOPERATIONS_H
#define SETOPERATIONS_H

#include <vector>
#include <string>
using namespace std;

class SetOperations {
public:
    // Basic set operations
    static vector<string> unionSets(vector<string> set1, vector<string> set2);
    static vector<string> intersectionSets(vector<string> set1, vector<string> set2);
    static vector<string> differenceSets(vector<string> set1, vector<string> set2);

    // Check operations
    static bool isSubset(vector<string> subset, vector<string> superset);
    static bool contains(vector<string> set, string element);

    // Power set (generates all subsets)
    static vector<vector<string>> powerSet(vector<string> set);

    // Display
    static void displaySet(vector<string> set, string setName);
    static void displayPowerSet(vector<vector<string>> pset, string setName);

    // Get all unique elements from multiple sets
    static vector<string> getAllElements(vector<vector<string>> sets);
};

#endif