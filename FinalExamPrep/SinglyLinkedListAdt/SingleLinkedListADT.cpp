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
//			data = 0;
//			next = NULL;
//	}
//};
//
//
//// LINKED LIST CLASS
//class SinglyLinkedList {
//Node* head; // pointer to the first node in the linkedList
//Node* end; // pointer to the last node in the linkedList
//public:
//	SinglyLinkedList() {
//		head= NULL;
//		end = NULL;
//	}
//
//
//	// INSERTION at START
//	void InsertAtStart(int data) {
//		Node* newNode = new Node(data); // creating a new node
//		if (isEmpty()) { // if linkedList is empty
//			head= newNode;// head points to the new node
//			end = newNode;// end points to the new node
//		}
//		else { // if linkedList is not empty
//			newNode->next = head;// new node points to the first node
//			head  = newNode;// head points to the new node
//		}
//	}
//
//	// INSERTION at END
//	void InsertAtEnd(int data) {
//		if (isEmpty()) {
//			InsertAtStart(data); // if linkedList is empty then call InsertAtStart function
//		}
//		else {
//		Node* newNode = new Node(data); // creating a new node
//		//1st method if you dont have end pointer in your linkedList class
//		//Node* cur = head; // creating a pointer to traverse the linkedList
//		//	while (cur->next != NULL) {
//		//		cur = cur->next; // traversing the linkedList
//		//	}
//		//	// now cur points to the last node
//		//	cur->next = newNode;
//		//	end = newNode;
//		// 2nd method if you have end pointer in you linkedlist class
//		end->next = newNode;
//		end = end->next;
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
//			while (cur->data != posValue && cur) { // cur is not NULL and cur->data is not equal to posValue
//				cur = cur->next; // traversing the linkedList
//			}
//			if (!cur) {
//				cout<<"Value not found in the linkedList"<<endl;
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
//			Node * temp = head;
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
//			while (cur->next->next != NULL) {// cur->next->next is not NULL
//				cur = cur->next;
//			}
//			// now cur points to the second last node
//			Node* temp = cur->next;
//			end = cur;
//			cur->next = NULL;
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
//			while (cur->next->data != posVal && cur) {
//				cur = cur->next;
//			}
//			// now cur points to the node before the node to be deleted
//			if (!cur) {
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
//		while (cur) {
//			cout<<cur->data<<" ";
//			cur = cur->next;
//		}
//		cout<<endl;
//	}
//};
//
//int main() {
//	SinglyLinkedList sll;
//	sll.InsertAtStart(10);
//	sll.InsertAtStart(20);
//	sll.InsertAtStart(30);
//	sll.diplayLinkedList();
//	sll.InsertAtEnd(40);
//	sll.InsertAtEnd(50);
//	sll.InsertAtEnd(60);
//	sll.InsertAtEnd(70);
//	sll.diplayLinkedList();
//	sll.insertAtMiddle(100, 40);
//	//sll.insertAtMiddle(22, 500);
//	sll.diplayLinkedList();
//
//	return 0;
//}