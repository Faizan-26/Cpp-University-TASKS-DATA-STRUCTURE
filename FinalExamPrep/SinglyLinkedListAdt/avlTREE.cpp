//#include<iostream>
//using namespace std;
//
//struct AvlNode {
//	int data;
//	AvlNode* left;
//	AvlNode* right;
//	int height;
//	AvlNode(int Data) {
//		data = Data;
//		left = NULL;
//		right = NULL;
//		height = 0;
//	}
//	AvlNode() {
//		data = 0;
//		left = NULL;
//		right = NULL;
//		height = 0;
//	}
//};
//
//class AvlTree {
//	AvlNode* root;
//	AvlNode* makeDeletion(AvlNode* node, int data) {
//		if (node == nullptr) {
//			return nullptr;
//		}
//
//		if (data < node->data) {
//			node->left = makeDeletion(node->left, data);
//		}
//		else if (data > node->data) {
//			node->right = makeDeletion(node->right, data);
//		}
//		else {
//			if (node->left == nullptr && node->right == nullptr) {
//				delete node;
//				node = nullptr;
//				return node;
//			}
//			else if (node->left == nullptr) {
//				AvlNode* temp = node;
//				node = node->right;
//				delete temp;
//			}
//			else if (node->right == nullptr) {
//				AvlNode* temp = node;
//				node = node->left;
//				delete temp;
//			}
//			else {
//				AvlNode* temp = node->right;
//				while (temp->left != nullptr) {
//					temp = temp->left;
//				}
//				node->data = temp->data;
//				node->right = makeDeletion(node->right, temp->data);
//			}
//
//			node->height = 1 + max(height(node->left), height(node->right));
//
//			int balance = height(node->left) - height(node->right);
//
//			if (balance == 2) {
//				if (node->data < node->left->data) {
//					return singleRotationWithLeft(node);
//				}
//				else {
//					return doubleRotationWithLeft(node);
//				}
//			}
//			else if (balance == -2) {
//				if (node->data < node->right->data) {
//					return singleRotationWithRight(node);
//				}
//				else {
//					return doubleRotationWithRight(node);
//				}
//			}
//		}
//
//		return node;
//	}
//
//public:
//	AvlTree() {
//		root = NULL;
//	}
//	
//
//	int height(AvlNode* node) {
//		if (node == NULL) {
//			return -1;
//		}
//		else {
//			return node->height;
//		}
//	}
//
//	void find(int data) {
//		AvlNode* cur = root;
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
//		cout << "Cannot find " << data << " in tree.\n";
//	}
//
//	AvlNode* singleRotationWithLeft(AvlNode* node) { // RR rotation
//		AvlNode* tempNode;
//		tempNode = node->left;
//		node->left = tempNode->right;
//		tempNode->right = node;
//		node->height = max(height(node->left), height(node->right)) +1;
//		tempNode->height = max(height(tempNode->left), height(tempNode->right)) +1;
//		return tempNode; 
//	}
//
//	AvlNode* singleRotationWithRight(AvlNode* node) {//LL rotation
//		AvlNode* tempNode;
//		tempNode = node->right;
//		node->right = tempNode->left;
//		tempNode->left = node;
//		node->height = max(height(node), height(tempNode)) + 1;
//		tempNode->height = max(height(node), height(tempNode)) + 1;
//		return tempNode;
//	}
//
//	AvlNode* doubleRotationWithRight(AvlNode* node) {
//		// RR rotation
//		node->right = singleRotationWithLeft(node->right);
//		// LL rotation
//		return singleRotationWithRight(node);
//	}
//
//	AvlNode* doubleRotationWithLeft(AvlNode* node) {
//		// LL rotation
//		node->left= singleRotationWithRight(node->left);
//		// RR rotation
//		return singleRotationWithLeft(node);
//	}
//
//	AvlNode* makeInsertion(int data, AvlNode*& node) {
//		if (node == NULL) {
//			AvlNode* newNode = new AvlNode(data);
//			node = newNode;
//		}
//		else if (data < node->data) {
//			node->left = makeInsertion(data, node->left);
//			if (height(node->left) - height(node->right) == 2) {
//				if (data < node->left->data) {
//					node = singleRotationWithLeft(node); //RR rotation
//				}
//				else {
//					//RL rotation
//					node = doubleRotationWithLeft(node);
//				}
//			}
//		}
//		else if (data > node->data) {
//			node->right = makeInsertion(data, node->right);
//			if (height(node->right) - height(node->left) == 2) {
//				if (data < node->right->data) {
//					//LR rotation
//					node = doubleRotationWithRight(node);
//				}
//				else {
//					node = singleRotationWithRight(node);
//				}
//			}
//		}
//		else {
//			cout << "\nYour data already exist in tree.\n";
//		}
//		node->height = max(height(node->left), height(node->right))+1;
//		return node;
//	}
//	void inFixDisplay(AvlNode* r) {
//		if (!r) return;
//		inFixDisplay(r->left);
//		cout << r->data << "  ";
//		inFixDisplay(r->right);
//	}
//	void preFixDisplay(AvlNode* r) {
//		if (!r) return;
//		cout << r->data << "  ";
//		inFixDisplay(r->left);
//		inFixDisplay(r->right);
//	}
//	void postFixDisplay(AvlNode* r) {
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
//		root = makeDeletion(root, data);
//	}
//
//	void insert(int data) {
//		makeInsertion(data, root);
//	}
//};
//
//int main() {
//	
//	AvlTree tree;
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
//	cout<<"after del 2 \n";
//	tree.deleteNode(2);
//	tree.displayTree();
//	cout<<"after del 13 \n";
//	tree.deleteNode(13);
//	tree.displayTree();
//	// EXPRECTED OUTPUT : 1 2 3 4 5 6 7 8 9 10 11 12 13 15 16 17 18 
//	return 0;
//}