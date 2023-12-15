
#include<iostream>
using namespace std;

class HashClass {
	int size = 5;
	int* hashTable;
	int count = 0;
	int probingType = 0; // 0 fir linear 1 for quadratic and 2 for double hashing
public:
	HashClass(int Size , int proobingType) {
		size = Size;
		probingType = proobingType;
		hashTable = new int[size];
		for (int i = 0; i < size; i++) {
			hashTable[i] = -1;
		}
	};

	int hashFunc(int key) {
		return key % size;
	}

	int doubleHashing(int address) {
		int hash2 = 7 - (address % 7); // A secondary hash function
		return (address + hash2) % size;
	}

	void insert(int data) {
		if (loadFactor() > 0.7) { 
			//cout << "REHASHED" << endl;
			HashClass temp(size * 2, probingType);
			for (int i = 0; i < size; i++)
			{
				temp.insert(hashTable[i]);
			}
			temp.insert(data);
			delete[] hashTable;
			this->hashTable = temp.hashTable;
			this->size = temp.size;
			this->count = temp.count;
		}
		else if (count < size) {
			++count;
			if (probingType == 0) { // linear
			int address = hashFunc(data);
			while (hashTable[address] != -1) {
				address = (address + 1) % size;
			}
			hashTable[address] = data;
			}
			else if (probingType == 1) { // quadratic
				int address = hashFunc(data);
				int i = 1;
				while (hashTable[address] != -1) {
					address = (address + i*i) % size;
					i++;
				}
				hashTable[address] = data;
			}
			else if (probingType == 2) { // double hashing
				int address = doubleHashing(data);
				while (hashTable[address] != -1) {
					address = (address + 1) % size;
				}
				hashTable[address] = data;
			}
		}

	}
	int* getAddress() {
		return hashTable;
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

	double loadFactor() {
		return static_cast<double>(count / size);
	}
	void deleteData(int data) {
		int address = hashFunc(data);
		while (hashTable[address] != -1) {
			if (hashTable[address] == data) {
				hashTable[address] = -2;
			}
			address = (address + 1) % size;
		}
	}
	void displayAll() {
		for (int i = 0; i < size; i++)
		{
			cout << "  " << hashTable[i];
		}
	}
};

int main() {
	HashClass linear_table(15, 0);
	HashClass quad_table(15, 1);
	HashClass double_table(15, 2);
	int keys[16] = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };
	for (int i = 0; i < 16; i++)
	{
		linear_table.insert(keys[i]);
		quad_table.insert(keys[i]);
		double_table.insert(keys[i]);
	}

	cout << "\nDATA IN LINEAR HASHTABLE :\n";
	linear_table.displayAll();
	cout << "\nDATA IN QUAD HASHTABLE :\n";
	quad_table.displayAll();
	cout << "\nDATA IN DOUBLE HASHTABLE :\n";
	double_table.displayAll();
	cout << endl;
	system("pause");
	return 0;
}