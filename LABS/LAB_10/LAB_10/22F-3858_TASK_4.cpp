//#include<iostream>
//using namespace std;
//
//class Binary_heap {
//	int* arr;
//	int size;
//	int totalItems;
//
//public:
//	Binary_heap(int size) {
//		this->size = size;
//		totalItems = 0;
//		arr = new int[size];
//	}
//
//	int getMini() {
//		return arr[1];
//	}
//
//	void insert_max_heap(int number) {
//		if (totalItems == size - 1) {
//			cout << "Heap is full.\n";
//			return;
//		}
//		else {
//			++totalItems;
//			arr[totalItems] = number;
//			percolate_up_max(totalItems);
//		}
//	}
//
//	void percolate_up_max(int index) {
//		while (index > 1 && arr[index / 2] < arr[index]) {
//			swap(arr[index / 2], arr[index]);
//			index = index / 2;
//		}
//	}
//
//	void percolate_down_max(int index) {
//		int largerValue = index;
//		while (1) {
//			if (index * 2 <= totalItems && arr[index * 2] >= arr[largerValue]) {
//				largerValue = index * 2;
//			}
//			if (index * 2 + 1 <= totalItems && arr[index * 2 + 1] >= arr[largerValue]) {
//				largerValue = index * 2 + 1;
//			}
//			if (largerValue == index) {
//				break;
//			}
//			swap(arr[largerValue], arr[index]);
//			index = largerValue;
//		}
//	}
//
//	void extractMax(int& deletedNum) {
//		cout << arr[1] << " deleted.\n";
//		deletedNum = arr[1];
//		arr[1] = arr[totalItems];
//		totalItems--;
//		percolate_down_max(1);
//	}
//};
//
//int main() {
//	Binary_heap heapmax(100);
//	int arr[10] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
//	for (int i = 0; i < 10; i++) {
//		heapmax.insert_max_heap(arr[i]);
//	}
//	int deletedNum = 0;
//	for (int i = 0; i < 10; i++) {
//		heapmax.extractMax(deletedNum);
//		arr[i] = deletedNum;
//	}
//
//	cout << "RESULT ARRAY : \n";
//	for (int i = 0; i < 10; i++) {
//		cout << arr[i] << "  ";
//	}
//
//	return 0;
//}
