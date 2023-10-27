//#include <iostream>
//using namespace std;
//
//struct AvlNode {
//    int data;
//    AvlNode* left;
//    AvlNode* right;
//    int height;
//
//    AvlNode(int value) : data(value), left(NULL), right(NULL), height(0) {}
//};
//
//class AvlTree {
//private:
//    AvlNode* root;
//
//public:
//    AvlTree() : root(NULL) {}
//    int getHeight(AvlNode* node) {
//        if (node == nullptr) {
//            return -1;
//        }
//        return node->height;
//    }
//
//    int getBalanceFactor(AvlNode* node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        return getHeight(node->left) - getHeight(node->right);
//    }
//
//    AvlNode* rotateRight(AvlNode* y) { // RR rotation
//        AvlNode* x = y->left;
//        AvlNode* T2 = x->right;
//
//        x->right = y;
//        y->left = T2;
//
//        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
//        x->height = max(getHeight(x->left), y->height) + 1;
//
//        return x; /* New root */
//    }
//
//    AvlNode* rotateLeft(AvlNode* x) {
//        AvlNode* y = x->right;
//        AvlNode* T2 = y->left;
//
//        y->left = x;
//        x->right = T2;
//
//        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
//        y->height = max(getHeight(y->left), x->height) + 1;
//
//        return y; /* New root */
//    }
//
//    AvlNode* doubleRotateWithRight(AvlNode* K1) {
//        /* RR rotation between K3 and K2 */
//        K1->right = rotateLeft(K1->right);
//        /* LL rotation between K1 and K2 */
//        return rotateRight(K1);
//    }
//
//    AvlNode* doubleRotateWithLeft(AvlNode* K3) {
//        /* LL rotation between K1 and K2 */
//        K3->left = rotateRight(K3->left);
//        /* RR rotation between K3 and K2 */
//        return rotateLeft(K3);
//    }
//
//    AvlNode* insert(int x, AvlNode* T) {
//        if (T == nullptr) {
//            /* Create and return a new node */
//            return new AvlNode(x);
//        }
//
//        if (x < T->data) {
//            T->left = insert(x, T->left);
//        }
//        else if (x > T->data) {
//            T->right = insert(x, T->right);
//        } /* Else X is in the tree already; we'll do nothing */
//
//        T->height = 1 + max(getHeight(T->left), getHeight(T->right));
//
//        int balance = getBalanceFactor(T);
//
//        if (balance > 1) {
//            if (x < T->left->data) {
//                return rotateRight(T); // Right-Right rotation
//            }
//            else {
//                return doubleRotateWithLeft(T); // Right-Left rotation
//            }
//        }
//        if (balance < -1) {
//            if (x > T->right->data) {
//                return rotateLeft(T); // Left-Left rotation
//            }
//            else {
//                return doubleRotateWithRight(T); // Left-Right rotation
//            }
//        }
//        return T;
//    }
//
//    bool find(int value, AvlNode* startNode) {
//        while (startNode) {
//            if (value < startNode->data) {
//                startNode = startNode->left;
//            }
//            else if (value > startNode->data) {
//                startNode = startNode->right;
//            }
//            else {
//                cout << "VALUE FOUND.\n";
//                return true;
//            }
//        }
//        cout << "Value not found.\n";
//        return false;
//    }
//
//    AvlNode* deleteNode(int num, AvlNode* nodePtr) {
//        if (nodePtr == nullptr) {
//            cout << "Num not found!\n";
//            return nullptr;
//        }
//
//        if (num < nodePtr->data) {
//            nodePtr->left = deleteNode(num, nodePtr->left);
//        }
//        else if (num > nodePtr->data) {
//            nodePtr->right = deleteNode(num, nodePtr->right);
//        }
//        else {
//            AvlNode* tempNode = nodePtr;
//            if (nodePtr->left == nullptr) {
//                nodePtr = nodePtr->right;
//            }
//            else if (nodePtr->right == nullptr) {
//                nodePtr = nodePtr->left;
//            }
//            else {
//                tempNode = nodePtr->right;
//                while (tempNode->left) {
//                    tempNode = tempNode->left;
//                }
//                tempNode->left = nodePtr->left;
//                nodePtr = nodePtr->right;
//            }
//            delete tempNode;
//        }
//
//        if (nodePtr != nullptr) {
//            nodePtr->height = 1 + max(getHeight(nodePtr->left), getHeight(nodePtr->right)); // calculates height of inserted node
//
//            int balance = getBalanceFactor(nodePtr);
//
//            if (balance > 1) {
//                if (getBalanceFactor(nodePtr->left) >= 0) {
//                    return rotateRight(nodePtr); // Right-Right rotation
//                }
//                else {
//                    return doubleRotateWithLeft(nodePtr); // Right-Left rotation
//                }
//            }
//            if (balance < -1) {
//                if (getBalanceFactor(nodePtr->right) <= 0) {
//                    return rotateLeft(nodePtr); // Left-Left rotation
//                }
//                else {
//                    return doubleRotateWithRight(nodePtr); // Left-Right rotation
//                }
//            }
//        }
//        return nodePtr;
//    }
//
//    void inorderDisplay(AvlNode* p) const {
//        if (p != nullptr) {
//            inorderDisplay(p->left);
//            cout << p->data << " ";
//            inorderDisplay(p->right);
//        }
//    }
//
//    void insert(int x) {
//        root = insert(x, root);
//    }
//
//    void remove(int num) {
//        root = deleteNode(num, root);
//    }
//
//    bool find(int value) {
//        return find(value, root);
//    }
//
//    void displayInOrder() {
//        inorderDisplay(root);
//        cout << endl;
//    }
//};
//
//int main() {
//    AvlTree avl;
//    avl.insert(10);
//    avl.insert(4);
//    avl.insert(13);
//    avl.insert(3);
//    avl.insert(8);
//    avl.insert(11);
//    avl.insert(20);
//
//    cout << "In-order traversal: ";
//    avl.displayInOrder();
//
//    avl.remove(8);
//
//    cout << "In-order traversal after removing 8: ";
//    avl.displayInOrder();
//
//    cout << "Searching for 12: ";
//    avl.find(13);
//
//    cout << "Searching for 8: ";
//    avl.find(8);
//
//    return 0;
//}
