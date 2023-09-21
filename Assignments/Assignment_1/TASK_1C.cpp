//#include <iostream>
//using namespace std;
//
//class ArrayADT
//{
//private:
//    int* arr;
//    int size;
//    int evenIndex = 0, oddIndex = 1;
//public:
//    ArrayADT(int size)
//    {
//        arr = new int[size]; // creates an array of size dynamically
//        this->size = size;
//        for (int i = 0; i < size; i++)
//        {
//            cout << "\nEnter Element in index " << i + 1 << " : ";
//            cin >> arr[i];
//        }
//    }
//    int get(int index) // this function Get the element at a specific index and return to user.
//    {
//        if (index <= size && index > 0)
//        {
//            return arr[index - 1]; // this will return value in that array
//        }
//        else
//        {
//            cout << "\nYour given index doesn't exists in array." << endl;
//            return -1;
//        }
//    }
//    void insert(int index)
//    {
//        if (index <= size + 1 && index > 0)
//        {
//            int tempElement;
//            cout << "\nEnter Element To add in array :";
//            cin >> tempElement;
//            cout << "\n";
//            int* newArray = new int[size + 1];  // now create an array of size increased by one
//            for (int i = 0; i < index - 1; i++) // copy elements before insertation index
//            {
//                *(newArray + i) = *(arr + i);
//            }
//
//            newArray[index - 1] = tempElement;
//            for (int i = index; i <= size; i++)
//            {
//                *(newArray + i) = *(arr + i - 1); // copies elements of old array in new array after specified index
//            }
//            delete[] arr; // deallocate old array elements
//            size++;
//            arr = newArray;
//        }
//        else
//        {
//            cout << "\nYour given index doesn't exists in array." << endl;
//        }
//
//    }
//    void Delete(int index)
//    {
//        if (index <= size && index >= 0)
//        {
//            int* newArray = new int[size - 1];
//            for (int oldIndex = 0, newIndex = 0; oldIndex < index; oldIndex++, newIndex++)
//            {
//                if (oldIndex == index - 1)
//                {
//                    newIndex--;
//                }
//                else
//                {
//                    newArray[newIndex] = arr[oldIndex];
//                }
//            }
//            delete[] arr;
//            arr = newArray;
//            size--;
//        }
//        else {
//            cout << "\nIndex out of range, please enter valid index.";
//        }
//    }
//    int Size() // gets length of array
//    {
//        return size;
//    }
//    void Append()
//    {
//        cout << "\nEnter Element to append in array";
//        int tempElement = 0;
//        cin >> tempElement;
//        int* newArray = new int[size + 1];
//        for (int i = 0; i < size; i++)
//        {
//            newArray[i] = arr[i]; // fills new array with old array
//        }
//        newArray[size] = tempElement; // fill element at end of new array
//        delete[] arr; // de allocates old array
//        size++;
//        arr = newArray; // assign address of new array to old array
//    }
//    void Display() {
//        for (int i = 0; i < size; i++)
//        {
//            cout << arr[i] << "    ";
//        }
//    }
//    void EvenOddInput(int element) {
//        cout << "\n\"REMEMBER INDEX STARTS FROM 0\"\n";
//        if (element % 2 == 0) {
//            if (evenIndex >= size) {
//                cout << "\nEven Indexes are full.\n";
//                return;
//            }
//            arr[evenIndex] = element;
//            evenIndex += 2;
//        }
//        else {
//            if (oddIndex >= size) {
//                cout << "\nOdd Indexes are full.\n";
//                return;
//            }
//            arr[oddIndex] = element;
//            oddIndex += 2;
//        }
//    }
//    void printDivisors() {
//        for (int i = 0; i < size; i++)
//        {
//            cout << arr[i] << " : ";
//            for (int j = 1; j <= arr[i] / 2; j++) {
//                if (arr[i] % j == 0) {
//                    cout << j<<"   ";
//                }
//            }
//            cout << endl;
//        }
//    }
//};
//int main()
//{
//    int length;
//    cout << "Enter Length of array to create :";
//    cin >> length;
//    ArrayADT array(length);
//    int index = 0;
//    bool menu = true;
//    while (menu) {
//        cout << "\n1. Insert Element at specific index.\n";
//        cout << "2. Get Element from specific index.\n";
//        cout << "3. Delete Element of specific index.\n";
//        cout << "4. Append Element in array.\n";
//        cout << "5. Get size of array.\n";
//        cout << "6. Display array.\n";
//        cout << "7. EvenODD input.\n";
//        cout << "8. Print Divisors.\n";
//        cout << "9. Exit\n";
//        int choice = 0;
//        cin >> choice;
//        switch (choice)
//        {
//        case 1:
//            cout << "Enter Index :";
//            cin >> index;
//            cout << "\n";
//            array.insert(index);
//            break;
//
//        case 2:
//            cout << "Enter Index :";
//            cin >> index;
//            cout << "\n";
//            cout << "Your Element at index" << index << "   is : " << array.get(index) << endl;
//            break;
//
//        case 3:
//            cout << "Enter Index :";
//            cin >> index;
//            cout << "\n";
//            array.Delete(index);
//            break;
//
//        case 4:
//            array.Append();
//            break;
//
//        case 5:
//            cout << "Size of array : " << array.Size() << endl;
//            break;
//
//        case 6:
//            array.Display();
//            break;
//
//        case 7:
//            int tempNumber;
//            cout << "Enter Even/Odd number to enter in even/odd index :";
//            cin >> tempNumber;
//            array.EvenOddInput(tempNumber);
//            break;
//
//        case 8:
//            array.printDivisors();
//            break;
//
//        default:
//            cout << "Exiting\n";
//            menu = false;
//            break;
//        }
//    }
//    return 0;
//}