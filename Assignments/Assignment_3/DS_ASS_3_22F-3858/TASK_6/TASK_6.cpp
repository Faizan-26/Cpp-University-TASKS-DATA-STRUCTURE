//#include <iostream>
//using namespace std;
//
//struct AvlNode {
//    int StudentId;
//    string department;
//    AvlNode* left;
//    AvlNode* right;
//    int height;
//
//    AvlNode(int value, string Dep) : StudentId(value), left(NULL), right(NULL), height(0), department(Dep) {}
//};
//
//class AvlDataBase {
//private:
//    AvlNode* root;
//
//public:
//    AvlDataBase() : root(NULL) {}
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
//        return x;
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
//        return y;
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
//
// 
//
//    void inorderDisplay(AvlNode* p) const {
//        if (p != nullptr) {
//            inorderDisplay(p->left);
//            cout << p->StudentId << " " <<p->department <<"  ";
//            inorderDisplay(p->right);
//        }
//    }
//
//    void displayInOrder() {
//        inorderDisplay(root);
//        cout << endl;
//    }
//
//  
//    void addStudent(int id, string dep) {
//       root = insert(id, dep, root);
//    }
//    AvlNode* insert(int id, string dep, AvlNode* T) {
//                if (T == nullptr) {
//                    return new AvlNode(id, dep);
//                }
//        
//                if (id < T->StudentId) {
//                    T->left = insert(id, dep, T->left);
//                }
//                else if (id > T->StudentId) {
//                    T->right = insert(id,dep, T->right);
//                }
//                else if (id == T->StudentId) {
//                    cout << "Student Already exists.\n";
//                    return T;
//                }
//                T->height = 1 + max(getHeight(T->left), getHeight(T->right));
//        
//                int balance = getBalanceFactor(T);
//        
//                if (balance > 1) {
//                    if (id < T->left->StudentId) {
//                        return rotateRight(T); // Right-Right rotation
//                    }
//                    else {
//                        return doubleRotateWithLeft(T); // Right-Left rotation
//                    }
//                }
//                if (balance < -1) {
//                    if (id > T->right->StudentId) {
//                        return rotateLeft(T); // Left-Left rotation
//                    }
//                    else {
//                        return doubleRotateWithRight(T); // Left-Right rotation
//                    }
//                }
//                return T;
//    }
//    string setDepartment(int studentId) {
//        if (studentId >= 1000 && studentId <= 1999) {
//            return "CS";
//        }
//        else if (studentId >= 2000 && studentId <= 2999) {
//            return "SE";
//        }
//        else if (studentId >= 3000 && studentId <= 3999) {
//            return "EE";
//        }
//        else if (studentId >= 4000 && studentId <= 4999) {
//            return "S&H";
//        }
//        else if (studentId >= 5000 && studentId <= 5999) {
//            return "FSM";
//        }
//        else return "INVALID ID";
//    }
//    void editStudent(int id) {
//        if (find(id, root)) {
//            cout << "\nStudent updated\n";
//        }
//        else {
//            cout << "\nStudent not found in database.\n";
//        }
//    }
//    bool find(int id, AvlNode* startNode) {
//        while (startNode) {
//            if (id < startNode->StudentId) {
//                startNode = startNode->left;
//            }
//            else if (id > startNode->StudentId) {
//                startNode = startNode->right;
//            }
//            else {
//                string tempString = " ";
//                int tempId = 0;
//                cout << "Enter new id of student :";
//                cin >> tempId;
//                tempString = setDepartment(tempId);
//                startNode->StudentId = tempId;
//                startNode->department = tempString;
//                return true;
//            }
//        }
//        return false;
//    }
//};
//
//int main() {
//    AvlDataBase database;
//    int choice = 0;
//    int tempStudentId = 0;
//    string tempStudentDepartment = " ";
//    bool end = false;
//    while (!end) {
//        cout << "\n1. Add a student.\n2.Update Student.\n3.Display InOrder.\n";
//        cin >> choice;
//        switch (choice) {
//        case 1:
//            cin >> tempStudentId;
//            tempStudentDepartment = database.setDepartment(tempStudentId);
//            database.addStudent(tempStudentId, tempStudentDepartment);
//            break;
//        case 2:
//            cin >> tempStudentId;
//            database.editStudent(tempStudentId);
//            break;
//        case 3:
//            database.displayInOrder();
//            break;
//        default:
//            end = true;
//            break;
//        }
//
//    }
//
//    return 0;
//}