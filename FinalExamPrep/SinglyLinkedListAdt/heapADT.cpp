//#include<iostream>
//using namespace std;
//
//class minHeap{
//    int* arr;
//    int size;
//    int totalItems;
//    public:
//    minHeap(){
//        arr = new  int [10]; // by default have size of 10
//        size = 10;
//        totalItems = 0;
//    }
//
//    minHeap(int S){
//        size = S;
//        arr = new int [size];
//        totalItems=0;
//    }
//
//    int getMin(){
//        return arr[1];
//    }
//
//    void perculateUp(int index){
//        while(index>1 && arr[index] >= arr[index/2]){
//            swap(arr[index], arr[index/2]);
//            index= index/2;
//        }
//    }
//
//    void perculateDown(int index){
//       int smallerChild = index;
//       while(true){
//        if(index*2 <size  && arr[index*2] <arr[index] ){
//            smallerChild= index*2;
//        }
//        if(index*2+1 <size && arr[index*2+1]< arr[index]){
//            smallerChild = index*2+1;
//        }
//        if(smallerChild == index){
//            break;
//        }
//        swap(arr[index], arr[smallerChild]);
//        index= smallerChild;
//       }
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
//int main(){
//    minHeap h(10);
//    h.insert(10);
//    h.insert(20);
//    h.insert(30);
//    h.insert(40);
//    h.insert(50);
//    h.insert(60);
//    h.insert(70);
//    h.insert(80);
//    h.insert(90);
//    h.insert(100);
//    h.display();
//    h.extractMin();
//    h.display();
//    h.extractMin();
//    h.display();
//    h.extractMin();
//    h.display();
//
//}
//
