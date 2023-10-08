#include<iostream>
#include<string>
using namespace std;

// Global variables here
string resultString = " ";

void menu() {
    cout << "\n1. Calculate expression as Postfix.\n2. Calculate expression as Prefix.\n3. Quit.\n";
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
    void makeNull() {
        while (!isEmpty()) {
            pop();
        }
    }
} stakData, stakCalculate;

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
int performOperation(string op ,int operand1, int operand2) {
    if (op == "+")
        return operand1 + operand2;
    else if (op == "-")
        return operand1 - operand2;
    else if (op == "*")
        return operand1 * operand2;
    else if (op == "/")
        return operand1 / operand2;
    else if (op == "%")
        return operand1 % operand2;
    else
        cout << "\nInvalid Operator!!\n";
    return 0;
}
void evaluatePreexpression(string ch) { //symb = next inputS character;
    if (!isOperator(ch) && ch != "(" && ch != ")") { //if (symb is an operand)
        stakCalculate.push(ch); //push(opndstk, symb)
   }
    else { // if ch is operator
        int operand1, operand2;
        operand1 =stoi(stakCalculate.pop());
        operand2 = stoi(stakCalculate.pop()); // convert string into number
        // now perfrom calculation and store them in result using operand1 and operand2 and ch will be operator
        int result = performOperation(ch, operand1, operand2); // perform operaiton according to ch
        stakCalculate.push(to_string(result)); // convert result to string and paush in stack
    }
}
void evaluatePostexpression(string ch) {
    if (!isOperator(ch) && ch != "(" && ch != ")") {
        stakCalculate.push(ch); // Push operands onto the stack
    }
    else  { // If ch is an operator
       
        int operand1 = stoi(stakCalculate.pop());
        int operand2 = stoi(stakCalculate.pop());
        int result = performOperation(ch, operand2, operand1);
        cout <<"RESULT HERE" << result<<endl;
        stakCalculate.push(to_string(result));
    }
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
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ') {
            continue;
        }
        else {
            token = expression[i];
            convertToPostfix(token);
        }
    }

    while (!stakData.isEmpty()) {
        resultString += stakData.pop() + " ";
    }
    cout << "\nYour Postfix Expression: " << resultString << endl;
    cout << "Now Calculating POSTFix expression.\n";
    stakCalculate.makeNull(); // make sure stack is already empty if not then make it empty
    // now calculate result string
    token = " ";
    for (int i = 0; i < resultString.length(); i++)
    {
        if (resultString[i] == ' ') {
            continue;
        }
        else {
            token = resultString[i];
            evaluatePostexpression(token);
        }
    }
    string result = " ";
    result = stakCalculate.pop();
    cout << "Result of expression is :" << result << endl;

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

    cout << "\nYour Prefix Expression: " << prefixExpression << endl;
    // now calculate the preExpression 
    cout << "Now calculating your Prefix expression.\n";
    stakCalculate.makeNull(); // make sure stack is already empty if not then make it empty
    token = " "; // reset token value
    for (int i = prefixExpression.length()-1; i >= 0; i--)
    {
        if (prefixExpression[i] == ' ') {
            continue;
        }
        else {
            token = prefixExpression[i];
            evaluatePreexpression(token);
        }
    }
    string result = stakCalculate.pop();
    cout << "Result of prefix expression is :" << result << endl;
}

int main() {
    int choice = 0;
    while (1) {
        menu();
        cout << "Select Option :";
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