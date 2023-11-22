//#include <iostream>
//using namespace std;
//
//struct AvlNode
//{
//    int Element;
//    AvlNode* Left;
//    AvlNode* Right;
//    int Height;
//};
//
//class AVLTree
//{
//private:
//public:
//    AVLTree() {}
//
//    int Height(AvlNode* p)
//    {
//        if (p == NULL)
//            return 0;
//        else
//            return 1 + max(Height(p->Left), Height(p->Right));
//    }
//
//    int Max(int x, int y)
//    {
//        if (x >= y)
//            return x;
//        else
//            return y;
//    }
//
//    AvlNode* SingleRotateLeft(AvlNode* K1)
//    {
//        AvlNode* K2;
//        K2 = K1->Right;
//        K1->Right = K2->Left;
//        K2->Left = K1;
//        K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
//        K2->Height = Max(Height(K2->Right), K1->Height) + 1;
//        return K2; /* New root */
//    }
//
//    AvlNode* SingleRotateRight(AvlNode* K2)
//    {
//        AvlNode* K1;
//        K1 = K2->Left;
//        K2->Left = K1->Right;
//        K1->Right = K2;
//        K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
//        K1->Height = Max(Height(K1->Left), K2->Height) + 1;
//        return K1; /* New root */
//    }
//
//    AvlNode* DoubleRotateRight(AvlNode* K3)
//    {
//        /* Rotate between K1 and K2 */
//        K3->Left = SingleRotateLeft(K3->Left);
//        /* Rotate between K3 and K2 */
//        return SingleRotateRight(K3);
//    }
//
//    AvlNode* DoubleRotateLeft(AvlNode* K1)
//    {
//        /* Rotate between K3 and K2 */
//        K1->Right = SingleRotateRight(K1->Right);
//        /* Rotate between K1 and K2 */
//        return SingleRotateLeft(K1);
//    }
//
//    AvlNode* Insert(int X, AvlNode* T)
//    {
//        if (T == NULL)
//        {
//            /* Create and return a one-node tree */
//            T = new AvlNode;
//            T->Element = X;
//            T->Height = 0;
//            T->Left = T->Right = NULL;
//        }
//        else if (X < T->Element)
//        {
//            T->Left = Insert(X, T->Left);
//            if (Height(T->Left) - Height(T->Right) == 2)
//                if (X < T->Left->Element)
//                    T = SingleRotateRight(T);
//                else
//                    T = DoubleRotateRight(T);
//        }
//        else if (X > T->Element)
//        {
//            T->Right = Insert(X, T->Right);
//            if (Height(T->Right) - Height(T->Left) == -2)
//                if (X > T->Right->Element)
//                    T = SingleRotateLeft(T);
//                else
//                    T = DoubleRotateLeft(T);
//        }
//        /* Else X is in the tree already; we'll do nothing */
//        T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
//
//        return T;
//    }
//
//    AvlNode* FindMin(AvlNode* T)
//    {
//        if (T == nullptr)
//            return nullptr;
//        else if (T->Left == nullptr)
//            return T;
//        else
//            return FindMin(T->Left);
//    }
//
//    AvlNode* Delete(int X, AvlNode* T)
//    {
//        if (T == nullptr)
//            return nullptr; // Element not found
//
//        if (X < T->Element)
//        {
//            T->Left = Delete(X, T->Left);
//        }
//        else if (X > T->Element)
//        {
//            T->Right = Delete(X, T->Right);
//        }
//        else // Element found
//        {
//            // Node with only one child or no child
//            if (T->Left == nullptr)
//            {
//                AvlNode* temp = T->Right;
//                delete T;
//                return temp;
//            }
//            else if (T->Right == nullptr)
//            {
//                AvlNode* temp = T->Left;
//                delete T;
//                return temp;
//            }
//
//            // Node with two children, get the in-order successor (smallest in the right subtree)
//            AvlNode* temp = FindMin(T->Right);
//            T->Element = temp->Element;
//            T->Right = Delete(temp->Element, T->Right);
//        }
//
//        // Update height
//        T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
//
//        // Check for balance and perform rotations if needed
//        int balance = Height(T->Left) - Height(T->Right);
//
//        // Left Heavy
//        if (balance > 1)
//        {
//            // Left-Left case
//            if (X < T->Left->Element)
//                return SingleRotateRight(T);
//            // Left-Right case
//            else
//            {
//                T->Left = SingleRotateLeft(T->Left);
//                return SingleRotateRight(T);
//            }
//        }
//        // Right Heavy
//        else if (balance < -1)
//        {
//            // Right-Right case
//            if (X > T->Right->Element)
//                return SingleRotateLeft(T);
//            // Right-Left case
//            else
//            {
//                T->Right = SingleRotateRight(T->Right);
//                return SingleRotateLeft(T);
//            }
//        }
//
//        return T;
//    }
//
//    void inorderTraversal(AvlNode* newroot)
//    {
//        // inorder traversal gives sorted data
//        if (newroot)
//        {
//            inorderTraversal(newroot->Left);
//            cout << newroot->Element << " ";
//            inorderTraversal(newroot->Right);
//        }
//    }
//
//    ~AVLTree() {}
//};
//
//int main()
//{
//    AVLTree tree1;
//    AvlNode* root = nullptr; // Initialize the root to nullptr
//
//    root = tree1.Insert(12, root);
//    root = tree1.Insert(15, root);
//
//    cout << "Inorder Traversal of the tree: ";
//    tree1.inorderTraversal(root);
//    cout << endl;
//
//    root = tree1.Delete(12, root);
//
//    cout << "Inorder Traversal after deleting 12: ";
//    tree1.inorderTraversal(root);
//    cout << endl;
//
//    return 0;
//}

#include<iostream>
using namespace std;
int main() {
int m = 7, n = m / 2 + 1;
char ch = '+';
for (int i = 0; i < n - 1; i++){
	for (int j = 0; j < i; j++)
		cout << " ";
	for (int j = 0; j < m; j++) {
		if (j == m - 1 || j == 0)
			cout << ch;
		else
			cout << " ";
	}
	m = m - 2;
	cout << endl;
}
}