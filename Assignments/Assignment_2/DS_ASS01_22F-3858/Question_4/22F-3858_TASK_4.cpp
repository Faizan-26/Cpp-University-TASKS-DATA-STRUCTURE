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
//
//class circularLinkedList {
//private:
//	Node* head;
//public:
//	circularLinkedList() {
//		head = NULL;
//	}
//	bool isEmpty() {
//		return head == NULL;
//	}
//	void insertData(int data) {
//		Node* newNode = new Node(data);
//		if (isEmpty()) {
//			head = newNode;
//			head->next = head;
//			return;
//		}
//		Node* cur = head;
//		while (cur->next != head) { // traverse
//			cur = cur->next;
//		}
//		cur->next = newNode; // insert at last
//		newNode->next = head;  
//	}
//	int getRemainingNode(int m) {
//		if (isEmpty()) {
//			return -1;
//		}
//		Node* cur = head; // for traverse
//		Node* initial = new Node; // node before cur node
//		while (cur->next != cur) {
//			int count = 0;
//			while (count != m) {
//				count++;
//				initial = cur;
//				cur = cur->next; // traverse till count != m
//			}
//			// now cur node is at m location
//			// delete m node
//			initial->next = cur->next;
//			delete cur;
//			cur = initial->next; 
//		}
//		return cur->data; /// returns data of remaining node 
//	}
//	~circularLinkedList() {
//		if (isEmpty()) {
//			return;
//		}
//		Node* cur = head;
//		Node* nextNode = new Node;
//		while (cur->next != head) {
//			nextNode = cur->next;
//			delete cur;
//			cur = nextNode;
//		}
//		delete nextNode;
//	}
//};
//int main() {
//	cout << "Enter Length of circle :";
//	int N;
//	cin >> N;
//	circularLinkedList List;
//	cout << "Enter Data in Circular Linked List :";
//	int data;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> data;
//		if (data > 0) {
//			List.insertData(data);
//		}
//		else {
//			cout << "\nData cannot be negative.\n";
//		}
//	}
//	cout << "Count to choose Next :";
//	int M;
//	cin >> M;
//	cout << endl;
//	cout<<"OUTPUT :"<<List.getRemainingNode(M);
//	return 0;
//}