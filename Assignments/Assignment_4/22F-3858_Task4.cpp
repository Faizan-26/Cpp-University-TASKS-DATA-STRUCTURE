//#include <iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//	Node(int key) : data(key), next(NULL) {}
//};
//
//class HashTable {
//	static const int size = 15;
//	Node* hashtable[size];
//
//
//public:
//	HashTable() {
//		for (int i = 0; i < size; ++i) {
//			hashtable[i] = NULL;
//		}
//	}
//
//	int hashFunc(int key) {
//		return key % size;
//	}
//
//	void insert(int key) {
//		int index = hashFunc(key);
//		Node* newNode = new Node(key);
//
//		if (hashtable[index] == NULL) {
//			hashtable[index] = newNode;
//		}
//		else {
//			newNode->next = hashtable[index];// insert at start
//			hashtable[index] = newNode;
//		}
//	}
//
//	bool search(int key) {
//		int index = hashFunc(key);
//		Node* cur = hashtable[index];
//
//		while (cur != NULL) {
//			if (cur->data == key) {
//				return true;
//			}
//			cur = cur->next;
//		}
//		return false;
//	}
//
//	void deleteVal(int key) {
//		int index = hashFunc(key);
//		Node* cur = hashtable[index];
//		Node* prev = NULL;// for deleting 1st node
//
//		while (cur != NULL && cur->data != key) {
//			prev = cur;
//			cur = cur->next;
//		}
//
//		if (cur != NULL) {
//			if (prev == NULL) { // for deleting 1st node
//				hashtable[index] = cur->next;
//			}
//			else {
//				prev->next = cur->next;
//			}
//			delete cur;
//		}
//	}
//
//	void displayALL() {
//		int i = 0;
//		cout << "\n Data in Chainigng hashtable :\n";
//		for (int i = 0; i < size; i++)
//		{
//			Node* temp = hashtable[i];
//			while (temp != NULL) {
//				cout << "  " << temp->data;
//				temp = temp->next;
//			}
//			cout << endl;
//		}
//	}
//};
//const int BUCKET_SIZE = 3;
//
//class BucketHashTable {
//    int size;
//    int count; // count number of items
//    int** hashtables;
//
//public:
//    BucketHashTable(int S) : size(S) {
//        count = 0;
//        hashtables = new int* [size];
//        for (int i = 0; i < size; i++) {
//            hashtables[i] = new int[BUCKET_SIZE];
//            for (int j = 0; j < BUCKET_SIZE; j++) {
//                hashtables[i][j] = -1;
//            }
//        }
//    }
//
//    int hashFunc(int key) {
//        return key % size;
//    }
//
//    double loadFactor() {
//        return static_cast<double>(count) / size;
//    }
//
//    void insert(int data) {
//        if (loadFactor() > 0.7) {
//            rehash(data);
//        }
//		else {
//        int index = hashFunc(data) % size;
//        int bucketIndex = -1;
//
//        for (int i = 0; i < BUCKET_SIZE; ++i) {
//            if (hashtables[index][i] == -1) {
//                bucketIndex = i;
//                break;
//            }
//        }
//        if (bucketIndex != -1) {
//            hashtables[index][bucketIndex] = data;
//            count++;
//        }
//		}
//    }
//
//    void rehash(int data) {
//		BucketHashTable temp(size * 2);
//
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < BUCKET_SIZE; j++) {
//				int tempValue = hashtables[i][j];
//				if (tempValue != -1) {
//				temp.insert(tempValue);
//				}
//			}
//		}
//		temp.insert(data);
//		delete[] hashtables;
//		this->hashtables = temp.hashtables;
//		this->count = temp.count;
//		this->size = temp.size;
//    }
//
//    void displayALL() {
//        cout << "\nData in Bucketing Hashtable :\n";
//        for (int i = 0; i < size; i++) {
//            cout << "Bucket " << i + 1 << ": ";
//            for (int j = 0; j < BUCKET_SIZE; ++j) {
//                if (hashtables[i][j] != -1) {
//                    cout << "  " << hashtables[i][j];
//                }
//            }
//            cout << endl;
//        }
//    }
//};
//
//int main() {
//	HashTable table;
//	BucketHashTable bucket(15);
//	int keys[16] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
//		for (int i = 0; i < 16; i++)
//		{
//			table.insert(keys[i]);
//			bucket.insert(keys[i]);
//		}
//		
//	table.displayALL();
//	bucket.displayALL();
//	system("pause");
//	return 0;
//}