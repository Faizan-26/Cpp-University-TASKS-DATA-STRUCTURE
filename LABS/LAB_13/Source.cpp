#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char c) {
    return c == '~' || c == '*' || c == '+' || c == '>' || c == '=';
}

int precedence(char c) {
    if (c == '~') return 4;
    if (c == '*') return 3;
    if (c == '+') return 2;
    if (c == '>') return 1;
    if (c == '=') return 0;
    return -1;
}

string infixToPostfix(string exp) {
    string postfix = "";
    stack<char> s;
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (c == ' ') continue; // ignore spaces
        if (isalpha(c)) { // if c is a variable then append it to postfix
            postfix += c;
        }
        else if (c == '(') { // if c is an opening bracket, push it to stack
            s.push(c);
        }
        else if (c == ')') { // if c is a closing bracket, pop and append all operators until '('
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') s.pop(); // pop the '('
        }
        else if (isOperator(c)) { // if c is an operator, pop and append all operators with higher or equal precedence
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // push c to stack
        }
    }
    while (!s.empty()) { // pop and append the remaining operators
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// A function to evaluate a postfix expression for a given assignment of variables
bool evaluatePostfix(string postfix, bool vars[]) {
    stack<bool> s;
    for (int i = 0; i < postfix.size(); i++) {
        char c = postfix[i];
        if (isalpha(c)) { // if c is a variable, push its value to stack
            s.push(vars[c - 'a']);
        }
        else if (isOperator(c)) { // if c is an operator, pop and apply it to the operands
            bool x, y, z;
            switch (c) {
            case '~': // for negation
                x = s.top();
                s.pop();
                z = !x;
                break;
            case '*': // conjunction
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();
                z = x && y;
                break;
            case '+': // disjunction
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();
                z = x || y;
                break;
            case '>': // implication
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();
                z = !y || x;
                break;
            case '=': // equivalence
                x = s.top();
                s.pop();
                y = s.top();
                s.pop();
                z = x == y;
                break;
            }
            s.push(z); // push the result to stack
        }
    }

    return s.top(); // return the final result
}

void printTruthTable(string exp) {
    string postfix = infixToPostfix(exp);
    cout << "Your post expression :" << postfix << endl;
    bool vars[26] = { false }; // an array to store the variables in the expression
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (isalpha(c) && !vars[c - 'a']) {
            vars[c - 'a'] = true; // add c to vars if it is a variable and not already present
        }
    }
    int n = 0; // the number of variables
    for (int i = 0; i < 26; i++) {
        if (vars[i]) n++;
    }
    int rows = 1 << n; // the number of rows in the truth table
    cout << "Truth table for " << exp << ":\n";
    for (int i = 0; i < 26; i++) { // print the header row
        if (vars[i]) {
            cout << static_cast<char>('a' + i) << "\t";
        }
    }
    cout << exp << "\n";
    for (int i = 0; i < rows; i++) {
        bool assignment[26] = { false }; // an array to store the assignment
        int index = 0;
        for (int j = 0; j < 26; j++) {
            if (vars[j]) {
                assignment[j] = ((i / static_cast<int>(pow(2, n - index - 1))) % 2) != 0;
                cout << assignment[j] << "\t"; // print the value
                index++;
            }
        }
        bool result = evaluatePostfix(postfix, assignment); // evaluate the expression for the assignment
        cout << result << "\n"; // print the result
    }
}

int main() {
    string exp;
    cout << "Enter an expression: ";
    getline(cin, exp);
    printTruthTable(exp);
    return 0;
}