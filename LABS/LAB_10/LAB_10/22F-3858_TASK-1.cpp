//#include<iostream>
//using namespace std;
//class Binary_heap {
//	int* arr;
//	int size;
//	int totalItems;
//public:
//	Binary_heap(int size) {
//		this->size = size;
//		totalItems = 0;
//		arr = new int[size];
//	}
//    int getMini(){
//        return arr[1];
//    }
//
//	void insert_min_heap(int number){
//       if(totalItems == size-1){
//        cout<<"Heap is full.\n";
//        return;
//       }
//        else{
//           ++totalItems;
//            arr[totalItems] = number;
//            perculate_up(totalItems);
//        }
//    }
//
//    void perculate_up(int index){ // for min heap
//        while(index > 1 && arr[index/2]  >= arr[index]){
//            swap(arr[index / 2], arr[index]);
//            index = index/2;
//        }
//    }
//    void perculate_down(int index){
//        int smallerValue = index;
//        while(1){
//            if(index*2 < size && arr[index*2] < arr[smallerValue]){
//                smallerValue = index * 2;
//            }
//            if(index*2 +1 < size && arr[index*2+1] < arr[smallerValue]){
//                smallerValue = index*2 + 1;
//            }
//            if (smallerValue == index){
//                break;
//            }
//            swap(arr[smallerValue], arr[index]);
//            index= smallerValue;
//        }
//    }
//
//    void extractMin(){
//        cout << endl;
//        cout << arr[1] << " deleted.\n";
//        arr[1] = arr[totalItems--];
//        perculate_down(1);
//    }
//};
//int main() {
//    Binary_heap binary(100);
//    binary.insert_min_heap(4);
//    binary.insert_min_heap(1);
//    binary.insert_min_heap(8);
//    binary.insert_min_heap(12);
//    cout<<"GET MINI :"<<binary.getMini();
//    binary.extractMin();
//    cout << "GET MINI :" << binary.getMini();
//	return 0;
//}