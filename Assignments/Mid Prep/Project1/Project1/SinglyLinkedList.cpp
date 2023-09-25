//#include<iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node() {
//		data = 0;
//		next = NULL;
//	}
//	Node(int Data) {
//		data = Data;
//		next = NULL;
//	}
//};
//class SingleLinkedListAdt {
//	Node* head;
//public:
//	SingleLinkedListAdt() {
//		head = NULL;
//	}
//	bool isEmpty() {
//		return head == NULL;
//	}
//	void insertAtBegin(int data) {
//		Node* temp = new Node(data);
//		if (isEmpty()) {
//			head = temp;
//			cout << "\nNode was empty\n";
//			return;
//		}
//		cout << "\nNode was not empty\n";
//		temp->next = head;
//		head = temp;
//	}
//	void insertAtEnd(int data) {
//		Node* cur = head;
//		while (cur->next != NULL) {
//			cur = cur->next;
//		}
//		Node* newNode = new Node(data);
//		cur->next = newNode;
//	}
//	void displaySinglyLinkedList() {
//		Node* cur = head;
//		cout << endl;
//		while (cur != NULL) {
//			cout << cur->data << "    ";
//			cur = cur->next;
//		}
//	}
//	void insertAtMiddle(int data, int index) {
//		Node* cur = head;
//		bool found = false;
//		while (cur != NULL) {
//			if (cur->data == index) {
//				found = true;
//				break;
//			}
//			cur = cur->next;
//		}
//		if (found) {
//			Node* newNode = new Node(data);
//			newNode->next = cur->next;
//			cur->next = newNode;
//			return;
//		}
//		else {
//			cout << "\nInvalid index value\n";
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
//			delete deletedNode;
//		}
//		else {
//			cout << "\n Cannot found given data in Linked List\n";
//		}
//	}
//	void reverseList() {
//		Node* cur = head;
//		Node* successer = NULL, * predecessor = NULL;
//		while (cur != NULL) {
//			successer = cur->next;
//			cur->next = predecessor;
//			predecessor = cur;
//			cur = successer;
//		}
//		head = predecessor;
//	}
//};
//int main() {
//	SingleLinkedListAdt S;
//	S.insertAtBegin(1);
//	S.insertAtEnd(2);
//	S.insertAtEnd(3);
//	S.insertAtEnd(4);
//	S.deletefromMiddle(1);
//	S.displaySinglyLinkedList();
//	S.reverseList();
//	S.displaySinglyLinkedList();
//	return 0;
//}
