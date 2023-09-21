//#include<iostream>
//#include<fstream>
//using namespace std;
//struct PolynomialNode {
//	int coefficient;
//	int pwr;
//	PolynomialNode* next;
//	PolynomialNode() {
//		coefficient = 0;
//		pwr = 0;
//		next = NULL;
//	}
//	PolynomialNode(int coeff, int PWR ) {
//		coefficient = coeff;
//		pwr = PWR;
//		next = NULL;
//	}
//};
//class PolyNomial {
//private:
//	PolynomialNode * head;
//public:
//	PolyNomial() {
//		head = NULL;
//	}
//	bool isEmpty() {
//		return (head == NULL);
//	}
//	void addNode(int coeff, int pwr) {
//		PolynomialNode* newNode = new PolynomialNode(coeff, pwr);
//		if (isEmpty()) {
//			head = newNode;
//			return;
//		}
//		PolynomialNode* cur = head;
//		while (cur->next != NULL) {
//			cur = cur->next;
//		}
//		cur->next =newNode;
//	}
//	void importFromFile(string filename) {
//		ifstream fin(filename);
//		if (fin.is_open()) {
//			int coeff, pwr;
//			char base, sign; 	// only for get text in format
//			while (fin >> coeff >> base >> sign >> pwr)
//			{	
//				addNode(coeff, pwr);
//			}
//		}
//		else {
//			cout << "\n Cannot open file\n";
//		}
//		fin.close();
//	}
//	PolyNomial operator+(const PolyNomial& other) { // operator overloading
//		PolyNomial asnwer;
//		PolynomialNode* node1 = head;
//		PolynomialNode* node2 = other.head;
//		while (node1 && node2)// true until both are NULL
//		{
//			if (node1->pwr > node2->pwr) {
//				asnwer.addNode(node1->coefficient, node1->pwr);
//				node1 = node1->next;
//			}
//			else if (node1->pwr == node2->pwr) {
//				asnwer.addNode(node1->coefficient + node2->coefficient, node1->pwr);
//				// traverse
//				node1 = node1->next;
//				node2 = node2->next;
//			}
//			else {
//				asnwer.addNode(node2->coefficient, node2->pwr);
//				node2 = node2->next;
//			}
//		}
//		// now if only a or b is not null
//		while (node1) {
//			asnwer.addNode(node1->coefficient, node1->pwr);
//			node1 = node1->next;
//		}
//		while (node2) {
//			asnwer.addNode(node2->coefficient, node2->pwr);
//			node2 = node2->next;
//		}
//		return asnwer;
//	}
//	void displayPolynomial() {
//		if (isEmpty()) {
//			cout << "\nNode is empty.\n";
//			return;
//		}
//		PolynomialNode* cur = head;
//		while (cur != NULL) {
//			cout << cur->coefficient << "x^" << cur->pwr;
//			if (cur->next && cur->next->coefficient >= 0) {
//				cout << "+";
//			}
//			cur = cur->next;
//		}
//	}
//};
//int main() {
//	PolyNomial result, temp1, temp2;
//	temp1.importFromFile("polynomial1.txt");
//	cout << "\n1st polynomial imported from file :\n";
//	temp1.displayPolynomial();
//	temp2.importFromFile("polynomial2.txt");
//	cout << "\n2nd polynomial imported from file :\n";
//	temp2.displayPolynomial();
//	result = temp1 + temp2;
//	cout << "\nResult :\n";
//	result.displayPolynomial();
//	return 0;
//}