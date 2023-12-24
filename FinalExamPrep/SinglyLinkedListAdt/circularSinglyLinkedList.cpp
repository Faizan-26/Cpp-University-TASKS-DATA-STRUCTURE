//#include<iostream>
//using namespace std;
//
//// NODE STRUCTURE
//struct Node {
//	int data;// data part
//	Node* next;// pointer to next node in the linkedList
//
//	Node(int Data) { // overloaded constructor
//		data = Data;
//		next = NULL; // by default Node points to NULL
//	}
//	Node() { // default constructor
//		data = 0;
//		next = NULL;
//	}
//};
//
//
//// LINKED LIST CLASS
//class SinglyLinkedListCircular {
//	Node* head; // pointer to the first node in the linkedList
//
//public:
//	SinglyLinkedListCircular() {
//		head = NULL;
//	}
//
//
//	// INSERTION at START
//	void InsertAtStart(int data) {
//		Node* newNode = new Node(data); // creating a new node
//		if (isEmpty()) { // if linkedList is empty
//			head = newNode;// head points to the new node
//			head->next = head;
//		}
//		else { // if linkedList is not empty
//			Node* cur = head;
//			while (cur->next != head) {
//				cur = cur->next;
//			}
//			newNode->next = head;
//			head = newNode;// head points to the new node
//			cur->next = newNode;
//		}
//	}
//
//	// INSERTION at END
//	void InsertAtEnd(int data) {
//		if (isEmpty()) {
//			InsertAtStart(data); // if linkedList is empty then call InsertAtStart function
//		}
//		else {
//			Node* newNode = new Node(data); // creating a new node
//			//1st method if you dont have end pointer in your linkedList class
//			Node* cur = head; // creating a pointer to traverse the linkedList
//				while (cur->next != head) {
//					cur = cur->next; // traversing the linkedList
//				}
//				// now cur points to the last node
//				cur->next = newNode;
//				newNode->next = head;
//		}
//	}
//
//	// INSERTION at a specific position (INSERT AT MIDDLE)
//	void insertAtMiddle(int data, int posValue) { // posValue is the value after which you want to insert the new node
//		if (isEmpty()) {
//			InsertAtStart(data); // if linkedList is empty then call InsertAtStart function
//		}
//		else {
//			Node* newNode = new Node(data); // creating a new node
//			Node* cur = head; // creating a pointer to traverse the linkedList
//			while (cur->data != posValue && cur !=head) { // cur is not NULL and cur->data is not equal to posValue
//				cur = cur->next; // traversing the linkedList
//			}
//			if (!cur) {
//				cout << "Value not found in the linkedList" << endl;
//				return;
//			}
//			// now cur points to the node after which we want to insert the new node
//			newNode->next = cur->next;
//			cur->next = newNode;
//		}
//	}
//
//	// isEmpty() function checks if the linkedList is empty or not
//	bool isEmpty() {
//		if (head == NULL) { // if head is NULL then linkedList is empty
//			return true;
//		}
//
//		return false;
//	}
//	bool deleteAtStart() {
//		if (isEmpty()) {
//			cout << "Linked List is empty ..." << endl;
//			return false;
//		}
//		else {
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//			return true;
//		}
//	}
//	bool deleteAtEnd() { // delete the last node
//		if (isEmpty()) {
//			cout << "Linked List is empty ..." << endl;
//			return false;
//		}
//		else {
//			Node* cur = head;
//			while (cur->next->next != head) {// cur->next->next is not NULL
//				cur = cur->next;
//			}
//			// now cur points to the second last node
//			Node* temp = cur->next;
//			cur->next = head;
//			delete temp;
//		}
//	}
//	bool deleteAtMiddle(int posVal) { // del node after posVal
//		if (isEmpty()) {
//			cout << "Linked List is empty ..." << endl;
//			return false;
//		}
//		else {
//			Node* cur = head;
//			while (cur->next->data != posVal && cur != head) {
//				cur = cur->next;
//			}
//			// now cur points to the node before the node to be deleted
//			if (cur == head) {
//				cout << "Value not found in the linkedList" << endl;
//				return false;
//			}
//			Node* temp = cur->next;
//			cur->next = cur->next->next;
//			delete temp;
//			return true;
//		}
//	}
//	void diplayLinkedList() {
//		Node* cur = head;
//		do {
//			cout << cur->data << " ";
//			cur = cur->next;
//		} while (cur != head && cur != NULL);
//		cout << endl;
//	}
//
//};
//
//int main() {
//	SinglyLinkedListCircular sll;
//	sll.InsertAtStart(10);
//	sll.InsertAtStart(20);
//	sll.InsertAtStart(30);
//	sll.diplayLinkedList();
//	sll.InsertAtEnd(40);
//	sll.InsertAtEnd(50);
//	sll.InsertAtEnd(60);
//	sll.InsertAtEnd(70);
//	sll.diplayLinkedList();
//	//sll.insertAtMiddle(100, 40);
//	sll.insertAtMiddle(22, 500);
//	sll.diplayLinkedList();
//
//	return 0;
//}