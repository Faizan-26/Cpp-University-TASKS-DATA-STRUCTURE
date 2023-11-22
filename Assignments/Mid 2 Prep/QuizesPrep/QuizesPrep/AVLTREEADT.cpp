//// this code contains simple ADT of BST Not AVL BST
//#include<iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	int height;
//	Node* left;
//	Node* right;
//	Node() {
//		data = 0;
//		height = 0;
//		left = NULL;
//		right = NULL;
//	}
//	Node(int data) {
//		this->data = data;
//		height = 0;
//		left = NULL;
//		right = NULL;
//	}
//};
//
//class BST {
//	Node* root;
//
//public:
//	BST() {
//		root = NULL;
//	}
//	int Height(Node* position) {
//		if (position == NULL) {
//			return -1;
//		}
//		else {
//			return position->height;
//		}
//	}
//	void DeleteNode(int data, Node*& curNode) { // use & so that old curNode value also update
//		if (curNode == NULL) {
//			cout << "Node not found.\n";
//		}
//		else if (data < curNode->data) {
//			DeleteNode(data, curNode->left);
//		}
//		else if (data > curNode->data) {
//			DeleteNode(data, curNode->right);
//		}
//		makeDeletion(curNode);
//	}
//	void makeDeletion(Node*& curNode) {
//		Node* tempNode;
//		//case for having only left child
//		if (curNode)
//			if (curNode->right == NULL) { // means left exist or may b not
//				tempNode = curNode;
//				curNode = curNode->left;
//				delete tempNode;
//			}
//		if (curNode->left == NULL) {
//			tempNode = curNode;
//			curNode = curNode->right;
//			delete tempNode;
//		}
//		else {// node having both left and right
//			tempNode = curNode->right; {
//				while (tempNode->left) {
//					tempNode = tempNode->left;
//				}
//				tempNode->left = curNode->left;
//				tempNode = curNode;
//				curNode = curNode->right;
//				delete tempNode;
//			}
//		}
//	}
//	bool FindData(int data) {
//		Node* cur = root;
//
//		while (cur) {
//			if (cur->data == data) {
//				return true;
//			}
//			else if (data < cur->data) {
//				cur = cur->left;
//			}
//			else {
//				cur = cur->right;
//			}
//		}
//		return false;
//	}
//	// insert without recurrion
//	void insert(int data) {
//		Node* newNode = new Node(data);
//		if (!root) {
//			root = newNode;
//			return;
//		}
//		Node* curNode = root;
//		while (1) {
//			if (data < curNode->data) {
//				if (curNode->left) {
//					curNode = curNode->left;
//				}
//				else {
//					curNode->left = newNode;
//					return;
//				}
//			}
//			else if (data > curNode->data)
//			{
//				if (curNode->right)
//				{
//					curNode = curNode->right;
//				}
//				else {
//					curNode->right = newNode;
//					return;
//				}
//			}
//			else
//			{
//				cout << "Node already exists.\n";
//				break;
//			}
//		}
//
//	}
//	void inOrderDisplay(Node* Root) {
//		if (Root != NULL) {
//			inOrderDisplay(Root->left);
//			cout << Root->data;
//			inOrderDisplay(Root->right);
//		}
//	}
//	void preOrderDisplay(Node* Root) {
//		if (Root != NULL) {
//			cout << Root->data;
//			inOrderDisplay(Root->left);
//			inOrderDisplay(Root->right);
//		}
//	}
//	void postOrderDisplay(Node* Root) {
//		if (Root != NULL) {
//			inOrderDisplay(Root->left);
//			inOrderDisplay(Root->right);
//			cout << Root->data;
//		}
//	}
//	Node* getRoot() {
//		return root;
//	}
//};
//
//int main() {
//	BST myTree;
//	myTree.insert(2);
//	myTree.insert(1);
//	myTree.insert(4);
//	myTree.insert(7);
//	myTree.insert(69);
//	myTree.insert(3);
//
//	myTree.inOrderDisplay(myTree.getRoot());
//	cout << endl;
//	Node* deletingnode = myTree.getRoot();
//	myTree.DeleteNode(69, deletingnode);
//	myTree.inOrderDisplay(myTree.getRoot());
//	cout << endl;
//	return 0;
//}


#include<iostream>
using namespace std;
struct node
{
	int data;
	node* L;
	node* R;
};
class 	Binary_Search_Tree
{
	node* root;

public:
	Binary_Search_Tree()
	{
		root = NULL;
	}
	void Insertion(int num)
	{
		node* ptr = new node;
		node* curr = root;

		ptr->data = num;
		ptr->L = NULL;
		ptr->R = NULL;

		if (root == NULL)
		{
			root = ptr;

		}
		else {

			curr = root;

			while (curr != NULL)
			{

				if (num < curr->data)
				{
					if (curr->L == NULL)
					{
						curr->L = ptr;
						break;
					}
					curr = curr->L;

				}
				else if (num > curr->data)
				{
					if (curr->R == NULL)
					{
						curr->R = ptr;
						break;
					}

					curr = curr->R;
				}
			}
		}
	}


	void ShowIn(node* ptr)
	{
		if (ptr == NULL)
		{
			return;
		}
		ShowIn(ptr->L);
		cout << ptr->data << " ";
		ShowIn(ptr->R);
	}
	void displaypre(node* ptr)
	{
		if (ptr == NULL)
		{
			return;
		}
		cout << ptr->data << " ";
		displaypre(ptr->L);

		displaypre(ptr->R);
	}
	void displaypost(node* ptr)
	{
		if (ptr == NULL)
		{
			return;
		}
		displaypost(ptr->L);

		displaypost(ptr->R);
		cout << ptr->data << " ";
	}

	void disin()
	{
		ShowIn(root);
	}
	void dispre()
	{
		displaypre(root);
	}
	void dispost()
	{
		displaypost(root);
	}

	node* getRoot()
	{
		return root;
	}

	void mirror(node* p)
	{
		if (p == NULL)
			return;
		else
		{
			node* temp;


			mirror(p->L);
			mirror(p->R);


			temp = p->L;
			p->L = p->R;
			p->R = temp;
		}
	}
	void mirr()
	{
		mirror(root);
	}



};
void merge(node* ptr, Binary_Search_Tree obj)
{
	if (ptr == NULL)
	{
		return;
	}
	else
	{
		merge(ptr->L, obj);
		merge(ptr->R, obj);
		obj.Insertion(ptr->data);
	}
}

int main()
{
	Binary_Search_Tree s, s1, s2;
	int  n, n1, n2, n3, n4, n5;
	cout << "Enter plz firdt tree size : ";
	cin >> n;
	cout << "ENter nodes of fisrt : ";
	for (int i = 1; i <= n; i++)
	{
		cin >> n1;
		s.Insertion(n1);

	}
	cout << "Plz enter 2nd tree Size : ";
	cin >> n2;
	cout << "Enter nodes of 2nd : ";
	for (int i = 1; i <= n2; i++)
	{
		cin >> n3;
		s1.Insertion(n3);

	}
	cout << "Plz enter 3rd tree Size : ";
	cin >> n4;
	cout << "Enter nodes of 3 : ";
	for (int i = 1; i <= n4; i++)
	{
		cin >> n5;
		s2.Insertion(n5);

	}
	cout << "first is" << endl;
	cout << "In_Order display of 1" << endl;
	s.disin();
	cout << endl;
	cout << "Pre_Order display of 1" << endl;
	s.dispre();
	cout << endl;
	cout << "Post_Order display of 1" << endl;
	s.dispost();
	cout << endl;
	cout << endl;

	cout << "second is" << endl;
	cout << "In_Order display of 2" << endl;
	s1.disin();
	cout << "Pre_Order display of 2" << endl;
	s1.dispre();
	cout << endl;
	cout << "Post_Order display of 2" << endl;
	s1.dispost();

	cout << endl;
	cout << endl;
	cout << "third is" << endl;
	cout << "In_Order display of 3" << endl;
	s2.disin();
	cout << "Pre_Order display of 3" << endl;
	s2.dispre();
	cout << endl;
	cout << "Post_Order display of 3" << endl;
	s2.dispost();

	cout << endl;
	cout << endl;
	cout << ">>>>>>>>>>> MERGED ALL THREE TREES<<<<<<<<<<<<" << endl;
	merge(s1.getRoot(), s);
	merge(s2.getRoot(), s);

	s.disin();
	cout << endl;
	cout << "mirror is" << endl;

	s.mirr();
	cout << "Mirror inorder ::" << endl;
	s.disin();
	cout << endl;
	cout << "Mirror preorder ::" << endl;
	s.dispre();

	cout << endl;
	cout << "Mirror postorder" << endl;
	s.dispost();
	cout << endl;
	system("pause");
	return 0;
}
