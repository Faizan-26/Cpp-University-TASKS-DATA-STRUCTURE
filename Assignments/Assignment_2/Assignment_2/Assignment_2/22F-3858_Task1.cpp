#include<iostream>
#include<string>
#include<sstream>
using namespace std;

// Global variables here
string resultString = " ";
void menu() {
    cout << "1.Calculate Data as Postfix.\n2. Calculate Data as Prefix.\n3.Quit.\n";
}

struct Node {
    string data;
    Node* next;
    Node() {
        data = " ";
        next = NULL;
    }
    Node(string Data) {
        data = Data;
        next = NULL;
    }
};

class StackClass {
private:
    Node* top;
public:
    StackClass() {
        top = NULL;
    }
    bool isEmpty() {
        return (top == NULL);
    }
    bool push(string data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            top = newNode;
            return true;
        }
        newNode->next = top;
        top = newNode;
        return true;
    }
    string pop() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return " ";
        }
        string value = top->data;
        Node* deleteNode = top;
        top = top->next;
        delete deleteNode;
        return value;
    }
    string giveTopValue() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return " ";
        }
        return top->data;
    }
} stakData;

bool isOperator(string op) {
    if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%")
        return true;
    return false;
}

int getPrecedence(string op) {
    if (op == "+" || op == "-")
        return 1;
    if (op == "*" || op == "/" || op == "%")
        return 2;
    return 0;
}

void convertToPostfix(string ch) {
    if (!isOperator(ch) && ch != "(" && ch != ")") {
        resultString += ch + " ";
    }
    else if (ch == ")") {
        while (!stakData.isEmpty() && stakData.giveTopValue() != "(") {
            resultString += stakData.pop() + " ";
        }
        if (!stakData.isEmpty() && stakData.giveTopValue() == "(") {
            stakData.pop();
        }
    }
    else if (ch == "(") {
        stakData.push(ch);
    }
    else {
        while (!stakData.isEmpty() && getPrecedence(ch) <= getPrecedence(stakData.giveTopValue())) {
            resultString += stakData.pop() + " ";
        }
        stakData.push(ch);
    }
}

void convertPostExpression() {
    resultString = "";
    cout << "\nEnter Your Expression (with spaces): ";
    string expression, token;
    getline(cin, expression); // get input with spaces

    istringstream tokenStream(expression); // create instance of expression in tokenStream
    while (getline(tokenStream, token, ' ')) { // read tokenStream until it get ' ' or end of expression
        convertToPostfix(token); // if not ' ' then do this 
    }

    while (!stakData.isEmpty()) {
        resultString += stakData.pop() + " ";
    }
    cout << "Your Postfix Expression: " << resultString << endl;
}


void convertPreExpression() {
    resultString = "";
    cout << "\nEnter Your Expression (with space): ";
    string expression, token;
    getline(cin, expression);
    // change brackets 
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(') {
            expression[i] = ')';
        }
        else if (expression[i] == ')') {
            expression[i] = '(';
        }
    }
    // Reverse the original expression
    string reverseExpression = "";
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        reverseExpression += expression[i];
    }

    for (int i = 0; i < reverseExpression.length(); i++)
    {
        if (reverseExpression[i] == ' ') {
            continue;
        }
        else {
            token = reverseExpression[i];
            convertToPostfix(token);
        }
    }

    while (!stakData.isEmpty()) {
        resultString += stakData.pop() + " ";
    }

    // Reverse the postfix result to get the prefix expression
    string prefixExpression = "";
    for (int i = resultString.length() - 1; i >= 0; i--)
    {
        if (resultString[i] == ' ') {
            continue;
        }
        prefixExpression += resultString[i];
    }

    cout << "Your Prefix Expression: " << prefixExpression << endl;
}

int main() {
    int choice = 0;
    while (1) {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            convertPostExpression();
            break;
        case 2:
            convertPreExpression();
            break;
        default:
            return 0;
        }
    }
    return 0;
}
