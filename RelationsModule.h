#ifndef RELATIONSMODULE_H
#define RELATIONSMODULE_H

#include <string>
#include <vector>
using namespace std;

// Represents a binary relation pair (a, b)
struct Pair {
    string first;
    string second;
};

class RelationsModule {
private:
    vector<Pair> relation;
    string relationName;

public:
    RelationsModule();
    RelationsModule(string name);

    // Add a relation pair
    void addPair(string a, string b);

    // Get all elements in domain
    vector<string> getDomain();

    // Get all elements in codomain
    vector<string> getCodomain();

    // Check properties
    bool isReflexive();
    bool isSymmetric();
    bool isTransitive();
    bool isEquivalence();

    // Relation composition
    static RelationsModule compose(RelationsModule& r1, RelationsModule& r2);

    // Display relation
    void display() const;

    // Get relation
    vector<Pair> getRelation() const;
};

#endif