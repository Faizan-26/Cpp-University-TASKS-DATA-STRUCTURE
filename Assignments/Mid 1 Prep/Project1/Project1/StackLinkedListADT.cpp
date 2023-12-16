#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

class StackAdt {
Node* top;
public:
    StackAdt() {
        top = NULL;
    }
    void push(int data) {
        Node* temp = new Node(data);
        if (top == NULL) {
            top = temp;
        }
        else {
            temp->next = top;
            top = temp;
        }
    }
    void pop(int& data) {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        else {
            data = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void peek(int& data) {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        else {
            data = top->data;
        }
    }
    void displayStack() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};
int main() {
	StackAdt s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.displayStack();
	int x;
	s.pop(x);
	s.displayStack();
	return 0;
}