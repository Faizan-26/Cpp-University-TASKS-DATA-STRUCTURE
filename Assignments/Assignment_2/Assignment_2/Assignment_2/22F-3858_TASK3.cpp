//#include<iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node() {
//		data = 0;
//		next = NULL;
//	}
//	Node(int data) {
//		this->data = data;
//		next = NULL;
//	}
//};
//class Stack {
//	Node* top;
//public:
//	Stack() {
//		top = NULL;
//	}
//	bool isEmpty() {
//		return top == NULL;
//	}
//	bool push(int data) {
//		Node* newNode = new Node(data);
//		newNode->next = top;
//		top = newNode;
//		return true;
//	}
//	bool pop(int& tempData) {
//		if (isEmpty()) {
//			return false;
//		}
//		Node* tempNode = top;
//		tempData = tempNode->data;
//		top = tempNode->next;
//		delete tempNode;
//	}
//	void displayStack() {
//		Node* cur = top;
//
//		cout << endl;
//		while (cur != NULL) {
//			cout << cur->data << "   ";
//			cur = cur->next;
//		}
//		cout << endl;
//	}
//	~Stack() {
//		int n;
//		while (top != NULL) {
//			pop(n);
//		}
//		delete top;
//	}
//};
//class queueStack {
//	Stack S1, S2; 
//	int numItems;
//public:
//	queueStack() {
//		numItems = 0;
//	}
//	bool isEmpty() {
//		return numItems == 0;
//	}
//	void enqueue(int value) {
//		S1.push(value);
//		numItems++;
//	}
//	int dequeue(){
//		int value =0 ;
//		while (!S1.isEmpty()) {
//			S1.pop(value);
//			S2.push(value); // store data of S1 to S2 the stack will become inverted
//		}
//		S2.pop(value);
//		numItems--;
//		return value;
//	}
//	~queueStack() {
//		while (!isEmpty()) {
//			dequeue();
//		}
//	}
//};
//int main() {
//	queueStack Q1;
//	Q1.enqueue(178);
//	Q1.enqueue(-43);
//	Q1.enqueue(953);
//	cout << Q1.dequeue();
//	return 0;
//}