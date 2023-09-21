//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//struct Employee_Node {
//	string name;
//	int hours;
//	int wage;
//	Employee_Node* next;
//	Employee_Node() {
//		name = "";
//		hours = 0;
//		wage = 0;
//		next = NULL;
//	}
//	Employee_Node(string Name, int Hours) {
//		name = Name;
//		hours = Hours;
//		wage = 0;
//		next = NULL;
//	}
//	void calculateWage() {
//		wage = hours * 50;
//	}
//};
//class Company {
//	Employee_Node* head;
//public:
//	Company() {
//		head = NULL;
//	}
//	void createEmployeeNodes() { // this function will get data from employees.txt and create nodes of every employee
//		ifstream fin("Employees.txt");
//		string tempname;
//		int temphour;
//		if (fin.is_open()) {
//			while (fin >> tempname >> temphour) {
//				Employee_Node* newNode = new Employee_Node;
//				newNode->hours = temphour;
//				newNode->name = tempname;
//				if (head == NULL) { // its mean there is no any existing node in runtime
//					head = newNode;
//				}
//				else {
//					Employee_Node* current = head;
//					while (current->next != NULL) {
//						current = current->next;
//					}
//					current->next = newNode;
//				}
//			}
//			
//		}
//		else {
//			cout << "\nFile cannot open.\n";
//		}
//	}
//	void safeEmployeeWages() {
//		ofstream fout("Wages.txt");
//		if (fout.is_open()) {
//			Employee_Node* current = head;
//			do
//			{
//				current->calculateWage(); // calculates wage of every employee
//				fout << current->name << " " << current->wage<<endl;
//				current = current->next;
//			} while (current != NULL);
//		}
//		else {
//			cout << "\nWages.txt Not found."<<endl;
//		}
//	}
//	void displayNodes() {
//		Employee_Node* temp = head;
//		do{
//			cout <<"NAME : " << temp->name << " Wage: " << temp->wage<<endl;
//			temp = temp->next;
//		} while (temp != NULL);
//	}
//
//};
//int main() {
//	Company temp;
//	temp.createEmployeeNodes();
//	temp.safeEmployeeWages();
//	temp.displayNodes();
//	return 0;
//}