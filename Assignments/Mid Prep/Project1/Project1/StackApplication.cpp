//#include <iostream>
//#include <conio.h>
//#include<string>
//using namespace std;
//struct node
//{
//	char data;
//	node* next;
//}*p = NULL, * top = NULL, * save = NULL, * ptr;
//bool isEmpty() {
//	return top == NULL;
//}
//char stackTop() {
//	return top->data;
//}
//void push(char x)
//{
//	p = new node;
//	p->data = x;
//	p->next = NULL;
//	if (top == NULL)
//	{
//		top = p;
//	}
//	else
//	{
//		p->next = top;
//		top = p;
//	}
//}
//char pop()
//{
//	if (isEmpty())
//	{
//		cout << "\n Stack is empty.\n";
//	}
//	else
//	{
//		char x = top->data;
//		ptr = top;
//		top = top->next;
//		delete ptr;
//		return x;
//	}
//}
//bool prec(char ch1, char ch2) {
//	int p1, p2; //  to store precedence of ch 1 or 2
//	switch (ch1) { // for assign p1 according to left which is ch1
//	case '^':
//		p1 = -1;
//		break;
//	case '*':
//	case '/':
//		p1 = 0;
//		break;
//	case '+':
//	case '-':
//		p1 = 1;
//		break;
//	default:
//		p1 = -2; // if input is invalid invalid operator
//	}
//	// lesser value have higher precedency
//	switch (ch2) {
//	case '^':
//		p2 = -1;
//		break;
//	case '*':
//	case '/':
//		p2 = 0;
//		break;
//	case '+':
//	case '-':
//		p2 = 1;
//		break;
//	default:
//		p2 = -2;
//	}
//	// if any operator is invalid
//	if (p1 == -2 || p2 == -2)
//		return false;
//	else
//		// return true if precedence 1 is less or equal to precedence 2, except when both are ^
//		return (p1 == -1 && p2 != -1) || (p1 != -1 && p2 != -1 && p1 <= p2);
//}
//
//string poststring; // for storing final output
//void postfix(char character, char topsymb) {
//
//	if (character >= 'a' && character <= 'z' || character >='A' && character <= 'Z') { // if character is an operand
//		poststring += character;
//	}
//	else if (character == '(') {
//		push(character); // push it to stack
//	}
//	else if (character == ')') { // if character is a closing parenthesis
//		while (!isEmpty() && top->data != '(') { // while stack is not empty and top is not an opening parenthesis
//			topsymb = pop();
//			poststring += topsymb;
//		}
//		if (!isEmpty() && top->data == '(') { // if stack is not empty and top is an opening parenthesis
//			topsymb = pop(); // discard both parentheses from output
//		}
//	}
//	else { // if character is an operator
//		while (!isEmpty() && prec(top->data, character)) { // while stack is not empty and top has higher or equal precedence than character
//			topsymb = pop();
//			poststring += topsymb;
//		}
//		push(character);
//	}
//}
//int main()
//{
//	char expr[30];
//	cout << "enter the balanced expression\n";
//	cin >> expr;
//	char topsymb = ' ';
//	poststring = "";
//	for (int i = 0; i < strlen(expr); i++)
//	{
//		postfix(expr[i], topsymb);
//	}
//	while (!isEmpty()) {
//		topsymb = pop();
//		poststring += topsymb;
//	}
//	cout << "ans is " << poststring << endl;
//	system("pause");
//}