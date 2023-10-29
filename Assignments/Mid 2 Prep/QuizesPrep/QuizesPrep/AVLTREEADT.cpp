// this code contains simple ADT of BST Not AVL BST
#include<iostream>
using namespace std;

struct Node {
	int data;
	int height;
	Node* left;
	Node* right;
	Node() {
		data = 0;
		height = 0;
		left = NULL;
		right = NULL;
	}
	Node(int data) {
		this->data = data;
		height = 0;
		left = NULL;
		right = NULL;
	}
};

class BST {
	Node* root;

public:
	BST() {
		root = NULL;
	}
	int Height(Node* position) {
		if (position == NULL) {
			return -1;
		}
		else {
			return position->height;
		}
	}
	void DeleteNode(int data, Node*& curNode) { // use & so that old curNode value also update
		if (curNode == NULL) {
			cout << "Node not found.\n";
		}
		else if (data < curNode->data) {
			DeleteNode(data, curNode->left);
		}
		else if (data > curNode->data) {
			DeleteNode(data, curNode->right);
		}
		makeDeletion(curNode);
	}
	void makeDeletion(Node*& curNode) {
		Node* tempNode;
		//case for having only left child
		if (curNode)
			if (curNode->right == NULL) { // means left exist or may b not
				tempNode = curNode;
				curNode = curNode->left;
				delete tempNode;
			}
		if (curNode->left == NULL) {
			tempNode = curNode;
			curNode = curNode->right;
			delete tempNode;
		}
		else {// node having both left and right
			tempNode = curNode->right; {
				while (tempNode->left) {
					tempNode = tempNode->left;
				}
				tempNode->left = curNode->left;
				tempNode = curNode;
				curNode = curNode->right;
				delete tempNode;
			}
		}
	}
	bool FindData(int data) {
		Node* cur = root;

		while (cur) {
			if (cur->data == data) {
				return true;
			}
			else if (data < cur->data) {
				cur = cur->left;
			}
			else {
				cur = cur->right;
			}
		}
		return false;
	}
	// insert without recurrion
	void insert(int data) {
		Node* newNode = new Node(data);
		if (!root) {
			root = newNode;
			return;
		}
		Node* curNode = root;
		while (1) {
			if (data < curNode->data) {
				if (curNode->left) {
					curNode = curNode->left;
				}
				else {
					curNode->left = newNode;
					return;
				}
			}
			else if (data > curNode->data)
			{
				if (curNode->right)
				{
					curNode = curNode->right;
				}
				else {
					curNode->right = newNode;
					return;
				}
			}
			else
			{
				cout << "Node already exists.\n";
				break;
			}
		}

	}
	void inOrderDisplay(Node* Root) {
		if (Root != NULL) {
			inOrderDisplay(Root->left);
			cout << Root->data;
			inOrderDisplay(Root->right);
		}
	}
	void preOrderDisplay(Node* Root) {
		if (Root != NULL) {
			cout << Root->data;
			inOrderDisplay(Root->left);
			inOrderDisplay(Root->right);
		}
	}
	void postOrderDisplay(Node* Root) {
		if (Root != NULL) {
			inOrderDisplay(Root->left);
			inOrderDisplay(Root->right);
			cout << Root->data;
		}
	}
	Node* getRoot() {
		return root;
	}
};

int main() {
	BST myTree;
	myTree.insert(2);
	myTree.insert(1);
	myTree.insert(4);
	myTree.insert(7);
	myTree.insert(69);
	myTree.insert(3);

	myTree.inOrderDisplay(myTree.getRoot());
	cout << endl;
	Node* deletingnode = myTree.getRoot();
	myTree.DeleteNode(69, deletingnode);
	myTree.inOrderDisplay(myTree.getRoot());
	cout << endl;
	return 0;
}