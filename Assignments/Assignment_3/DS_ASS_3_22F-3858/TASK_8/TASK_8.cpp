#include <iostream>
#include <string>
using namespace std;



struct AvlNode {
    string songName;
    int frequency;
    AvlNode* left;
    AvlNode* next;
    AvlNode* right;
    int height;

    AvlNode(int songFreq, string Sname) :next(NULL),  left(NULL), right(NULL), height(0), songName(Sname), frequency(songFreq) {
    }
};


class AVLTree {
private:
    AvlNode* root;

    int height(AvlNode* N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

    AvlNode* rightRotate(AvlNode* y) {
        AvlNode* x = y->left;
        AvlNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    AvlNode* leftRotate(AvlNode* x) {
        AvlNode* y = x->right;
        AvlNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    int getBalance(AvlNode* N) {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    AvlNode* insert(AvlNode* node, string songName, int frequency) {
        if (node == NULL) {
            return new AvlNode(frequency, songName);
        }

        if (songName == node->songName) {
            AvlNode* newListNode = new AvlNode(frequency, songName);
            newListNode->next = node->next;// insert at start
            node->next = newListNode;
            return node; // No need to further insert in the tree since it's a duplicate
        }

        if (frequency < node->frequency) {
            node->left = insert(node->left, songName, frequency);
        }
        else {
            node->right = insert(node->right, songName, frequency);
        }

        // Balance the tree after insertion
        int balance = getBalance(node);

        if (balance > 1 && songName < node->left->songName) {
            return rightRotate(node);
        }
        else if (balance < -1 && songName > node->right->songName) {
            return leftRotate(node);
        }
        else if (balance > 1 && songName > node->left->songName) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        else if (balance < -1 && songName < node->right->songName) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        return node;
    }

    void inOrderdisplay(AvlNode* node) {
        if (node == NULL) {
            return;
        }

        inOrderdisplay(node->left);

        cout << "Song Name: " << node->songName << " | Frequency: " << node->frequency << endl;
        AvlNode* current = node->next;
        while (current != NULL) {
            cout << "Song Name: " << current->songName << " | Frequency: " << current->frequency << endl;
            current = current->next;
        }

        inOrderdisplay(node->right);
    }

public:
    AVLTree() : root(NULL) {}

    void addSong(string songName, int freq) {
        root = insert(root, songName, freq);
    }

    
    void menu() {
        cout << "\n1. Add Song.\n2. Play Song.\n3.Quit\n";
    }
    void display() {
        inOrderdisplay(root);
    }

    AvlNode* findNode(AvlNode* cur, int songFreq) {
        while (cur) {
            if (songFreq < cur->frequency) {
                cur = cur->left;
            }
            else if (songFreq > cur->frequency){
                cur = cur->right;
            }
            else {
                return cur;
            }
        }
        return NULL;
    }
    
    AvlNode* minValueNode(AvlNode* node) {
        AvlNode* current = node;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    AvlNode* deleteNode(AvlNode* cur, string songName, int frequency) {
        if (cur == NULL) {
            return cur;
        }

        if (songName < cur->songName) {
            cur->left = deleteNode(cur->left, songName, frequency);
        }
        else if (songName > cur->songName) {
            cur->right = deleteNode(cur->right, songName, frequency);
        }
        else {
            if (cur->next != NULL) {
                // If the node has a linked list, just remove the specific song
                AvlNode* temp = cur->next;
                AvlNode* prev = NULL;

                while (temp != NULL && temp->songName != songName) {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp != NULL) {
                    if (prev == NULL) {
                        cur->next = temp->next;
                        delete temp;
                    }
                    else {
                        prev->next = temp->next;
                        delete temp;
                    }
                }
            }
            else {
                if ((cur->left == NULL) || (cur->right == NULL)) {
                    AvlNode* temp; // initially NULL
                    if (root->left != NULL) {
                        temp = root->left;
                    }
                    else {
                        temp = root->right;
                    }

                    if (temp == NULL) { // deletion for two childrens 
                        temp = root;
                        root = NULL;
                    }
                    else {
                        *root = *temp;
                    }
                    delete temp;
                }
                else {
                    AvlNode* temp = minValueNode(root->right);

                    root->songName = temp->songName;
                    root->frequency = temp->frequency;

                    root->right = deleteNode(root->right, temp->songName, temp->frequency);
                }
            }
        }

        if (root == NULL) {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }
        else if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        else if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
        else if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }


    void play(string SongName, int freq) {
        if (playSong(root, SongName, freq)) {
            cout << "\nSong Played.\n";
        }
        else {
            cout << "\nSong not found.\n";
        }
    }
    bool playSong(AvlNode* cur, string SongName, int freq) {
        AvlNode* NodeList = findNode(cur, freq); // return a node having same frequncy
        if (NodeList == NULL) { // if NodeList is null return false
            return false;
        }
        // now check if list have songName
        bool hasSong = false;
        int count = 0; // for counting number of nodes
        while (NodeList->next != NULL) {
            count++;
            if (NodeList->songName == SongName) {
                hasSong = true;
                break;
            }
            NodeList = NodeList->next;
        }
        if (hasSong) {
            // now we found song its time to delete from its old place and insert having frequency added by 1
            if (count == 0) { // means there is only 1 node , we need to delete from tree not from linked list
                int tempfreq = NodeList->frequency;
                string tempSname = NodeList->songName;
                deleteNode(NodeList, tempSname, tempfreq);
                addSong(tempSname, tempfreq);
           }
            else { // delete from linked list
                if (NodeList->next == NULL) {// if NodeList is end of linked List node
                    int tempfreq = NodeList->frequency;
                    string tempSname = NodeList->songName;
                    delete NodeList;
                    addSong(tempSname, ++tempfreq); // increment frequency by 1
                }
                else { // if NodeList is in middle
                    AvlNode* deletedNode = NodeList;
                    int tempfreq = NodeList->frequency;
                    string tempSname = NodeList->songName;
                    NodeList = NodeList->next;
                    delete deletedNode;
                    addSong(tempSname, ++tempfreq); // increment frequency by 1
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
};



int main() {
    AVLTree playList;
    int choice = 0;
    int tempFrequence = 0;
    string tempSongName= "";
    while (choice >= 0) {
        playList.menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter Song name :";
            cin >> tempSongName;
            cout << "\nEnter Song Frequency :";
            cin >> tempFrequence;
            playList.addSong(tempSongName, tempFrequence);
            cout << endl;
            playList.display();
            break;
        case 2:
            cout << "\nEnter Song name to play:";
            cin >> tempSongName;
            cout << "\nEnter Song Frequency to play :";
            cin >> tempFrequence;
            playList.play(tempSongName, tempFrequence);
            cout << endl;
            playList.display();
            break;
        default:
            return 0;
        }
    }
    
    return 0;
}

