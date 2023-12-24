//#include<iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//	Node(int Data) {
//		data = Data;
//		left = NULL;
//		right = NULL;
//	}
//	Node() {
//		data = 0;
//		left = NULL;
//		right = NULL;
//	}
//};
//
//class BST {
//	Node* root;
//
//	void makeDeletion(Node* node) {
//		Node* tempNode;
//		if (node->right == NULL) // means there is right is NULL has one child
//		{
//			tempNode = node;
//			node = node->left;
//			delete tempNode;
//		}
//		else if (node->left == NULL) {
//			tempNode = node;
//			node = node->right;
//			delete tempNode;
//		}
//		else { // case for two children
//			tempNode = node->right;
//			while (tempNode->left) {
//				tempNode = tempNode->left;
//			}
//			tempNode->left = node->left;
//			tempNode = node;
//			node = node->right;
//			delete tempNode;
//		}
//	}
//public:
//	BST() {
//		root = NULL;
//	}
//
//	void find(int data) {
//		Node* cur = root;
//
//		while (cur) {
//			if (data< cur->data ) {
//				cur = cur->left;
//			}
//			else if (data > cur->data) {
//				cur = cur->right;
//			}
//			else {
//				cout << data << " is present in your tree.\n";
//				return;
//			}
//		}
//		cout << "Cannot find "<<data<<" in tree.\n";
//	}
//
//	bool insert(int data) {
//		Node* newNode = new Node(data);
//		if (!root) root = newNode;
//		else {
//			Node* cur = root;
//			while (1) {
//				if (data < cur->data) {
//					if (cur->left) cur = cur->left;
//					else {
//						cur->left = newNode;
//						return true;
//					}
//				}
//				else if (data > cur->data) {
//					if (cur->right) cur = cur->right;
//					else {
//						cur->right = newNode;
//						return true;
//					}
//				}
//				else {
//					cout << "\nDuplicate value cannot exist in BST.\n";
//					return false;
//				}
//			}
//		}
//	}
//	void inFixDisplay(Node* r) {
//		if (!r) return;
//		inFixDisplay(r->left);
//		cout << r->data << "  ";
//		inFixDisplay(r->right);
//	}
//	void preFixDisplay(Node* r) {
//		if (!r) return;
//		cout << r->data << "  ";
//		inFixDisplay(r->left);
//		inFixDisplay(r->right);
//	}
//	void postFixDisplay(Node* r) {
//		if (!r) return;
//		inFixDisplay(r->left);
//		inFixDisplay(r->right);
//		cout << r->data << "  ";
//	}
//
//	void displayTree() {
//		inFixDisplay(root);
//		cout << endl;
//		preFixDisplay(root);
//		cout << endl;
//		postFixDisplay(root);
//		cout << endl;
//	}
//
//	void deleteNode(int data) {
//		Node* cur = root;
//
//		while (cur) {
//			if (data < cur->data) {
//				cur = cur->left;
//			}
//			else if (data > cur->data) {
//				cur = cur->right;
//			}
//			else {
//				cout << data << " is present in your tree.\n";
//				return;
//			}
//		}
//		makeDeletion(cur);
//	}
//
//};
//
//int main() {
//	BST tree;
//	tree.insert(10);
//	tree.insert(5);
//	tree.insert(15);
//	tree.insert(3);
//	tree.insert(7);
//	tree.insert(12);
//	tree.insert(17);
//	tree.insert(1);
//	tree.insert(4);
//	tree.insert(6);
//	tree.insert(8);
//	tree.insert(11);
//	tree.insert(13);
//	tree.insert(16);
//	tree.insert(18);
//	tree.insert(2);
//	tree.insert(9);
//	tree.displayTree();
//	tree.find(10);
//	tree.find(5);
//	tree.find(15);
//	tree.find(3);
//	tree.find(7);
//	tree.find(12);
//	tree.find(17);
//	tree.find(1);
//	tree.find(4);
//	tree.find(6);
//	tree.find(8);
//	tree.find(11);
//	tree.find(13);
//	tree.find(16);
//	tree.find(18);
//	tree.find(2);
//	tree.find(9);
//	tree.deleteNode(10);
//	tree.displayTree();
//	tree.find(10);
//	tree.find(5);
//	tree.find(15);
//	tree.find(3);
//	tree.find(7);
//	tree.find(12);
//	tree.find(17);
//	tree.find(1);
//	tree.find(4);
//	tree.find(6);
//	tree.find(8);
//	tree.find(11);
//	tree.find(13);
//	tree.find(16);
//	tree.find(18);
//	tree.find(2);
//	tree.find(9);
//	
//	return 0;
//}