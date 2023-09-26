//#include<iostream>
//using namespace std;
//class IntStack {
//	int* stackArray;
//	int size;
//	int top;
//public:
//	IntStack() {
//		stackArray = NULL;
//		size = 0;
//		top = -1;
//
//	}
//	IntStack(int Size) {
//		size = Size;
//		stackArray = new int [size];
//		top = -1;
//	}
//	bool isEmpty() {
//		return top == -1;
//	}
//	bool isFull() {
//		return top == size - 1;
//	}
//	bool push(int x) {
//		if (isFull()) {
//			return false;
//		}
//		top++;
//		stackArray[top] = x;
//		return true;
//	}
//	int pull() {
//		if (isEmpty()) {
//			return;
//		}
//		int x;
//		x = stackArray[top];
//		top--;
//		return x;
//	}
//	~IntStack() {
//		delete[] stackArray;
//	}
//};
//int main() {
//	IntStack s(5);
//	return 0;
//}