//#include<iostream>
//using namespace std;
//
//struct Student {
//	string name = "";
//	int id = 0;
//	float gpa = 0.00;
//};
//class Student_Record {
//private :
//	int size;
//	Student* records;
//public:
//	Student_Record() {
//		records = NULL;
//		size = 0;
//	}
//	void Initialize_Records() {
//		cout << "\nEnter Number of Student records:";
//		cin >> size;
//		records = new Student[size];
//		for (int i = 0; i < size; i++)
//		{
//			cout << "\nEnter " << i+1 << " Student Record : \n";
//			cout << "\n Enter Name of Student: ";
//			cin >> (*(records+i)).name;
//			cout << "\n Enter id of Student: ";
//			cin >> (*(records+i)).id;
//			cout << "\n Enter Gpa of Student: ";
//			cin >> (*(records + i)).gpa;
//		}
//		cout << "\n Records initialized for " << size << " students" << endl;
//	}
//	void add_Record() {
//		size++;
//		Student tempStudent;
//		cout << "\nEnter Student's Name : ";
//		cin >> tempStudent.name;
//		cout << "\nEnter Student's id : ";
//		cin >> tempStudent.id;
//		cout << "\nEnter Student's gpa : ";
//		cin >> tempStudent.gpa;
//		Student* newRecord = new Student[size];
//		for (int i = 0; i < size-1; i++) // copying old record
//		{
//			*(newRecord + i) = *(records + i);
//		}
//		*(newRecord + size-1) = tempStudent;
//		delete[] records; // de allocate old address of record
//		records = newRecord; // allocate new address of record
//	}
//	void update_GPA() {
//		cout << "\nEnter id of student to update GPA: ";
//		
//		int tempid = 0;
//		cin >> tempid;
//		bool idFound = false;
//		for (int i = 0; i < size && !idFound; i++)
//		{
//			if ((*(records + i)).id == tempid) {
//				idFound = true;
//				cout << "\n Enter updated gpa : ";
//				cin >> (*(records + i)).gpa;
//			}
//		}
//		if (idFound) {
//			cout << "\n GPA of student was updated.\n";
//		}
//		else {
//			cout << "\n Cannot find Student with this id.\n";
//		}
//	}
//	void Display_All_Records() {
//		for (int i = 0; i < size; i++)
//		{
//			cout << "\nName : " << (*(records+i)).name;
//			cout << "\tId : " << (*(records+i)).id;
//			cout << "\tGpa : " << (*(records + i)).gpa << endl;
//		}
//	}
//	void Display_Highest_GPA() {
//		int maxGpa = 0;
//		for (int i = 0; i < size; i++)
//		{
//			if ((*(records)).gpa > maxGpa) {
//				maxGpa = (*(records)).gpa;
//			}
//		}
//		cout << "\nMax Gpa :"<<maxGpa;
//	}
//};
//void displayMenu() {
//	cout << "\n1. Initialize Records\n";
//	cout << "2. Add Record.\n";
//	cout << "3. Update Gpa.\n";
//	cout << "4. Display All Records.\n";
//	cout << "5. Display Highest Gpa.\n";
//	cout << "6. Exit";
//}
//int main() {
//	cout << "------ STUDENT RECORD MANAGMENT SYSTEM ------\n";
//	int choice = 0;
//	int size = 0;
//	Student_Record Students;
//	while (choice!=6) {
//		displayMenu();
//		cout << "\n\n Enter your choice: ";
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			Students.Initialize_Records();
//			break;
//		case 2:
//			Students.add_Record();
//			break;
//		case 3:
//			Students.update_GPA();
//			break;
//		case 4:
//			Students.Display_All_Records();
//			break;
//		case 5:
//			Students.Display_Highest_GPA();
//			break;
//		case 6:
//			break;
//		default:
//			cout << "\nInvalid Choice.\n";
//		}
//	}
//	return 0;
//}