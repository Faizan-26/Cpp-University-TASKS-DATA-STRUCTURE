#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int key) : data(key), next(NULL) {}
};

class HashTable {
    static const int TABLE_SIZE = 100;
    Node* table[TABLE_SIZE];


public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = NULL;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* cur = table[index];

        while (cur != nullptr) {
            if (cur->data == key) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* cur = table[index];
        Node* prev = nullptr;

        // Traverse the linked list to find the key
        while (cur != nullptr && cur->data != key) {
            prev = cur;
            cur = cur->next;
        }

        // If the key is found, remove the node
        if (cur != nullptr) {
            if (prev == nullptr) {
                // If the key is in the first node
                table[index] = cur->next;
            }
            else {
                // If the key is in a middle or last node
                prev->next = cur->next;
            }
            delete cur;
        }
    }

    // Destructor to free memory
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* cur = table[i];
            while (cur != nullptr) {
                Node* next = cur->next;
                delete cur;
                cur = next;
            }
        }
    }
};

int main() {
      return 0;
}
