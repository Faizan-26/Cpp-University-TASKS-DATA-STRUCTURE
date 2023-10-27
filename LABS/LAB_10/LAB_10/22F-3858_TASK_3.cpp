#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
};

class BST {
	int start;
public:
	Node* root;
	BST() {
		root = NULL;
		start = -1;
	}

	Node* insertNode(Node* Root, int num) {
		Node* newNode = new Node;
		newNode->data = num;
		if (!Root) {
			Root = newNode;
		}
		else {
			if (num < Root->data) {
				Root->left = insertNode(Root->left, num);
			}
			else if (num > Root->data) {
				Root->right = insertNode(Root->right, num);
			}
		}
		return Root;
	}

	void inOrder(Node* Root, int arr[]) {
		if (Root) {  // Changed 'if (root)' to 'if (Root)'
			inOrder(Root->left, arr);
			arr[++start] = Root->data;
			inOrder(Root->right, arr);
		}
	}

	Node* getRoot() {
		return root;
	}
};

int main() {
	BST tree;
	tree.root = tree.insertNode(tree.getRoot(), 1); // Assign root after inserting the first node
	tree.insertNode(tree.getRoot(), 3);
	tree.insertNode(tree.getRoot(), 2);
	tree.insertNode(tree.getRoot(), 9);
	tree.insertNode(tree.getRoot(), 7);
	int arr[5] = {};
	tree.inOrder(tree.getRoot(), arr);
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << "  ";
	}
	return 0;
}
