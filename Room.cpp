#include "Room.h"
#include <iostream>
using namespace std;

Room::Room() {
    roomNumber = "";
    roomType = "";
    capacity = 0;
    assignedCourse = "";    
    isOccupied = false;     
}

Room::Room(string number, string type, int cap) {
    roomNumber = number;
    roomType = type;
    capacity = cap;
    assignedCourse = "";    
    isOccupied = false;     
}

string Room::getRoomNumber() const {
    return roomNumber;
}

string Room::getRoomType() const {
    return roomType;
}

int Room::getCapacity() const {
    return capacity;
}

string Room::getAssignedCourse() const {
    return assignedCourse;
}

bool Room::getIsOccupied() const {
    return isOccupied;
}

void Room::assignToCourse(string courseCode) {
    assignedCourse = courseCode;
    isOccupied = true;
}

void Room::freeRoom() {
    assignedCourse = "";
    isOccupied = false;
}

void Room::display() const {
    cout << "Room Number: " << roomNumber << endl;
    cout << "Room Type: " << roomType << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Status: " << (isOccupied ? "Occupied" : "Available") << endl;  
    if (isOccupied) {                                                       
        cout << "Assigned to: " << assignedCourse << endl;                  
    }                                                                       
}