#include<iostream>
#include<string>
using namespace std;
struct Product {
	int id = 0;
	string name = " ";
	int quantity = 0;
};
void menu() {
	cout << "\n1. Add new product.\n";
	cout << "\n2. Remove a product.\n";
	cout << "\n3. Display inventory.\n";
}
void addToInventory(Product*& arr, int& size) {
	Product* newarray = new Product[size + 1];
	for (int i = 0; i < size; i++) // copying old array
	{
		newarray[i].id = arr[i].id;
		newarray[i].name = arr[i].name;
		newarray[i].quantity = arr[i].quantity;
	}
	cout << "\n Enter Id of your product " << " : ";
	cin >> newarray[size].id;
	cout << "\n Enter name of your product " << " : ";
	cin >> newarray[size].name;
	cout << "\n Enter quantity of your product " << " : ";
	cin >> newarray[size].quantity;
	delete[] arr;
	arr = newarray;
	size++;
}
void deleteFromInventory(int& size, Product*& arr) { // Product*& arr this becomes pointer of type product that points to array
	Product* newarray = new Product[size - 1];
	cout << "\nEnter Id to delete Product :" << endl;
	int id;
	cin >> id;
	bool found = false;
	for (int i = 0, j = 0; i < size && j <= size - 1; i++, j++)
	{
		if (id == arr[i].id) {
			j--;
			found = true;
			continue;
		}
		else {
			newarray[j].id = arr[i].id;
			newarray[j].name = arr[i].name;
			newarray[j].quantity = arr[i].quantity;
		}
	}
	if (found) {
		cout << "\nDeleted.\n";
		delete[] arr;
		arr = newarray;
		size--;
	}
	else {
		delete[] newarray;
		cout << "Product with ID " << id << " not found.\n";
	}
}
void displayInventory(Product* array, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "Id :" << array[i].id << endl;
		cout << "Name :" << array[i].name << endl;
		cout << "Quantity :" << array[i].quantity << endl;
	}
}
int main() {
	int size = 0;
	cout << "Enter Size of your inventory :";
	cin >> size;
	Product* array = new Product[size];
	for (int i = 0; i < size; i++)
	{
		cout << "\n Enter Id of your product " << i + 1 << " : ";
		cin >> array[i].id;
		cout << "\n Enter name of your product " << i + 1 << " : ";
		cin >> array[i].name;
		cout << "\n Enter quantity of your product " << i + 1 << " : ";
		cin >> array[i].quantity;
	}
	int choice = 0;
	while (1) {
		menu();
		cin >> choice;
		if (choice == 1) {
			addToInventory(array, size);
		}
		else if (choice == 2) {
			deleteFromInventory(size, array);
		}
		else if (choice == 3) {
			displayInventory(array, size);
		}
		else {
			break;
		}
	}
	delete[] array; 
	return 0; 
}
