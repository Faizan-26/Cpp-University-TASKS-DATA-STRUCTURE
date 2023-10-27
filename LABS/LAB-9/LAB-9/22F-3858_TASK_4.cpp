#include <iostream>
using namespace std;

struct AvlNode {
    int data;
    AvlNode* left;
    AvlNode* right;
    int height;

    AvlNode(int value) : data(value), left(NULL), right(NULL), height(0) {}
};

class AvlTree {
private:
    AvlNode* root;

public:
    AvlTree() : root(NULL) {}
    int getHeight(AvlNode* node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height;
    }

    int getBalanceFactor(AvlNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    AvlNode* rotateRight(AvlNode* y) { // RR rotation
        AvlNode* x = y->left;
        AvlNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), y->height) + 1;

        return x; /* New root */
    }

    AvlNode* rotateLeft(AvlNode* x) {
        AvlNode* y = x->right;
        AvlNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), x->height) + 1;

        return y; /* New root */
    }

    AvlNode* doubleRotateWithRight(AvlNode* K1) {
        /* RR rotation between K3 and K2 */
        K1->right = rotateLeft(K1->right);
        /* LL rotation between K1 and K2 */
        return rotateRight(K1);
    }

    AvlNode* doubleRotateWithLeft(AvlNode* K3) {
        /* LL rotation between K1 and K2 */
        K3->left = rotateRight(K3->left);
        /* RR rotation between K3 and K2 */
        return rotateLeft(K3);
    }

    AvlNode* insert(int x, AvlNode* T) {
        if (T == nullptr) {
            /* Create and return a new node */
            return new AvlNode(x);
        }

        if (x < T->data) {
            T->left = insert(x, T->left);
        }
        else if (x > T->data) {
            T->right = insert(x, T->right);
        } /* Else X is in the tree already; we'll do nothing */
        if (x == T->data) {
            cout << "Already Exists.\n";
            return T;
        }
        T->height = 1 + max(getHeight(T->left), getHeight(T->right));

        int balance = getBalanceFactor(T);

        if (balance > 1) {
            if (x < T->left->data) {
                return rotateRight(T); // Right-Right rotation
            }
            else {
                return doubleRotateWithLeft(T); // Right-Left rotation
            }
        }
        if (balance < -1) {
            if (x > T->right->data) {
                return rotateLeft(T); // Left-Left rotation
            }
            else {
                return doubleRotateWithRight(T); // Left-Right rotation
            }
        }
        return T;
    }

    bool find(int value, AvlNode* startNode) {
        while (startNode) {
            if (value < startNode->data) {
                startNode = startNode->left;
            }
            else if (value > startNode->data) {
                startNode = startNode->right;
            }
            else {
                cout << "found";
                return true;
            }
        }
        return false;
    }

    AvlNode* deleteNode(int num, AvlNode* nodePtr) {
        if (nodePtr == nullptr) {
            cout << "Num not found!\n";
            return nullptr;
        }

        if (num < nodePtr->data) {
            nodePtr->left = deleteNode(num, nodePtr->left);
        }
        else if (num > nodePtr->data) {
            nodePtr->right = deleteNode(num, nodePtr->right);
        }
        else {
            AvlNode* tempNode = nodePtr;
            if (nodePtr->left == nullptr) {
                nodePtr = nodePtr->right;
            }
            else if (nodePtr->right == nullptr) {
                nodePtr = nodePtr->left;
            }
            else {
                tempNode = nodePtr->right;
                while (tempNode->left) {
                    tempNode = tempNode->left;
                }
                tempNode->left = nodePtr->left;
                nodePtr = nodePtr->right;
            }
            delete tempNode;
        }

        if (nodePtr != nullptr) {
            nodePtr->height = 1 + max(getHeight(nodePtr->left), getHeight(nodePtr->right)); // calculates height of inserted node

            int balance = getBalanceFactor(nodePtr);

            if (balance > 1) {
                if (getBalanceFactor(nodePtr->left) >= 0) {
                    return rotateRight(nodePtr); // Right-Right rotation
                }
                else {
                    return doubleRotateWithLeft(nodePtr); // Right-Left rotation
                }
            }
            if (balance < -1) {
                if (getBalanceFactor(nodePtr->right) <= 0) {
                    return rotateLeft(nodePtr); // Left-Left rotation
                }
                else {
                    return doubleRotateWithRight(nodePtr); // Left-Right rotation
                }
            }
        }
        return nodePtr;
    }

    void inorderDisplay(AvlNode* p) const {
        if (p != nullptr) {
            inorderDisplay(p->left);
            cout << p->data << " ";
            inorderDisplay(p->right);
        }
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int num) {
        root = deleteNode(num, root);
    }

 
    void displayInOrder() {
        inorderDisplay(root);
        cout << endl;
    }
    AvlNode* getRoot() {
        return root;
    }
    int calcuateheight(AvlNode* temp)
            {
                int h = 0;
                if (temp != NULL)
                {
                    int l_height = calcuateheight(temp->left);
                    int r_height = calcuateheight(temp->right);
                    int max_height = max(l_height, r_height);
                    h = max_height + 1;
                }
                return h;
            }
    void insertNode(int num) {
        if (!root) root = new AvlNode(num);
        else {
            AvlNode* curNode = root;
            while (1) {
                if (num < curNode->data) {
                    if (curNode->left)
                        curNode = curNode->left;
                    else {

                        curNode->left = new AvlNode(num);
                        curNode->left->height = calcuateheight(curNode->left);
                        return;
                    }
                }
                else if (num > curNode->data) {
                    if (curNode->right) {
                        curNode = curNode->right;
                    }
                    else {
                        curNode->right = new AvlNode(num);
                        curNode->right->height = calcuateheight(curNode->right);
                        return;
                    }
                }
                else {
                    cout << "\nDUPLICATE NUMBER FOUND IN TREE.\n";
                }
            }
        }
    }

    void joinTrees(AvlNode* avl1, AvlNode* avl2) {
        if (avl1 != nullptr) {
            inorderDisplay(avl1->left);
            insertNode(avl1->data);
            inorderDisplay(avl1->right);
        }
        if (avl2 != nullptr) {
            inorderDisplay(avl2->left);
            insertNode(avl2->data);
            inorderDisplay(avl2->right);
        }
    }
};

int main() {
    AvlTree avl1 , avl2 , result;
    avl1.insert(10);
    avl1.insert(4);
    avl1.insert(13);
    avl1.insert(3);
    avl2.insert(8);
    avl2.insert(11);
    avl2.insert(20);

    cout << "\nIn-order traversal of avl1 : \n";
    avl1.displayInOrder();
    cout << "\nIn-order traversal of avl2 :\n";
    avl2.displayInOrder();
    cout << "Resultant Tree :" << endl;
    result.joinTrees(avl1.getRoot(), avl2.getRoot());
    result.displayInOrder();
    return 0;
}
