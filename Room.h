#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

class Room {
private:
    string roomNumber;
    string roomType;
    int capacity;
    string assignedCourse;  // ADD THIS LINE
    bool isOccupied;        // ADD THIS LINE

public:
    Room();
    Room(string number, string type, int cap);

    // Getters
    string getRoomNumber() const;
    string getRoomType() const;
    int getCapacity() const;
    string getAssignedCourse() const;  // ADD THIS LINE
    bool getIsOccupied() const;        // ADD THIS LINE

    // ADD THESE FUNCTIONS
    void assignToCourse(string courseCode);
    void freeRoom();

    // Display
    void display() const;
};

#endif