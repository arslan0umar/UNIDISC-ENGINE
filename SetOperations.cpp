#include "SetOperations.h"
#include <iostream>
using namespace std;

vector<string> SetOperations::unionSets(vector<string> set1, vector<string> set2) {
    vector<string> result = set1;

    for (int i = 0; i < set2.size(); i++) {
        bool found = false;
        for (int j = 0; j < result.size(); j++) {
            if (result[j] == set2[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(set2[i]);
        }
    }
    return result;
}

vector<string> SetOperations::intersectionSets(vector<string> set1, vector<string> set2) {
    vector<string> result;

    for (int i = 0; i < set1.size(); i++) {
        for (int j = 0; j < set2.size(); j++) {
            if (set1[i] == set2[j]) {
                result.push_back(set1[i]);
                break;
            }
        }
    }
    return result;
}

vector<string> SetOperations::differenceSets(vector<string> set1, vector<string> set2) {
    vector<string> result;

    for (int i = 0; i < set1.size(); i++) {
        bool found = false;
        for (int j = 0; j < set2.size(); j++) {
            if (set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(set1[i]);
        }
    }
    return result;
}

bool SetOperations::isSubset(vector<string> subset, vector<string> superset) {
    for (int i = 0; i < subset.size(); i++) {
        bool found = false;
        for (int j = 0; j < superset.size(); j++) {
            if (subset[i] == superset[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool SetOperations::contains(vector<string> set, string element) {
    for (int i = 0; i < set.size(); i++) {
        if (set[i] == element) {
            return true;
        }
    }
    return false;
}

vector<vector<string>> SetOperations::powerSet(vector<string> set) {
    vector<vector<string>> result;
    int n = set.size();
    int powerSetSize = 1;

    // Calculate 2^n
    for (int i = 0; i < n; i++) {
        powerSetSize = powerSetSize * 2;
    }

    // Generate all subsets
    for (int i = 0; i < powerSetSize; i++) {
        vector<string> subset;
        for (int j = 0; j < n; j++) {
            // Check if jth bit is set in i
            if ((i & (1 << j)) > 0) {
                subset.push_back(set[j]);
            }
        }
        result.push_back(subset);
    }
    return result;
}

void SetOperations::displaySet(vector<string> set, string setName) {
    cout << setName << " = { ";
    for (int i = 0; i < set.size(); i++) {
        cout << set[i];
        if (i < set.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
}

void SetOperations::displayPowerSet(vector<vector<string>> pset, string setName) {
    cout << "\n" << setName << " (Size: " << pset.size() << "):" << endl;
    for (int i = 0; i < pset.size(); i++) {
        cout << "  { ";
        for (int j = 0; j < pset[i].size(); j++) {
            cout << pset[i][j];
            if (j < pset[i].size() - 1) cout << ", ";
        }
        cout << " }" << endl;
    }
}

vector<string> SetOperations::getAllElements(vector<vector<string>> sets) {
    vector<string> allElements;

    for (int i = 0; i < sets.size(); i++) {
        for (int j = 0; j < sets[i].size(); j++) {
            bool found = false;
            for (int k = 0; k < allElements.size(); k++) {
                if (allElements[k] == sets[i][j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                allElements.push_back(sets[i][j]);
            }
        }
    }

    return allElements;
}