#include <iostream>
#include <string>
using namespace std;

class Lab {
    string labName;
    int capacity;
public:
    string getLabName() {
        return labName; 
    }
    int getCapacity() {
        return capacity; 
    }
    void setLabName(string Lname) {
        labName = Lname;
    }
    void setCapacity(int Cap) {
        capacity = Cap;
    }
};

class LecturerRoom {
    string roomName;
    int capacity;
public:
    string getRoomName() {
        return roomName; 
    }
    int getCapacity() { 
        return capacity; 
    }
    void setRoomName(string Rname) {
        roomName = Rname; 
    }
    void setCapacity(int Cap) { 
        capacity= Cap; 
    }
};

class N2Building {
    Lab lab[4];
    LecturerRoom room[4];
public:
    N2Building() {
        string tempName;
        int tempCap;
        for (int i = 0; i < 4; i++)
        {
            cout << "\nEnter lab name :";
            cin >> tempName;
            cout << "\nEnter lab capacity :";
            cin >> tempCap;
            lab[i].setLabName(tempName);
            lab[i].setCapacity(tempCap);
        }
        for (int i = 0; i < 4; i++)
        {
            cout << "\nEnter Lecturer's name :";
            cin >> tempName;
            cout << "\nEnter lab capacity :";
            cin >> tempCap;
            room[i].setRoomName(tempName);
            room[i].setCapacity(tempCap);
        }
    }
    void showAllLecturerRoom() {
        for (int i = 0; i < 4; i++)
        {
        cout << "Lecturer Room: " << room[i].getRoomName() << " Capacity: " << room[i].getCapacity() << endl;
        }
    } void showAllLabs() {
        for (int i = 0; i < 4; i++)
        {
            cout << "Lab: " << lab[i].getLabName() << " Capacity: " << lab[i].getCapacity() << endl;
        }
}
};

int main() {
    N2Building building;
    building.showAllLecturerRoom();
    building.showAllLabs();
    return 0;
}


