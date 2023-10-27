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
//    int calcuateheight(AvlNode* temp)
//    {
//        int h = 0;
//        if (temp != NULL)
//        {
//            int l_height = calcuateheight(temp->left);
//            int r_height = calcuateheight(temp->right);
//            int max_height = max(l_height, r_height);
//            h = max_height + 1;
//        }
//        return h;
//    }
//    int getHeight(AvlNode* node) {
//        if (node == NULL) {
//            return -1;
//        }
//        return node->height;
//    }
//
//    int getBalanceFactor(AvlNode* node) {
//        if (node == NULL) {
//            return -1;
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
//
//        /* RR rotation between K3 and K2 */
//        return rotateLeft(K3);
//    }
//
//
//    void insertNode(int num) {
//        if (!root) root = new AvlNode(num);
//        else {
//            AvlNode* curNode = root;
//            while (1) {
//                if (num < curNode->data) {
//                    if (curNode->left)
//                        curNode = curNode->left;
//                    else {
//
//                        curNode->left = new AvlNode(num);
//                        curNode->left->height = calcuateheight(curNode->left);
//                        return;
//                    }
//                }
//                else if (num > curNode->data) {
//                    if (curNode->right) {
//                        curNode = curNode->right;
//                    }
//                    else {
//                        curNode->right = new AvlNode(num);
//                        curNode->right->height = calcuateheight(curNode->right);
//                        return;
//                    }
//                }
//                else {
//                    cout << "\nDUPLICATE NUMBER FOUND IN TREE.\n";
//                }
//            }
//        }
//    }
//
//    AvlNode* convertBSTtoAVL(AvlNode* p) {
//        if (p != NULL) {
//            p->left = convertBSTtoAVL(p->left);
//            p->right = convertBSTtoAVL(p->right);
//
//            int balance = getBalanceFactor(p);
//            if (balance > 1) {
//                if (p->data < p->left->data) {
//                    p = rotateRight(p);
//                }
//                else {
//                    p = doubleRotateWithLeft(p);
//                }
//            }
//            if (balance < -1) {
//                if (p->data > p->right->data) {
//                    p = rotateLeft(p);
//                }
//                else {
//                    p = rotateLeft(p);
//                }
//            }
//        }
//        return p;
//    }
//    void inorderDisplay(AvlNode* p) const {
//        if (p != NULL) {
//            inorderDisplay(p->left);
//            cout << p->data << " ";
//            inorderDisplay(p->right);
//        }
//    }
//
//    void displayInOrder() {
//        inorderDisplay(root);
//        cout << endl;
//    }
//
//    bool isAVL(AvlNode* Root, bool& avl) {
//        if (Root == NULL) {
//            avl = true;
//            return true;
//        }
//        int balanceFactor = getBalanceFactor(Root);
//        if (balanceFactor < -1 || balanceFactor > 1) {
//            avl = false;
//            return false;
//        }
//        return isAVL(Root->left , avl) && isAVL(Root->right, avl);
//    }
//    AvlNode* getRoot() {
//        return root;
//    }
//    AvlNode* insert(int x, AvlNode* T) {
//                if (T == NULL) {
//                    return new AvlNode(x);
//                }
//        
//                if (x < T->data) {
//                    T->left = insert(x, T->left);
//                }
//                else if (x > T->data) {
//                    T->right = insert(x, T->right);
//                } 
//        
//                T->height = 1 + max(getHeight(T->left), getHeight(T->right));
//        
//                int balance = getBalanceFactor(T);
//        
//                if (balance > 1) {
//                    if (x < T->left->data) {
//                        return rotateRight(T); // Right-Right rotation
//                    }
//                    else {
//                        return doubleRotateWithLeft(T); // Right-Left rotation
//                    }
//                }
//                if (balance < -1) {
//                    if (x > T->right->data) {
//                        return rotateLeft(T); // Left-Left rotation
//                    }
//                    else {
//                        return doubleRotateWithRight(T); // Left-Right rotation
//                    }
//                }
//                return T;
//            }
//    void setRoot(AvlNode* newRoot) {
//        root = newRoot;
// }
//};
//
//int main() {
//    AvlTree avl;
//    avl.insertNode(1);
//    avl.insertNode(2);
//    avl.insertNode(3);
//    avl.insertNode(4);
//    avl.insertNode(5);
//    avl.insertNode(6);
//
//    bool is_AVL = false;
//    avl.isAVL(avl.getRoot(), is_AVL);
//    if (is_AVL) {
//        cout << "Your Tree is AVL.\n";
//    }
//    else {
//        cout << "Your tree is not avl.\n";
//    }
//    cout << "Converting BST to AVL.\n"; 
//    avl.setRoot(avl.convertBSTtoAVL(avl.getRoot()));
//    is_AVL = false;
//    avl.isAVL(avl.getRoot(), is_AVL);
//
//    if (!is_AVL) {
//        cout << "Your Tree is AVL.\n";
//    }
//    else {
//        cout << "Your tree is not avl.\n";
//    }
//
//    return 0;
//}
