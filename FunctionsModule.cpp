#include "FunctionsModule.h"
#include <iostream>
using namespace std;

FunctionsModule::FunctionsModule() {
    functionName = "Function";
}

FunctionsModule::FunctionsModule(string name) {
    functionName = name;
}

void FunctionsModule::addMapping(string domain, string codomain) {
    Mapping m;
    m.domain = domain;
    m.codomain = codomain;
    function.push_back(m);
}

vector<string> FunctionsModule::getDomain() {
    vector<string> domain;
    for (int i = 0; i < function.size(); i++) {
        bool found = false;
        for (int j = 0; j < domain.size(); j++) {
            if (domain[j] == function[i].domain) {
                found = true;
                break;
            }
        }
        if (!found) {
            domain.push_back(function[i].domain);
        }
    }
    return domain;
}

vector<string> FunctionsModule::getCodomain() {
    vector<string> codomain;
    for (int i = 0; i < function.size(); i++) {
        bool found = false;
        for (int j = 0; j < codomain.size(); j++) {
            if (codomain[j] == function[i].codomain) {
                found = true;
                break;
            }
        }
        if (!found) {
            codomain.push_back(function[i].codomain);
        }
    }
    return codomain;
}

bool FunctionsModule::isInjective() {
    // One-to-one: no two domain elements map to same codomain element
    for (int i = 0; i < function.size(); i++) {
        for (int j = i + 1; j < function.size(); j++) {
            if (function[i].codomain == function[j].codomain &&
                function[i].domain != function[j].domain) {
                return false;
            }
        }
    }
    return true;
}

bool FunctionsModule::isSurjective(vector<string> targetCodomain) {
    // Onto: every element in codomain has a preimage
    for (int i = 0; i < targetCodomain.size(); i++) {
        bool found = false;
        for (int j = 0; j < function.size(); j++) {
            if (function[j].codomain == targetCodomain[i]) {
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

bool FunctionsModule::isBijective(vector<string> targetCodomain) {
    return isInjective() && isSurjective(targetCodomain);
}

FunctionsModule FunctionsModule::compose(FunctionsModule& f1, FunctionsModule& f2) {
    FunctionsModule result("Composition");

    vector<Mapping> func1 = f1.getFunction();
    vector<Mapping> func2 = f2.getFunction();

    // Composition: if f1(a) = b and f2(b) = c, then result(a) = c
    for (int i = 0; i < func1.size(); i++) {
        for (int j = 0; j < func2.size(); j++) {
            if (func1[i].codomain == func2[j].domain) {
                result.addMapping(func1[i].domain, func2[j].codomain);
            }
        }
    }

    return result;
}

void FunctionsModule::display() const {
    cout << "\n=== " << functionName << " ===" << endl;
    for (int i = 0; i < function.size(); i++) {
        cout << "f(" << function[i].domain << ") = "
            << function[i].codomain << endl;
    }
}

vector<Mapping> FunctionsModule::getFunction() const {
    return function;
}