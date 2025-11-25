# UNIDISC Engine - University Discrete Structures Management System 🎓🔢

![UNIDISC](https://img.shields.io/badge/UNIDISC_C%2B%2B-blue.svg)
![Discrete Math](https://img.shields.io/badge/Discrete_Mathematics-green.svg)
![OOP](https://img.shields.io/badge/OOP-C%2B%2B-orange.svg)

## Link

[📺 Watch Demo Video (Google Drive)](https://drive.google.com/file/d/1g7qZ493UMqtelMdXyxtrZkLzdv_9lwWZ/view?usp=sharing) <!-- Replace with actual link -->

## Table of Contents

* [Description](#description)
* [Features](#features)
* [Installation](#installation)
* [File Structure](#file-structure)
* [Usage](#usage)
* [Modules Overview](#modules-overview)
* [Testing](#testing)
* [Sample Input Guide](#sample-input-guide)
* [Development](#development)

---

## Description

**UNIDISC Engine** is a comprehensive C++ application that implements discrete mathematics concepts for university course management. Built as a project for FAST NUCES University, it demonstrates practical applications of discrete structures including sets, relations, functions, logic, induction, and combinatorics in a real-world educational management system.

✨ Highlights:
* Interactive CLI-based university management system
* 11+ discrete mathematics modules with practical implementations
* Course prerequisite verification using mathematical induction
* Automated consistency checking across all entities
* Complete validation system with error handling
* Save/Load functionality (optional extension)

---

## Features

### Core Management Systems

- **Course Management**: Add courses, define prerequisites, view course chains
- **Student Management**: Enroll students, track completed courses, manage enrollments
- **Faculty Management**: Assign faculty to courses, track teaching assignments
- **Room Management**: Allocate rooms to courses with occupation tracking

### Discrete Mathematics Implementations

#### 1. Set Operations Module 📊
- Union, intersection, difference operations
- Subset and superset verification
- Power set generation (2^n subsets)
- Practical application: Find students in multiple courses

#### 2. Induction & Prerequisites Module 🔗
- Mathematical induction for prerequisite verification
- Strong induction for multi-level prerequisite chains
- Recursive verification algorithm
- Base case and inductive step validation

#### 3. Logic & Inference Engine 🧠
- Propositional logic rule system
- IF-THEN conditional rules
- Forward chaining inference
- Automatic conclusion derivation

#### 4. Relations Module 🔄
- Binary relation validation (Student-Course, Faculty-Course, Course-Room)
- Reflexive property checking
- Symmetric property verification
- Transitive property validation
- Equivalence relation detection

#### 5. Functions Module 📈
- Function mapping (Student→Course, Course→Faculty, Faculty→Room)
- Injective (one-to-one) verification
- Surjective (onto) validation
- Bijective function checking
- Function composition support

#### 6. Combinations Module 🎲
- Project group assignments using C(n,r)
- Lab session distribution
- Elective course assignment
- Combination and permutation calculations
- All possible combinations generation

#### 7. Consistency Checker Module ✅
- System-wide validation
- Prerequisite enforcement
- Credit overload detection
- Faculty assignment verification
- Room allocation consistency

### Advanced Features

* **Input Validation**: All inputs validated against existing records
* **Error Handling**: User-friendly error messages
* **Data Persistence**: Room occupation tracking
* **Modular Architecture**: Each module independently testable

---

## Installation

1. Clone or download the repository:

```bash
git clone https://github.com/yourusername/UNIDISC-Engine.git
```

2. Ensure all source files are in the same directory:
   - All `.cpp` and `.h` files
   - Main.cpp or TestingMain.cpp

3. Compile the interactive program:

```bash
g++ -o unidisc Main.cpp Course.cpp Student.cpp Faculty.cpp Room.cpp \
    SetOperations.cpp InductionModule.cpp LogicEngine.cpp \
    RelationsModule.cpp FunctionsModule.cpp CombinationModule.cpp \
    ConsistencyChecker.cpp
```

4. Or compile the automated testing version:

```bash
g++ -o test TestingMain.cpp Course.cpp Student.cpp Faculty.cpp Room.cpp \
    SetOperations.cpp InductionModule.cpp LogicEngine.cpp \
    RelationsModule.cpp FunctionsModule.cpp CombinationModule.cpp \
    ConsistencyChecker.cpp
```

5. Run the program:

```bash
./unidisc        # Interactive version
./test           # Automated testing version
```

> 📦 No external libraries needed. Only standard C++ headers are used.

---

## File Structure

```
Main.cpp                    # Interactive user interface
TestingMain.cpp             # Automated unit testing
Course.h / Course.cpp       # Course entity with prerequisites
Student.h / Student.cpp     # Student entity with enrollments
Faculty.h / Faculty.cpp     # Faculty entity with assignments
Room.h / Room.cpp           # Room entity with occupation tracking
SetOperations.h / .cpp      # Set theory operations
InductionModule.h / .cpp    # Mathematical induction verification
LogicEngine.h / .cpp        # Logic and inference system
RelationsModule.h / .cpp    # Binary relations and properties
FunctionsModule.h / .cpp    # Function mappings and properties
CombinationModule.h / .cpp  # Combinatorics and group assignments
ConsistencyChecker.h / .cpp # System-wide validation
README.md                   # This file
SampleInput.md              # Complete testing guide
```

---

## Usage

### Interactive Mode

Run `./unidisc` and navigate through menus:

1. **Course Management** → Add courses and prerequisites
2. **Student Management** → Add students and manage enrollments
3. **Faculty Management** → Assign faculty to courses
4. **Room Management** → Allocate rooms to courses
5. **Discrete Modules** → Test set operations, induction, logic, etc.

### Testing Mode

Run `./test` for automated demonstration:
- All modules tested with hardcoded data
- Shows step-by-step operations
- Validates all discrete structure implementations

---

## Modules Overview

### Module 1: Course & Scheduling 📚
**Discrete Concepts**: Partial orders, directed acyclic graphs (DAGs)
- Generate valid course sequences
- Handle prerequisite dependencies
- Verify course chains using induction

### Module 2: Student Group Combinations 👥
**Discrete Concepts**: Combinations C(n,r), permutations P(n,r)
- Assign students to project groups
- Distribute students across lab sessions
- Calculate possible elective combinations

### Module 3: Induction & Strong Induction 🔍
**Discrete Concepts**: Mathematical induction, recursive verification
- Base case: Course with no prerequisites
- Inductive step: If prerequisites satisfied, course can be taken
- Strong induction: Check all transitive prerequisites

### Module 4: Logic & Inference 💭
**Discrete Concepts**: Propositional logic, forward chaining
- Define IF-THEN rules
- Apply modus ponens
- Derive conclusions from facts

### Module 5: Set Operations 📐
**Discrete Concepts**: Set theory, power sets, Cartesian products
- Find students in multiple courses (intersection)
- Combine student sets (union)
- Check subset relationships
- Generate power sets P(A) = 2^|A|

### Module 6: Relations 🔗
**Discrete Concepts**: Binary relations, equivalence classes, partial orders
- Reflexive: ∀x, (x,x) ∈ R
- Symmetric: ∀x,y, (x,y) ∈ R → (y,x) ∈ R
- Transitive: ∀x,y,z, (x,y) ∈ R ∧ (y,z) ∈ R → (x,z) ∈ R
- Equivalence: Reflexive ∧ Symmetric ∧ Transitive

### Module 7: Functions 📊
**Discrete Concepts**: Injective, surjective, bijective functions
- Injective: f(a) = f(b) → a = b
- Surjective: ∀y ∈ B, ∃x ∈ A, f(x) = y
- Bijective: Injective ∧ Surjective
- Function composition: (f ∘ g)(x) = f(g(x))

### Module 8: Automated Proof & Verification ✓
**Discrete Concepts**: Proof techniques, formal verification
- Step-by-step prerequisite proofs
- Induction-based verification
- Logic rule validation

### Module 9: Consistency Checker 🛡️
**Discrete Concepts**: Constraint satisfaction, graph coloring
- Detect conflicts using set intersections
- Verify prerequisites using graph traversal
- Check student overload using sum constraints

### Module 10: Algorithmic Efficiency ⚡
**Discrete Concepts**: Recursion, dynamic programming
- Memoization for prerequisite checks
- Efficient set operations
- Optimized relation composition

---

## Testing

### Quick Test (5 minutes)

```bash
# Compile and run test
g++ -o test TestingMain.cpp *.cpp
./test
```

Expected output:
- ✓ Course added: CS101 - Programming (3 credits)
- ✓ Student added: S001 - Ali Ahmed
- ✓ Prerequisite added: CS201 requires CS101
- ✓ All 11 modules tested successfully

### Manual Testing

See `SampleInput.md` for complete step-by-step guide with:
- Sample data for all entities
- Test cases for each module
- Expected outputs
- Pass/fail scenarios

---

## Sample Input Guide

### Quick Setup (3 Courses, 3 Students)

```
# Add Courses
CS101 → Programming → 3 credits
CS201 → Data Structures → 3 credits (requires CS101)
CS301 → Algorithms → 4 credits (requires CS201)

# Add Students
S001 → Ali (completed CS101, CS201)
S002 → Sara (completed CS101)
S003 → Ahmed (no courses completed)

# Test Induction
S001 → CS301 ✓ (has all prerequisites)
S002 → CS301 ✗ (missing CS201)
```

For complete testing guide, see [SampleInput.md](SampleInput.md)

---

## Key Algorithms

### Prerequisite Verification (Strong Induction)

```cpp
bool verifyPrerequisites(course, student, depth) {
    // Base case
    if (course has no prerequisites)
        return true;
    
    // Inductive step
    for each prerequisite:
        if (student hasn't completed prerequisite)
            return false;
        
        // Strong induction: recursively check prerequisites
        if (!verifyPrerequisites(prerequisite, student, depth+1))
            return false;
    
    return true;
}
```

### Power Set Generation (Bit Manipulation)

```cpp
PowerSet(S) {
    n = |S|
    P = {}
    
    for i = 0 to 2^n - 1:
        subset = {}
        for j = 0 to n-1:
            if (i & (1 << j)):
                subset.add(S[j])
        P.add(subset)
    
    return P
}
```

### Function Property Checking

```cpp
isInjective(f) {
    for each pair (a,b) where a ≠ b:
        if (f(a) == f(b))
            return false
    return true
}

isSurjective(f, codomain) {
    for each y in codomain:
        if (no x exists where f(x) = y)
            return false
    return true
}
```

---

## Development

### Built With:

* **Language**: C++ (C++11 or higher)
* **Paradigm**: Object-Oriented Programming
* **Data Structures**: Vectors, custom classes
* **Design Pattern**: Modular architecture with separation of concerns

### Architecture Principles:

1. **Encapsulation**: Each entity (Course, Student, Faculty) is self-contained
2. **Modularity**: Each discrete structure module is independent
3. **Validation**: Input validation at every step
4. **Extensibility**: Easy to add new modules or features

### Future Enhancements:

- [ ] Graph visualization of prerequisite chains
- [ ] Web-based UI using C++ backend
- [ ] Database integration for persistence
- [ ] Multi-semester planning
- [ ] AI-based course recommendation
- [ ] Conflict resolution algorithms
- [ ] Performance optimization for large datasets

---

## Academic Context

**Course**: Discrete Structures (CS-212)  
**Institution**: FAST NUCES University  
**Semester**: Fall 2024  
**Concepts Covered**:
- Set Theory & Operations
- Relations & Functions
- Mathematical Induction
- Propositional Logic
- Combinatorics
- Graph Theory (Prerequisites as DAG)
- Proof Techniques

---

## Examples & Demonstrations

### Example 1: Set Operations
```
Students in CS201 = {S001, S002, S003}
Students in CS301 = {S001, S004}

Union = {S001, S002, S003, S004}
Intersection = {S001}
Difference (CS201 - CS301) = {S002, S003}
```

### Example 2: Induction Proof
```
Prove: S001 can take CS301

Base case: CS101 has no prerequisites ✓

Inductive step:
  CS301 requires CS201 ✓ (S001 completed)
  CS201 requires CS101 ✓ (S001 completed)

Conclusion: S001 can take CS301 ✓
```

### Example 3: Equivalence Relation
```
Relation: "enrolled in same course"
R = {(S001,S001), (S001,S002), (S002,S001), (S002,S002)}

Reflexive: ✓ (everyone related to themselves)
Symmetric: ✓ (if a~b then b~a)
Transitive: ✓ (if a~b and b~c then a~c)

Result: Equivalence relation ✓
```

---

## Contributing

🛠️ **This project is open to collaboration!**

Ways to contribute:
- Add new discrete structure modules
- Improve algorithm efficiency
- Add visualization features
- Enhance error handling
- Write additional test cases
- Improve documentation

Fork it, make improvements, and submit a pull request!

---

## License

This project is open source and available for educational purposes.

---

## Contact

**Developer**: Muhammad Arslan, Muhammad Dawood, Mian Dawood  
**University**: FAST NUCES  
**Email**: [arslanumar0326@gmail.com]  
**GitHub**: [arslan0umar](https://github.com/arslan0umar)

---

## Acknowledgments

- FAST NUCES University for project requirements
- Discrete Structures course instructors
- Open source community for inspiration

---

**⭐ If you find this project helpful, please give it a star!**

---


*Built with 💻 and discrete mathematics 🔢*
