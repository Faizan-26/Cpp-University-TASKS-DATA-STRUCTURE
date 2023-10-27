//#include<iostream>
//using namespace std;
//struct Building {
//    int id;
//    int floors;
//    Building() {
//        id = 0;
//        floors = 0;
//    }
//};
//class Binary_heap {
//    Building* arrayOfBuildings;
//    int size;
//    int totalBuilding;
//public:
//    Binary_heap(int size) {
//        this->size = size;
//        totalBuilding = 0;
//        arrayOfBuildings = new Building[size];
//    }
//    int getHighestPriorityBuilding() { // returns building with heighes priority
//        return arrayOfBuildings[1].id;
//    }
//
//    void insert_min_heap(int floor, int id) {
//        if (totalBuilding == size - 1) {
//            cout << "Heap is full.\n";
//            return;
//        }
//        else {
//            ++totalBuilding;
//            arrayOfBuildings[totalBuilding].floors = floor;
//            arrayOfBuildings[totalBuilding].id= id;
//            perculate_up(totalBuilding);
//        }
//    }
//
//    void perculate_up(int index) { // 
//        while (index > 1 && arrayOfBuildings[index / 2].floors <= arrayOfBuildings[index].floors) {
//            swap(arrayOfBuildings[index / 2].floors, arrayOfBuildings[index].floors);
//            swap(arrayOfBuildings[index / 2].id, arrayOfBuildings[index].id);
//            index = index / 2;
//        }
//    }
//    void perculate_down(int index) {
//        int smallerValue = index;
//        while (1) {
//            if (index * 2 < size && arrayOfBuildings[index * 2].floors > arrayOfBuildings[smallerValue].floors) {
//                smallerValue = index * 2;
//            }
//            if (index * 2 + 1 < size && arrayOfBuildings[index * 2 + 1].floors > arrayOfBuildings[smallerValue].floors) {
//                smallerValue = index * 2 + 1;
//            }
//            if (smallerValue == index) {
//                break;
//            }
//            swap(arrayOfBuildings[smallerValue].floors, arrayOfBuildings[index].floors);
//            swap(arrayOfBuildings[smallerValue].id, arrayOfBuildings[index].id);
//            index = smallerValue;
//        }
//    }
//
//    void constructBuilding() {
//        cout << endl;
//        cout << arrayOfBuildings[1].id << " deleted having \"" << arrayOfBuildings[1].floors<<"\" floors";
//        arrayOfBuildings[1] = arrayOfBuildings[totalBuilding--];
//        perculate_down(1);
//    }
//};
//int main() {
//    Binary_heap binary(100);
//    binary.insert_min_heap(20,1);
//    binary.insert_min_heap(45, 2);
//    cout << "\nGET MINI :" << binary.getHighestPriorityBuilding();
//    binary.insert_min_heap(5,3);
//    cout << "\nGET MINI :" << binary.getHighestPriorityBuilding();
//    binary.constructBuilding();
//    cout << "\nGET MINI :" << binary.getHighestPriorityBuilding();
//    binary.constructBuilding();
//    binary.constructBuilding();
//    return 0;
//}