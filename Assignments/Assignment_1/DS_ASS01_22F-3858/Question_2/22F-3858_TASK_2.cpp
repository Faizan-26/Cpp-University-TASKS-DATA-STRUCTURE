//#include<iostream>
//using namespace std;
//class Array {
//private:
//	int * arr;
//	int size=0;
//	int numItems;
//public:
//	Array() { // default constructor
//		numItems = -1;
//		cout << "\nEnter Size of an array :";
//		while (size <= 0)
//		{
//			cin >> size;
//			if (size > 0) {
//				arr = new int[size];
//				cout << "\nInitialize Your array :";
//				for (int i = 0; i < size; i++)
//				{
//					cin >> arr[i];
//					numItems++;
//				}
//				cout << endl;
//			}
//			else {
//				cout << "\nSize must be greater then 0.\n";
//			}
//		}
//	
//	}
//	Array(int Size) { // parameterized constructor
//		numItems = -1;
//		while (Size <= 0)
//		{
//			cin >> Size;
//			if (size > 0) {
//				arr = new int[Size];
//				size = Size;
//				cout << "\nInitialize Your array :";
//				for (int i = 0; i < size; i++)
//				{
//					cin >> arr[i];
//					numItems++;
//				}
//				cout << endl;
//			}
//			else {
//				cout << "\nSize must be greater then 0.\n";
//				cin >> size;
//			}
//		}
//		
//	}
//	Array(const Array& other) // copy constructor
//	{
//		size = other.size;
//		arr = new int[size];
//		numItems = other.numItems;
//		for (int i = 0; i < size; i++)
//		{
//			arr[i] = other.arr[i];
//		}
//	}
//	
//	bool isEmpty() {
//		return (numItems == -1);
//	}
//	bool isFull() {
//		return (numItems == size - 1);
//	}
//	int length() {
//		return size;
//	}
//	void printList() {
//		if (isEmpty()) {
//			cout << "\nList is empty, please enter some data\n";
//			return;
//		}
//		else {
//			cout << "\nElements is array :";
//			for (int i = 0; i < size; i++)
//			{
//				cout << *(arr+i)<<"  ";
//			}
//			cout << endl;
//		}
//	}
//	int searchElementLinear(int X) { //Linear Search
//		bool found = false;
//		if (isEmpty()) {
//			cout << "\nList is empty, please enter some data\n";
//			return -1;
//		}
//		else {
//			for (int i = 0; i < size; i++)
//			{
//				if (arr[i] == X) {
//					found = true;
//					return i; // returns element index location of dynamic array
//				}
//			}
//		}
//		if (!found) {
//			cout << "\nElement cannot be found please enter other value.\n";
//			return -1;
//		}
//	}
//	int searchElementBinary(int X) { // binary Search 
//		// first sort array  for binary search
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = 0; j < size; j++) {
//				if (arr[i] < arr[j]) {
//					int temp = arr[i];
//					arr[i] = arr[j];
//					arr[j] = temp;
//				}
//			}
//		}
//		cout << "After Sorting :";
//		printList();
//
//		// now apply binary search
//		int start = 0, end = size - 1;
//		int middle = 0;
//		while (start <= end) {
//			middle = (start + end) / 2;
//			if (arr[middle] == X) {
//				return middle;
//			}
//			else if(arr[middle] > X) {
//				end = middle - 1;
//			}
//			else if (arr[middle] < X) {
//				start = middle + 1;
//			}
//		}
//		return -1;
//	}
//	void insertElementAt(int value, int pos) {
//		bool found = false;
//		if (isEmpty()) {
//			cout << "\nList is empty, please enter some data\n";
//			return;
//		}
//		else {
//			if (pos < 0 || pos >= size) {
//				cout << "\nPlease enter valid position";
//				cout << endl;
//				return;
//			}
//			int* tempArr = new int[size + 1];
//			for (int i = 0; i < pos; i++) // copies before pos
//			{
//				tempArr[i] = arr[i];
//			}
//			tempArr[pos] = value;// stores value at specific pos given by user
//			for (int i = pos+1; i <= size; i++) 
//			{
//				tempArr[i] = arr[i-1];
//			}
//			delete[] arr;
//			size++;
//			numItems++;
//			arr = tempArr;
//		}
//	}
//	bool deleteElement(int X) {
//		bool found = false;
//		if (isEmpty()) {
//			cout << "\nList is empty, please enter some data\n";
//			return false;
//		}
//
//		int findIndex = searchElementLinear(X); // search element and return index of that element
//		if (findIndex >= 0 || findIndex < size) { // deletes element at find index
//			for (int i = findIndex; i < size-1; i++)
//			{
//				arr[i] = arr[i + 1];
//			}
//			size--;
//			numItems--;
//		}
//	}
//	void reverseList() {
//		int start = 0;
//		int end = size - 1;
//		int tempElement; // for swaping
//		for (int i = 0; i < size/2; i++)
//		{
//			tempElement = arr[start]; // swap start with end
//			arr[start] = arr[end];
//			arr[end] = tempElement;
//			start++;
//			end--;
//		}
//	}
//	void copyList(const Array& other) {
//		numItems = other.numItems;
//		size = other.size;
//		for (int i = 0; i < size; i++)
//		{
//			arr[i] = other.arr[i];
//		}
//	}
//	void emptyList() {
//		numItems = -1;
//		size = 0;
//	}
//	~Array() {
//		emptyList();
//		delete[] arr;
//	}
//};
//
//void menu(int & choice) {
//	cout << "\n1. Print List"<<endl
//		<<"2. Linear Search"
//		<< endl << "3. Binary Search"
//		<< endl << "4. Insert At index"
//		<< endl << "5. Delete" 
//		<< endl <<"6. Check Full"
//		<< endl << "7. Check Empty"
//		<< endl << "8. Length"
//		<< endl << "9. Reverse"
//		<< endl << "10. Empty List"
//		<< endl <<"11. Copy From Another List"
//		<< endl << "12. Exit"
//		<< endl << "\nEnter choice: ";
//	cin >> choice;
//}
//int main() {
//	int choice = 0;
//	int element = 0; int position = 0;
//	Array temp;
//	while (1) {
//		menu(choice);
//		switch (choice) {
//		case 1:
//			temp.printList();
//			break;
//		case 2:
//			cout<< "Enter element to search: ";
//			cin >> element;
//			position = temp.searchElementLinear(element);
//			if (position == -1) { 
//				cout << "Element not found please enter another element.\n"; 
//			}
//			else cout << "Element found at index " << position << "."<<endl;
//			break;
//		case 3:
//			cout << "Enter element to search (binary): ";
//			cin >> element;
//			position = temp.searchElementBinary(element);
//			if (position == -1) cout << "Element not found please enter another element.\n";
//			else cout << "Element found at index " << position << ".\n";
//			break;
//		case 4:
//			cout << "\nEnter element: ";
//			cin >> element;
//			cout << "\nEnter position: ";
//			cin >> position;
//			temp.insertElementAt(element, position);
//			break;
//		case 5:
//			cout << "Enter element to delete: ";
//			cin >> element;
//			temp.deleteElement(element);
//			break;
//		case 6:
//			if (temp.isFull()) { 
//				cout << "List is full.\n";
//			}
//			else { cout << "List contains some elements full.\n"; }
//			break;
//		case 7:
//			if (temp.isEmpty()) {
//				cout << "List is empty.\n";
//			}
//			else cout << "List constains some elements\n";
//			break;
//		case 8:
//			cout << "Length of list: " << temp.length() << ".\n";
//			break;
//		case 9:
//			temp.reverseList();
//			cout << "\n List reversed.\n";
//			break;
//		case 10:
//			temp.emptyList();
//			cout << "\n List is now empty.\n";
//			break;
//		case 11:
//		{
//			Array otherArr;
//			cout << "Data in new Arr :";
//			otherArr.printList();
//			cout << "\n Copying data of new Array in old array.\n";
//			temp.copyList(otherArr);
//		}
//		break;
//		case 12:
//			return 0;
//		default:
//			cout << "Invalid choice. Try again.\n";
//		}
//		}
//	return 0;
//}
