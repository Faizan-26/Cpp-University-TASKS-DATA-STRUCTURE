//#include<iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node* prev;
//	Node() {
//		data = 0;
//		next = NULL;
//		prev = NULL;
//	}
//	Node(int D) {
//		data = D;
//		next = NULL;
//		prev = NULL;
//	}
//};
//class Doubly {
//	Node* head;
//public:
//	Doubly() {
//		head = NULL;
//	}
//	bool isEmpty() {
//		return head == NULL;
//	}
//	void InsertAtBegin(int data) {
//		Node* newNode = new Node(data);
//		if (isEmpty()) {
//			head = newNode;
//			return;
//		}
//		newNode->next = head;
//
//		head = newNode;
//	}
//	void displayDoubly() {
//		Node* cur = head;
//		while (cur != NULL) {
//			cout << cur->data << "   ";
//			cur = cur->next;
//		}
//	}
//	void InsertAtLast(int data) {
//		if (isEmpty()) {
//			InsertAtBegin(data);
//			return;
//		}
//		Node* cur = head;
//		while (cur->next != NULL) {
//			cur = cur->next;
//		}
//		Node* newNode = new Node(data);
//		newNode->prev = cur;
//		cur->next = newNode;
//	}
//	void InsertAtMiddle(int data, int index) {
//		if (isEmpty()) {
//			InsertAtBegin(data);
//			return;
//		}
//		Node* cur = head;
//		bool found = false;
//		while (cur != NULL ) {
//			if (cur->data == index) {
//				found = true;
//				break;
//			}
//			cur = cur->next;
//		}
//		if (found) {
//			Node* newNode = new Node(data);
//			newNode->next = cur->next;
//			newNode->prev = cur;
//			cur->next->prev = newNode;
//			cur->next = newNode;
//		}
//		else {
//			cout << "\nInvalid Index\n";
//		}
//	}
//	void deletefromMiddle(int data) {
//		Node* cur = head;
//		bool found = false;
//		while (cur != NULL) {
//			if (cur->data == data) {
//				found = true;
//				break;
//			}
//			cur = cur->next;
//		}
//		if (found) {
//			Node* deletedNode = cur->next;
//			cur->next = cur->next->next;
//			cur->next->next->prev = cur;
//			delete deletedNode;
//		}
//		else {
//			cout << "\n Cannot found given data in Linked List\n";
//		}
//	}
//};
//int main() {
//	Doubly D;
//	D.InsertAtBegin(1);
//
//	D.InsertAtBegin(2);
//	D.InsertAtBegin(3);
//	D.InsertAtMiddle(4, 2);
//	D.InsertAtLast(5);
//	D.deletefromMiddle(2);
//	//D.InsertAtBegin(2);
//	D.displayDoubly();
//	return 0;
//}