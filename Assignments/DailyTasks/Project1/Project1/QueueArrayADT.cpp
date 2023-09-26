//#include<iostream>
//using namespace std;
//class QueueArrayAdt {
//	int size;
//	int rear;
//	int front;
//	int numItems;
//	int* array;
//public:
//	QueueArrayAdt(int size) {
//		this->size = size;
//		front= -1;
//		rear = -1;
//		numItems = 0;
//		array = new int[size];
//	}
//	bool isEmpty() {
//		return numItems == 0;
//	}
//	bool isFull() {
//		return numItems == size - 1;
//	}
//	void enqueue(int data) {
//		if (isFull()) {
//			cout << "\n Queue is Full.\n";
//			return;
//		}
//		rear = (rear + 1) % size;
//		array[rear] = data;
//		numItems++;
//		cout << "\nData is added in array Adt.\n";
//	}
//	void dequeue() {
//		if (isEmpty()) {
//			cout << "\nQueue is Empty.\n";
//			return;
//		}
//		front = (front + 1) % size;
//		cout << array[front] << " removed from queue.\n";
//		numItems--;
//	}
//	~QueueArrayAdt() {
//		front = -1;
//		rear = -1;
//		numItems = 0;
//		delete[] array;
//	}
//};
//int main() {
//	QueueArrayAdt a(4);
//	a.enqueue(1);
//	a.enqueue(2);
//	a.enqueue(3);
//	a.enqueue(4);
//	a.dequeue();
//	a.dequeue();
//	a.dequeue();
//	return 0;
//}