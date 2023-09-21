#include<iostream>
using namespace std;
int main() {
	int size = 6;
	int* arr = new int[size];
	cout << "Enter ELements in array :\n";
	for (int i = 0; i < size; i++)
	{
		cin >> *(arr+i);
	}
	cout << endl;
	// display orignal array 
	cout << "Orignal Array :\n";
	for (int i = 0; i < size; i++)
	{
		cout<< *(arr+i)<<"   ";
	}
	cout << endl;
	int middle = size / 2;
	// ascending order sorting before middle
	for (int i = 0; i < middle; i++)
	{
		for (int j = i+1; j < middle; j++)
		{
			if (*(arr + i) > *(arr + j)) {

				int temp = *(arr + i);
				*(arr+i) = *(arr + j);
				*(arr+j) = temp;
			}
		}
	}
	// descending order sorting after middle
	for (int i = middle; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(arr + i) < *(arr + j)) {

				int temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
	cout << "Sorted array :\n";
	for (int i = 0; i < size; i++)
	{
		cout << *(arr+i)<<"   ";
	}
	// now update array using formula x*(i+1) * (i-1)
	int minIndex = 0, maxIndex = size-1;
	int* tempArr = new int[size];
	// copy elements of old array in temp array
	for (int i = 0; i < size; i++)
	{
		*(tempArr + i) = *(arr + i);
	}
	for (int i = 0; i < size; i++)
	{
		if (i == minIndex) {
			*(tempArr + i) = *(arr + i) * *(arr + maxIndex) * *(arr+i+1);
		}
		else if (i == maxIndex) {
			*(tempArr + i) = *(arr + i) * *(arr + minIndex) * *(arr + i - 1);
		}
		else {
			*(tempArr + i) = *(arr + i) * *(arr + i-1) * *(arr + i + 1);
		}
	}
	delete[] arr; // deallocate old memory address of arr
	arr = tempArr; // allocate memory address of tempArr to arr
 	/// print the updated array
	cout << "\nUpdated Array :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i)<<"   ";
	}
	delete[] arr; // this will deallocate tempArr memory address as well as arr
	return 0;
}