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
 //class QueueLinkedListAdt {
 //	Node* rear;
 //	Node* front;
 //	int numItems;
 //public:
 //	QueueLinkedListAdt() {
 //		rear = NULL;
 //		front = NULL;
 //		numItems = 0;
 //	}
 //	bool isEmpty() {
 //		return numItems == 0;
 //	}
 //	void enqueue(int data) {
 //		Node* newNode = new Node(data);
 //		if (isEmpty()) {
 //			front = newNode;
 //			rear = newNode;
 //		}
 //		else {
 //			rear->next = newNode;
 //			rear = newNode;
 //			numItems++;
 //		}
 //	}
 //	void dequeue(int & num) {
 //		if (isEmpty()) {
 //			cout << "\nQueue is already empty.\n";
 //			return;
 //		}
 //		numItems--;
 //		num = front->data;
 //		Node* deletedNode	= front;
 //		front = front->next;
 //		delete deletedNode;
 //	}
 //	void makeNull() {
 //		int x;
 //		while (!isEmpty()) {
 //			dequeue(x);
 //		}
 //	}
 //	~QueueLinkedListAdt() {
 //		makeNull();
 //	}
 //};
 //int main() {
 //	QueueLinkedListAdt q;
 //	q.enqueue(1);
 //	int x;
 //	q.dequeue(x);
 //	return 0;
 //}