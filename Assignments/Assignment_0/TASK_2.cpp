//#include<iostream>
//using namespace std;
//int main() {
//    const int size = 10;
//    int arr[size];
//    int* ptr = arr; 
//
//    cout << "\nEnter elements in your array :" << endl;
//    for (int i = 0; i < size; ++i) {
//        cin >> *(ptr + i);
//    }
//
//    cout << "\nOriginal array elements :" << endl;
//    for (int i = 0; i < size; ++i) {
//        cout << *(ptr + i) << "   ";
//    }
//
//    cout << "\nElements having at least two elements greater that that:" << endl;
//    for (int i = 0; i < size; ++i) {
//        int count = 0;
//        for (int j = 0; j < size; ++j) {
//            if (*(ptr + j) > *(ptr + i)) {
//                count++;
//            }
//        }
//        if (count >= 2) {
//            cout << *(ptr + i) << " ";
//        }
//    }
//
//    return 0;
//}
