#ifndef FUNCTIONSMODULE_H
#define FUNCTIONSMODULE_H

#include <string>
#include <vector>
using namespace std;

// Function mapping (domain -> codomain)
struct Mapping {
    string domain;
    string codomain;
};

class FunctionsModule {
private:
    vector<Mapping> function;
    string functionName;

public:
    FunctionsModule();
    FunctionsModule(string name);

    // Add a mapping
    void addMapping(string domain, string codomain);

    // Get domain and codomain
    vector<string> getDomain();
    vector<string> getCodomain();

    // Check properties
    bool isInjective();
    bool isSurjective(vector<string> targetCodomain);
    bool isBijective(vector<string> targetCodomain);

    // Function composition
    static FunctionsModule compose(FunctionsModule& f1, FunctionsModule& f2);

    // Display
    void display() const;

    // Get function
    vector<Mapping> getFunction() const;
};

#endif