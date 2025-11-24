#include "RelationsModule.h"
#include <iostream>
using namespace std;

RelationsModule::RelationsModule() {
    relationName = "Relation";
}

RelationsModule::RelationsModule(string name) {
    relationName = name;
}

void RelationsModule::addPair(string a, string b) {
    Pair p;
    p.first = a;
    p.second = b;
    relation.push_back(p);
}

vector<string> RelationsModule::getDomain() {
    vector<string> domain;
    for (int i = 0; i < relation.size(); i++) {
        bool found = false;
        for (int j = 0; j < domain.size(); j++) {
            if (domain[j] == relation[i].first) {
                found = true;
                break;
            }
        }
        if (!found) {
            domain.push_back(relation[i].first);
        }
    }
    return domain;
}

vector<string> RelationsModule::getCodomain() {
    vector<string> codomain;
    for (int i = 0; i < relation.size(); i++) {
        bool found = false;
        for (int j = 0; j < codomain.size(); j++) {
            if (codomain[j] == relation[i].second) {
                found = true;
                break;
            }
        }
        if (!found) {
            codomain.push_back(relation[i].second);
        }
    }
    return codomain;
}

bool RelationsModule::isReflexive() {
    vector<string> elements = getDomain();
    vector<string> elements2 = getCodomain();

    // Merge both sets
    for (int i = 0; i < elements2.size(); i++) {
        bool found = false;
        for (int j = 0; j < elements.size(); j++) {
            if (elements[j] == elements2[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            elements.push_back(elements2[i]);
        }
    }

    // Check if (a, a) exists for all a
    for (int i = 0; i < elements.size(); i++) {
        bool found = false;
        for (int j = 0; j < relation.size(); j++) {
            if (relation[j].first == elements[i] &&
                relation[j].second == elements[i]) {
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

bool RelationsModule::isSymmetric() {
    // For every (a, b), check if (b, a) exists
    for (int i = 0; i < relation.size(); i++) {
        bool found = false;
        for (int j = 0; j < relation.size(); j++) {
            if (relation[j].first == relation[i].second &&
                relation[j].second == relation[i].first) {
                found = true;
                break;
            }
        }
        if (!found && relation[i].first != relation[i].second) {
            return false;
        }
    }
    return true;
}

bool RelationsModule::isTransitive() {
    // For every (a, b) and (b, c), check if (a, c) exists
    for (int i = 0; i < relation.size(); i++) {
        for (int j = 0; j < relation.size(); j++) {
            if (relation[i].second == relation[j].first) {
                // Found (a, b) and (b, c), now check for (a, c)
                bool found = false;
                for (int k = 0; k < relation.size(); k++) {
                    if (relation[k].first == relation[i].first &&
                        relation[k].second == relation[j].second) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool RelationsModule::isEquivalence() {
    return isReflexive() && isSymmetric() && isTransitive();
}

RelationsModule RelationsModule::compose(RelationsModule& r1, RelationsModule& r2) {
    RelationsModule result("Composition");

    vector<Pair> rel1 = r1.getRelation();
    vector<Pair> rel2 = r2.getRelation();

    // For composition: if (a, b) in R1 and (b, c) in R2, then (a, c) in result
    for (int i = 0; i < rel1.size(); i++) {
        for (int j = 0; j < rel2.size(); j++) {
            if (rel1[i].second == rel2[j].first) {
                result.addPair(rel1[i].first, rel2[j].second);
            }
        }
    }

    return result;
}

void RelationsModule::display() const {
    cout << "\n=== " << relationName << " ===" << endl;
    cout << "{ ";
    for (int i = 0; i < relation.size(); i++) {
        cout << "(" << relation[i].first << ", " << relation[i].second << ")";
        if (i < relation.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
}

vector<Pair> RelationsModule::getRelation() const {
    return relation;
}