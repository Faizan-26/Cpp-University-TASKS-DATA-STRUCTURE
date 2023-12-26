//#include<iostream>
//using namespace std;
//
//class Heap{
//    int* arr;
//    int size;
//    int totalItems;
//    public:
//    Heap(){
//        arr = new  int [10]; // by default have size of 10
//        size = 10;
//        totalItems = 0;
//        for (int i = 0; i < 10; i++)
//        {
//            arr[i] = -1;
//        }
//    }
//
//    Heap(int S){
//        size = S;
//        arr = new int [size];
//        for (int i = 0; i < S; i++)
//        {
//            arr[i] = -1;
//        }
//        totalItems=0;
//    }
//
//    int getMin(){
//        return arr[1];
//    }
//
//    void perculateUp(int index) {
//        while (index > 1 && arr[index] < arr[index / 2] && arr[index / 2] != -1) {
//            swap(arr[index], arr[index / 2]);
//            index = index / 2;
//        }
//    }
//
//
//    void perculateDown(int index)
//    {
//        int smallerChild = index;
//        while (true)
//        {
//            if (index * 2 < size && arr[index * 2] < arr[index] && arr[index * 2] != -1) {
//                smallerChild = index * 2;
//            }
//            if (index * 2 + 1 < size && arr[index * 2 + 1] < arr[index] && arr[index * 2 + 1] != -1) {
//                smallerChild = index * 2 + 1;
//            }
//            if (smallerChild == index) {
//                break;
//            }
//            swap(arr[index], arr[smallerChild]);
//            index = smallerChild;
//        }
//    }
//    void insert(int data){
//        if(totalItems == size-1){
//            cout<<"Heap is full\n";
//            return;
//        }
//        else{
//            ++totalItems;
//            arr[totalItems]=data;
//            perculateUp(totalItems);
//        }
//    }
//
//    
//    void extractMin(){
//        cout<<arr[1]<<" deleted.\n";
//        arr[1] = arr[totalItems--]; // this 1st assign the last element to the root and then decrease the totalItems
//        perculateDown(1);
//    }
//    void display(){
//        for(int i=1; i<=totalItems; i++){
//            cout<<arr[i]<<" ";
//        }
//        cout<<endl;
//    }
//};
//
//int main(){
//    Heap h(10);
//    h.insert(1);
//    h.insert(2);
//    h.insert(3);
//    h.insert(4);
//    h.insert(5);
//    h.insert(6);
//    h.display();
//    h.extractMin();
//    h.display();
//
//}
