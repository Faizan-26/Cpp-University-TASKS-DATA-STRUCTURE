//#include<iostream>
//#include<string>
//using namespace std;
//int counter = 0;// to calculate number of leaf nodes
//struct Node {
//    char data;
//    Node* left, * right;
//
//    Node() {
//        left = NULL;
//        right = NULL;
//        data = ' ';
//    }
//};
//
//class BST {
//    Node* root;
//
//public:
//    BST() {
//        root = NULL;
//    }
//
//    void insert(char data) {
//        Node* newNode = new Node;
//        newNode->data = data;
//        newNode->left = NULL;
//        newNode->right = NULL;
//        if (!root)
//            root = newNode; // if the tree is not created
//        else {
//            Node* cur = root;
//            while (true) {
//                if (data< cur->data) {
//                    if (cur->left) {
//                        cur = cur->left;
//                    }
//                    else {
//                        cur->left = newNode;
//                        return;
//                    }
//                }
//                else if (data > cur->data) {
//                    if (cur->right) {
//                        cur = cur->right;
//                    }
//                    else {
//                        cur->right = newNode;
//                        return;
//                    }
//                }
//                else {
//                    cur->left = newNode; // for the same score, store on the left
//                    break;
//                }
//            }
//        }
//    }
//
//    void deleteNode(char data, Node*& newNode) {
//        if (newNode == NULL) {
//            cout << data << " Not found\n";
//        }
//        else if (data < newNode->data) {
//            deleteNode(data, newNode->left);
//        }
//        else if (data > newNode->data) {
//            deleteNode(data, newNode->right);
//        }
//        else {
//            makeDelete(newNode);
//        }
//    }
//
//    void makeDelete(Node*& newNode) {
//        Node* deleteNode;
//        if (newNode->right == NULL) {
//            deleteNode = newNode;
//            newNode = newNode->left;
//            delete deleteNode;
//        }
//        else if (newNode->left == NULL) {
//            deleteNode = newNode;
//            newNode = newNode->right;
//            delete deleteNode;
//        }
//        else {
//            deleteNode = newNode->right;
//            while (deleteNode->left) {
//                deleteNode = deleteNode->left;
//            }
//            deleteNode->left = newNode->left;
//            deleteNode = newNode;
//            newNode = newNode->right;
//            delete deleteNode;
//        }
//    }
//    void inOrder(Node* cur){
//        if (!cur) {
//            return;
//    }
//        inOrder(cur->left);
//        cout << cur->data<<"   ";
//        inOrder(cur->right);
//    }
//    void display() {
//        inOrder(root);
//    }
//    
//    void removeChar(char ch) {
//        deleteNode(ch, root);
//    }
//   
//};
//int main() {
//    BST tree;
//    tree.insert('L');
//    tree.insert('P');
//    tree.insert('D');
//    tree.insert('C');
//    tree.insert('H');
//    tree.insert('F');
//    tree.insert('J');
//    tree.insert('A');
//
//
//    tree.display();
//
//    cout << "\nDELETING J\n";
//    tree.removeChar('J');
//    tree.display();
//
//
//    cout << "\nDELETING C\n";
//    tree.removeChar('C');
//    tree.display();
//
//
//    cout << "\nDELETING L\n";
//    tree.removeChar('L');
//    tree.display();
//
//
//    cout << "\nDELETING D\n";
//    tree.removeChar('D');
//    tree.display();
//
//
//    cout << "\nDELETING A\n";
//    tree.removeChar('A');
//    tree.display();
//
//    return 0;
//}