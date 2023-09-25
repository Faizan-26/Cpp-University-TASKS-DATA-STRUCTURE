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
//class CircularSingleLinkedListAdt {
//	Node* head;
//public:
//	CircularSingleLinkedListAdt() {
//		head = NULL;
//	}
//	bool isEmpty() {
//		return head == NULL;
//	}
//	void insertAtBegin(int data) {
//		Node* temp = new Node(data);
//		if (isEmpty()) {
//			head = temp;
//			head->next = temp;
//			cout << "\nNode was empty\n";
//			return;
//		}
//		cout << "\nNode was not empty\n";
//		temp->next = head;
//		head = temp;
//	}
//	void insertAtEnd(int data) {
//		Node* cur = head;
//		while (cur->next != head) {
//			cur = cur->next;
//		}
//		Node* newNode = new Node(data);
//		newNode->next = head;
//		cur->next = newNode;
//	}
//	void displaySinglyLinkedList() {
//		Node* cur = head;
//		cout << endl;
//		do {
//			cout << cur->data << "    ";
//			cur = cur->next;
//		} while (cur != head);
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
//};
//int main() {
//	CircularSingleLinkedListAdt S;
//	S.insertAtBegin(1);
//	S.insertAtEnd(2);
//	S.insertAtEnd(3);
//	S.insertAtEnd(4);
//	S.deletefromMiddle(1);
//	S.displaySinglyLinkedList();
//	return 0;
//}