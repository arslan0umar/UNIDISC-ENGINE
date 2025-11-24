#include "LogicEngine.h"
#include <iostream>
using namespace std;

void LogicEngine::addRule(string condition, string consequence, string description) {
    Rule r;
    r.condition = condition;
    r.consequence = consequence;
    r.description = description;
    rules.push_back(r);
}

bool LogicEngine::evaluateRule(Rule& rule, string fact1, string fact2) {
    // Simple string matching for demonstration
    if (fact1.find(rule.condition) != string::npos) {
        if (fact2.find(rule.consequence) != string::npos) {
            return true;
        }
    }
    return false;
}

vector<string> LogicEngine::performInference(vector<string>& facts) {
    vector<string> conclusions;

    cout << "\n=== Performing Logical Inference ===" << endl;
    cout << "Given Facts:" << endl;
    for (int i = 0; i < facts.size(); i++) {
        cout << "  - " << facts[i] << endl;
    }

    // Check each rule against facts
    for (int i = 0; i < rules.size(); i++) {
        for (int j = 0; j < facts.size(); j++) {
            if (facts[j].find(rules[i].condition) != string::npos) {
                cout << "\nRule Applied: " << rules[i].description << endl;
                cout << "  IF: " << rules[i].condition << endl;
                cout << "  THEN: " << rules[i].consequence << endl;
                conclusions.push_back(rules[i].consequence);
            }
        }
    }

    return conclusions;
}

void LogicEngine::displayRules() const {
    cout << "\n=== Logical Rules ===" << endl;
    for (int i = 0; i < rules.size(); i++) {
        cout << (i + 1) << ". " << rules[i].description << endl;
        cout << "   IF: " << rules[i].condition << endl;
        cout << "   THEN: " << rules[i].consequence << endl;
    }
}

bool LogicEngine::checkRule(string condition, string consequence,
    string fact1, string fact2) {
    cout << "\n=== Checking Rule ===" << endl;
    cout << "IF: " << condition << endl;
    cout << "THEN: " << consequence << endl;
    cout << "Fact 1: " << fact1 << endl;
    cout << "Fact 2: " << fact2 << endl;

    if (fact1.find(condition) != string::npos &&
        fact2.find(consequence) != string::npos) {
        cout << "Rule is SATISFIED" << endl;
        return true;
    }
    else {
        cout << "Rule is NOT SATISFIED" << endl;
        return false;
    }
}