//#include<iostream>
//using namespace std;
//struct studentDatabase {
//    string name= "";
//    int id = 0;
//    double gpa = 0;
//};
//void menu() {
//    cout << "\n1. Add Student.\n";
//    cout << "\n2. Delete Student.\n";
//    cout << "\n3. Search Student.\n";
//    cout << "\n4. Display Student.\n";
//    cout << "\n5. Exit.";
//    cout << "\nEnter your choice :";
//}
//void searchStudent(studentDatabase*& students, int size) {
//    bool found = false;
//    int tempId;
//    cout << "Enter id to search student :";
//    cin >> tempId;
//    for (int count = 0; count < size; count++)
//    {
//        if ((*(students + count)).id == tempId && students) {
//        cout << "\nName : " << (*(students + count)).name;
//        cout << "\nId : " << (*(students + count)).id;
//        cout << "\nGpa : " << (*(students + count)).gpa;
//        found = true;
//        }
//    }
//    if (!found) {
//        cout << "\nStudent with given id not found!\n";
//    }
//}
//void AddStudent(studentDatabase*& students, int& size) {
//    studentDatabase* tempStudent = new studentDatabase[size + 1];
//    int count = 0;
//    // copy old data from students in new Student;
//    for (count = 0; count < size; count++)
//    {
//        tempStudent[count].id = students[count].id;
//        tempStudent[count].name = students[count].name;
//        tempStudent[count].gpa = students[count].gpa;
//    }
//    // as size of tempStudent is more then older so
//    cout << "\nEnter Student name :";
//    cin >> (*(tempStudent + count)).name;
//    cout << "\nEnter Student ID :";
//    cin >> (*(tempStudent + count)).id;
//    cout << "\nEnter Student GPA :";
//    cin >> (*(tempStudent + count)).gpa;
//    // a new student is added now delete old
//    delete[] students;
//    students = tempStudent; // re assign to new created 
//    size++;
//}
//void deleteStudent(studentDatabase*& students, int& size) {
//    studentDatabase* tempStudent = new studentDatabase[size -1];
//    cout << "Enter Id of student to delete :";
//    int tempId;
//    cin >> tempId;
//    bool found = false;
//    for (int count = 0, i=0; count < size; count++, i++)
//    {
//        if ((*(students + count)).id == tempId && students){
//            count++;
//            (*(tempStudent + i)).name = (*(students + count)).name;
//            (*(tempStudent + i)).id = (*(students + count)).id;
//            (*(tempStudent + i)).gpa = (*(students + count)).gpa;
//            found = true;
//        }
//    }
//    if (found) {
//        cout << "Students Deleted.";
//    }
//    // as size of tempStudent is more then older so
//    // a new student is added now delete old
//    delete[] students;
//    students = tempStudent; // re assign to new created 
//    size--;
//}
//void displayStudents(studentDatabase* students, int size) {
//    for (int i = 0; i < size; i++)
//    {
//        cout << "\nName: "<< (*(students + i)).name;
//        cout << "\nId: " << (*(students + i)).id;
//        cout << "\nGpa: " << (*(students + i)).gpa;
//        cout << endl;
//    }
//}
//int main() {
//	int size = 0;
//	studentDatabase* students = new studentDatabase[size];
//	int choice = 0;
//	while (choice >= 0) {
//		menu();
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//            AddStudent(students, size);
//			break;
//		case 2:
//            deleteStudent(students, size);
//			break;
//		case 3:
//            searchStudent(students, size);
//            break;
//        case 4:
//            displayStudents(students, size);
//			break;
//		default:
//			choice = -1;
//			break;
//		}
//	}
//	return 0;
//}