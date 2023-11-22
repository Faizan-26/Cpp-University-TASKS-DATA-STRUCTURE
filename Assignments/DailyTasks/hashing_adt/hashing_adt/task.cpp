#include<iostream>
using namespace std;


class HashClass{
	static const int size = 200;
	int hashTable[size];
public:
	HashClass() {
		for (int i = 0; i < size; i++) {
			hashTable[i] = -1;
		}
	};

	int hashFunc(int key) {
		return key % size;
	}

	void insert(int data) {
		int address = hashFunc(data);
		// to avoid collisions
		while (hashTable[address] != -1) {
			address = (address + 1) % size;
		}

		hashTable[address] = data;
	}

	bool search(int data) {
		int address = hashFunc(data);
		while (hashTable[address] != -1) {
			if (hashTable[address] == data) {
				return true;
			}
			address = (address + 1) % size;
		}
		return false;
	}

	void deleteData(int data) {
		int address = hashFunc(data);
		while (hashTable[address] != -1) {
			if (hashTable[address] == data) {
				hashTable[address] = -1;
			}
			address = (address + 1) % size;
		}
	}
};