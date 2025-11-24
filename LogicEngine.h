#ifndef LOGICENGINE_H
#define LOGICENGINE_H

#include <string>
#include <vector>
using namespace std;

// Represents a logical rule
struct Rule {
    string condition;    // IF part
    string consequence;  // THEN part
    string description;
};

class LogicEngine {
private:
    vector<Rule> rules;

public:
    // Add a rule
    void addRule(string condition, string consequence, string description);

    // Check if a rule is satisfied
    bool evaluateRule(Rule& rule, string fact1, string fact2);

    // Inference: derive conclusions from facts
    vector<string> performInference(vector<string>& facts);

    // Display all rules
    void displayRules() const;

    // Check specific rule
    bool checkRule(string condition, string consequence,
        string fact1, string fact2);
};

#endif