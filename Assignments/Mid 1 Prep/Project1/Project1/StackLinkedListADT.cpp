// #include<iostream>
// using namespace std;
// struct Node {
// 	int data;
// 	Node* next;
// 	Node() {
// 		data = 0;
// 		next = NULL;
// 	}
// 	Node(int data) {
// 		this->data = data;
// 		next = NULL;
// 	}
// };
// class StackAdt {
// 	Node* top;
// public:
// 	StackAdt() {
// 		top = NULL;
// 	}
// 	bool isEmpty() {
// 		return top == NULL;
// 	}
// 	bool push(int data) {
// 		Node* newNode = new Node(data);
// 		newNode->next = top;
// 		top = newNode;
// 		return true;
// 	}
// 	bool pop(int &tempData) {
// 		if (isEmpty()) {
// 			return false;
// 		}
// 		Node* tempNode = top;
// 		tempData = tempNode->data;
// 		top = tempNode->next;
// 		delete tempNode;
// 	}
// 	void displayStack() {
// 		Node* cur = top;

// 		cout << endl;
// 		while (cur != NULL) {
// 			cout << cur->data << "   ";
// 			cur = cur->next;
// 		}
// 		cout << endl;
// 	}
// 	~StackAdt() {
// 		int n;
// 		while (top != NULL) {
// 			pop(n);
// 		}
// 		delete top;
// 	}
// };
// int main() {
// 	StackAdt s;
// 	s.push(1);
// 	s.push(2);
// 	s.push(3);
// 	s.displayStack();
// 	int x;
// 	s.pop(x);
// 	s.displayStack();
// 	return 0;
// }