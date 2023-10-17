//#include<iostream>
//using namespace std;
//class deque {
//	int* dequeArr;
//	int maxSize, rear, front;
//	int numItems;
//public:
//	deque(int size) {
//		maxSize = size;
//		dequeArr = new int[maxSize];
//		rear = front = -1;
//		numItems = 0;
//		for (int i = 0; i < maxSize; i++) {
//			dequeArr[i] = 0;
//		}
//	}
//	bool isEmpty() {
//		return numItems == 0;
//	}
//	bool isFull() {
//		return numItems == maxSize - 1;
//	}
//	void insertFront(int value) {
//		if (!isFull()) {
//			if (isEmpty()) { // for insert at first time
//				rear = (rear + 1) % maxSize;
//				front = (front + 1) % maxSize;
//				dequeArr[rear] = value;
//			}
//			else if (rear <= front) {
//				if (rear <= 0) rear = maxSize - 1;
//				else rear--;
//				dequeArr[rear] = value;
//			}
//			else {
//				if (front <= 0) front = maxSize - 1;
//				else front--;
//				dequeArr[front] = value;
//			}
//			numItems++;
//		}
//		else {
//			cout << "\nQueue is full.\n";
//		}
//	}
//	void insertBack(int value) {
//		if (!isFull()) {
//			if (isEmpty()) { // for insert at first time
//				rear = (rear + 1) % maxSize;
//				front= (front + 1) % maxSize;
//					dequeArr[rear] = value;
//			}
//			else if (rear >= front) {
//				rear = (rear + 1) % maxSize;
//				dequeArr[rear] = value;
//			}
//			else {
//				front = (front + 1) % maxSize;
//				dequeArr[front] = value;
//			}
//			numItems++;
//		}
//		else {
//			cout << "\nQueue is full.\n";
//		}
//	}
//	void removeFront() {
//		if (!isEmpty()) {
//			dequeArr[front] = 0;
//			if (numItems == 1) {
//				front = -1;
//				rear = -1;
//			}
//			else
//			front = (front + 1) % maxSize;
//		}
//		else {
//			cout << "\nQueue is empty.\n";
//		}
//		numItems--;
//	}
//	void removeBack() {
//		if (!isEmpty()) {
//			dequeArr[rear] = 0;
//			if (numItems == 1) {
//				rear = -1;
//				front = -1;
//			}
//			else
//			rear = (rear - 1) % maxSize;
//		}
//		else {
//			cout << "\nQueue is empty.\n";
//		}
//		numItems--;
//	}
//	void displayQueue() {
//		cout << "\nFront :" << front << "| Rear :" << rear << endl;
//		for (int i = 0; i < maxSize; i++)
//		{
//			cout << dequeArr[i]<<"  ";
//		}
//		cout << endl;
//	}
//	~deque() {
//		delete[] dequeArr;
//		maxSize = -1;
//		rear = -1;
//		front = -1;
//	}
//};
//int main() {
//	deque Q(10);
//	Q.insertBack(3);
//	Q.displayQueue();
//	Q.insertBack(14);
//	Q.displayQueue();
//	Q.insertFront(90);
//	Q.displayQueue();
//	Q.removeFront();
//	Q.displayQueue();
//	Q.removeBack();
//	Q.displayQueue();
//	Q.removeFront();
//	Q.displayQueue();
//	return 0;
//}