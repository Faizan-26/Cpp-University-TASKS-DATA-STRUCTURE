//#include<iostream>
//using namespace std;
//
//class arrQueueAdt {
//	int* array;
//	int size = 0;
//	int rear;
//	int front;
//	int numItems;
//public:
//	arrQueueAdt() {
//		int size =numItems= 0;
//		array = NULL;
//		rear = front = -1;
//	}
//	arrQueueAdt(int S) {
//		int size = S;
//		numItems = 0;
//		array = new int [size];
//		for (int i = 0; i < size; i++)
//		{
//			array[i] = -1;
//		}
//		rear = front = -1;
//	}
//
//	bool isEmpty() {
//		return numItems == 0;
//	}
//
//	bool isFull() {
//		return numItems == size - 1;
//	}
//
//	bool enqueue(int data) {
//		if (isFull()) {
//			cout << "\nMax capacity reached.\n";
//			return false;
//		}
//		if (isEmpty()) {
//			front = rear = 0;
//			array[rear] = data;
//		}
//		else {
//			rear = (rear + 1) % size;
//			array[rear] = data;
//		}
//		numItems++;
//		return true;
//	}
//
//	bool dequeue() {
//		if (isEmpty()) {
//			cout << "\nQueue is Empty.\n";
//			return false;
//		}
//		front = (front+1)%size;
//		numItems--;
//		return true;
//	}
//};
//
//int main() {
//		arrQueueAdt q(5);
//	q.enqueue(1);
//	q.enqueue(2);
//	q.enqueue(3);
//	q.enqueue(4);
//	q.enqueue(5);
//	q.dequeue();
//
//	return 0;
//}