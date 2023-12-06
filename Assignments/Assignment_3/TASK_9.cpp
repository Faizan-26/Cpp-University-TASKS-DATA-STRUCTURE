#include<iostream>
using namespace std;
struct Building {
    string name;
    int condition;
    Building() {
        name = "";
        condition = 0;
    }
    Building(string Name, int c) {
        name = Name;
        condition = c;
    }
};
class Binary_heap {
    Building* arrayOfpatients;
    int size;
    int totalPatients;
public:
    Binary_heap(int size) {
        this->size = size;
        totalPatients = 0;
        arrayOfpatients = new Building[size];
    }
    string getHighestPriorityBuilding() { // returns building with heighes priority
        return arrayOfpatients[1].name;
    }

    void insert_min_heap(int condition, string name) {
        if (totalPatients == size - 1) {
            cout << "Heap is full.\n";
            return;
        }
        else {
            ++totalPatients;
            arrayOfpatients[totalPatients].condition = condition;
            arrayOfpatients[totalPatients].name= name;
            perculate_up(totalPatients);
        }
    }

    void perculate_up(int index) { // 
        while (index > 1 && arrayOfpatients[index / 2].condition <= arrayOfpatients[index].condition) {
            swap(arrayOfpatients[index / 2].condition, arrayOfpatients[index].condition);
            swap(arrayOfpatients[index / 2].name, arrayOfpatients[index].name);
            index = index / 2;
        }
    }
    void perculate_down(int index) {
        int smallerValue = index;
        while (1) {
            if (index * 2 < size && arrayOfpatients[index * 2].condition > arrayOfpatients[smallerValue].condition) {
                smallerValue = index * 2;
            }
            if (index * 2 + 1 < size && arrayOfpatients[index * 2 + 1].condition > arrayOfpatients[smallerValue].condition) {
                smallerValue = index * 2 + 1;
            }
            if (smallerValue == index) {
                break;
            }
            swap(arrayOfpatients[smallerValue].condition, arrayOfpatients[index].condition);
            swap(arrayOfpatients[smallerValue].name, arrayOfpatients[index].name);
            index = smallerValue;
        }
    }

    void allotbed() {
        cout << endl;
        cout << arrayOfpatients[1].name << " alloted bed having \"" << arrayOfpatients[1].condition<<"\" condition";
        arrayOfpatients[1] = arrayOfpatients[totalPatients--];
        perculate_down(1);
    }
};
int main() {
    Binary_heap binary(100);
    binary.insert_min_heap(20,"Patient1");
    binary.insert_min_heap(45, "Patient2");
    cout << "\nGET High Priority :" << binary.getHighestPriorityBuilding();
    binary.insert_min_heap(5,"Patient3");
    cout << "\nGET High Priority :" << binary.getHighestPriorityBuilding();
    binary.allotbed();
    cout << "\nnGET High Priority:" << binary.getHighestPriorityBuilding();
    binary.allotbed();
    binary.allotbed();
    return 0;
}