//#include<iostream>
//#include<string>
//using namespace std;
//int counter = 0;// to calculate number of leaf nodes
//struct Node {
//    int id;
//    string playerName;
//    int score;
//    Node* left, * right;
//
//    Node() {
//        left = NULL;
//        right = NULL;
//        id = 0;
//        score = 0;
//        playerName = "";
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
//    void addPlayer(int id, string name, int score) {
//        Node* newNode = new Node;
//        newNode->id = id;
//        newNode->playerName = name;
//        newNode->score = score;
//        newNode->left = NULL;
//        newNode->right = NULL;
//        if (!root)
//            root = newNode; // if the tree is not created
//        else {
//            Node* cur = root;
//            while (true) {
//                if (score < cur->score) {
//                    if (cur->left) {
//                        cur = cur->left;
//                    }
//                    else {
//                        cur->left = newNode;
//                        return;
//                    }
//                }
//                else if (score > cur->score) {
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
//    void deleteNode(int id, Node*& newNode) {
//        if (newNode == NULL) {
//            cout << id << " Player not found\n";
//        }
//        else if (id < newNode->id) {
//            deleteNode(id, newNode->left);
//        }
//        else if (id > newNode->id) {
//            deleteNode(id, newNode->right);
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
//
// 
//    void updateScore(int playerID, int updatedScore) {
//
//        Node* cur = root;
//        Node* prev = NULL;
//
//        while (cur) {
//            if (playerID == cur->id) {
//                cout << "Player found .\n";
//                cur->score = updatedScore;
//                break;
//            }
//            prev = cur;
//            if (playerID < cur->id) {
//                cur = cur->left;
//            }
//            else {
//                cur = cur->right;
//            }
//        }
//
//        if (cur == nullptr) {
//            cout << "Player with ID " << playerID << " not found." << endl;
//            return;
//        }
//
//        if (prev) {
//            if (prev->left == cur) {
//                prev->left = nullptr;
//            }
//            else {
//                prev->right = nullptr;
//            }
//        }
//        else {
//            root = nullptr;
//        }
//
//        addPlayer(playerID, cur->playerName, updatedScore);
//    }
//
//
//    void getTopPlayers(Node* pointerNode, int& num) {
//        if (pointerNode != NULL && num > 0) {
//            getTopPlayers(pointerNode->right, num);
//            cout << "\nPlayer ID : " << pointerNode->id << endl;
//            cout << "Player Name : " << pointerNode->playerName << endl;
//            cout << "Player Score : " << pointerNode->score << endl;
//            num--;
//            getTopPlayers(pointerNode->left, num);
//        }
//    }
//
//    Node* getRootNode() {
//        return root;
//    }
//    void countLeafNodes(Node* node) {
//        if (node == nullptr) {
//            return ; 
//        }
//        if (node->left == nullptr && node->right == nullptr) {
//            counter++;
//        }
//       
//        countLeafNodes(node->left);
//        countLeafNodes(node->right);
//    }
//};
//int main() {
//    BST RankingSystem;
//    RankingSystem.addPlayer(1, "Player1", 100);
//    RankingSystem.addPlayer(2, "Player2", 30);
//    RankingSystem.addPlayer(3, "Player3", 190);
//    RankingSystem.addPlayer(4, "Player4", 95);
//    RankingSystem.countLeafNodes(RankingSystem.getRootNode());
//    cout <<"Number of leaf node :"<< counter;
//    return 0;
//}
