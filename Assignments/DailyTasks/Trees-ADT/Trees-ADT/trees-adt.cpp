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
	Node* root;
public:
	BST() {
		root = NULL;
	}
	void insertNode(int num) {
		Node* newNode = new Node;
		newNode->data = num;
		if (!root) root = newNode;
		else {
			Node* curNode = root;
			while (1) {
				if (num < curNode->data) {
					if (curNode->left)
						curNode = curNode->left;
					else {
						curNode->left = new Node; 
						return;
					}
				}
				else if (num > curNode->data) {
					if (curNode->right) {
						curNode = curNode->right;
					}
					else {
						curNode->right = newNode;
						return;
					}
				}
				else {
					cout << "\nDUPLICATE NUMBER FOUND IN TREE.\n";
				}
			}
		}
	}
	bool find(int value, Node* startNode) {
		// start node is to specify searching from specific part of tree
		while (startNode) { // if start node != NULL
			if (value < startNode->data) {
				startNode = startNode->left;
			}
			else if (value > startNode->data) {
				startNode = startNode->right;
			}
			else {
				cout << "VALUE FOUND.\n";
				return true;
			}
		}
		cout << "Value not found.\n";
		return false;
	}
	void makeDeletion(Node*& nodePtr) {
		Node* tempNode;
		if (nodePtr->right == NULL) { // if only left node is NULL
			tempNode = nodePtr;
			nodePtr = nodePtr->left;
			delete tempNode;
		}
		else if (nodePtr->left == NULL) { // if only right NODE is null
			tempNode = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNode;
		}
		else { // case for two childrens
			tempNode = nodePtr->right;
			while (tempNode->left) {
				tempNode = tempNode->left;
			}
			tempNode->left = nodePtr->left;
			tempNode = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNode;
		}
	}
	void deleteNode(int num, Node*& nodePtr) {
		if (nodePtr == NULL) {
			cout << "Num not found!\n";
		}
		else if (num < nodePtr->data) {
			deleteNode(num, nodePtr->left);
		}
		else if (num > nodePtr->data) {
			deleteNode(num, nodePtr->right);
		}
		else {
			makeDeletion(nodePtr);
		}
	}
	 
};
int main() {

	return 0;
}