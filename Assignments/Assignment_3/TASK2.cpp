//#include<iostream>
//#include<string>
//using namespace std;
//
//struct Node {
//    int value;
//   
//    Node* left, * right;
//
//    Node() {
//        left = NULL;
//        right = NULL;
//        value = 0;
//    } Node(int v) {
//        left = NULL;
//        right = NULL;
//        value = v;
//    }
//};
//
//class BST {
//
//public:
//    Node* root;
//    BST() {
//        root = NULL;
//    }
//
//    void insertElement(Node*& node, int num)
//    {
//        if (node == nullptr)
//            node = new Node(num);
//        else if (num < node->value)
//            insertElement(node->left, num);
//        else if (num > node->value)
//            insertElement(node->right, num);
//        else
//            cout << "Duplicated values present." << endl;
//    }
//    void insert(int num)
//    {
//        insertElement(root, num);
//    }
//    
//    void convertToGreater() {
//        int sum = 0;
//        addAllRightNodeValuesToCurrent(root, sum);
//    }
//    void addAllRightNodeValuesToCurrent(Node* Root , int & sum) { // inorder traversal
//        if (!Root) {
//            return;
//        }
//        addAllRightNodeValuesToCurrent(Root->right, sum);
//        Root->value += sum;
//        sum = Root->value;
//        addAllRightNodeValuesToCurrent(Root->left, sum);
//    }
// 
//    void inOrder(Node* Root) {
//        if (!Root) {
//            return;
//        }
//        inOrder(Root->left);
//        cout << "   " << Root->value;
//        inOrder(Root->right);
//    }
//    void displayTree() {
//        inOrder(root);
//    }
//    Node* getRootNode() {
//        return root;
//    }
//};
//
//int main() {
//    BST tree;
//   
//    tree.insert(1);
//    tree.insert(4);
//    tree.insert(2);
//    tree.insert(0);
//    tree.insert(3);
//    tree.insert(6);
//    tree.insert(5);
//    tree.insert(7);
//    tree.insert(8);
//
//    tree.displayTree();
//    cout << endl;
//    tree.convertToGreater();
//    tree.displayTree();
//    return 0;
//}